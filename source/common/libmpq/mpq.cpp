#include "../DefInc.h"

#include "mpq.h"
#include <ctype.h>

#include "bzlib.h"

#include "../crc/CrcService.h"


void compress_bzip2(char * in_buf, unsigned int in_size, char * out_buf, unsigned int * out_size)
{
	BZ2_bzBuffToBuffCompress(out_buf, out_size, in_buf, in_size, 1, 0, 0);
}

void decompress_bzip2(char * in_buf, unsigned int in_size, char * out_buf, unsigned int * out_size)
{
	BZ2_bzBuffToBuffDecompress(out_buf, out_size, in_buf, in_size, 0, 0);
}

mpq_file * check_file(const char * nPath)
{
	mpq_file * mpqfile = new mpq_file;
	fopen_s(&mpqfile->mFile, nPath, "rb");
	head_table headtable;
	fread(&headtable, sizeof(head_table), 1, mpqfile->mFile);
	mpqfile->mCount = headtable.mCount;
	mpqfile->mCompress = headtable.mCompress;
	mpqfile->mHashTable = new hash_table[mpqfile->mCount];
	fread(mpqfile->mHashTable, sizeof(hash_table), mpqfile->mCount, mpqfile->mFile);
	return mpqfile;
}

mpq_file * open_file(const char * nPath, int nCount)
{
	mpq_file * mpqfile = new mpq_file;
	fopen_s(&mpqfile->mFile, nPath, "wb");
	head_table headtable;
	headtable.mCompress = true;
	headtable.mCount = nCount;
	headtable.mHash = 0;
	headtable.mSize = 0;
	fwrite(&headtable, sizeof(head_table), 1, mpqfile->mFile);
	mpqfile->mCount = headtable.mCount;
	mpqfile->mCompress = headtable.mCompress;
	mpqfile->mIndex = 0;
	mpqfile->mPos = sizeof(head_table) + sizeof(hash_table) * (mpqfile->mCount);
	mpqfile->mHashTable = new hash_table[mpqfile->mCount];
	return mpqfile;
}

bool have_file(mpq_file * nFile, const char * nKey)
{
	std::CrcService& crcService_ = std::Singleton<std::CrcService>::instance();
	unsigned long hash1 = crcService_.runCommon(nKey);
	unsigned long beg = 0;
	unsigned int end = 0;
	for (unsigned short i = 0; i < nFile->mCount; ++i)
	{
		hash_table * hashtable = &(nFile->mHashTable[i]);
		if (hashtable->mHash == hash1)
		{
			return true;
		}
	}
	return false;
}

void read_file(mpq_file * nFile, const char * nKey, char ** nBuf, unsigned int * nSize)
{
	std::CrcService& crcService_ = std::Singleton<std::CrcService>::instance();
	unsigned long hash1 = crcService_.runCommon(nKey);
	unsigned long beg = 0;
	unsigned int end = 0;
	for (unsigned short i = 0; i < nFile->mCount; ++i)
	{
		hash_table * hashtable = &(nFile->mHashTable[i]);
		if (hashtable->mHash == hash1)
		{
			beg = hashtable->mBeg;
			end = hashtable->mEnd;
			(*nSize) = hashtable->mSize;
			break;
		}
	}
 	static char buf[1024 * 1024];
 	memset(buf, 0, sizeof(buf));
	fseek(nFile->mFile, beg, SEEK_SET);
	fread(buf, 1, end, nFile->mFile);
	(*nBuf) = new char[*nSize];
 	decompress_bzip2(buf, end, *nBuf, nSize);
}

static void write_buf(mpq_file * nFile, const char * nKey, char * nBuf, unsigned int nSize)
{
	static char buf[1024 * 1024];
	memset(buf, 0, sizeof(buf));
	unsigned int size = 1024 * 1024;
	compress_bzip2(nBuf, nSize, buf, &size);
	fseek(nFile->mFile, nFile->mPos, SEEK_SET);
	hash_table * hashtable = &(nFile->mHashTable[nFile->mIndex]);
	hashtable->mBeg = nFile->mPos;
	hashtable->mEnd = size;
	hashtable->mSize = nSize;
	std::CrcService& crcService_ = std::Singleton<std::CrcService>::instance();
	hashtable->mHash = crcService_.runCommon(nKey);
	fwrite(buf, 1, size, nFile->mFile);
	nFile->mIndex++;
	nFile->mPos += size;
}

void write_file(mpq_file * nFile, const char * nPath, const char * nKey)
{
	FILE * file = nullptr;
	fopen_s(&file, nPath, "rb");
	fseek(file, 0, SEEK_END);
	long len = ftell(file);
	fseek(file, 0, SEEK_SET);
	static char buf[1024 * 1024];
	memset(buf, 0, sizeof(buf));
	fread(buf, 1, len, file);
	fclose(file);
	buf[len + 1] = 0;
	write_buf(nFile, nKey, buf, len);
}

void free_buf(char * nBuf, unsigned int nSize)
{
	delete [] nBuf;
}

void save_close_file(mpq_file * nFile)
{
	save_file(nFile);
	close_file(nFile);
}

void close_file(mpq_file * nFile)
{
	fclose(nFile->mFile);
	delete [] nFile->mHashTable;
	delete nFile;
}

void save_file(mpq_file * nFile)
{
	fseek(nFile->mFile, sizeof(head_table), SEEK_SET);
	fwrite(nFile->mHashTable, sizeof(hash_table), nFile->mCount, nFile->mFile);
}


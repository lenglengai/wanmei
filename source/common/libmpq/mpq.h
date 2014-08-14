#ifndef mpq_h__
#define mpq_h__

#include <cstdio>

struct head_table
{
	unsigned long mHash;
	unsigned long mSize;
	unsigned short mCount;
	bool mCompress;
};

struct hash_table
{
	unsigned long mHash;
	unsigned long mBeg;
	unsigned long mEnd;
	unsigned long mSize;
};

struct mpq_file
{
	FILE * mFile;
	bool mCompress;
	unsigned short mCount;
	int mIndex;
	unsigned long mPos;
	struct hash_table * mHashTable;
};
void compress_bzip2(char * in_buf, unsigned int in_size, char * out_buf, unsigned int * out_size);
void decompress_bzip2(char * in_buf, unsigned int in_size, char * out_buf, unsigned int * out_size);
unsigned long hash_string(const char * nKey, unsigned long nOffset);
mpq_file * check_file(const char * nPath);
mpq_file * open_file(const char * nPath, int nCount);
bool have_file(mpq_file * nFile, const char * nKey);
void read_file(mpq_file * nFile, const char * nKey, char ** nBuf, unsigned int * nSize);
void write_file(mpq_file * nFile, const char * nPath, const char * nKey);
void free_buf(char * nBuf, unsigned int nSize);
void close_file(mpq_file * nFile);
void save_close_file(mpq_file * nFile);
void save_file(mpq_file * nFile);

#endif // mpq_h__

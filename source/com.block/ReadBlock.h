#pragma once

#include "IBlock.h"

namespace std{

	class ReadBlock : public IBlock, boost::noncopyable
	{
	public:
		bool runBool(bool& nValue);

		bool runInt8(__i8& nValue);
		bool runInt8s(list<__i8>& nValue);

		bool runInt16(__i16& nValue);
		bool runInt16s(list<__i16>& nValue);

		bool runInt32(__i32& nValue);
		bool runInt32s(list<__i32>& nValue);

		bool runInt64(__i64& nValue);
		bool runInt64s(list<__i64>& nValue);

		bool runString(string& nValue);
		bool runStrings(list<string>& nValue);

		bool runFloat(float& nValue);
		bool runFloats(list<float>& nValue);

		bool runDouble(double& nValue);
		bool runDoubles(list<double>& nValue);

		bool runPush(char * nBuffer, __i16 nSize);

		ReadBlock();
		~ReadBlock();

	private:
		char * getBuffer(__i16 nSize);
		void runClear();

	private:
		char mValue[1024];
		__i16 mLeft;
		char * mBuffer;
		__i16 mSize;
		__i16 mLength;
		__i16 mPos;
	};
	typedef boost::shared_ptr<ReadBlock> ReadBlockPtr;

}

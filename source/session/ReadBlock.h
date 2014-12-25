#pragma once

namespace std{

	enum class BlockPushType_ : __i8
	{
		mError_ = 0,
		mLength_ = 1,
		mFinish_ = 2
	};
	class ReadBlock : public IBlock
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
		
		bool isReader() const;

		BlockPushType_ runPush(char * nBuffer, const __i16 nSize);
		void endPush();
		void runClear();

		ReadBlock();
		~ReadBlock();

	private:
		const char * getBuffer(const __i16 nSize);
		
	private:
		char mValue[PACKETMAX];
		__i16 mLeft;
		char * mBuffer;
		__i16 mSize;
		__i16 mLength;
		__i16 mPos;
	};
	typedef shared_ptr<ReadBlock> ReadBlockPtr;

}

#pragma once

#ifdef __NET__
namespace std{

	enum BlockPushType_ : __i8
	{
		mBlockPushTypeError_ = 0,
		mBlockPushTypeLength_ = 1,
		mBlockPushTypeFinish_ = 2
	};
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

		bool runString(std::string& nValue);
		bool runStrings(list<std::string>& nValue);

		bool runFloat(float& nValue);
		bool runFloats(list<float>& nValue);

		bool runDouble(double& nValue);
		bool runDoubles(list<double>& nValue);

		BlockPushType_ runPush(char * nBuffer, __i16 nSize);
		void endPush();

		ReadBlock();
		~ReadBlock();

	private:
		char * getBuffer(__i16 nSize);
		void runClear();

	private:
		char mValue[PACKETMAX];
		__i16 mLeft;
		char * mBuffer;
		__i16 mSize;
		__i16 mLength;
		__i16 mPos;
	};
	typedef std::shared_ptr<ReadBlock> ReadBlockPtr;

}
#endif

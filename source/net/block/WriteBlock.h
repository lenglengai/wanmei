#pragma once

namespace std {

	class WriteBlock : public IBlock, boost::noncopyable
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

		void runClear();
		void runEnd();

		char * getBuffer();
		__i16 getLength();
		__i16 getTotal();

		WriteBlock();
		~WriteBlock();
	
	private:
		template<typename T>
		bool runCopy(T& nT)
		{
			if ((mLength + sizeof(__i16)+sizeof(T)) > PACKETMAX) {
				return false;
			}
			memcpy((mBuffer + mLength + sizeof(__i16)), &nT, sizeof(T));
			mLength += sizeof(T);
			return true;
		}

		bool runCopy(const char * nValue, __i16 nLength);

	private:
		char mBuffer[PACKETMAX];
		__i16 mLength;
	};
	typedef boost::shared_ptr<WriteBlock> WriteBlockPtr;

}

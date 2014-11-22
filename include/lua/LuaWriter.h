#pragma once

namespace std {

	class LuaWriter : boost::noncopyable
	{
	public:
		void runString(std::string& nValue, const char * nName);
		void runString(const char * nValue, const char * nName);
		void runString(char * nValue, const char * nName);

		template<typename T>
		void runInt(T nValue, const char * nName)
		{
			this->runFirst();
			mValue += nName; mValue += "=";
			mValue +=  __convert<std::string, T>(nValue, mConvertTypeText_);
		}

		template<typename T>
		void runInt(T nValue)
		{
			this->runFirst();
			mValue +=  __convert<std::string, T>(nValue, mConvertTypeText_);
		}

		template<typename T>
		void indexBegin(T nIndex)
		{
			this->runFirst();
			mValue += "[";
			mValue +=  __convert<std::string, T>(nIndex, mConvertTypeText_);
			mValue += "]={";
			mFirst = true;
		}

		void indexEnd();

		void tableBegin(const char * nName, bool nReturn = false);
		void tableEnd(bool nReturn = false);

		template <typename T>
		void runInts(std::list<T>& nValue, const char * nName)
		{
			tableBegin(nName);
			for (auto& i : nValue) {
				runInt(i);
			}
			tableEnd();
		}
		void runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName);

		const char * getValue();
		void runClear();

	private:
		void runFirst();

	public:
		LuaWriter();
		~LuaWriter();

	private:
		std::string mValue;
		std::string mTable;
		bool mFirst;
	};

}

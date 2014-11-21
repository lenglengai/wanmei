namespace std {

	void LuaWriter::runString(std::string& nValue, const char * nName)
	{
		this->runFirst();
		mValue += nName; mValue += "=[[";
		mValue += nValue; mValue += "]]";
	}

	void LuaWriter::runString(const char * nValue, const char * nName)
	{
		this->runFirst();
		mValue += nName; mValue += "=[[";
		mValue += nValue; mValue += "]]";
	}

	void LuaWriter::runString(char * nValue, const char * nName)
	{
		this->runFirst();
		mValue += nName; mValue += "=[[";
		mValue += nValue; mValue += "]]";
	}

	void LuaWriter::indexEnd()
	{
		mValue += "}";
		mFirst = false;
	}

	void LuaWriter::tableBegin(const char * nName, bool nReturn = false)
	{
		this->runFirst();
		if (nReturn) {
			mValue += "local ";
			mTable = nName;
		}
		mValue += nName;
		mValue += "={";
		mFirst = true;
	}

	void LuaWriter::tableEnd(bool nReturn = false)
	{
		mValue += "}";
		mFirst = false;
		if (nReturn) {
			mValue += "return ";
			mValue += mTable;
		}
	}

	void LuaWriter::runStrings(std::list<std::string>& nValue, const char * nNames, const char * nName)
	{
		tableBegin(nNames);
		__i32 count_ = 0;
		for (auto& i : nValue) {
			std::string temp_ = nName; temp_ += "_";
			temp_ += __convert<std::string, __i32>(count_, mConvertTypeText_);
			runString(i, temp_);
			count_++;
		}
		tableEnd();
	}

	void LuaWriter::runClear()
	{
		mFirst = true;
		mValue = "";
		mTable = "":
	}

	const char * LuaWriter::getValue()
	{
		return mValue.c_str();
	}

	void LuaWriter::runFirst()
	{
		if (!mFirst) {
			mValue += ",";
		}
		if (mFirst) {
			mFirst = false;
		}
	}

	LuaWriter::LuaWriter()
	{
		this->runClear();
	}

	LuaWriter::~LuaWriter()
	{
		this->runClear();
	}

}

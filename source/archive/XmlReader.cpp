#include "../Include.h"

#ifdef __COCOS2DX__
#include <cocos2d.h>
#endif

namespace std {

	void XmlReader::runBool(bool& nValue, const char * nName, const bool nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, bool>(text_, ConvertType_::mText_);
	}

	void XmlReader::runInt8(__i8& nValue, const char * nName, const __i8 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i8>(text_);
	}

	void XmlReader::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i8 value_ = __convert<char *, __i8>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt8Count(__i8& nValue, const char * nName, const __i32 nCount, const __i8 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i8>(text_);
	}

	void XmlReader::runInt8sCount(list<__i8>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i8 temp = 0; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runInt8(temp, name_.c_str());
			if (0 != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runInt8Semi(list<__i8>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, __i8>(tempStr));
		}
	}

	void XmlReader::runInt16(__i16& nValue, const char * nName, const __i16 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i16>(text_);
	}

	void XmlReader::runInt16s(list<__i16>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i16 value_ = __convert<char *, __i16>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt16Count(__i16& nValue, const char * nName, const __i32 nCount, const __i16 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i16>(text_);
	}

	void XmlReader::runInt16sCount(list<__i16>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i16 temp = 0; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runInt16(temp, name_.c_str());
			if (0 != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runInt16Semi(list<__i16>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, __i16>(tempStr));
		}
	}

	void XmlReader::runInt32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i32>(text_);
	}

	void XmlReader::runInt32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i32 value_ = __convert<char *, __i32>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i32>(text_);
	}

	void XmlReader::runInt32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i32 temp = 0; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runInt32(temp, name_.c_str());
			if (0 != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runInt32Semi(list<__i32>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, __i32>(tempStr));
		}
	}

	void XmlReader::runCrc32(__i32& nValue, const char * nName, const __i32 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		CrcService& crcService = Singleton<CrcService>::instance();
		nValue = crcService.runCommon(text_);
	}

	void XmlReader::runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		CrcService& crcService = Singleton<CrcService>::instance();
		xmlNode_ = xmlNode_->first_node();
		for (; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling()) {
			char * text_ = xmlNode_->value();
			__i32 value_ = crcService.runCommon(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runCrc32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		CrcService& crcService = Singleton<CrcService>::instance();
		nValue = crcService.runCommon(text_);
	}


	void XmlReader::runCrc32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i32 tempI32 = 0; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runCrc32(tempI32, name_.c_str());
			if (0 != tempI32) nValue.push_back(tempI32);
		}
	}

	void XmlReader::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		CrcService& crcService = Singleton<CrcService>::instance();
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(crcService.runCommon(tempStr.c_str()));
		}
	}

	void XmlReader::runInt64(__i64& nValue, const char * nName, const __i64 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) {
			char * text_ = xmlAttribute_->value();
			nValue = __convert<char *, __i64>(text_);
		}
	}

	void XmlReader::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i64 value_ = __convert<char *, __i64>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt64Count(__i64& nValue, const char * nName, const __i32 nCount, const __i64 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, __i64>(text_);
	}

	void XmlReader::runInt64sCount(list<__i64>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i64 temp = 0; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runInt64(temp, name_.c_str());
			if (0 != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runInt64Semi(list<__i64>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, __i64>(tempStr));
		}
	}

	void XmlReader::runString(string& nValue, const char * nName, const char * nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		nValue = xmlAttribute_->value();
	}

	void XmlReader::runStrings(list<string>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			string value_ = xmlNode_->value();
			nValue.push_back(value_);
		}
	}

	void XmlReader::runStringCount(string& nValue, const char * nName, const __i32 nCount, const char * nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		nValue = xmlAttribute_->value();
	}

	void XmlReader::runStringsCount(list<string>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			string temp = ""; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runString(temp, name_.c_str());
			if ("" != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runStringSemi(list<string>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		boost::split(nValue, text_, boost::is_any_of(";"));
	}

	void XmlReader::runFloat(float& nValue, const char * nName, const float nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, float>(text_);
	}

	void XmlReader::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			float value_ = __convert<char *,float>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runFloatCount(float& nValue, const char * nName, const __i32 nCount, const float nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, float>(text_);
	}

	void XmlReader::runFloatsCount(list<float>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			float temp = 0.f; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runFloat(temp, name_.c_str());
			if (0.f != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runFloatSemi(list<float>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, float>(tempStr));
		}
	}

	void XmlReader::runDouble(double& nValue, const char * nName, const double nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) {
			char * text_ = xmlAttribute_->value();
			nValue = __convert<char *, double>(text_);
		}
	}

	void XmlReader::runDoubles(list<double>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			double value_ = __convert<char *, double>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runDoubleCount(double& nValue, const char * nName, const __i32 nCount, const double nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<__i32, string>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		char * text_ = xmlAttribute_->value();
		nValue = __convert<char *, double>(text_);
	}

	void XmlReader::runDoublesCount(list<double>& nValue, const char * nName, const __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			double temp = 0.; string name_ = nName;
			name_.append(__convert<__i32, string>(i));
			this->runDouble(temp, name_.c_str());
			if (0. != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runDoubleSemi(list<double>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			string& tempStr = (*it);
			nValue.push_back(__convert<string, double>(tempStr));
		}
	}

	bool XmlReader::openUrl(const char * nUrl)
	{
#ifdef __COCOS2DX__
		if (FileUtils::getInstance()->isFileExist(nUrl)) {
			string data_ = cocos2d::FileUtils::getInstance()->getStringFromFile(nUrl);
			mXmlDocument.parse<0>(data_.c_str());
			mXmlNode = mXmlDocument.first_node();
			return true;
		}
		return false;
#else
		mFileDoc.reset(new file<char>(nUrl));
		mXmlDocument.parse<0>(mFileDoc->data());
		mXmlNode = mXmlDocument.first_node();
		return true;
#endif
	}

	bool XmlReader::openStr(char * nValue)
	{
		mXmlDocument.parse<0>(nValue);
		mXmlNode = mXmlDocument.first_node();
		return true;
	}

	void XmlReader::selectStream(const char * nStreamName) const
	{
	}

	__i32 XmlReader::pushStream(const char * nName)
	{
		mXmlNodes.push(mXmlNode);
		return 0;
	}

	void XmlReader::popStream()
	{
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	void XmlReader::runClose()
	{
	}

	XmlReader::XmlReader()
		: mXmlDocument()
		, mXmlNode(nullptr)
		, mXmlNodes()
	{
	}

	XmlReader::~XmlReader()
	{
		mXmlDocument.clear();
		mXmlNode = nullptr;
	}

}

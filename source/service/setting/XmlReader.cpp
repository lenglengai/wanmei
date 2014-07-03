#include "../../common/DefInc.h"
#include "../crc/CrcService.h"
#include "XmlReader.h"

#include "SettingService.h"

namespace std {

	void XmlReader::runBool(bool& nValue, const char * nName, bool nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<bool, char *>(text_, mConvertTypeText_);
	}

	void XmlReader::runInt8(__i8& nValue, const char * nName, __i8 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i8, char *>(text_);
	}

	void XmlReader::runInt8s(list<__i8>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() )
		{
			char * text_ = xmlNode_->value();
			__i8 value_ = __convert<__i8, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i8, char *>(text_);
	}

	void XmlReader::runInt8sCount(list<__i8>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i8 temp = 0; std::string name_ = nName;
			name_.append(__convert<std::string, __i32>(i));
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
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<std::string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			std::string& tempStr = (*it);
			nValue.push_back(__convert<__i8, std::string>(tempStr));
		}
	}

	void XmlReader::runInt16(__i16& nValue, const char * nName, __i16 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i16, char *>(text_);
	}

	void XmlReader::runInt16s(list<__i16>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i16 value_ = __convert<__i16, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal)
	{
		nValue = nOptimal; std::string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i16, char *>(text_);
	}

	void XmlReader::runInt16sCount(list<__i16>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i16 temp = 0; std::string name_ = nName;
			name_.append(__convert<string, __i32>(i));
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
		for (; it != splits.end(); ++it)
		{
			string& tempStr = (*it);
			nValue.push_back(__convert<__i16, string>(tempStr));
		}
	}

	void XmlReader::runInt32(__i32& nValue, const char * nName, __i32 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i32, char *>(text_);
	}

	void XmlReader::runInt32s(list<__i32>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() )
		{
			char * text_ = xmlNode_->value();
			__i32 value_ = __convert<__i32, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i32, char *>(text_);
	}

	void XmlReader::runInt32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i32 temp = 0; string name_ = nName;
			name_.append(__convert<string, __i32>(i));
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
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			std::string& tempStr = (*it);
			nValue.push_back(__convert<__i32, std::string>(tempStr));
		}
	}

	void XmlReader::runCrc32(__i32& nValue, const char * nName, __i32 nOptimal)
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

	void XmlReader::runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal)
	{
		nValue = nOptimal; std::string name_ = nName; name_ += "_";
		name_.append(__convert<std::string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		CrcService& crcService = Singleton<CrcService>::instance();
		nValue = crcService.runCommon(text_);
	}


	void XmlReader::runCrc32sCount(list<__i32>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i32 tempI32 = 0; std::string name_ = nName;
			name_.append(__convert<std::string, __i32>(i));
			this->runCrc32(tempI32, name_.c_str());
			if (0 != tempI32) nValue.push_back(tempI32);
		}
	}

	void XmlReader::runCrc32Semi(list<__i32>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		CrcService& crcService = Singleton<CrcService>::instance();
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<std::string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			std::string& tempStr = (*it);
			nValue.push_back(crcService.runCommon(tempStr.c_str()));
		}
	}

	void XmlReader::runInt64(__i64& nValue, const char * nName, __i64 nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) {
			char * text_ = xmlAttribute_->value();
			nValue = __convert<__i64, char *>(text_);
		}
	}

	void XmlReader::runInt64s(list<__i64>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			__i64 value_ = __convert<__i64, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal)
	{
		nValue = nOptimal; std::string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<__i64, char *>(text_);
	}

	void XmlReader::runInt64sCount(list<__i64>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			__i64 temp = 0; std::string name_ = nName;
			name_.append(__convert<string, __i32>(i));
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
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<std::string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			std::string& tempStr = (*it);
			nValue.push_back(__convert<__i64, string>(tempStr));
		}
	}

	void XmlReader::runString(std::string& nValue, const char * nName, const char * nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		nValue = xmlAttribute_->value();
	}

	void XmlReader::runStrings(list<std::string>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() )
		{
			string value_ = xmlNode_->value();
			nValue.push_back(value_);
		}
	}

	void XmlReader::runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal)
	{
		nValue = nOptimal; string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		nValue = xmlAttribute_->value();
	}

	void XmlReader::runStringsCount(list<std::string>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			std::string temp = ""; std::string name_ = nName;
			name_.append(__convert<std::string, __i32>(i));
			this->runString(temp, name_.c_str());
			if ("" != temp){
				nValue.push_back(temp);
			}
		}
	}

	void XmlReader::runStringSemi(list<std::string>& nValue, const char * nName)
	{
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		boost::split(nValue, text_, boost::is_any_of(";"));
	}

	void XmlReader::runFloat(float& nValue, const char * nName, float nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_) return;
		char * text_ = xmlAttribute_->value();
		nValue = __convert<float, char *>(text_);
	}

	void XmlReader::runFloats(list<float>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() ) {
			char * text_ = xmlNode_->value();
			float value_ = __convert<float, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal)
	{
		nValue = nOptimal; std::string name_ = nName; name_ += "_";
		name_.append(__convert<std::string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		char * text_ = xmlAttribute_->value();
		nValue = __convert<float, char *>(text_);
	}

	void XmlReader::runFloatsCount(list<float>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i)
		{
			float temp = 0.f; std::string name_ = nName;
			name_.append(__convert<std::string, __i32>(i));
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
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<std::string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it)
		{
			std::string& tempStr = (*it);
			nValue.push_back(__convert<float, std::string>(tempStr));
		}
	}

	void XmlReader::runDouble(double& nValue, const char * nName, double nOptimal)
	{
		nValue = nOptimal;
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(nName);
		if (nullptr == xmlAttribute_)
		{
			char * text_ = xmlAttribute_->value();
			nValue = __convert<double, char *>(text_);
		}
	}

	void XmlReader::runDoubles(list<double>& nValue, const char * nNames, const char * nName)
	{
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		if (nullptr == xmlNode_) return;
		xmlNode_ = xmlNode_->first_node();
		for ( ; xmlNode_ != NULL; xmlNode_ = xmlNode_->next_sibling() )
		{
			char * text_ = xmlNode_->value();
			double value_ = __convert<double, char *>(text_);
			nValue.push_back(value_);
		}
	}

	void XmlReader::runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal)
	{
		nValue = nOptimal; std::string name_ = nName; name_ += "_";
		name_.append(__convert<std::string, __i32>(nCount));
		xml_attribute<char> * xmlAttribute_ = mXmlNode->first_attribute(name_.c_str());
		char * text_ = xmlAttribute_->value();
		nValue = __convert<double, char *>(text_);
	}

	void XmlReader::runDoublesCount(list<double>& nValue, const char * nName, __i32 nCount)
	{
		for (__i32 i = 0; i < nCount; ++i) {
			double temp = 0.; std::string name_ = nName;
			name_.append(__convert<std::string, __i32>(i));
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
		std::string text_ = xmlAttribute_->value();
		boost::trim_if(text_, boost::is_any_of("; "));
		list<std::string> splits;
		boost::split(splits, text_, boost::is_any_of(";"));
		list<std::string>::iterator it = splits.begin();
		for (; it != splits.end(); ++it) {
			std::string& tempStr = (*it);
			nValue.push_back(__convert<double, std::string>(tempStr));
		}
	}

	void XmlReader::openUrl(const char * nUrl)
	{
		SettingService& settingService_ = Singleton<SettingService>::instance();
		std::string url_ = settingService_.systemPath();
		if ("" != url_) url_ += "/"; url_ += nUrl;
		mFileDoc.reset(new file<char>(url_.c_str()));
		mXmlDocument.parse<0>(mFileDoc->data());
		mXmlNode = mXmlDocument.first_node();
	}

	void XmlReader::selectStream(const char * nStreamName) {
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
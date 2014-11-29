#pragma once

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"

using namespace rapidxml;

namespace std {

	class __funapi XmlReader : boost::noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, bool nOptimal = false);

		void runInt8(__i8& nValue, const char * nName, __i8 nOptimal = 0);
		void runInt8s(std::list<__i8>& nValue, const char * nNames, const char * nName);
		void runInt8Count(__i8& nValue, const char * nName, __i32 nCount, __i8 nOptimal = 0);
		void runInt8sCount(std::list<__i8>& nValue, const char * nName, __i32 nCount);
		void runInt8Semi(std::list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName, __i16 nOptimal = 0);
		void runInt16s(std::list<__i16>& nValue, const char * nNames, const char * nName);
		void runInt16Count(__i16& nValue, const char * nName, __i32 nCount, __i16 nOptimal = 0);
		void runInt16sCount(std::list<__i16>& nValue, const char * nName, __i32 nCount);
		void runInt16Semi(std::list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runInt32s(std::list<__i32>& nValue, const char * nNames, const char * nName);
		void runInt32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runInt32sCount(std::list<__i32>& nValue, const char * nName, __i32 nCount);
		void runInt32Semi(std::list<__i32>& nValue, const char * nName);

		void runCrc32(__i32& nValue, const char * nName, __i32 nOptimal = 0);
		void runCrc32s(std::list<__i32>& nValue, const char * nNames, const char * nName);
		void runCrc32Count(__i32& nValue, const char * nName, __i32 nCount, __i32 nOptimal = 0);
		void runCrc32sCount(std::list<__i32>& nValue, const char * nName, __i32 nCount);
		void runCrc32Semi(std::list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName, __i64 nOptimal = 0);
		void runInt64s(std::list<__i64>& nValue, const char * nNames, const char * nName);
		void runInt64Count(__i64& nValue, const char * nName, __i32 nCount, __i64 nOptimal = 0);
		void runInt64sCount(std::list<__i64>& nValue, const char * nName, __i32 nCount);
		void runInt64Semi(std::list<__i64>& nValue, const char * nName);

		void runString(std::string& nValue, const char * nName, const char * nOptimal = "");
		void runStrings(std::list<string>& nValue, const char * nNames, const char * nName);
		void runStringCount(std::string& nValue, const char * nName, __i32 nCount, const char * nOptimal = "");
		void runStringsCount(std::list<std::string>& nValue, const char * nName, __i32 nCount);
		void runStringSemi(std::list<std::string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName, float nOptimal = 0.f);
		void runFloats(std::list<float>& nValue, const char * nNames, const char * nName);
		void runFloatCount(float& nValue, const char * nName, __i32 nCount, float nOptimal = 0.f);
		void runFloatsCount(std::list<float>& nValue, const char * nName, __i32 nCount);
		void runFloatSemi(std::list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName, double nOptimal = 0.);
		void runDoubles(std::list<double>& nValue, const char * nNames, const char * nName);
		void runDoubleCount(double& nValue, const char * nName, __i32 nCount, double nOptimal = 0.);
		void runDoublesCount(std::list<double>& nValue, const char * nName, __i32 nCount);
		void runDoubleSemi(std::list<double>& nValue, const char * nName);

		template<class T>
		void runStream(T& nValue, const char * nName);
		template<class T>
		void runStreamCount(T& nValue, const char * nName, __i32 nCount = 0);
		template<class T>
		void runStreamsCount(std::list<std::shared_ptr<T>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);
		template<class T0, class T1>
		void runKeyStreamsCount(std::map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount = 0);

		bool openStr(char * nValue);
		bool openUrl(const char * nUrl);
		void selectStream(const char * nStreamName);
		__i32 pushStream(const char * nName);
		void popStream();
		void runClose();

	public:
		XmlReader();
		~XmlReader();
	private:
		xml_document<char> mXmlDocument;
		xml_node<char> * mXmlNode;
		std::shared_ptr<file<char>> mFileDoc;
		std::stack<xml_node<char> *> mXmlNodes;
	};

	template<class T>
	void XmlReader::runStream(T& nValue, const char * nName)
	{
		mXmlNodes.push(mXmlNode);
		mXmlNode = mXmlNode->first_node(nName);
		if (nullptr != mXmlNode) {
			nValue.serialize(this, 0);
		}
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	template<class T>
	void XmlReader::runStreamCount(T& nValue, const char * nName, __i32 nCount)
	{
		mXmlNodes.push(mXmlNode);
		string name_ = nName; name_ += "_";
		name_.append(__convert<string, __i32>(nCount));
		mXmlNode = mXmlNode->first_node(name_.c_str());
		if (nullptr != mXmlNode) {
			nValue.serialize(this, nCount);
		}
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	template<class T0>
	void XmlReader::runStreamsCount(std::list<std::shared_ptr<T0> >& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		mXmlNodes.push(mXmlNode);
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		xmlNode_ = xmlNode_->first_node();
		for (; xmlNode_ != nullptr; xmlNode_ = xmlNode_->next_sibling()) {
			mXmlNode = xmlNode_;
			std::shared_ptr<T0> t_(new T0());
			t_->serialize(this, nCount);
			if (t_->isDefault()) continue;
			nValue.push_back(t_);
		}
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}

	template<class T0, class T1>
	void XmlReader::runKeyStreamsCount(std::map<T0, std::shared_ptr<T1>>& nValue, const char * nNames, const char * nName, __i32 nCount)
	{
		mXmlNodes.push(mXmlNode);
		xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
		xmlNode_ = xmlNode_->first_node();
		for (; xmlNode_ != nullptr; xmlNode_ = xmlNode_->next_sibling())
		{
			mXmlNode = xmlNode_;
			std::shared_ptr<T1> t_(new T1());
			t_->serialize(this, nCount);
			if (t_->isDefault()) continue;
			nValue[t_->getKey()] = t_;
		}
		mXmlNode = mXmlNodes.top();
		mXmlNodes.pop();
	}
}
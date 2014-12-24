#pragma once

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"

using namespace rapidxml;

namespace std {

	class __funapi XmlReader : noncopyable
	{
	public:
		void runBool(bool& nValue, const char * nName, const bool nOptimal = false);

		void runInt8(__i8& nValue, const char * nName, const __i8 nOptimal = 0);
		void runInt8s(list<__i8>& nValue, const char * nNames, const char * nName);
		void runInt8Count(__i8& nValue, const char * nName, const __i32 nCount, const __i8 nOptimal = 0);
		void runInt8sCount(list<__i8>& nValue, const char * nName, const __i32 nCount);
		void runInt8Semi(list<__i8>& nValue, const char * nName);

		void runInt16(__i16& nValue, const char * nName, const __i16 nOptimal = 0);
		void runInt16s(list<__i16>& nValue, const char * nNames, const char * nName);
		void runInt16Count(__i16& nValue, const char * nName, const __i32 nCount, const __i16 nOptimal = 0);
		void runInt16sCount(list<__i16>& nValue, const char * nName, const __i32 nCount);
		void runInt16Semi(list<__i16>& nValue, const char * nName);

		void runInt32(__i32& nValue, const char * nName, const __i32 nOptimal = 0);
		void runInt32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runInt32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal = 0);
		void runInt32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount);
		void runInt32Semi(list<__i32>& nValue, const char * nName);

		void runCrc32(__i32& nValue, const char * nName, const __i32 nOptimal = 0);
		void runCrc32s(list<__i32>& nValue, const char * nNames, const char * nName);
		void runCrc32Count(__i32& nValue, const char * nName, const __i32 nCount, const __i32 nOptimal = 0);
		void runCrc32sCount(list<__i32>& nValue, const char * nName, const __i32 nCount);
		void runCrc32Semi(list<__i32>& nValue, const char * nName);

		void runInt64(__i64& nValue, const char * nName, const __i64 nOptimal = 0);
		void runInt64s(list<__i64>& nValue, const char * nNames, const char * nName);
		void runInt64Count(__i64& nValue, const char * nName, const __i32 nCount, const __i64 nOptimal = 0);
		void runInt64sCount(list<__i64>& nValue, const char * nName, const __i32 nCount);
		void runInt64Semi(list<__i64>& nValue, const char * nName);

		void runString(string& nValue, const char * nName, const char * nOptimal = "");
		void runStrings(list<string>& nValue, const char * nNames, const char * nName);
		void runStringCount(string& nValue, const char * nName, const __i32 nCount, const char * nOptimal = "");
		void runStringsCount(list<string>& nValue, const char * nName, const __i32 nCount);
		void runStringSemi(list<string>& nValue, const char * nName);

		void runFloat(float& nValue, const char * nName, const float nOptimal = 0.f);
		void runFloats(list<float>& nValue, const char * nNames, const char * nName);
		void runFloatCount(float& nValue, const char * nName, const __i32 nCount, const float nOptimal = 0.f);
		void runFloatsCount(list<float>& nValue, const char * nName, const __i32 nCount);
		void runFloatSemi(list<float>& nValue, const char * nName);

		void runDouble(double& nValue, const char * nName, const double nOptimal = 0.);
		void runDoubles(list<double>& nValue, const char * nNames, const char * nName);
		void runDoubleCount(double& nValue, const char * nName, const __i32 nCount, const double nOptimal = 0.);
		void runDoublesCount(list<double>& nValue, const char * nName, const __i32 nCount);
		void runDoubleSemi(list<double>& nValue, const char * nName);

		template<class __t>
		void runStream(__t& nValue, const char * nName)
		{
			mXmlNodes.push(mXmlNode);
			mXmlNode = mXmlNode->first_node(nName);
			if (nullptr != mXmlNode) {
				nValue.serialize(this, 0);
			}
			mXmlNode = mXmlNodes.top();
			mXmlNodes.pop();
		}
		template<class __t>
		void runStreamCount(__t& nValue, const char * nName, const __i32 nCount = 0)
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
		
		template<class __t>
		void runStreamsCount(list<shared_ptr<__t>>& nValue, const char * nNames, const char * nName, const __i32 nCount = 0)
		{
			mXmlNodes.push(mXmlNode);
			xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
			xmlNode_ = xmlNode_->first_node();
			for (; xmlNode_ != nullptr; xmlNode_ = xmlNode_->next_sibling()) {
				mXmlNode = xmlNode_;
				shared_ptr<__t> t_(new __t());
				t_->serialize(this, nCount);
				if (t_->isDefault()) continue;
				nValue.push_back(t_);
			}
			mXmlNode = mXmlNodes.top();
			mXmlNodes.pop();
		}
		
		template<class __t0, class __t1>
		void runKeyStreamsCount(map<__t0, shared_ptr<__t1>>& nValue, const char * nNames, const char * nName, const __i32 nCount = 0)
		{
			mXmlNodes.push(mXmlNode);
			xml_node<char> * xmlNode_ = mXmlNode->first_node(nNames);
			xmlNode_ = xmlNode_->first_node();
			for (; xmlNode_ != nullptr; xmlNode_ = xmlNode_->next_sibling())
			{
				mXmlNode = xmlNode_;
				shared_ptr<__t1> t_(new __t1());
				t_->serialize(this, nCount);
				if (t_->isDefault()) continue;
				nValue[t_->getKey()] = t_;
			}
			mXmlNode = mXmlNodes.top();
			mXmlNodes.pop();
		}
	
		bool openStr(char * nValue);
		bool openUrl(const char * nUrl);
		void selectStream(const char * nStreamName) const;
		__i32 pushStream(const char * nName);
		void popStream();
		void runClose();

	public:
		XmlReader();
		~XmlReader();
	private:
		xml_document<char> mXmlDocument;
		xml_node<char> * mXmlNode;
		shared_ptr<file<char>> mFileDoc;
		stack<xml_node<char> *> mXmlNodes;
	};
	
}

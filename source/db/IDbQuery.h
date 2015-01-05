#pragma once

#ifdef __WITHSQL__
namespace std {

	class IDbQuery : noncopyable
	{
	public:
		template <typename __t>
		void returnResult(__t& nValue)
		{
			string value_(""); this->getValue(value_);
			nValue = __convert<string, __t>(value_);
		}
		void returnResult(string& nValue);
		virtual bool nextRow() = 0;
		
	protected:
		virtual void getValue(string& nValue) = 0;
	};
	
}
#endif

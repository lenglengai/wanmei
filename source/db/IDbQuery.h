#pragma once

#ifdef __WITHMYSQL__
namespace std {

	class IDbQuery : boost::noncopyable
	{
	public:
		template <typename __t>
		void returnResult(__t& nValue)
		{
			string value_(""); this->getValue(value_);
			nValue = __convert<__t, string>(value_);
		}
		void returnResult(string& nValue);
		virtual bool nextRow() = 0;
		
	protected:
		virtual void getValue(string& nValue) = 0;
	};
	
}
#endif

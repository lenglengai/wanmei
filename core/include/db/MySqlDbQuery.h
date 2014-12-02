#pragma once

#ifdef __WITHMYSQL__
#include <errno.h>
#include <errmsg.h>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")

namespace std {

	class MySqlQuery : public IDbQuery
	{
	public:
		void getValue(string& nValue);
		__i16 runQuery();
		bool nextRow();
		
		MySqlQuery(MYSQL& nMYSQL);
		~MySqlQuery();
	
	private:
		MYSQL_RES * mMYSQL_RES;
		MYSQL_ROW mMYSQL_ROW;
		MYSQL& mMYSQL;
		__i32 * mLengths;
		__i8 mIndex;
	};
	
}
#endif

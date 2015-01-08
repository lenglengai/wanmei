#pragma once

#ifdef __CLIENT__
#include <errno.h>
#include <errmsg.h>
#include <mysql.h>

namespace std {

	class MySqlQuery : public IDbQuery
	{
	public:
		void runBool(bool& nValue) OVERRIDE FINAL;
		void runInt8(__i8& nValue) OVERRIDE FINAL;
		void runInt16(__i16& nValue) OVERRIDE FINAL;
		void runInt32(__i32& nValue) OVERRIDE FINAL;
		void runInt64(__i64& nValue) OVERRIDE FINAL;
		void runFloat(float& nValue) OVERRIDE FINAL;
		void runDouble(double& nValue) OVERRIDE FINAL;
		void runString(string& nValue) OVERRIDE FINAL;
		void runData(char *& nValue, __i16& nSize) OVERRIDE FINAL;
		bool nextRow()  OVERRIDE FINAL;
		
		__i16 runQuery();
		
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

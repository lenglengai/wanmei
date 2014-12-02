#pragma once

namespace std {

	class MySqlQuery : public IDbQuery
	{
	public:
		__i8 getInt8();
		__i16 getInt16();
		__i32 getInt32();
		__i64 getInt64();
		float getFloat();
		double getDouble();
		string getString();
		
		__i16 runQuery();
		bool nexRow();
		
		MySqlQuery(MYSQL& nMYSQL);
		~MySqlQuery();
	
	private:
		MYSQL_RES * mMYSQL_RES;
		MYSQL_ROW * mMYSQL_ROW;
		MYSQL& mMYSQL;
		__i32 * mLengths;
		__i8 mIndex;
	};
	
}


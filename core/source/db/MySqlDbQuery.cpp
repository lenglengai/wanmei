#include "../../include/Include.h"

namespace std {

	__i8 MySqlQuery::getInt8()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<__i8, string>(tempStr);
	}
	
	__i16 MySqlQuery::getInt16()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<__i16, string>(tempStr);
	}
	
	__i32 MySqlQuery::getInt32()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<__i32, string>(tempStr);
	}
	
	__i64 MySqlQuery::getInt64()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<__i64, string>(tempStr);
	}
	
	float MySqlQuery::getFloat()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<float, string>(tempStr);
	}
	
	double MySqlQuery::getDouble()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return __convert<double, string>(tempStr);
	}
	
	string MySqlQuery::getString()
	{
	    string tempStr;
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			tempStr.assign(value_, size_);
		}
		++mIndex;
		return tempStr;
	}
		
	__i16 MySqlQuery::runQuery()
	{
		mMYSQL_RES = mysql_store_result(&mMYSQL);
		if (!mMYSQL_RES) {
			if (0 != mysql_errno(&mMYSQL)) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(mMYSQL)));
				return ERRORINT::DBERROR;
			}  else {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1("mysql_store_result")));
				return ERRORINT::DBERROR;
			}
		}
		return ERRORINT::SUCESS;
	}

	bool MySqlQuery::nextRow()
	{
	    mMYSQL_ROW = mysql_fetch_row(mMYSQL_RES);
		mLengths = reinterpret_cast<__i32 *>(mysql_fetch_lengths(mMYSQL_RES));
		mIndex = 0;
		return (nullptr != mMYSQL_ROW);
	}
		
	MySqlQuery::MySqlQuery(MYSQL& nMYSQL)
		: mMYSQL (nMYSQL)
		, mMYSQL_RES(nullptr)
		, mMYSQL_ROW(nullptr)
		, mIndex(0)
	{
	}
	
	MySqlQuery::~MySqlQuery()
	{
		if (mMYSQL_RES) {
			mysql_free_result(mMYSQL_RES);
		}
	}
	
}


#include "../Include.h"

#ifdef __WITHSQLITE__
namespace std {

	void MySqlQuery::getValue(string& nValue)
	{
		char * value_ = reinterpret_cast<char *>(mMYSQL_ROW[mIndex]);
		__i16 size_ = static_cast<__i16>(mLengths[mIndex]);
		if ( (nullptr != value_) && (size_ > 0) ) {
			nValue.assign(value_, size_);
		}
		++mIndex;
	}
		
	__i16 MySqlQuery::runQuery()
	{
		mMYSQL_RES = mysql_store_result(&mMYSQL);
		if (!mMYSQL_RES) {
			if (0 != mysql_errno(&mMYSQL)) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(mysql_error(&mMYSQL)));
				return Error_::mDbError_;
			}  else {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1("mysql_store_result"));
				return Error_::mDbError_;
			}
		}
		return Error_::mSucess_;
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
#endif

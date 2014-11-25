#pragma once

namespace std {

	class __funapi ValueList : boost::noncopyable
	{
	public:
		template<typename T>
		void insert(__i32 nId, __i32 nNo, T& nT) {
			__i32 index_ = nId << 16 + nNo;
			auto it = mValues.find(index_);
			if ( it != mValues.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_2(nId, nNo));
				return;
			}
			void * value_ = reinterpreter_cast<void *>(&nT);
			mValues[index_] = value_;
		}
		
		template<typename T>
		void insert(__i32 nId, __i32 nNo, T * nT) {
			__i32 index_ = nId << 16 + nNo;
			auto it = mValues.find(index_);
			if ( it != mValues.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_2(nId, nNo));
				return;
			}
			void * value_ = reinterpreter_cast<void *>(nT);
			mValues[index_] = value_;
		}
		
		template<typename T>
		T * getAt(__i32 nId, __i32 nNo) {
			__i32 index_ = nId << 16 + nNo;
			auto it = mValues.find(index_);
			if ( it == mValues.end() ) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_2(nId, nNo));
				return nullptr;
			}
			return reinterpreter_cast<T *>(mValues[index_]);
		}
		
		ValueList();
		~ValueList();
		
	private:
		std::map<__i32, void *> mValues;
	};
	typedef std::shared_ptr<ValueList> ValueListPtr;

}

#include "../Include.h"
#include "IoService.h"

namespace std{

#ifdef __CONSOLE__
	const StringWriterPtr SessionService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); __i32 sessionCount_ = 0;
		__i32 classid_ = __classinfo<SessionService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(mSessionId, "sessionId");
	#ifdef __SERVER__
		{
			lock_guard<mutex> lock_(mMutex);
			sessionCount_ = mSessions.size();
		}
		stringWriter_->runInt32(sessionCount_, "sessionCount");
	#endif
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr SessionService::commandFindId(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
	#ifdef __SERVER__
		const string& strSession_ = nCommandArgs.getCommandArg(1);
		__i32 sessionId_ = __convert<string, __i32>(strSession_);
		bool isFind_ = false;
		auto it = mSessions.find(sessionId_);
		if (it != mSessions.end()) {
			isFind_ = true;
		}
		stringWriter_->runString(strSession_, "strSession");
		stringWriter_->runInt32(sessionId_, "sessionId");
		stringWriter_->runBool(isFind_, "isFind");
	#endif
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	bool SessionService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&SessionService::commandInfo, this, placeholders::_1));
		this->registerCommand("findId", std::bind(&SessionService::commandFindId, this, placeholders::_1));
	#endif
		return true;
	}
	
	void SessionService::removeSession(__i32 nSessionId)
	{
	#ifdef __SERVER__
		lock_guard<mutex> lock_(mMutex);
		auto it = mSessions.find(nSessionId);
		if (it == mSessions.end()) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(nSessionId));
			return;
		}
		mSessions.erase(it);
	#endif
	}
	
	SessionPtr& SessionService::createSession()
	{
	#ifdef __SERVER__
		IoService& ioService_ = Service<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		SessionPtr session_(new Session(++mSessionId, ioservice));
		lock_guard<mutex> lock_(mMutex);
		mSessions[mSessionId] = session_;
		return mSessions[mSessionId];
	#endif
	#ifdef __CLIENT__
		IoService& ioService_ = Service<IoService>::instance();
		asio::io_service& ioservice = ioService_.getIoService();
		mSession.reset(new Session(++mSessionId, ioservice));
		return mSession;
	#endif
	}
	
#ifdef __CLIENT__
	SessionPtr& SessionService::getSession()
	{
		return mSession;
	}
#endif
	
	void SessionService::runClear()
	{
	#ifdef __SERVER__
		mSessions.clear();
	#endif
		mSessionId = 0;
	}
	
	SessionService::SessionService()
	{
	}
	
	SessionService::~SessionService()
	{
	}
	
	static Service<SessionService> sSessionService;
}

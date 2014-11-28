#include "../../include/Include.h"

namespace std {

#ifdef __CONSOLE__
	void ClosedService::runCommand(std::list<std::string>& nCommand)
	{
	#ifdef __CLIENT__
		__i32 count_ = static_cast<__i32>(nCommand.size());
		if ( 0 != (count_ % 2) ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(count_));
			return;
		}
		C2SClosed * c2SClosed_ = new C2SClosed();
		for ( int i = 0; i < count_; i += 2 ) {
			std::string& type_ = nCommand.front();
			if ("i8" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				__i8 value_ = __convert<__i8, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("i16" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				__i16 value_ = __convert<__i16, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("i32" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				__i32 value_ = __convert<__i32, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("i64" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				__i64 value_ = __convert<__i64, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("float" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				float value_ = __convert<float, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("double" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				double value_ = __convert<double, std::string>(strValue_);
				c2SClosed_->runPush(value_);
				nCommand.pop_front();
			} else if ("string" == type_) {
				nCommand.pop_front();
				std::string& strValue_ = nCommand.front();
				c2SClosed_->runPush(strValue_);
				nCommand.pop_front();
			} else {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(type_));
				return;
			}
		}
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		PacketPtr packet_(c2SClosed_);
		player_->runSend(packet_);
	#endif
	}
#endif
	
	ClosedMgrPtr& ClosedService::getClosedMgr(__i32 nModule, __i32 nClosedMgr)
	{
		auto it = mClosedModules.find(nModule);
		if ( it == mClosedModules.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nModule));
			return __defaultptr<ClosedMgr>();
		}
		ClosedModulePtr& closedModule_ = it->second;
		return closedModule_->getClosedMgr(nClosedMgr);
	}
	
	bool ClosedService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ClosedService::runInit, this));
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	void ClosedService::runInit()
	{
	#ifdef __CONSOLE__
		ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
		consoleService_.registerConsole(this);
	#endif
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	ClosedService::ClosedService() {
		mClosedModules.clear();
	}
	
	ClosedService::~ClosedService() {
		mClosedModules.clear();
	}

	static Preinit<ClosedService> sClosedServicePreinit;
	
}

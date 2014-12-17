#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr IService::runCommand(list<string>& nCommand)
	{
		return __defaultptr<StringWriter>();
	}
#endif
	
	bool IService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunLuaApi.connect(boost::bind(&IService::runLuaApi, this));
		return true;
	}
	
	void IService::runLuaApi()
	{
	}
	
	IService::IService()
	{
	}
	
	IService::~IService()
	{
	}

}

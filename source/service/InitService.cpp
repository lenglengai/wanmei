#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr InitService::runCommand(std::list<std::string>& nCommand)
	{
		StringWriterPtr stringWriter(new StringWriter());
		std::string& command_ = nCommand.front();
		if ("-resume" == command_) {
			this->runResume();
			stringWriter->runString("InitService", "runResume sucess!");
		} else if ("-pause" == command_) {
			this->runPause();
			stringWriter->runString("InitService", "runPause sucess!");
		} else {
			stringWriter->runString("InitService", "do nothing");
		}
		return stringWriter;
	}
#endif

	bool InitService::runPreinit()
	{
		PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
		if ( !preinitSlot_.runPreinit0() ) {
			return false;
		}
		if ( !preinitSlot_.runPreinit1() ) {
			return false;
		}
		preinitSlot_.runClear();
		
		ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
		serviceMgr_.registerService(this);
		
		return true;
	}
	
	void InitService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<InitService>("InitService");
		luaService_.runMethod<InitService>(&InitService::runResume, "runResume");
		luaService_.runMethod<InitService>(&InitService::runPause, "runPause");
		
		this->m_tRunLuaApi();
	}
	
	void InitService::runLoad0()
	{
		this->m_tRunLoad0();
	}

	void InitService::runLoad1()
	{
		this->m_tRunLoad1();
	}

	void InitService::runInit0()
	{
		this->m_tRunInit0();
	}

	void InitService::runInit1()
	{
		this->m_tRunInit1();
	}

	void InitService::runStart0()
	{
		this->m_tRunStart0();
	}

	void InitService::runStart1()
	{
		this->m_tRunStart1();
	}

	void InitService::runRun()
	{
		this->m_tRunRun();
	}

	void InitService::runStop()
	{
		this->m_tRunStop();
	}

	void InitService::runSave()
	{
		this->m_tRunSave();
	}

	void InitService::runExit()
	{
		this->m_tRunExit();
	}
	
	void InitService::runResume()
	{
		this->m_tRunResume();
	}
	
	void InitService::runPause()
	{
		this->m_tRunPause();
	}
	
	void InitService::runInitDataBase()
	{
		this->m_tInitDataBase();
	}

	void InitService::runInitDbTable()
	{
		this->m_tInitDbTable();
	}
	
	void InitService::runClear()
	{
		m_tRunLuaApi.disconnect_all_slots();
		m_tRunLoad0.disconnect_all_slots();
		m_tRunLoad1.disconnect_all_slots();
		m_tRunInit0.disconnect_all_slots();
		m_tRunInit1.disconnect_all_slots();
		m_tRunStart0.disconnect_all_slots();
		m_tRunStart1.disconnect_all_slots();
		m_tRunRun.disconnect_all_slots();
		m_tRunStop.disconnect_all_slots();
		m_tRunSave.disconnect_all_slots();
		m_tRunExit.disconnect_all_slots();
		
		m_tRunResume.disconnect_all_slots();
		m_tRunPause.disconnect_all_slots();
		
		m_tInitDataBase.disconnect_all_slots();
		m_tInitDbTable.disconnect_all_slots();
	}

	InitService::InitService()
	{
		this->runClear();
	}

	InitService::~InitService()
	{
		this->runClear();
	}

}

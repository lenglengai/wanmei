#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr InitService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<InitService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(VERHIGH, "highVersion");
		stringWriter_->runInt32(VERLOW, "lowVersion");
		stringWriter_->runInt32(VERBUILD, "buildVersion");
		stringWriter_->runInt32(BUILDYEAR, "buildYear");
		stringWriter_->runInt32(BUILDMONTH, "buildMonth");
		stringWriter_->runInt32(BUILDDAY, "buildDay");
		stringWriter_->runInt32(STARTYEAR, "startYear");
		stringWriter_->runInt32(STARTMONTH, "startMonth");
		stringWriter_->runInt32(STARTDAY, "startDay");
		stringWriter_->runInt32(ENDYEAR, "endYear");
		stringWriter_->runInt32(ENDMONTH, "endMonth");
		stringWriter_->runInt32(ENDDAY, "endDay");
		stringWriter_->runInt32(INITYEAR, "initYear");
		stringWriter_->runInt32(INITMONTH, "initMonth");
		stringWriter_->runInt32(INITDAY, "initDay");
		stringWriter_->runString(CONFIGUREFILE, "configureFile");
		stringWriter_->runInt32(PACKETMAX, "maxPacketSize");
		stringWriter_->runString(VERNAME, "versionName");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandResume(const CommandArgs& nCommandArgs)
	{
		this->runResume();
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		stringWriter_->runString("sucess", "runResume");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandPause(const CommandArgs& nCommandArgs)
	{
		this->runPause();
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		stringWriter_->runString("sucess", "runResume");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

	bool InitService::runPreinit()
	{
		ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
		serviceMgr_.runPreinit();
		serviceMgr_.registerService(this);
		
		PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
		if ( !preinitSlot_.runPreinit0() ) {
			return false;
		}
		if ( !preinitSlot_.runPreinit1() ) {
			return false;
		}
		preinitSlot_.runClear();
		
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&InitService::commandInfo, this, placeholders::_1));
		this->registerCommand("resume", std::bind(&InitService::commandResume, this, placeholders::_1));
		this->registerCommand("pause", std::bind(&InitService::commandPause, this, placeholders::_1));
	#endif
	
		return true;
	}
	
	InitService * InitService::getInitService()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		return (&initService_);
	}
	
	void InitService::runLuaApi()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<InitService>("InitService");
		luaService_.runFun(&InitService::getInitService, "InitService");
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

	void InitService::runStop0()
	{
		this->m_tRunStop0();
	}

	void InitService::runStop1()
	{
		this->m_tRunStop1();
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
		m_tRunStop0.disconnect_all_slots();
		m_tRunStop1.disconnect_all_slots();
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

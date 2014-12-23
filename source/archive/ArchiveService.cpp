#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr ArchiveService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classinfo<ArchiveService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		return stringWriter_;
	}
	
	StringWriterPtr ArchiveService::commandReload(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		this->runClear();
		bool isOpen_ = mArchiveReader.runOpen(CONFIGUREFILE);
		stringWriter_->runBool(isOpen_, "isOpen");
		return stringWriter_;
	}
	
	StringWriterPtr ArchiveService::commandConfigure(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		mIsWriter = true; mArchives.clear();
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.runLoad0(); initService_.runLoad1();
		mArchiveWriter.runOpen(CONFIGUREFILE);
        mArchiveWriter.runArchives(mArchives);
        mArchiveWriter.runClose();
		stringWriter_->runString("configure", "archive");
		return stringWriter_;
	}
	
    void ArchiveService::registerArchive(const char * nArchive)
    {
        auto it = mArchives.find(nArchive);
        if ( it != mArchives.end()) {
            LogService& logService_ = Singleton<LogService>::instance();
            logService_.logError(log_1(nArchive));
            return;
        }
        mArchives.insert(nArchive);
    }
#endif
	
	bool ArchiveService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit1.connect(boost::bind(&ArchiveService::runInit, this));
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&ArchiveService::commandInfo, this, placeholders::_1));
		this->registerCommand("reload", std::bind(&ArchiveService::commandReload, this, placeholders::_1));
	#endif
		return true;
	}
	
	void ArchiveService::runInit()
	{
		if( mArchiveReader.runOpen(CONFIGUREFILE) ) {
			mIsArchive = true;
		} else {
			mIsArchive = false;
		}
	}

	void ArchiveService::runClear()
	{
		mArchiveReader.runClose();
		mIsArchive = true;
	}

	ArchiveService::ArchiveService()
	{
		this->runClear();
	}

	ArchiveService::~ArchiveService()
	{
		this->runClear();
	}
	
	static Preinit1<ArchiveService> sArchiveServicePreinit;

}


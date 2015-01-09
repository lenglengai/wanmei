#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr ArchiveService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_("");
		__i32 classid_ = __classinfo<ArchiveService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr ArchiveService::commandReload(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		this->runClear();
		bool isOpen_ = mArchiveReader.runOpen(CONFIGUREFILE);
		if( isOpen_ ) {
			mIsArchive = true;
		} else {
			mIsArchive = false;
		}
		stringWriter_->runBool(isOpen_, "isOpen");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr ArchiveService::commandConfigure(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		mArchiveWriter.runClear(); mArchives.clear(); mIsWriter = true;
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.loadBegin(); initService_.loading();
		initService_.loadEnd();
		mArchiveWriter.runOpen(CONFIGUREFILE);
        mArchiveWriter.runArchives(mArchives);
        mArchiveWriter.runClose();
		stringWriter_->runString("configure", "archive");
		stringWriter_->finishClass();
		stringWriter_->runClose();
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
	
	void ArchiveService::freeBuf(char * nBuf, const __i32 nSize)
	{
		mArchiveReader.freeBuf(nBuf, nSize);
	}
	
	bool ArchiveService::runPreinit()
	{
		if( mArchiveReader.runOpen(CONFIGUREFILE) ) {
			mIsArchive = true;
		} else {
			mIsArchive = false;
		}
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&ArchiveService::commandInfo, this, placeholders::_1));
		this->registerCommand("reload", std::bind(&ArchiveService::commandReload, this, placeholders::_1));
		this->registerCommand("configure", std::bind(&ArchiveService::commandConfigure, this, placeholders::_1));
	#endif
		return true;
	}
	
	void ArchiveService::runClear()
	{
		mArchiveReader.runClose();
		mIsArchive = true;
	#ifdef __CONSOLE__
		mArchiveWriter.runClear();
		mArchives.clear();
		mIsWriter = false;
	#endif
	}

	ArchiveService::ArchiveService()
	{
	}

	ArchiveService::~ArchiveService()
	{
	}
	
	static Service<ArchiveService> sArchiveService;

}


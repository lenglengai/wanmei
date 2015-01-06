#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr ProtocolService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); __i32 protocolCount_ = 0;
		__i32 classid_ = __classinfo<IoService>(className_);
		protocolCount_ = static_cast<__i32>(mProtocols.size());
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(protocolCount_, "protocolCount");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr ProtocolService::commandFindId(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strProtocol_ = nCommandArgs.getCommandArg(1);
		__i32 protocolId_ = __convert<string, __i32>(strProtocol_);
		bool isFind_ = false;
		auto it = mProtocols.find(protocolId_);
		if (it != mProtocols.end()) {
			isFind_ = true;
		}
		stringWriter_->runString(strProtocol_, "strProtocol_");
		stringWriter_->runInt32(protocolId_, "protocolId");
		stringWriter_->runBool(isFind_, "isFind");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr ProtocolService::commandFindName(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		const string& strProtocol_ = nCommandArgs.getCommandArg(1);
		__i32 protocolId_ = __stringid(strProtocol_.c_str());
		bool isFind_ = false;
		auto it = mProtocols.find(protocolId_);
		if (it != mProtocols.end()) {
			isFind_ = true;
		}
		stringWriter_->runString(strProtocol_, "strProtocol");
		stringWriter_->runInt32(protocolId_, "protocolId");
		stringWriter_->runBool(isFind_, "isFind");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif

	bool ProtocolService::runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession)
	{
		__i16 version_ = 0; nReadBlock->runInt16(version_);
		if (Error_::mMustUpdate_ == __vercheck(version_)) {
			return false;
		}
		
		__i32 protocolId_ = 0; nReadBlock->runInt32(protocolId_);
		auto it = mProtocols.find(protocolId_);
		if (it == mProtocols.end()) {
			return false;
		}
		IProtocol * protocol_ = it->second;
		
		__i32 packetType_ = 0; nReadBlock->runInt32(packetType_);
		const PacketIdPtr& packetId_ = protocol_->getPacketId(packetType_);
		if (!packetId_) {
			return false;
		}
		
		PacketPtr packet_ = packetId_->createPacket();
		BlockPtr block_ = nReadBlock;
		packet_->runBlock(block_);
		if (packet_->isError()) {
			return false;
		}
		return packet_->handleRun(nSession);
	}
		
	bool ProtocolService::runPreinit()
	{
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&ProtocolService::commandInfo, this, placeholders::_1));
		this->registerCommand("findId", std::bind(&ProtocolService::commandFindId, this, placeholders::_1));
		this->registerCommand("findName", std::bind(&ProtocolService::commandFindName, this, placeholders::_1));
	#endif
		this->runClear();
		return true;
	}

	void ProtocolService::runClear()
	{
		mProtocols.clear();
	}

	ProtocolService::ProtocolService()
	{
	}

	ProtocolService::~ProtocolService()
	{
	}
	
	static Service<ProtocolService> sProtocolService;

}

#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	StringWriterPtr ProtocolService::commandInfo(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		string className_(""); __i32 protocolCount_ = 0;
		__i32 classid_ = __classinfo<ProtocolService>(className_);
		stringWriter_.runString(className_className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		protocolCount_ = mProtocols.size();
		stringWriter_.runInt32(protocolCount_, "protocolCount");
		return stringWriter_;
	}
	
	StringWriterPtr ProtocolService::commandFindId(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		const string& strProtocol_ = nCommand.getCommandArg(1);
		__i32 protocolId_ = __convert<string, __i32>(strProtocol_);
		bool isFind_ = false;
		auto it = mServices.find(protocolId_);
		if (it != mServices.end()) {
			isFind_ = true;
		}
		stringWriter_.runString(strProtocol_, "strProtocol_");
		stringWriter_.runInt32(protocolId_, "protocolId");
		stringWriter_.runBool(isFind_, "isFind");
		return stringWriter_;
	}
	
	StringWriterPtr ProtocolService::commandFindName(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		const string& strProtocol_ = nCommand.getCommandArg(1);
		__i32 protocolId_ = __stringid(strProtocol_.c_str());
		bool isFind_ = false;
		auto it = mProtocols.find(protocolId_);
		if (it != mProtocols.end()) {
			isFind_ = true;
		}
		stringWriter_.runString(strProtocol_, "strProtocol");
		stringWriter_.runInt32(protocolId_, "protocolId");
		stringWriter_.runBool(isFind_, "isFind");
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
		PacketIdPtr& packetId_ = protocol_->getPacketId(packetType_);
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
		this->registerCommand("info", std::bind(&ProtocolService::commandInfo, this, _1));
		this->registerCommand("findId", std::bind(&ProtocolService::commandFindId, this, _1));
		this->registerCommand("findName", std::bind(&ProtocolService::commandFindName, this, _1));
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
		this->runClear();
	}

	ProtocolService::~ProtocolService()
	{
		this->runClear();
	}
	
	static Preinit0<ProtocolService> sProtocolServicePreinit;

}

#pragma once

namespace std {

	class ClosedProtocol;
	class C2SClosed : public Packet<C2SClosed, ClosedProtocol>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(PlayerPtr& nPlayer);
		void runCloseds(ClosedsPtr& nCloseds);
		void runClosed(ClosedPtr& nClosed);
	#endif
		bool runBlock(BlockPtr& nBlock);

		C2SClosed();
		~C2SClosed();

	private:
		std::list<__i8> mInt8s;
		std::list<__i16> mInt16s;
		std::list<__i32> mInt32s;
		std::list<__i64> mInt64s;
		std::list<string> mStrings;
		std::list<float> mFloats;
		std::list<double> mDoubles;
		__i32 mModule;
		__i32 mClosed;
	};
	typedef std::shared_ptr<C2SClosed> C2SClosedPtr;
	
}

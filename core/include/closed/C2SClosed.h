#pragma once

namespace std {

	class ClosedProtocol;
	class C2SClosed : public Packet<C2SClosed, ClosedProtocol>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(PlayerPtr& nPlayer);
		void runCloseds(PlayerPtr& nPlayer, ClosedsPtr& nCloseds);
		void runClosed(PlayerPtr& nPlayer, ClosedPtr& nClosed);
		void runValues(Values& nValues, ClosedPtr& nClosed);
	#endif
		bool runBlock(BlockPtr& nBlock);
		
		template<typename T>
		void runPush(T& nT) {
			ValuePtr value_(new Value<T>(nT));
			mValues.push_back(value_);
		}

		C2SClosed();
		~C2SClosed();

	private:
		std::vector<ValuePtr> mValues;
		__i32 mModule;
		__i32 mClosed;
	};
	typedef std::shared_ptr<C2SClosed> C2SClosedPtr;
	
}

#include "../Common.h"

namespace std {

		void PreinitSlot::runPreinit()
		{
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_1("PreinitSlot run runPreinit!"));
		#endif
			this->m_tRunPreinit();
		#ifdef __LOG__
			logService_.logInfo(log_1("PreinitSlot run runPreinit finish!"));
		#endif
		}
		
		PreinitSlot::PreinitSlot()
		{
			m_tRunPreinit.disconnect_all_slots();
		}
		
		PreinitSlot::~PreinitSlot()
		{
			m_tRunPreinit.disconnect_all_slots();
		}
		
}

#include "../Include.h"

#ifdef __WITHDEBUG__

#ifdef __WINDOW__
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#endif

namespace std {

#ifdef __WINDOW__
	LONG WINAPI exceptionFilter(struct _EXCEPTION_POINTERS * nExceptionInfo)
	{
		string fileName = APPNAME;
		fileName += "-";
		fileName += __convert<string,__i32>(VERHIGH);
		fileName += ".";
		fileName += __convert<string,__i32>(VERLOW);
		fileName += ".";
		fileName += __convert<string,__i32>(VERBUILD);
		fileName += ".dmp";
		HANDLE fileHandle = ::CreateFileA(fileName.c_str(), GENERIC_WRITE,
			FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		MINIDUMP_EXCEPTION_INFORMATION miniDumpExceptionInfo;
		miniDumpExceptionInfo.ThreadId = ::GetCurrentThreadId();
		miniDumpExceptionInfo.ExceptionPointers = nExceptionInfo;
		miniDumpExceptionInfo.ClientPointers = FALSE;
		::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(),
			fileHandle, MiniDumpNormal, &miniDumpExceptionInfo, nullptr, nullptr);
		return EXCEPTION_CONTINUE_SEARCH;
	}
#endif

#ifdef __WINDOW__
	__i32 MyXcptFilter()
	{
		return EXCEPTION_CONTINUE_SEARCH;
	}
#endif

	bool DebugService::runPreinit()
	{
	#ifdef __WINDOW__
		::SetUnhandledExceptionFilter( exceptionFilter );
		void * _XcptFilter = (void*)GetProcAddress(::LoadLibraryA("msvcrt.dll"), "_XcptFilter");
		DWORD dwOldProtect = 0;
		::VirtualProtect(_XcptFilter, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(char*)_XcptFilter = 0xe9;
		*(unsigned int*)((char*)_XcptFilter + 1) = (unsigned int)MyXcptFilter - ((unsigned int)_XcptFilter + 5);
		::VirtualProtect(_XcptFilter, 5, dwOldProtect, &dwOldProtect);
	#endif
		return true;
	}
	
	DebugService::DebugService()
	{
	}
	
	DebugService::~DebugService()
	{
	}
	
	static Preinit0<DebugService> sDebugServicePreinit;
	
}
#endif


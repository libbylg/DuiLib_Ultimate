#ifndef UILIB
#define UILIB


#ifdef UILIB_STATI
#define UILIB_API 
#else
#if defined(UILIB_EXPORTS)
#	if defined(_MSC_VER)
#		define DUILIB_API __declspec(dllexport)
#	else
#		define UILIB_API 
#	endif
#else
#	if defined(_MSC_VER)
#		define UILIB_API __declspec(dllimport)
#	else
#		define UILIB_API 
#	endif
#endif
#endif
#define UILIB_COMDAT __declspec(selectany)

#pragma warning(disable:4505)
#pragma warning(disable:4251)
#pragma warning(disable:4189)
#pragma warning(disable:4121)
#pragma warning(disable:4100)

#if defined _M_IX86
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stddef.h>
#include <richedit.h>
#include <tchar.h>
#include <assert.h>
#include <crtdbg.h>
#include <malloc.h>
#include <comdef.h>
#include <gdiplus.h>
#include <ShellAPI.h>
#include <zmouse.h>
#include <math.h>
#include <crtdbg.h>
#include <map>
#include <algorithm>
#include <shlobj.h>
#include <vector>
#include <OAIdl.h>
#include <vector>
#include <atlbase.h>

#ifdef _DEBUG
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#endif

/////////////////////////////////////////////////////////////////////////////////////
//
#ifndef ASSERT
#define ASSERT(expr)  _ASSERTE(expr)
#endif


#pragma comment( lib, "comctl32.lib" )
#pragma comment( lib, "GdiPlus.lib" )
#pragma comment( lib, "Imm32.lib" )
#pragma comment( lib, "winmm.lib" )

#endif//UILIB



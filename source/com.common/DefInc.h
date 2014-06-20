#pragma once

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#ifdef WIN32
#define __FUN__ __FUNCTION__
#else
#define __FUN__ __PRETTY_FUNCTION__
#endif

typedef char __i8;
typedef short __i16;
typedef long __i32;
typedef long long __i64;

#define INITTIME "2014-09-23 23:59:59.000"

#include <boost/noncopyable.hpp>
#include <boost/smart_ptr.hpp>

#include <string>
#include <list>
#include <map>

#ifdef __STARTUP__
#include <Startup.h>
#endif

#include "Singleton.h"
#include "Convert.h"
#include "Default.h"
#include "ERRORINT..h"

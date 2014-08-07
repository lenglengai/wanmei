#pragma once

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#ifdef _WIN32
#define __FUN__ __FUNCTION__
#else
#define __FUN__ __PRETTY_FUNCTION__
#endif

typedef char __i8;
typedef short __i16;
typedef long __i32;
typedef long long __i64;

#include <boost/noncopyable.hpp>

#include <memory>
#include <string>
#include <list>
#include <map>

#ifdef __ANDROID__
#include <AndroidInclude.h>
#endif

#ifdef __CLIENT__
#include <ClientInclude.h>
#endif

#ifdef __SERVER__
#include <ServerInclude.h>
#endif

#ifdef __LOGIN__
#include <LoginInclude.h>
#endif

#include "utility/Singleton.h"
#include "utility/Convert.h"
#include "utility/Default.h"
#include "utility/ERRORINT.h"
#include "shiny/Shiny.h"
#include "lua/LuaScript.h"

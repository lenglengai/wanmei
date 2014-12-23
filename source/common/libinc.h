#pragma once

#ifdef __WINDOW__
#pragma warning( push )
#pragma warning( disable : 4819 )
#endif

#include <boost/algorithm/string.hpp>
#include <boost/signals2.hpp>
#include <boost/format.hpp>
#include <boost/bind.hpp>

using namespace boost;

#ifndef __WINDOW__
#include <cxxabi.h>
#include <malloc.h>
#endif

#ifdef __WINDOW__
#pragma warning( pop )
#endif

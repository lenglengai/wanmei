#pragma once

#ifdef __WINDOW__
#pragma warning( push )
#pragma warning( disable : 4819 )
#pragma warning( disable : 4503 )
#endif

#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

using namespace boost;

#ifdef __WINDOW__
#pragma warning( pop )
#endif

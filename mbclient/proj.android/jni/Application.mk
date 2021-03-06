APP_STL := gnustl_static #c++_static
NDK_TOOLCHAIN_VERSION=clang

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fsigned-char
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -D__ANDROID__

#APP_CFLAGS += -Wno-error=format-security

APP_LDFLAGS := -latomic
APP_LDFLAGS += $(BOOST_ROOT)/stage/lib/libboost_system.a

APP_DEBUG := $(strip $(NDK_DEBUG))
ifeq ($(APP_DEBUG),1)
  APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
  APP_OPTIM := debug
else
  APP_CPPFLAGS += -DNDEBUG
  APP_OPTIM := release
endif

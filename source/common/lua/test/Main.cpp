#include "../../DefInc.h"
#include "../LuaScript.h"

#include <iostream>

class MyBase
{
public:
	static void runScript(std::LuaScript& nLuaScript)
	{
		nLuaScript.runClass<MyBase>("MyBase");
		nLuaScript.runMethod<MyBase>(&MyBase::fun0, "fun0");
		nLuaScript.runMethod<MyBase>(&MyBase::fun1, "fun1");
	}

	virtual int fun0(int nValue)
	{
		return (nValue + 3);
	}

	int fun1(bool nValue)
	{
		if (true == nValue)
		{
			return 12;
		}
		return 32;
	}
};

class MySub : public MyBase
{
public:
	static void runScript(std::LuaScript& nLuaScript)
	{
		MyBase::runScript(nLuaScript);
		nLuaScript.runClass<MySub>("MySub");
		nLuaScript.runInherit<MySub, MyBase>();
		nLuaScript.runMethod<MySub>(&MySub::fun0, "fun0");
		nLuaScript.runMethod<MySub>(&MySub::fun2, "fun2");
	}

	int fun0(int nValue)
	{
		return (nValue + 5);
	}

	int fun2(bool nValue)
	{
		if (true == nValue)
		{
			return 25;
		}
		return 96;
	}
};


int main( int argc, char * argv[] )
{
	std::LuaScript luaScript;
	MySub::runScript(luaScript);

	MyBase myBase;
	MySub mySub;

	luaScript.runFile("test0.lua");
	bool sucess = luaScript.runCall<bool>("test0", &myBase);
	std::cout << sucess << std::endl;

	luaScript.runFile("test1.lua");
	sucess = luaScript.runCall<bool>("test1", &myBase);
	std::cout << sucess << std::endl;

	luaScript.runFile("test2.lua");
	sucess = luaScript.runCall<bool>("test2", &mySub);
	std::cout << sucess << std::endl;

	luaScript.runFile("test3.lua");
	sucess = luaScript.runCall<bool>("test3", &mySub);
	std::cout << sucess << std::endl;

	return 0;
}


#include "../../include/Include.h"

namespace std {

	bool IValue::runBlock(BlockPtr& nBlock)
	{
		return false;
	}
	
	bool Value<__i8>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 1;
		nBlock->runInt8(value_);
		nBlock->runInt8(mValue);
		return false;
	}
	
	__i8 Value<__i8>::getValue()
	{
		return mValue;
	}
	
	Value<__i8>::Value()
		: mValue (0)
	{
	}
	
	Value<__i8>::Value(__i8 nValue)
		: mValue (nValue)
	{
	}
	
	Value<__i8>::~Value()
	{
		mValue = 0;
	}
	
	bool Value<__i16>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 2;
		nBlock->runInt8(value_);
		nBlock->runInt16(mValue);
		return false;
	}
	
	__i16 Value<__i16>::getValue()
	{
		return mValue;
	}
	
	Value<__i16>::Value()
		: mValue (0)
	{
	}
	
	Value<__i16>::Value(__i16 nValue)
		: mValue (nValue)
	{
	}
	
	Value<__i16>::~Value()
	{
		mValue = 0;
	}
	
	bool Value<__i32>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 3;
		nBlock->runInt8(value_);
		nBlock->runInt32(mValue);
		return false;
	}
	
	__i32 Value<__i32>::getValue()
	{
		return mValue;
	}
	
	Value<__i32>::Value()
		: mValue (0)
	{
	}
	
	Value<__i32>::Value(__i32 nValue)
		: mValue (nValue)
	{
	}
	
	Value<__i32>::~Value()
	{
		mValue = 0;
	}
	
	bool Value<__i64>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 4;
		nBlock->runInt8(value_);
		nBlock->runInt64(mValue);
		return false;
	}
	
	__i64 Value<__i64>::getValue()
	{
		return mValue;
	}
	
	Value<__i64>::Value()
		: mValue (0)
	{
	}
	
	Value<__i64>::Value(__i64 nValue)
		: mValue (nValue)
	{
	}
	
	Value<__i64>::~Value()
	{
		mValue = 0;
	}
	
	bool Value<float>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 5;
		nBlock->runInt8(value_);
		nBlock->runFloat(mValue);
		return false;
	}
	
	float Value<float>::getValue()
	{
		return mValue;
	}
	
	Value<float>::Value()
		: mValue (0.f)
	{
	}
	
	Value<float>::Value(float nValue)
		: mValue (nValue)
	{
	}
	
	Value<float>::~Value()
	{
		mValue = 0.f;
	}
	
	bool Value<double>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 6;
		nBlock->runInt8(value_);
		nBlock->runDouble(mValue);
		return false;
	}
	
	double Value<double>::getValue()
	{
		return mValue;
	}
	
	Value<double>::Value()
		: mValue (0.)
	{
	}
	
	Value<double>::Value(double nValue)
		: mValue (nValue)
	{
	}
	
	Value<double>::~Value()
	{
		mValue = 0.;
	}
	
	bool Value<std::string>::runBlock(BlockPtr& nBlock)
	{
		__i8 value_ = 7;
		nBlock->runInt8(value_);
		nBlock->runString(mValue);
		return false;
	}
	
	std::string& Value<std::string>::getValue()
	{
		return mValue;
	}
	
	Value<std::string>::Value()
		: mValue ("")
	{
	}
	
	Value<std::string>::Value(const char * nValue)
		: mValue (nValue)
	{
	}
	
	Value<std::string>::~Value()
	{
		mValue = "";
	}
	
}

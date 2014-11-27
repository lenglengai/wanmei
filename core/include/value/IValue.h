#pragma once

namespace std {

	class __funapi IValue : boost::noncopyable
	{
	public:
		virtual bool runBlock(BlockPtr& nBlock);
	};
	typedef std::shared_ptr<IValue> ValuePtr;

	template <typename T>
	class __funapi Value : IValue
	{
	public:
		std::shared_ptr<T>& getValue()
		{
			return mValue;
		}
		
		Value<T>()
		{
		}
		
	private:
		std::shared_ptr<T> mValue;
	};
	
	template <>
	class __funapi Value<__i8> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i8 getValue();
		
		Value<__i8>();
		Value<__i8>(__i8 nValue);
		~Value<__i8>();
		
	private:
		__i8 mValue;
	};

	template <>
	class __funapi Value<__i16> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i16 getValue();
		
		Value<__i16>();
		Value<__i16>(__i16 nValue);
		~Value<__i16>();
		
	private:
		__i16 mValue;
	};
	
	template <>
	class __funapi Value<__i32> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i32 getValue();
		
		Value<__i32>();
		Value<__i32>(__i32 nValue);
		~Value<__i32>();
		
	private:
		__i32 mValue;
	};
	
	template <>
	class __funapi Value<__i64> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i64 getValue();
		
		Value<__i64>();
		Value<__i64>(__i64 nValue);
		~Value<__i64>();
		
	private:
		__i64 mValue;
	};
	
	template <>
	class __funapi Value<float> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		float getValue();
		
		Value<float>();
		Value<float>(float nValue);
		~Value<float>();
		
	private:
		float mValue;
	};
	
	template <>
	class __funapi Value<double> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		double getValue();
		
		Value<double>();
		Value<double>(double nValue);
		~Value<double>();
		
	private:
		double mValue;
	};

	template <>
	class __funapi Value<std::string> : IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		std::string& getValue();
		
		Value<std::string>();
		Value<std::string>(const char * nValue);
		~Value<std::string>();
		
	private:
		std::string mValue;
	};
	
}

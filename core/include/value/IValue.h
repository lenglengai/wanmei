#pragma once

namespace std {

	class __funapi IValue : boost::noncopyable
	{
	public:
		virtual bool runBlock(BlockPtr& nBlock);
	};
	typedef std::shared_ptr<IValue> ValuePtr;

	template <typename T>
	class __funapi Value : public IValue
	{
	public:
		std::shared_ptr<T>& getValue()
		{
			return mValue;
		}
		
		Value()
		{
		}
		
	private:
		std::shared_ptr<T> mValue;
	};
	
	template <>
	class __funapi Value<__i8> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i8 getValue();
		
		Value();
		Value(__i8 nValue);
		~Value();
		
	private:
		__i8 mValue;
	};

	template <>
	class __funapi Value<__i16> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i16 getValue();
		
		Value();
		Value(__i16 nValue);
		~Value();
		
	private:
		__i16 mValue;
	};
	
	template <>
	class __funapi Value<__i32> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i32 getValue();
		
		Value();
		Value(__i32 nValue);
		~Value();
		
	private:
		__i32 mValue;
	};
	
	template <>
	class __funapi Value<__i64> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		__i64 getValue();
		
		Value();
		Value(__i64 nValue);
		~Value();
		
	private:
		__i64 mValue;
	};
	
	template <>
	class __funapi Value<float> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		float getValue();
		
		Value();
		Value(float nValue);
		~Value();
		
	private:
		float mValue;
	};
	
	template <>
	class __funapi Value<double> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		double getValue();
		
		Value();
		Value(double nValue);
		~Value();
		
	private:
		double mValue;
	};

	template <>
	class __funapi Value<std::string> : public IValue
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		std::string& getValue();
		
		Value();
		Value(const char * nValue);
		~Value();
		
	private:
		std::string mValue;
	};
	
}

#pragma once

namespace std {

	enum ConvertType_
	{
		mConvertTypeCommon_ = 1,
		mConvertTypeBinary_ = 2,
		mConvertTypeText_ = 3,
		mConvertTypeToUtf8_ = 4,
		mConvertTypeFromUtf8_ = 5
	};

	namespace convert_namespace {

		template<typename T1, typename T2>
		struct Convert
		{
			T1 operator () (T2& nValue, ConvertType_ nConvertType)
			{
				return static_cast<T1>(nValue);
			}
		};

		template<typename T1>
		struct Convert<T1, bool>
		{
			T1 operator () (bool nValue, ConvertType_ nConvertType)
			{
				return ((true == nValue) ? 1 : 0);
			}
		};

		template<typename T1>
		struct Convert<T1, char *>
		{
			T1 operator () (char * nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeBinary_ == nConvertType) {
					return ( *((T1 *)nValue) );
				}
				return boost::lexical_cast<T1>(nValue);
			}
		};

		template<typename T1>
		struct Convert<T1, const char *>
		{
			T1 operator () (const char * nValue, ConvertType_ nConvertType)
			{
				return boost::lexical_cast<T1>(nValue);
			}
		};
		
		template<typename T1>
		struct Convert<T1, std::string>
		{
			T1 operator () (const std::string& nValue, ConvertType_ nConvertType)
			{
				return boost::lexical_cast<T1>(nValue);
			}
		};

		template<typename T1>
		struct Convert<T1, const std::string>
		{
			T1 operator () (const std::string& nValue, ConvertType_ nConvertType)
			{
				return boost::lexical_cast<T1>(nValue);
			}
		};

		template<typename T1>
		struct Convert<bool, T1>
		{
			bool operator () (T1& nValue, ConvertType_ nConvertType)
			{
				return ((1 == nValue) ? true : false);
			}
		};

		template<>
		struct Convert<bool, float>
		{
			bool operator () (float& nValue, ConvertType_ nConvertType)
			{
				return ( ( (0.01f > nValue) && (-0.01f < nValue) ) ? true : false);
			}
		};

		template<>
		struct Convert<bool, double>
		{
			bool operator () (double& nValue, ConvertType_ nConvertType)
			{
				return (((0.01 > nValue) && (-0.01 < nValue)) ? true : false);
			}
		};

		template<>
		struct Convert<bool, char *>
		{
			bool operator () (const char * nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeBinary_ == nConvertType) {
					__i8 value_ = *((__i8 *)nValue);
					return ((1 == value_) ? true : false);
				} else if (mConvertTypeText_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("true" == value_) ? true : false);
				} else {
					std::string value_(nValue); boost::trim(value_);
					return (("1" == value_) ? true : false);
				}
				return false;
			}
		};

		template<>
		struct Convert<bool, const char *>
		{
			bool operator () (const char * nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeText_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("true" == value_) ? true : false);
				} else if (mConvertTypeCommon_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("1" == value_) ? true : false);
				} else {
					return false;
				}
				return false;
			}
		};

		template<>
		struct Convert<bool, std::string>
		{
			bool operator () (std::string& nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeText_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("true" == value_) ? true : false);
				} else if (mConvertTypeCommon_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("1" == value_) ? true : false);
				} else {
					return false;
				}
				return false;
			}
		};

		template<>
		struct Convert<bool, const std::string>
		{
			bool operator () (const std::string& nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeText_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("true" == value_) ? true : false);
				} else if (mConvertTypeCommon_ == nConvertType) {
					std::string value_(nValue); boost::trim(value_);
					return (("1" == value_) ? true : false);
				} else {
					return false;
				}
				return false;
			}
		};

		template<>
		struct Convert<__i8, char *>
		{
			__i8 operator () (const char * nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeBinary_ == nConvertType) {
					return ( *((__i8 *)nValue) );
				}
				__i32 result32_ = boost::lexical_cast<__i32>(nValue);
				return boost::numeric_cast<__i8>(result32_);
			}
		};

		template<>
		struct Convert<__i8, const char *>
		{
			__i8 operator () (const char * nValue, ConvertType_ nConvertType)
			{
				__i32 result32_ = boost::lexical_cast<__i32>(nValue);
				return boost::numeric_cast<__i8>(result32_);
			}
		};

		template<>
		struct Convert<__i8, std::string>
		{
			__i8 operator () (std::string& nValue, ConvertType_ nConvertType)
			{
				__i32 result32_ = boost::lexical_cast<__i32>(nValue);
				return boost::numeric_cast<__i8>(result32_);
			}
		};

		template<>
		struct Convert<__i8, const std::string>
		{
			__i8 operator () (const std::string& nValue, ConvertType_ nConvertType)
			{
				__i32 result32_ = boost::lexical_cast<__i32>(nValue);
				return boost::numeric_cast<__i8>(result32_);
			}
		};

		template<typename __t1>
		struct Convert<std::string, __t1>
		{
			std::string operator () (__t1& nValue, ConvertType_ nConvertType)
			{
				return boost::lexical_cast<std::string>(nValue);
			}
		};

		template<>
		struct Convert<std::string, bool>
		{
			std::string operator () (bool nValue, ConvertType_ nConvertType)
			{
				if (mConvertTypeText_ == nConvertType) {
					return ((true == nValue) ? "true" : "false");
				}
				return ((true == nValue) ? "1" : "0");
			}
		};

		template<>
		struct Convert<std::string, __i8>
		{
			std::string operator () (__i8 nValue, ConvertType_ nConvertType)
			{
				__i32 result32_ = boost::numeric_cast<__i32>(nValue);
				return boost::lexical_cast<std::string>(result32_);
			}
		};

	}

	template<typename T1, typename T2>
	T1 __convert(T2 nValue, ConvertType_ nConvertType = mConvertTypeCommon_)
	{
		return convert_namespace::Convert<T1, T2>()(nValue, nConvertType);
	}

}


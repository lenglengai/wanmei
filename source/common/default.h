#pragma once

namespace std {

	namespace default_namespace {

		template<typename __t>
		struct Default
		{
			const __t& operator () () const
			{
				static __t value_ = 0;
				return value_;
			}
		};

		template<>
		struct Default<bool>
		{
			const bool& operator () ()const
			{
				static bool value_ = false;
				return value_;
			}
		};

		template<>
		struct Default<float>
		{
			const float& operator () ()const
			{
				static float value_ = 0.f;
				return value_;
			}
		};

		template<>
		struct Default<double>
		{
			const double& operator () ()const
			{
				static double value_ = 0.;
				return value_;
			}
		};

		template<>
		struct Default<const char *>
		{
			const char *& operator () ()const
			{
				static const char * value_ = "";
				return value_;
			}
		};

		template<>
		struct Default<string>
		{
			const string& operator () ()const
			{
				static string value_("");
				return value_;
			}
		};
		
	}

	template<typename __t>
	const __t& __default()
	{
		return default_namespace::Default<__t>()();
	}
	
	template<typename __t>
	const shared_ptr<__t>& __defaultptr()
	{
		static shared_ptr<__t> result_;
		return result_;
	}

}

#pragma once

namespace std {

	namespace default_namespace {

		template<typename __t>
		struct Default
		{
			const __t operator () () const
			{
				return 0;
			}
		};

		template<>
		struct Default<bool>
		{
			const bool operator () ()const
			{
				return false;
			}
		};

		template<>
		struct Default<float>
		{
			const float operator () ()const
			{
				return 0.f;
			}
		};

		template<>
		struct Default<double>
		{
			const double operator () ()const
			{
				return 0.;
			}
		};

		template<>
		struct Default<const char *>
		{
			const char * operator () ()const
			{
				return "";
			}
		};

		template<>
		struct Default<std::string>
		{
			const char * operator () ()const
			{
				return "";
			}
		};

	}

	template<typename __t>
	const __t __default()
	{
		return default_namespace::Default<__t>()();
	}
	
	template<typename __t>
	std::shared_ptr<__t>& __defaultptr()
	{
		static std::shared_ptr<__t> result_;
		return result_;
	}

}

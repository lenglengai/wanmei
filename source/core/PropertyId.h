#pragma once

namespace std {

	template<class T>
	class __funapi PropertyId : public IPropertyId
	{
	public:
		PropertyPtr createProperty()
		{
			return PropertyPtr(new T());
		}

		__i32 getPropertyId()
		{
			return T::sPropertyId;
		}
	};

}

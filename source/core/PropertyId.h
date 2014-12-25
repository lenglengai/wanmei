#pragma once

namespace std {

	template<class T>
	class __funapi PropertyId : public IPropertyId
	{
	public:
		const PropertyPtr createProperty() const
		{
			return PropertyPtr(new T());
		}

		__i32 getPropertyId() const
		{
			return T::sPropertyId;
		}
	};

}

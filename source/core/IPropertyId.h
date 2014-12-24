#pragma once

namespace std {

	class __funapi IPropertyId : noncopyable
	{
	public:
		virtual const PropertyPtr createProperty() const = 0;
		virtual const __i32 getPropertyId() const = 0;
	};
	typedef shared_ptr<IPropertyId> PropertyIdPtr;

}

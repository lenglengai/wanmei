#pragma once

namespace std {

	class __funapi IPropertyId : noncopyable
	{
	public:
		virtual PropertyPtr createProperty() = 0;
		virtual __i32 getPropertyId() = 0;
	};
	typedef shared_ptr<IPropertyId> PropertyIdPtr;

}

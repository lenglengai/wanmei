#pragma once

namespace std {

	class __funapi INumber : boost::noncopyable
	{
	};
	typedef std::shared_ptr<INumber> NumberPtr;

}

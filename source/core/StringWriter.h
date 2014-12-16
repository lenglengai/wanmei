#pragma once

namespace std {
	
	class StringWriter : noncopyable
	{
	public:
		const char * getValue();
		
		StringWriter();
		~StringWriter();
		
	private:
		string mValue;
	};
	
}

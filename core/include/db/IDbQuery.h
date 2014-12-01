#pragma once

namespace std {

	class IDbQuery : boost::noncopyable
	{
	public:
		IDbQuery(DbConnectionPtr& nConnection);
	private:
		DbConnectionPtr& mConnection;
	};
	
}


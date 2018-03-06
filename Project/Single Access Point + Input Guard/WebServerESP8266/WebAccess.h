#ifndef WEBACCESS_H
#define WEBACCESS_H

#include <InputGuard.h>
#include <functional>
#include <vector>

using namespace std;

enum class Protocol { 
	ALPHA,
	NUM,
	ALPHANUM,
	PORT,
	EMAIL,
	TIME,
	COMPLETETIME
};

static class WebAccess
{
	static const vector<function<bool(string)>> v_function;

	static bool validate(ESP8266WebServer& server, function<bool(string)> func)
	{
		bool res = true;
		for (int i = 0; i < server.args(); ++i)
		{
			res &= func(server.args[i]);
		}
		return res;
	}

public:
	static bool authorize(ESP8266WebServer& server, Protocol proto)
	{
		return Application::getInstance().Access				
			&& validate(server, v_function.at(static_cast<typename underlying_type<Protocol>::type>(proto)));
	}
};

#endif

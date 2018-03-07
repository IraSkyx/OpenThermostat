#include "WebAccess.h"
#include "InputGuard.h"
#include <ESP8266WebServer.h>
#include <functional>

static const vector<function<bool(String)>> v_function = {
	(*InputGuard::matchAlpha),
	(*InputGuard::matchNum),
	(*InputGuard::matchAlphaNum),
	(*InputGuard::matchPort),
	(*InputGuard::matchEmail),
	(*InputGuard::matchHhmm),
	(*InputGuard::matchHhmmss)
};
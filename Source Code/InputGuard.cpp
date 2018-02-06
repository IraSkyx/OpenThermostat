#include "InputGuard.h"
#include <regex>

//static void clearTags(String &s) 
//{
//	s = std::regex_replace(s, "<.*>", "");
//}


static bool InputGuard::matchWebSpecs(String &s)
{
	return InputSpecs::isAlphaNum(s);
}

static bool InputGuard::matchNTPSpecs(String &s)
{
	return InputSpecs::isNum(s);
}
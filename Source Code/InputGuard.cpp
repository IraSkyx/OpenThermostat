#include "InputGuard.h"
#include <regex>

static void clearTags(String &s) 
{
	s = std::regex_replace(s, "<.*>", "");
}

static bool InputGuard::alpha(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[A-Za-z]*"))
}

static bool InputGuard::num(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[0-9]*"))
}

static bool InputGuard::alphaNum(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[A-Za-z0-9]*"))
}
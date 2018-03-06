#include "InputSpecs.h"


static bool InputSpecs::isAlpha(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[A-Za-z]*"))
}

static bool InputSpecs::isNum(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[0-9]*"))
}

static bool InputSpecs::isAlphaNum(String &s)
{
	clearTags(s);
	return std::regex_match(s, std::regex("[A-Za-z0-9]*"))
}
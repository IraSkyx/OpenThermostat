#ifndef InputGard_h
#define InputGard_h

#include <regex>
#include <string>
#include "InputSpecs.h"

class InputGuard
{
public:
	static bool matchAlpha(String s) { return std::regex_match(s, InputSpecs::getAlpha()); } 
	static bool matchNum(String s) { return std::regex_match(s, InputSpecs::getNum()); }
	static bool matchAlphaNum(String s) { return std::regex_match(s, InputSpecs::getAlphaNum()); }
	static bool matchPort(String s) { return std::regex_match(s, InputSpecs::getPort()); }
	static bool matchEmail(String s) { return std::regex_match(s, InputSpecs::getEmail()); }
	static bool matchHhmm(String s) { return std::regex_match(s, InputSpecs::getHHmm()); }
	static bool matchHhmmss(String s) { return std::regex_match(s, InputSpecs::getHhmmss()); }
}

#endif
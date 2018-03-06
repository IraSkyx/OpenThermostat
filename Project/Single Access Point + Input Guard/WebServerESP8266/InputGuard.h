#ifndef InputGard_h
#define InputGard_h

#include <regex>
#include <string>
#include "InputSpecs.h"

class InputGuard
{
public:
	static bool matchAlpha(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getAlpha())); } 
	static bool matchNum(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getNum())); }
	static bool matchAlphaNum(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getAlphaNum())); }
	static bool matchPort(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getPort())); }
	static bool matchEmail(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getEmail())); }
	static bool matchHhmm(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getHhmm())); }
	static bool matchHhmmss(std::string s) { return std::regex_match(s, std::regex(InputSpecs::getHhmmss())); }
};

#endif

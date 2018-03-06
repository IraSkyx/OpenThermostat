#ifndef InputGard_h
#define InputGard_h

#include <regex>
#include <string>
#include "InputSpecs.h"

using namespace std;

class InputGuard
{
public:
	static bool matchAlpha(string s) { return regex_match(s, regex(InputSpecs::getAlpha())); } 
	static bool matchNum(string s) { return regex_match(s, regex(InputSpecs::getNum())); }
	static bool matchAlphaNum(string s) { return regex_match(s, regex(InputSpecs::getAlphaNum())); }
	static bool matchPort(string s) { return regex_match(s, regex(InputSpecs::getPort())); }
	static bool matchEmail(string s) { return regex_match(s, regex(InputSpecs::getEmail())); }
	static bool matchHhmm(string s) { return regex_match(s, regex(InputSpecs::getHhmm())); }
	static bool matchHhmmss(string s) { return regex_match(s, regex(InputSpecs::getHhmmss())); }
};

#endif

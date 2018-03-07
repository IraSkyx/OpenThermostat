#ifndef InputGard_h
#define InputGard_h

#include <regex>
#include <string>
#include "InputSpecs.h"

using namespace std;

class InputGuard
{
public:
	static bool matchAlpha(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getAlpha())); }
	static bool matchNum(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getNum())); }
	static bool matchAlphaNum(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getAlphaNum())); }
	static bool matchPort(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getPort())); }
	static bool matchEmail(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getEmail())); }
	static bool matchHhmm(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getHhmm())); }
	static bool matchHhmmss(String s) { return regex_match(string(s.toCharArray), regex(InputSpecs::getHhmmss())); }
};

#endif

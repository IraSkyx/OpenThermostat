#ifndef InputGard_h
#define InputGard_h

class InputGuard
{
private:
	static void clearTags(String &s)

public:
	static bool alpha(String &s);
	static bool num(String &s);
	static bool alphaNum(String &s);
}

#endif
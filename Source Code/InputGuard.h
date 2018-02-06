#ifndef InputGard_h
#define InputGard_h

class InputGuard
{
//private:
//	static void clearTags(String &s)

public:
	static bool matchWebSpecs(String &s);
	static bool matchNTPSpecs(String &s);
}

#endif
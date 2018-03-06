#ifndef InputSpecs_h
#define InputSpecs_h

#include <string>

class InputSpecs
{

public:
	static char* getAlpha() { return "[A-Za-z]*"; }
	static char* getNum() { return "[0-9]*"; }
	static char* getAlphaNum() { return "[A-Za-z0-9]*"; }
	static char* getPort() { return "[0-9]{1,5}"; }
	static char* getEmail() { return "[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}"; }
	static char* getHhmm() { return "[0-9]{2}(:|h| )[0-9]{2}"; }
	static char* getHhmmss() { return "[0-9]{2}(:|h| )[0-9]{2}(:|h| )[0-9]{2}"; }
};

#endif

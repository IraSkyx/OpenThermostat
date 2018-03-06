#ifndef InputSpecs_h
#define InputSpecs_h

class InputSpecs
{

private:
	static String alpha = "[A-Za-z]*";
	static String num = "[0-9]*";
	static String alphaNum = "[A-Za-z0-9]*";
	static String port = "[0-9]{1,5}";
	static String email = "[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}";
	static String hhmm = "[0-9]{2}(:|h| )[0-9]{2}";
	static String hhmmss = "[0-9]{2}(:|h| )[0-9]{2}(:|h| )[0-9]{2}";

public:
	static String getAlpha() { return alpha; }
	static String getNum() { return num; }
	static String getAlphaNum() { return alphaNum; }
	static String getPort() { return port; }
	static String getEmail() { return email; }
	static String getHhmm() { return hhmm; }
	static String getHhmmss() { return hhmmss; }
}

#endif
#include "CryptingModule.h"
#include "KeyHolder.h"

String CryptingModule::encrypt(String s)
{
	for (int i = 0; (i < 100 && s[i] != '\0'); i++)
		if (s[i] != ';')
			s[i] = s[i] + KeyHolder::getKey();
	return s;
}

String CryptingModule::decrypt(String s)
{
	for (int i = 0; (i < 100 && s[i] != '\0'); i++)
		if (s[i] != ';')
			s[i] = s[i] - KeyHolder::getKey();
	return s;
}

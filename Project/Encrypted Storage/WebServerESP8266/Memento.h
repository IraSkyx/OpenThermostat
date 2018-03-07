#ifndef MEMENTO_H
#define MEMENTO_H
#include <WString.h>

class Memento
{
private:
	/**
	 * Memento is declaring Application as his friend so that only
	 * Application can create or acces its members
	 */
	friend class Application;

	String m_state;
	Memento(const String& state);
	~Memento() = delete;
	String getState() const;
	void setState(const String& state);
};

#endif
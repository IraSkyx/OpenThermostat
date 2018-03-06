#ifndef MEMENTO_H
#define MEMENTO_H

class Memento
{
private:
	/**
	 * Memento is declaring Application as his friend so that only
	 * Application can create or acces its members
	 */
	friend class Application;

	/**
	 * All the ways to create Memento are private
	 * 
	 */
	Memento(const Application &app) { this->m_state = app.m_state; };
	~Memento() = delete;
	Memento &operator=(const Memento &src) { m_state = src.m_state; return *this; }
	Application m_state;
	Application getState() const { return m_state; }
	void setState(Application app) { this->m_state = app; }
	
};

#endif
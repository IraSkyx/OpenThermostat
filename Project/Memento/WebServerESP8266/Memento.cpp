#include "Memento.h"

Memento::Memento(const String& state)
{
	this->m_state = state; 
}

String Memento::getState() const
{
	return m_state; 
}

void Memento::setState(const String& state)
{
	m_state = state;
}
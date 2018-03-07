#ifndef CARETAKER_H
#define CARETAKER_H
#include "Memento.h"

/**
 * Responsible for the preservation of the Memento, not on the memo content operation or inspection
 */
class CareTaker
{
public:
	CareTaker(){}
	~CareTaker() {}
	void setMemento(Memento* memento);
	Memento* getMemento() { return this->memento; }
private:
	Memento* memento;
};

#endif

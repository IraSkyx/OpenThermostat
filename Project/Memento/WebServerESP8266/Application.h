#ifndef APPLICATION_H
#define APPLICATION_H

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(x)     Serial.print(x)
#define DEBUG_PRINTDEC(x)     Serial.print(x, DEC)
#define DEBUG_PRINTLN(x)  Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTDEC(x)
#define DEBUG_PRINTLN(x)
#endif

#define NBLOGS 15

#include <WString.h>
#include "FS.h"
#include "Memento.h"
#include "CareTaker.h"


class Application
{
private:
	String m_state;
	String file;
	String * Logs = NULL;
	uint8_t nblogs = 0;
	uint8_t firstlog = 0;

	//Memento
	// Le caretaker va être appellé lors du load() et su save() de l'Application
	CareTaker* taker{};

	//Singleton
	//On on récupère plutot une référence afin d'éviter les copies
	//car l'application restera la même, on toujours avoir une référence dessus
	//L'application ne doit pas être supprimée
	Application(const Application &copy) = delete;
	Application& operator=(const Application&) = delete;

	static Application m_instance;
	Application(); //constructeur
	~Application() {} //destructeur

public:
	float TempE;
	float HumE;
	String Wssid;
	String Wpass;
	uint8_t  dhtType;
	uint8_t dhtPin;
	uint8_t pirPin;
	uint8_t irPin;
	String AP;
	uint8_t Cmd;
	String Ntp;
	uint8_t Timezone;
	String Ip;
	String Gat;
	String Dns;
	String Mode;
	float Temp;
	float FTemp;
	String pwd;
	bool Access = false;
	bool domo;
	String domoIP;
	unsigned int domoPir;
	unsigned int domoTemp;
	unsigned int domoMode;
	unsigned int domogTemp;

	void save();
	void load();
	void init();
	void AddLog(String);
	uint8_t getNblogs() { return nblogs; };
	uint8_t getFirstlog() { return firstlog; };
	String * getLogs() { return Logs; };
	
	// retourne la référence sur l'Application
	static Application& getInstance() { 
		static Application m_instance; //destroyed at the {
		return m_instance;
	} 

	// Memento pimitives
	Memento* createMemento();
	void setMemento(Memento* memento);
	String getState() { return m_state; };
	void setState(const String& state) { m_state = state; }

};

#endif
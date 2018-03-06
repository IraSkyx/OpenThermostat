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

class Application
{
private:
    String file;
    String * Logs=NULL;
    uint8_t nblogs=0;
    uint8_t firstlog=0;

    //Singleton
    //On on récupère plutot une référence afin d'éviter les copies
    //car l'application restera la même, on toujours avoir une référence dessus
    //L'application ne doit pas être supprimée
    Application(const Application& copy) = delete;
    Application& operator=(const Application&) = delete;
	
    static Application m_instance;
    Application(); //constructeur
    ~Application(); //destructeur
	Application m_state;

public:
    static Application& getInstance(); //pour récupérer m_instance
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
    bool Access=false;
    bool domo;
    String domoIP;
    unsigned int domoPir;
    unsigned int domoTemp;
    unsigned int domoMode;
    unsigned int domogTemp;

  	void save ();
  	void load();
  	void init();
  	void AddLog(String);
  	uint8_t getNblogs() {return nblogs;};
  	uint8_t getFirstlog() {return firstlog;};
  	String * getLogs() {return Logs;};
	
	// Memento pimitives
	Memento* createMemento();
	void installMemento(Memento* memento);
	Memento* saveState();
};

#endif

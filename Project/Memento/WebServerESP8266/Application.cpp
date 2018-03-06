#include "Application.h"
#include <Time.h>
#include "sha512.h"
#include "CareTaker.h"
#include <string>

using namespace std;

// constructeur
Application::Application()
{
	//file en constante
	file = "f6.txt";
	Cmd = 0;
	Logs = new String[NBLOGS];
}

// Create a Memento object containing the internal state of the application m_state
Memento* Application::createMemento()
{
	return new Memento(m_state);
}

// Install the Memento
void Application::setMemento(Memento *mem)
{
	m_state = mem->getState();
}

// Initialisation des variables des variables à partir d'un fichier (ou non).
// Spiffs est un système de fichier pratique étant données les contraintes de la carte telles que sa RAM limitée par exemple.
// Il ne prend pas en charge les répertoire, et stocke juste une liste plate de fichiers mais accepte les "/" dans les noms de fichiers.
void Application::init()
{
	Access = false;
	// Si le fichier n'existe pas, on le crée en initialisant toutes les variables par défaut.
	SPIFFS.begin();
	if (!SPIFFS.exists(file))
	{
		DEBUG_PRINTLN(F("File Creation"));
		File f = SPIFFS.open(file, "w");
		f.print(F("0.0;0.0;ESP8266;esppwd;0;0;0;0;toshiba;fr.pool.ntp.org;2;0.0.0.0;0.0.0.0;0.0.0.0;Off;0.0;0.0;esppwd;0;;-1;-1;-1;-1;"));
		TempE = 0.0;
		HumE = 0.0;
		Wssid = "ESP8266";
		Wpass = "esppwd";
		dhtType = 0;
		dhtPin = 0;
		pirPin = 0;
		irPin = 0;
		AP = "toshiba";
		Ntp = "fr.pool.ntp.org";
		Timezone = 2;
		Ip = "0.0.0.0";
		Gat = "0.0.0.0";
		Dns = "0.0.0.0";
		Mode = "Off";
		Temp = 0.0;
		FTemp = 0.0;
		pwd = "esppwd";
		domo = false;
		domoIP = "";
		domoPir = -1;
		domoTemp = -1;
		domoMode = -1;
		domogTemp = -1;
	}
	else load(); //load of the file if it  doesn't exists
	SPIFFS.end();
}

// Load the file in memory and initialize the memento
void Application::load()
{
	DEBUG_PRINTLN(F("Restoration of the Memento"));
	DEBUG_PRINTLN(F("App config reading"));
	SPIFFS.begin();
	File f = SPIFFS.open(file, "r");
	TempE = f.readStringUntil(';').toFloat();
	HumE = f.readStringUntil(';').toFloat();
	Wssid = f.readStringUntil(';');
	Wpass = f.readStringUntil(';');
	dhtType = f.readStringUntil(';').toInt();
	dhtPin = f.readStringUntil(';').toInt();
	pirPin = f.readStringUntil(';').toInt();
	irPin = f.readStringUntil(';').toInt();
	AP = f.readStringUntil(';');
	Ntp = f.readStringUntil(';');
	Timezone = f.readStringUntil(';').toInt();
	Ip = f.readStringUntil(';');
	Gat = f.readStringUntil(';');
	Dns = f.readStringUntil(';');
	Mode = f.readStringUntil(';');
	Temp = f.readStringUntil(';').toFloat();
	FTemp = f.readStringUntil(';').toFloat();
	pwd = f.readStringUntil(';');
	if (f.readStringUntil(';').toInt() == 0) domo = false;
	else domo = true;
	domoIP = f.readStringUntil(';');
	domoPir = f.readStringUntil(';').toInt();
	domoTemp = f.readStringUntil(';').toInt();
	domoMode = f.readStringUntil(';').toInt();
	domogTemp = f.readStringUntil(';').toInt();
	f.close();
	SPIFFS.end();

	// Memento who restor the old state
	String chaineFormatee = String(TempE, 1) + ";" + String(HumE, 1) + ";" + Wssid + ";" + Wpass + ";" + dhtType + ";" + dhtPin + ";" + pirPin + ";" + irPin + ";" + AP + ";" + Ntp + ";" + String(Timezone) + ";" + Ip + ";" + Gat + ";" + Dns + ";" + Mode + ";" + String(Temp, 1) + ";" + String(FTemp, 1) + ";" + pwd + ";" + String(domo) + ";" + domoIP + ";" + String(domoPir) + ";" + String(domoTemp) + ";" + String(domoMode) + ";" + String(domogTemp) + ";";
	Application::getInstance().setMemento(taker->getMemento());
}

// Sauvegarde les données actuelles dans un nouveau fichier qui remplace le précédent.
void Application::save()
{
	String chaineFormatee = String(TempE, 1) + ";" + String(HumE, 1) + ";" + Wssid + ";" + Wpass + ";" + dhtType + ";" + dhtPin + ";" + pirPin + ";" + irPin + ";" + AP + ";" + Ntp + ";" + String(Timezone) + ";" + Ip + ";" + Gat + ";" + Dns + ";" + Mode + ";" + String(Temp, 1) + ";" + String(FTemp, 1) + ";" + pwd + ";" + String(domo) + ";" + domoIP + ";" + String(domoPir) + ";" + String(domoTemp) + ";" + String(domoMode) + ";" + String(domogTemp) + ";";
	Application::getInstance().setState(chaineFormatee);

	Serial.println("Save config : " + chaineFormatee);
	DEBUG_PRINTLN("Save config : " + chaineFormatee);
	SPIFFS.begin();
	SPIFFS.remove(file);
	File f = SPIFFS.open(file, "w");
	f.print(chaineFormatee); 
	f.close();
	SPIFFS.end();
}



void Application::AddLog(String s)
{
	// uint8_t = unsigned_char de valeur maximale 255.
	uint8_t end = (nblogs + firstlog) % NBLOGS;

	// Ajouter un log avec l'heure actuelle.
	Logs[end] = String(hour()) + ":" + String(minute()) + ":" + String(second()) + " " + s;
	if (nblogs < NBLOGS) nblogs++;
	if (end == firstlog)
		firstlog = (firstlog + 1) % NBLOGS;
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Arduino.h>
#include <Time.h>

#include "Application.h"
#include "IRManager.h"
#include "WifiManager.h"
#include "SensorManager.h"
#include "Thermostat.h"
#include "Web.h"
#include "TimeNtp.h"
#include "DomoticzBroadcaster.h"
// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Global var
// ------------------------------------------------------------------------------------------------------------------------------------------------------

#define DHTTYPE DHT22 // Définition du type de capteur de température / humidité

//CMD
#define CMD_REBOOT                          111
#define CMD_WIFI_DISCONNECT                 222
#define CMD_WEB_DISCONNECT                  333

//timers
unsigned long timerth=0.0;
unsigned long timer60=0.0;
unsigned long timer1=0.0;
uint8_t loggingloop=0;

//Objects
TimeNtp timentp;
WifiManager WifMan();
DomoticzBroadcaster domo();
SensorManager sensorMan(&domo);
IRManager  irmanager();
Thermostat thermos("TCal.txt","Tconfig.txt",&sensorMan,&irmanager,&domo);
Web web(&sensorMan,&thermos,&WifMan,&irmanager,&timentp, &domo);

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Setup et Loop
// ------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
	ESP.eraseConfig();
	Serial.begin(115200);  // Serial connection from ESP-01 via 3.3v console cable
	while (!Serial) ; // wait for Arduino Serial Monitor
	Application::getInstance().init();
	sensorMan.init();
	WifMan().initWifi();
	timentp.init(Application::getInstance().Ntp, Application::getInstance().Timezone);
	irmanager().init();
	thermos.init();
	web.init();
}

void runOnesecond()
{
  //update next timer
  timer1 = millis() + 1000;

// check CMD
if(Application::getInstance().Cmd==CMD_REBOOT)
{
  DEBUG_PRINT(F("Reboot CMD"));

  Application::getInstance().AddLog(F("Reboot CMD"));
  web.server.stop();
  web.server.close();
  WifMan().disconnect();
  ESP.restart();
}

//PIR
sensorMan.readPir(thermos.prestime);

}
void runthseconds()
{
loggingloop++;
if (loggingloop==10) Application::getInstance().Access=false;
  //update next timer
  timerth = millis() + 30000;
// DHT
sensorMan.ReadTempHum();

//thermostat control state
  if (thermos.IsStarted()== 1)
  {
  //check thermos statut with current temperature
  thermos.run();
  }
}

void loop() {
//timers
  if (millis() > timerth)
      runthseconds();

 if (millis() > timer60){
     if (Application::getInstance().domo) domo().sendTemp(sensorMan.getTemp());
      timer60 = millis() + 60000;
 }
 if (millis() > timer1)
 runOnesecond();

//everyloop web
web.server.handleClient();
Alarm.delay(100); // wait
}


void Repeats(){
// if (DEBUG) Serial.println("10 second timer");
//  if (DEBUG) Serial.println(hour());
}

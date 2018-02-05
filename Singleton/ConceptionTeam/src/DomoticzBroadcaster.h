#ifndef DOMOTICZ_BRODCASTER_H
#define DOMOTICZ_BRODCASTER_H

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "Application.h"

class DomoticzBroadcaster
{
private:
    Application &lconfig;

public:
  DomoticzBroadcaster(Application &c);
  void sendPir(uint8_t state);
  void sendTemp(float t);
  void sendMode(String mode);
  float getTemp();

};

#endif

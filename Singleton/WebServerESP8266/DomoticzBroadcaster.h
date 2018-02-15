#ifndef DOMOTICZ_BRODCASTER_H
#define DOMOTICZ_BRODCASTER_H

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "Application.h"

class DomoticzBroadcaster
{
  public:
  DomoticzBroadcaster();
  void sendPir(uint8_t state);
  void sendTemp(float t);
  void sendMode(String mode);
  float getTemp();

};

#endif

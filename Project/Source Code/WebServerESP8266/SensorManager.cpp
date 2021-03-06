/* Cette classe permet d'initialiser les capteurs DHT et Présence tout en controlant en permanence les données récupérées par la lecture.
  Elle permet aussi d'avoir accès directement aux valeurs humidité et température.
  Elle ajoute aussi le nombre de présence détectées aux logs et patiente entre chaque lecture. */


#include "SensorManager.h"

// Constructeur par défaut.
SensorManager::SensorManager()
{
// Initialisation du capteur de température DHT
lconfig=new Application();
dht=new DHT(lconfig->dhtPin, DHT22);
}

// Constructeur à partir de 2 configurations existantes.
SensorManager::SensorManager(Application *c, DomoticzBroadcaster * domo)
{
lconfig=c;
ldomo=domo;
}




// Équivalent d'un getter.
uint8_t SensorManager::getStatePIR() 
{return inputStatePIR; }



// Initialisation de la température et de l'humidité par défaut.
void SensorManager::init()
{ 
Temp=-1.0;
Hum=-1.0;
dht=new DHT(lconfig->dhtPin, DHT22);
dht->begin(); // Initialisation du capteur DHT

//pinMode(LED_BUILTIN, OUTPUT); // LED d'affichage si besoin.

pinMode(lconfig->pirPin, INPUT);
}




// Lecture des valeurs humidité et température.
// Retourne la chaine formatée des valeurs sondées.
void SensorManager::ReadTempHum() {
float humidity, temp; 
  // Lecture du capteur possible toutes les deux secondes
  unsigned long currentMillis = millis();

   // Si le délai entre deux lectures a été respecté alors on lis. Code non-implémenté.
   /*if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;*/

    humidity = dht->readHumidity(); // Donne un pourcentage.
    temp = dht->readTemperature(); // Donne en degrés.

    // Vérification de la lecture : si les valeurs ne sont pas des nombres alors on retourne une erreur.
    if (isnan(humidity) || isnan(temp)) {
      DEBUG_PRINTLN(F("Error reading DHT"));
    }
    else // Sinon on génére la chaîne formatée à afficher.
    {
       Temp=temp+lconfig->TempE;
       Hum=humidity+lconfig->HumE;
    }
}




// Getter qui retourne la chaine formatée de la température.
float SensorManager::getDirectTemp() {
float temp;  
    temp = dht->readTemperature();

    if (isnan(temp)) { // Si ce n'est pas un nombre alors erreur.
      return -1;
    }
    else // Retourne la chaîne formatée.
    {
      return temp;
    }
  }


// Getter qui retourne la chaine formatée de l'humidité.
float SensorManager::getDirectHum() {
float humidity; 
    humidity = dht->readHumidity();
    if (isnan(humidity)) { // Si ce n'est pas un nombre alors erreur.
      return -1;
    }
    else // Retourne la chaîne formatée.
    {
      return humidity;
    }
 }


// Lecture du capteur de présence.
void SensorManager::readPir(uint8_t prestime)
{
long currentMillis = millis();
uint8_t p;
  // Si le délai entre la dernière et la nouvelle lecture a été respecté ou que le capteur est à zero.
  // Alors on lit le capteur.
  // Le delai permet de laisser le temps de lire qu'un mouvement est détecté par le capteur.
 if (currentMillis - previousMillisPIR >= 5000 || inputStatePIR == 0) {
   
  // Lecture du capteur
  p=digitalRead(lconfig->pirPin);
  if (lconfig->domo && inputStatePIR==1 && p==0)
    ldomo->sendPir(0);
    inputStatePIR=p;
  if (inputStatePIR==1) {
  previousMillisPIR = currentMillis;
     
        if (lconfig->domo) ldomo->sendPir(1);
        long difference = (currentMillis - presencefirst)/1000;
        long difference2 = (currentMillis - presencelast)/1000;        
        if (difference < 180 or (difference2 <= prestime*60 and presencecount>2)  ) {
            presencecount++;
            presencelast=currentMillis;
            DEBUG_PRINTLN("pir detection nb :" + String(presencecount));
          }
          else{
            presencefirst=currentMillis;
            presencelast=presencefirst;
            presencecount=1;  
            lconfig->AddLog("presence count "+String(presencecount));
          }
  
}
  }
}





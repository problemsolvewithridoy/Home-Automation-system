/**********************************************************************************
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board:
 *  For ESP32 : https://github.com/espressif/arduino-esp32
 *  
 *  Download the libraries:
 *  Espalexa Library: https://github.com/Aircoookie/Espalexa
 **********************************************************************************/

#include <WiFi.h>
#include <Espalexa.h>

Espalexa espalexa;

// define the GPIO connected with Relays and switches
#define RelayPin1 23  //D23
#define RelayPin2 22  //D22
#define RelayPin3 21  //D21
#define RelayPin4 19  //D19
#define RelayPin5 18  //D18
#define RelayPin6 5   //D5
#define RelayPin7 25  //D25
#define RelayPin8 26  //D26

#define SwitchPin1 13  //D13
#define SwitchPin2 12  //D12
#define SwitchPin3 14  //D14
#define SwitchPin4 27  //D27
#define SwitchPin5 33  //D33
#define SwitchPin6 32  //D32
#define SwitchPin7 15  //D15
#define SwitchPin8 4   //D4

#define wifiLed    2   //D2

int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4
int toggleState_5 = 0; //Define integer to remember the toggle state for relay 5
int toggleState_6 = 0; //Define integer to remember the toggle state for relay 6
int toggleState_7 = 0; //Define integer to remember the toggle state for relay 7
int toggleState_8 = 0; //Define integer to remember the toggle state for relay 8

// prototypes
boolean connectWifi();

//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);
void fifthLightChanged(uint8_t brightness);
void sixthLightChanged(uint8_t brightness);
void senventhLightChanged(uint8_t brightness);
void eighthLightChanged(uint8_t brightness);

// WiFi Credentials
const char* ssid = "WiFi Name";
const char* password = "WiFi Password";

// device names
String Device_1_Name = "Study Lamp";
String Device_2_Name = "CFL";
String Device_3_Name = "Yellow light";
String Device_4_Name = "Red light";
String Device_5_Name = "Studio Light";
String Device_6_Name = "Outdoor Light";
String Device_7_Name = "Kitchen Light";
String Device_8_Name = "Room Light";

boolean wifiConnected = false;

//our callback functions
void firstLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin1, LOW);
      Serial.println("Device1 ON");
      toggleState_1 = 1;
    }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
    toggleState_1 = 0;
  }
}

void secondLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin2, LOW);
      Serial.println("Device2 ON");
      toggleState_2 = 1;
    }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
    toggleState_2 = 0;
  }
}

void thirdLightChanged(uint8_t brightness)
{
  //Control the device  
  if (brightness == 255)
    {
      digitalWrite(RelayPin3, LOW);
      Serial.println("Device3 ON");
      toggleState_3 = 1;
    }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
    toggleState_3 = 0;
  }
}

void fourthLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin4, LOW);
      Serial.println("Device4 ON");
      toggleState_4 = 1;
    }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
    toggleState_4 = 0;
  }
}

void fifthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin5, LOW);
      Serial.println("Device5 ON");
      toggleState_5 = 1;
    }
  else
  {
    digitalWrite(RelayPin5, HIGH);
    Serial.println("Device1 OFF");
    toggleState_5 = 0;
  }
}

void sixthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin6, LOW);
      Serial.println("Device6 ON");
      toggleState_6 = 1;
    }
  else
  {
    digitalWrite(RelayPin6, HIGH);
    Serial.println("Device6 OFF");
    toggleState_6 = 0;
  }
}

void seventhLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin7, LOW);
      Serial.println("Device7 ON");
      toggleState_7 = 1;
    }
  else
  {
    digitalWrite(RelayPin7, HIGH);
    Serial.println("Device7 OFF");
    toggleState_7 = 0;
  }
}

void eighthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin8, LOW);
      Serial.println("Device8 ON");
      toggleState_8 = 1;
    }
  else
  {
    digitalWrite(RelayPin8, HIGH);
    Serial.println("Device8 OFF");
    toggleState_8 = 0;
  }
}

void relayOnOff(int relay){
    EspalexaDevice* d = espalexa.getDevice(relay-1); //the index is zero-based
    switch(relay){
      case 1: 
             if(toggleState_1 == 1){
              d->setPercent(100); //set value "brightness" in percent
              digitalWrite(RelayPin1, LOW); // turn on relay 1
              toggleState_1 = 0;
              Serial.println("Device1 ON");
              }
             else{
              d->setPercent(0); //set value "brightness" in percent
              digitalWrite(RelayPin1, HIGH); // turn off relay 1
              toggleState_1 = 1;
              Serial.println("Device1 OFF");
              }
      break;
      case 2: 
             if(toggleState_2 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin2, LOW); // turn on relay 2
              toggleState_2 = 0;
              Serial.println("Device2 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin2, HIGH); // turn off relay 2
              toggleState_2 = 1;
              Serial.println("Device2 OFF");
              }
      break;
      case 3: 
             if(toggleState_3 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin3, LOW); // turn on relay 3
              toggleState_3 = 0;
              Serial.println("Device3 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin3, HIGH); // turn off relay 3
              toggleState_3 = 1;
              Serial.println("Device3 OFF");
              }
      break;
      case 4: 
             if(toggleState_4 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin4, LOW); // turn on relay 4
              toggleState_4 = 0;
              Serial.println("Device4 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin4, HIGH); // turn off relay 4
              toggleState_4 = 1;
              Serial.println("Device4 OFF");
              }
      break;
      case 5: 
             if(toggleState_5 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin5, LOW); // turn on relay 5
              toggleState_5 = 0;
              Serial.println("Device5 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin5, HIGH); // turn off relay 5
              toggleState_5 = 1;
              Serial.println("Device5 OFF");
              }
      break;
      case 6: 
             if(toggleState_6 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin6, LOW); // turn on relay 6
              toggleState_6 = 0;
              Serial.println("Device6 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin6, HIGH); // turn off relay 6
              toggleState_6 = 1;
              Serial.println("Device6 OFF");
              }
      break;
      case 7: 
             if(toggleState_7 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin7, LOW); // turn on relay 7
              toggleState_7 = 0;
              Serial.println("Device7 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin7, HIGH); // turn off relay 7
              toggleState_7 = 1;
              Serial.println("Device7 OFF");
              }
      break;
      case 8: 
             if(toggleState_8 == 1){
              d->setPercent(100);
              digitalWrite(RelayPin8, LOW); // turn on relay 8
              toggleState_8 = 0;
              Serial.println("Device8 ON");
              }
             else{
              d->setPercent(0);
              digitalWrite(RelayPin8, HIGH); // turn off relay 8
              toggleState_8 = 1;
              Serial.println("Device8 OFF");
              }
      break;
      default : break;      
      }
      delay(300);  
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}

void addDevices(){
  // Define your devices here.
  espalexa.addDevice(Device_1_Name, firstLightChanged); //simplest definition, default state off
  espalexa.addDevice(Device_2_Name, secondLightChanged);
  espalexa.addDevice(Device_3_Name, thirdLightChanged);
  espalexa.addDevice(Device_4_Name, fourthLightChanged);
  espalexa.addDevice(Device_5_Name, fifthLightChanged); 
  espalexa.addDevice(Device_6_Name, sixthLightChanged);
  espalexa.addDevice(Device_7_Name, seventhLightChanged);
  espalexa.addDevice(Device_8_Name, eighthLightChanged);

  espalexa.begin();
}


void setup()
{
  Serial.begin(115200);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);
  pinMode(SwitchPin5, INPUT_PULLUP);
  pinMode(SwitchPin6, INPUT_PULLUP);
  pinMode(SwitchPin7, INPUT_PULLUP);
  pinMode(SwitchPin8, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  digitalWrite(RelayPin5, HIGH);
  digitalWrite(RelayPin6, HIGH);
  digitalWrite(RelayPin7, HIGH);
  digitalWrite(RelayPin8, HIGH);

  // Initialise wifi connection
  wifiConnected = connectWifi();

  if (wifiConnected)
  {
    addDevices();
  }
  else
  {
    Serial.println("Cannot connect to WiFi. So in Manual Mode");
    delay(1000);
  }
}

void loop()
{
   if (WiFi.status() != WL_CONNECTED)
  {
    //Serial.print("WiFi Not Connected ");
    digitalWrite(wifiLed, LOW); //Turn off WiFi LED
    //Manual Switch Control
    if (digitalRead(SwitchPin1) == LOW){      
      relayOnOff(1);      
    }
    else if (digitalRead(SwitchPin2) == LOW){
      relayOnOff(2);
    }
    else if (digitalRead(SwitchPin3) == LOW){
      relayOnOff(3);
    }
    else if (digitalRead(SwitchPin4) == LOW){
      relayOnOff(4);
    }
    else if (digitalRead(SwitchPin5) == LOW){      
      relayOnOff(5);      
    }
    else if (digitalRead(SwitchPin6) == LOW){
      relayOnOff(6);
    }
    else if (digitalRead(SwitchPin7) == LOW){
      relayOnOff(7);
    }
    else if (digitalRead(SwitchPin8) == LOW){
      relayOnOff(8);
    }
  }
  else
  {
    //Serial.print("WiFi Connected  ");
    digitalWrite(wifiLed, HIGH);
    //Manual Switch Control
    if (digitalRead(SwitchPin1) == LOW){
      relayOnOff(1);      
    }
    else if (digitalRead(SwitchPin2) == LOW){
      relayOnOff(2);
    }
    else if (digitalRead(SwitchPin3) == LOW){
      relayOnOff(3);
    }
    else if (digitalRead(SwitchPin4) == LOW){
      relayOnOff(4);
    }
    else if (digitalRead(SwitchPin5) == LOW){      
      relayOnOff(5);      
    }
    else if (digitalRead(SwitchPin6) == LOW){
      relayOnOff(6);
    }
    else if (digitalRead(SwitchPin7) == LOW){
      relayOnOff(7);
    }
    else if (digitalRead(SwitchPin8) == LOW){
      relayOnOff(8);
    }
    //WiFi Control
    if (wifiConnected){
      espalexa.loop();
      delay(1);
    }
    else {
      wifiConnected = connectWifi(); // Initialise wifi connection
      if(wifiConnected){
      addDevices();
      }
    }
  }
}

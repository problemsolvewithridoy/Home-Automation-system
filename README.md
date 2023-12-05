
# The Ultimate 8-Channel Smart Home Controller Using ESP32: Google Home, Alexa, and Android App Control Device 🙂

I have shown how to make an ESP32 Alexa home automation system with Echo DOT, manual switches, relay module, and ESP32. I have used Amazon Alexa App to control the home appliances with voice commands for this Alexa automation project.

If there is no internet, still you can also control the home appliances from the pushbuttons and when the internet comes back the ESP32 will automatically connect with the WiFi.

![1x](https://github.com/problemsolvewithridoy/code-in-place-baby-snake/assets/123636419/849aff1d-315b-46a4-b510-bf73f400ee51)

The circuit is very simple, I have used D23, D22, D21, D19, D18, D5, D25 & D26 GPIO to control the 8- channel relay module. And the GPIO D13, D12, D14, D27, D33, D32, D15 & D4 are connected with manual switches to control the relay module manually. I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors with each switch.

As per the source code, when the control pins of the relay module receive the LOW signal the respective relay will turn on and the relay will turn off for the HIGH signal in the control pin. I have used a 5V 2Amp mobile charger to supply the circuit.

## Required Components for the ESP32 projects


```bash
1. ESP32 DEV KIT V1
2. 8-channel 5V SPDT Relay Module
3. Manual Switches or Push Switches
4. Amazon Echo Dot

```
    
## WiFi Control Relays ( Amazon Alexa App + Switch )


![2x](https://github.com/problemsolvewithridoy/code-in-place-baby-snake/assets/123636419/46b2241e-a9cf-4683-9ec8-db4c44a67fc3)

If the ESP32 is connected with WiFi, then you can control the relay module from Amazon Alexa App and manual switches. You can control and monitor the current status of the switches in the Alexa App.

## Control Relays manually with Switches (No WiFi)

![3x](https://github.com/problemsolvewithridoy/code-in-place-baby-snake/assets/123636419/6a42e028-564d-49c3-8071-382661a6ed6a)

If the WiFi is not available, you can control the relays from the switches manually.

The ESP32 will check for the WiFi after every 3 seconds. When the internet comes back, the ESP32 will automatically connect to the WiFi.

## Program ESP32 with Arduino IDE

In the Tutorial video, I have explained all the steps to program the ESP32 DEV KIT V1 using Arduino IDE.

```bash
1. Update the Preferences –> Aditional boards Manager URLs: 
https://dl.espressif.com/dl/package_esp32_index.json, 
http://arduino.esp8266.com/stable/package_esp8266com_index.json

2. Then install the ESP32 board from the Board manager or https://github.com/espressif/arduino-esp32 to download the ESP32 board.

3. Download the required libraries from the following links:
Espalexa Library: https://github.com/bxparks/AceButton
AceButton Library: https://github.com/Links2004/arduinoWebSockets/releases

```

Please download the latest version of the libraries from the given links. Then install the libraries at Arduino IDE – Sketch – Include Library – Add Zip Library.

## Home Automation System Code for Normal Switch

```bash
# Please Subscribe to my youtube channel "@problemsolvewithridoy"

#include <WiFi.h>
#include <Espalexa.h>
#include <AceButton.h>
using namespace ace_button;

Espalexa espalexa;

//Define the GPIO connected with Relays and switches
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

// WiFi Credentials
const char* ssid = "WiFi Name";
const char* password = "WiFi Password";

// device names
String Device_1_Name = "Study Lamp";
String Device_2_Name = "CFL";
String Device_3_Name = "Yellow light";
String Device_4_Name = "Night Lamp";
String Device_5_Name = "Studio Light";
String Device_6_Name = "Outdoor Light";
String Device_7_Name = "Kitchen Light";
String Device_8_Name = "Room Light";

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

ButtonConfig config1;
AceButton button1(&config1);
ButtonConfig config2;
AceButton button2(&config2);
ButtonConfig config3;
AceButton button3(&config3);
ButtonConfig config4;
AceButton button4(&config4);
ButtonConfig config5;
AceButton button5(&config5);
ButtonConfig config6;
AceButton button6(&config6);
ButtonConfig config7;
AceButton button7(&config7);
ButtonConfig config8;
AceButton button8(&config8);

void handleEvent1(AceButton*, uint8_t, uint8_t);
void handleEvent2(AceButton*, uint8_t, uint8_t);
void handleEvent3(AceButton*, uint8_t, uint8_t);
void handleEvent4(AceButton*, uint8_t, uint8_t);
void handleEvent5(AceButton*, uint8_t, uint8_t);
void handleEvent6(AceButton*, uint8_t, uint8_t);
void handleEvent7(AceButton*, uint8_t, uint8_t);
void handleEvent8(AceButton*, uint8_t, uint8_t);

boolean wifiConnected = false;

//our callback functions
void firstLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin1, LOW);
      Serial.println("Device1 ON");
    }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
  }
}

void secondLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin2, LOW);
      Serial.println("Device2 ON");
    }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
  }
}

void thirdLightChanged(uint8_t brightness)
{
  //Control the device  
  if (brightness == 255)
    {
      digitalWrite(RelayPin3, LOW);
      Serial.println("Device3 ON");
    }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
  }
}

void fourthLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin4, LOW);
      Serial.println("Device4 ON");
    }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
  }
}

void fifthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin5, LOW);
      Serial.println("Device5 ON");
    }
  else
  {
    digitalWrite(RelayPin5, HIGH);
    Serial.println("Device1 OFF");
  }
}

void sixthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin6, LOW);
      Serial.println("Device6 ON");
    }
  else
  {
    digitalWrite(RelayPin6, HIGH);
    Serial.println("Device6 OFF");
  }
}

void seventhLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin7, LOW);
      Serial.println("Device7 ON");
    }
  else
  {
    digitalWrite(RelayPin7, HIGH);
    Serial.println("Device7 OFF");
  }
}

void eighthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness == 255)
    {
      digitalWrite(RelayPin8, LOW);
      Serial.println("Device8 ON");
    }
  else
  {
    digitalWrite(RelayPin8, HIGH);
    Serial.println("Device8 OFF");
  }
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

  config1.setEventHandler(button1Handler);
  config2.setEventHandler(button2Handler);
  config3.setEventHandler(button3Handler);
  config4.setEventHandler(button4Handler);
  config5.setEventHandler(button5Handler);
  config6.setEventHandler(button6Handler);
  config7.setEventHandler(button7Handler);
  config8.setEventHandler(button8Handler);

  button1.init(SwitchPin1);
  button2.init(SwitchPin2);
  button3.init(SwitchPin3);
  button4.init(SwitchPin4);
  button5.init(SwitchPin5);
  button6.init(SwitchPin6);
  button7.init(SwitchPin7);
  button8.init(SwitchPin8);


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
  }
  else
  {
    //Serial.print("WiFi Connected  ");
    digitalWrite(wifiLed, HIGH);
    //Manual Switch Control
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
  button1.check();
  button2.check();
  button3.check();
  button4.check();
  button5.check();
  button6.check();
  button7.check();
  button8.check();
}

void button1Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT1");
  EspalexaDevice* d1 = espalexa.getDevice(0); //this will get "first device", the index is zero-based
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d1->setPercent(100); //set value "brightness" in percent
      digitalWrite(RelayPin1, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d1->setPercent(0); //set value "brightness" in percent
      digitalWrite(RelayPin1, HIGH);
      break;
  }
}

void button2Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT2");
  EspalexaDevice* d2 = espalexa.getDevice(1);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d2->setPercent(100);
      digitalWrite(RelayPin2, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d2->setPercent(0);
      digitalWrite(RelayPin2, HIGH);
      break;
  }
}

void button3Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT3");
  EspalexaDevice* d3 = espalexa.getDevice(2);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d3->setPercent(100);
      digitalWrite(RelayPin3, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d3->setPercent(0);
      digitalWrite(RelayPin3, HIGH);
      break;
  }
}

void button4Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT4");
  EspalexaDevice* d4 = espalexa.getDevice(3);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d4->setPercent(100);
      digitalWrite(RelayPin4, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d4->setPercent(0);
      digitalWrite(RelayPin4, HIGH);
      break;
  }
}

void button5Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT5");
  EspalexaDevice* d5 = espalexa.getDevice(4);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d5->setPercent(100);
      digitalWrite(RelayPin5, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d5->setPercent(0);
      digitalWrite(RelayPin5, HIGH);
      break;
  }
}

void button6Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT6");
  EspalexaDevice* d6 = espalexa.getDevice(5);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d6->setPercent(100);
      digitalWrite(RelayPin6, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d6->setPercent(0);
      digitalWrite(RelayPin6, HIGH);
      break;
  }
}

void button7Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT7");
  EspalexaDevice* d7 = espalexa.getDevice(6);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d7->setPercent(100);
      digitalWrite(RelayPin7, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d7->setPercent(0);
      digitalWrite(RelayPin7, HIGH);
      break;
  }
}

void button8Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT8");
  EspalexaDevice* d8 = espalexa.getDevice(7);
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("kEventPressed");
      d8->setPercent(100);
      digitalWrite(RelayPin8, LOW);
      break;
    case AceButton::kEventReleased:
      Serial.println("kEventReleased");
      d8->setPercent(0);
      digitalWrite(RelayPin8, HIGH);
      break;
  }
}
```

## Home Automation System Code for Push Switch

```bash
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


```

Enter the following WiFi credential in the code:
```bash
1. WiFi Name at “WiFi Name”
2. WiFi Password at “WiFi Password”
```

Then enter the device names in the code. Alexa will identify that device with the name mentioned in the code.

Now select the board as DOIT ESP32 DEVKIT V1 and the PORT in Arduino IDE. Then click on the upload button to program the ESP32 board.

After uploading the code, if the ESP32 connects to the internet, the blue LED should turn on.

## Configure Amazon Alexa App

![4x](https://github.com/problemsolvewithridoy/code-in-place-baby-snake/assets/123636419/beb437f2-5941-4ad4-b7cc-ca3528910240)

I have explained all the steps to add devices to Amazon Alexa App.

While configuring the Amazon Alexa App, the ESP32, Amazon Echo Dot and the smartphone should be connected to the same wifi network.

Once the Alexa App finds all the devices, you can control those devices with voice commands using the Alexa echo dot.

![5x](https://github.com/problemsolvewithridoy/code-in-place-baby-snake/assets/123636419/34dc6015-e417-45a9-b3e1-33aef81cafcf)

You may face No new devices found error while adding the devices with Alexa.

Then restart the echo dot, after restarting once the echo dot connects with the same WiFi, tap on “Try discovery again”.



## You can follow me 

Facebook:- https://www.facebook.com/problemsolvewithridoy/

Linkedin:- https://www.linkedin.com/in/ridoyhossain/

YouTube:- https://www.youtube.com/@problemsolvewithridoy

Gmail:- entridoy2@gmail.com

If you have any confusion, please feel free to contact me. Thank you


## License
This script is released under the MIT License. Feel free to use, modify, and distribute it as you wish. If you find any bugs or have any suggestions for improvement, please submit an issue or a pull request on this repository.



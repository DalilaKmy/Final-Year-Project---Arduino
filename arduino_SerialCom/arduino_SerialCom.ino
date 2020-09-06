#include <Robojax_AllegroACS_Current_Sensor.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial s(5,6);
int RelayPin = 7;
const int VIN = A0; // define the Arduino pin A0 as voltage input (V in)
const float VCC = 9.0;// supply voltage
const int MODEL = 2;   // enter the model (see above list)
Robojax_AllegroACS_Current_Sensor robojax(MODEL,VIN);
String str; 

void setup() {
  Serial.begin(115200);
  s.begin(115200);
  pinMode(RelayPin, OUTPUT);
}

//StaticJsonBuffer<1000> jsonBuffer;
//JsonObject& root = jsonBuffer.createObject();

void loop() {
  float I = robojax.getCurrent();
  float P = VIN*I;

  digitalWrite(RelayPin, LOW);
  Serial.println(String("I = ") + I + " Amp"); 
  Serial.println(String("P = ") + P + " Watts"); 
  str = String("coming from arduino: ")+String("I = ")+String(I)+String("P = ")+String(P)+String(" Status = ")+String(OUTPUT);
  Serial.println(str);
  delay(1500);
  

  digitalWrite(RelayPin, HIGH);
  Serial.println(String("I = ") + I + " Amp"); 
  Serial.println(String("P = ") + P + " Watts"); 
  str = String("coming from arduino: ")+String("I = ")+String(I)+String(" P = ")+String(P)+String(" Status = ")+String(OUTPUT);
  Serial.println(str);
  delay(1500);
}

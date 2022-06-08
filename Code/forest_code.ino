/*
  Forest Protection final code
  Author: Environmental Defenders team
*/

#include <ESP8266WiFi.h>

//Initializations
//constants won't change
int buzzer = 4; //initialize digital pin 4 as "buzzer"
int smokePin = A0; //initialize analog pin 0 as "smokePin"
int tempPin = A1; //initialize analog pin 1 as "tempPin"
int voltPin = A2; //initialize analog pin 2 as "voltPin"

//The setup function runs once when you press reset or power the board
void setup() {
  pinMode(buzzer, OUTPUT); //initialize "buzzer" as an output
  pinMode(smokePin, INPUT); //initialize "smokePin" as an input
  pinMode(tempPin, INPUT); //initialize "tempPin" as an input
  pinMode(voltPin, INPUT); //initialize "voltPin" as an input
  
  //Wi-Fi connenction
  WiFi.begin("network-name", "pass-to-network");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  //We'll use the serial monitor to view sensors' output
  Serial.begin(9600);
}

//The loop function runs over and over again forever
void loop() {
  int tempValue = analogRead(tempPin); //read the value from temperature sensor
  float voltage = tempValue*(5.0/1024.0); //convert the value to voltage
  float celsius = voltage*50; //convert the voltage to celsius
  
  //Print the temperature
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" *C");
  Serial.println();
  
  delay(1000); //wait 1 sec

  int smoke = analogRead(smokePin); //read the value from smoke sensor

  //Print the smoke
  Serial.print("Smoke: ");
  Serial.println(smoke);
  
  // Checks if it has reached the threshold value
  if (smoke > 540 && celsius > 200)
  {
    tone(buzzer, 255); //send 0.225KHz sound signal
    delay(1000); //for 1 sec
    noTone(buzzer); //stop sound
    delay(100); //for 0.1 sec

    tone(buzzer, 255); //send 0.225KHz sound signal
    delay(1000); //for 1 sec
    noTone(buzzer); //stop sound
    delay(100); //for 0.1 sec

    tone(buzzer, 255); //send 0.225KHz sound signal
    delay(1000); //for 1 sec
    noTone(buzzer); //stop sound
    delay(100); //for 0.1 sec
    
    ////Print Alarm
    Serial.println("Alarm!!!");
  }
  else
  {
    noTone(buzzer);
  }
  
  delay(5000); //wait 5 sec
  
  //Calculating the battery charging voltage
  int volts = analogRead(voltPin);
  
  //Print the volts
  Serial.print("Volts: ");
  Serial.println(volts);
  
  float v12 = (volts*12.0)/1023; //convert the value of the analog measurement (0-1023) to volts (0-12)
  
  //Print the volts
  Serial.print("V12: ");
  Serial.println(v12);
  Serial.println("__________________________________________");
}

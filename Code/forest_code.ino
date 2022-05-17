int buzzer = 4;
int smokePin = A0;
int tempPin = A1;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokePin, INPUT);
  pinMode(tempPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int tempValue = analogRead(tempPin); 
  float voltage = tempValue*(5.0/1024.0);
  float celsius = voltage*50;
  
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" *C");
  Serial.println();
  
  delay(1000);

  int smoke = analogRead(smokePin);

  Serial.print("Smoke: ");
  Serial.println(smoke);
  
  // Checks if it has reached the threshold value
  if (smoke > 540 && celsius > 200) //540, 60
  {
    tone(buzzer, 255);
    delay(1000);
    noTone(buzzer);
    delay(100);

    tone(buzzer, 255);
    delay(1000);
    noTone(buzzer);
    delay(100);

    tone(buzzer, 255);
    delay(1000);
    noTone(buzzer);
    delay(100);
  }
  else
  {
    noTone(buzzer);
  }
  
  delay(5000);
}

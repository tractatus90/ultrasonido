#include <NewPing.h>

#define BUZZER_PIN 9
#define LED_PIN 10
NewPing mySensor(2,3,400);

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);  
  pinMode(LED_PIN, OUTPUT);

}

void loop() 
{
  int distance = mySensor.ping_cm();
  if (distance > 0 && distance < 50)
  {
    analogWrite(BUZZER_PIN, 50);
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);
    digitalWrite(LED_PIN, LOW);
  }
  delay(50);
}
#include <Arduino.h>
int outputPin = 13;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(115200);
}

void PWMTick(int pinNum, unsigned long freqensy, byte duty)
{
  static volatile unsigned long PWM_Timer = 0;
  static volatile byte counter = 0;

  if (micros() - PWM_Timer > freqensy)
  {
    if (counter < duty)
    {
      digitalWrite(outputPin, HIGH);
    }
    if (counter >= duty)
    {
      digitalWrite(outputPin, LOW);
    }
    counter++;
    if (counter == 11)
    {
      counter = 0;
    }

    PWM_Timer = micros();
  }
}

void loop()
{
  PWMTick(outputPin, 10000, 5);
}

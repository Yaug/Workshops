#include <wiringPi.h>

void reset()
{
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
}

main()
{
  wiringPiSetup();
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  
  reset();
  
  for(;;)
  {
      digitalWrite(2, HIGH); delay(5000);
      digitalWrite(2, LOW); delay(100);
      digitalWrite(1, HIGH); delay(1000);
      digitalWrite(1, LOW); delay(100);
      digitalWrite(0, HIGH); delay(5000);
      digitalWrite(0, LOW); delay(100);
  }
}
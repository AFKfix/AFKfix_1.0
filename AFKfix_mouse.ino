// Defeat for screensaver/lockscreen timeout
//
// Based on Digispark libraries: https://digistump.com/
// Moves mouse a sub-pixel amount then back again,
// so the OS doesn't lock the screen.

#include <DigiMouse.h>

byte LEDpin = PB0;


void setup() {

  DigiMouse.begin(); //start or reenumerate USB
}

void loop() {
  
  int MouseDirection = 0; //0,1,2,3 : N,E,S,W
 
  // If not using plentiful DigiMouse.delay(), make sure to call
  // DigiMouse.update() at least every 50ms
  MouseDirection = random(0, 4);
  
  if (MouseDirection == 0) 
  {
  DigiMouse.moveY(-1); //up 1
  DigiMouse.delay(50);
  DigiMouse.moveY(1); //put the mouse where it was
  DigiMouse.delay(50);
  }

if (MouseDirection == 1)
{
  DigiMouse.moveX(1); //right 1
  DigiMouse.delay(50);
  DigiMouse.moveX(-1); //put the mouse where it was
  DigiMouse.delay(50);
}

if (MouseDirection == 2)
{
  DigiMouse.moveY(1); //down 1
  DigiMouse.delay(50);
  DigiMouse.moveY(-1); //put the mouse where it was
  DigiMouse.delay(50);
}
  
if (MouseDirection == 3)
{
  DigiMouse.moveX(-1); //left 1
  DigiMouse.delay(50);
  DigiMouse.moveX(1); //put the mouse where it was
  DigiMouse.delay(50);
}


  pinMode(LEDpin, OUTPUT); //blink the LED so we know it's moved the mouse
  digitalWrite(LEDpin, HIGH); //Red
  DigiMouse.delay(50);
  digitalWrite(LEDpin, LOW);

  pinMode(LEDpin, INPUT); //high impedance, LED should be off

// wait a random time between 5 & 20s to do it again:
int WaitTime;
WaitTime = random(5000,20000);
DigiMouse.delay(WaitTime);

}

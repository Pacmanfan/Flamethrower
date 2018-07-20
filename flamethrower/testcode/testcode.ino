const int redLED= 5; //red LED connects to digital pin 2
//const int greenLED= 9; //green LED connects to digital pin 4
//const int blueLED= 14; //blue LED connects to digital pin 7

void setup()
{
//sets all LEDs as outputs
pinMode(redLED, OUTPUT); 
//pinMode(greenLED, OUTPUT); 
//pinMode(blueLED, OUTPUT); 
}

void loop()
{
digitalWrite(redLED,HIGH); //turns the LED on
delay(1000); //waits 3 seconds
digitalWrite(redLED, LOW); //turns off the red LED
delay(1000); //waits 3 seconds
/*
digitalWrite(greenLED,HIGH); //turns on the green LED
delay(3000); //waits 3 seconds
digitalWrite(greenLED, LOW); //turns green LED off
digitalWrite(blueLED, HIGH); //turns blue LED on 
delay(3000); //waits 3 seconds
digitalWrite(blueLED, LOW); //turns blue LED off
*/
}

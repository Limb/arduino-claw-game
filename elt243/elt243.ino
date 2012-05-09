#include <Servo.h> 
#include <LiquidCrystal.h>

Servo myservo;
Servo updownservo;
LiquidCrystal lcd(7,8,9,10,11,12);

int speed = 90;
boolean claw = false;
boolean running = false;

long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)
int count = 20;

void setup() 
{ 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
  myservo.write(90);
  updownservo.attach(5);
  updownservo.write(90);
  lcd.begin(16, 2);
  lcd.print("The Claw Game!");
  Serial.begin(19200);
  Serial.println("Ready");
} 
 
 
void loop() 
{
  if(running == false && analogRead(0) < 100)
  {
    running = true;
    count = 20;
  }
 while(running == true)
  { 
    if (Serial.available() > 0) {
      // Read a byte from the serial buffer.
      char incomingByte = (char)Serial.read();
      switch(incomingByte)
      {
        case 'r':
          speed = 93;
          break;
        case 'l':
          speed = 87;
          break;
        case 'o':
        if(claw == true)
        {
          Serial.println("opening claw");
          digitalWrite(3,LOW);
          digitalWrite(4,HIGH);
          delay(1200);
          digitalWrite(4,LOW);
          claw = false;
        }
          break;
        case 'c':
        if(claw == false) {
          Serial.print("closing claw");
          updownservo.write(85);
          delay(3500);
          updownservo.write(90);
          digitalWrite(4,LOW);
          digitalWrite(3,HIGH);
          delay(1200);
          digitalWrite(3,LOW);
          updownservo.write(95);
          delay(4200);
          updownservo.write(90);
          claw = true; 
        }
          break;
        case 's':
           speed = 90;
           break; 
        default:
          speed = 90;
          break;
      }
      Serial.print("Speed: ");
      Serial.println(speed);
    }
    else {
      speed = 90;
    }
    myservo.write(speed);
    
    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;
      count -= 1;
      lcd.setCursor(0, 1);
      lcd.print("               ");
      lcd.setCursor(0, 1);
      lcd.print("Time Left: ");
      lcd.print(count);
    }
    if(count == 0)
    {
      running = false;
      myservo.write(90);
      lcd.setCursor(0, 1);
      lcd.print("               ");
      lcd.setCursor(0,1);
      lcd.print("Game over!");
    }
    
    delay(50);
  }
} 

#define RED_LED 5
#define GREEN_LED 13
#define BLUE_LED 3
#define YELLOW_LED 10
#define BLUE_BUTTON 2
#define RED_BUTTON 6
#define YELLOW_BUTTON 9
#define GREEN_BUTTON 12
#define PIEZO_PIN 4

void setup() {
  Serial.begin(19200);
  pinMode(RED_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(RED_BUTTON, HIGH);
  digitalWrite(GREEN_BUTTON, HIGH);
  digitalWrite(BLUE_BUTTON, HIGH);
  digitalWrite(YELLOW_BUTTON, HIGH);
}

void loop() {

  if(digitalRead(RED_BUTTON) == LOW)
  {
    digitalWrite(RED_LED, LOW);
    Serial.print("r");
  }
  else
    digitalWrite(RED_LED, HIGH);
  if(digitalRead(GREEN_BUTTON) == LOW)
  {
    digitalWrite(GREEN_LED, LOW);
    Serial.print("c");
  }
  else
    digitalWrite(GREEN_LED, HIGH);
  if(digitalRead(BLUE_BUTTON) == LOW)
  {
    digitalWrite(BLUE_LED, LOW);
    Serial.print("l");
  }
  else
    digitalWrite(BLUE_LED, HIGH);
  if(digitalRead(YELLOW_BUTTON) == LOW)
  {
    digitalWrite(YELLOW_LED, LOW);
    Serial.print("o");
  }
  else
    digitalWrite(YELLOW_LED, HIGH);

  delay(50);
}


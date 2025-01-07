const int RLed = 13;
const int YLed = 12;
const int GLed = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(RLed, OUTPUT);
  pinMode(YLed, OUTPUT);
  pinMode(GLed, OUTPUT);

  digitalWrite(RLed, HIGH);
  digitalWrite(YLed, HIGH);
  digitalWrite(GLed, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RLed, LOW);
  delay(500);
  digitalWrite(RLed, HIGH);
  delay(500);

  digitalWrite(YLed, LOW);
  delay(500);
  digitalWrite(YLed, HIGH);
  delay(500);

  digitalWrite(GLed, LOW);
  delay(500);
  digitalWrite(GLed, HIGH);
  delay(500);
}

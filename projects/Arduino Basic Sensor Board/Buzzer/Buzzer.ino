const int buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzer, HIGH);
  delay(500);

  digitalWrite(buzzer, LOW);
  delay(1000);
}

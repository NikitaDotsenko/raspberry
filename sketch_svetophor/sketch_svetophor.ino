const int pinRed = 12;
const int pinYellow = 11;
const int pinGreen = 10;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen, OUTPUT);
}

void loop() {
  digitalWrite(pinRed, HIGH);
    digitalWrite(pinYellow, LOW);
  digitalWrite(pinGreen, LOW);
    delay(1500);
  digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, HIGH);
  digitalWrite(pinGreen, LOW);
    delay(1500);

  digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
  digitalWrite(pinGreen, HIGH);
    delay(1500);

  digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, HIGH);
  digitalWrite(pinGreen, LOW);
    delay(1500);
}

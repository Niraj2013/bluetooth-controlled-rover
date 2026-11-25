char Bluetooth = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
void Forward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void Backward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Left() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Right() {
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void Stop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9, 150);
  analogWrite(10, 150);

  if (Serial.available()) {
    Bluetooth = Serial.read();

    Serial.print("I recieved - ");
    Serial.println(Bluetooth);
    if (Bluetooth == 'F') {
      Forward();
      delay(1000);
      Stop();
    } else if (Bluetooth == 'B') {
      Backward();
      delay(1000);
      Stop();
    } else if (Bluetooth == 'R') {
      Right();
      delay(1000);
      Stop();
    } else if (Bluetooth == 'L') {
      Left();
      delay(1000);
      Stop();
    } else if (Bluetooth == 'S') {
      Stop();
    }
  }
}
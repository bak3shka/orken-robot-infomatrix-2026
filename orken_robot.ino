int b_niz = 27;
int b_verh = 34;

int leftMotor1 = 4;
int leftMotor2 = 5;
int rightMotor1 = 2;
int rightMotor2 = 3;

int spinMotor1 = 6;
int spinMotor2 = 7;

int liftMotor1 = 9;
int liftMotor2 = 8;

int nasos1 = 10;
int nasos2 = 11;

int laser = 42;
int photo = A0;
int v_photo = 0;

int soilMoisturePin = A1;
int soilMoistureValue = 0;
int moistureThreshold = 400;

int v_b_niz = 0;
int v_b_verh = 0;

void setup() {
  pinMode(b_niz, INPUT);
  pinMode(b_verh, INPUT);
  pinMode(photo, INPUT);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);

  pinMode(spinMotor1, OUTPUT);
  pinMode(spinMotor2, OUTPUT);

  pinMode(liftMotor1, OUTPUT);
  pinMode(liftMotor2, OUTPUT);

  pinMode(nasos1, OUTPUT);
  pinMode(nasos2, OUTPUT);

  pinMode(laser, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  forward();
  delay(500);
  stopp();

  soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(soilMoistureValue);

 if (soilMoistureValue < moistureThreshold) {
    Serial.println("Soil is Dry. Watering the plant...");
    nasos(); 
  } else {
    Serial.println("Soil is Wet. No need to water.");
  }

  delay(1000);
  tpyba_niz();
  delay(500);
  plant();
  nasos();
  delay(2000);

  digitalWrite(nasos1, LOW);
  digitalWrite(nasos2, LOW);
  delay(1000);
  tpyba_verh();
  forward();
  delay(500);
}

void plant() {
  digitalWrite(laser, HIGH);
  v_photo = analogRead(photo);
  while (v_photo > 900) {
    v_photo = analogRead(photo);
    analogWrite(spinMotor1, 0);
    analogWrite(spinMotor2, 100);
  }
  analogWrite(spinMotor1, 0);
  analogWrite(spinMotor2, 0);
  digitalWrite(laser, LOW);
}

void nasos() {
  analogWrite(nasos1, 200);
  analogWrite(nasos2, 0);
}

void tpyba_niz() {
  v_b_niz = digitalRead(b_niz);
  while (v_b_niz == 0) {
    v_b_niz = digitalRead(b_niz);
    analogWrite(liftMotor1, 0);
    analogWrite(liftMotor2, 200);
  }
  analogWrite(liftMotor1, 0);
  analogWrite(liftMotor2, 0);
}

void tpyba_verh() {
  v_b_verh = digitalRead(b_verh);
  while (v_b_verh == 0) {
    v_b_verh = digitalRead(b_verh);
    analogWrite(liftMotor1, 200);
    analogWrite(liftMotor2, 0);
  }
  analogWrite(liftMotor1, 0);
  analogWrite(liftMotor2, 0);
}

void forward() {
  analogWrite(leftMotor1, 150);
  analogWrite(leftMotor2, 0);
  analogWrite(rightMotor1, 150);
  analogWrite(rightMotor2, 0);
}

void back() {
  analogWrite(leftMotor1, 0);
  analogWrite(leftMotor2, 150);
  analogWrite(rightMotor1, 0);
  analogWrite(rightMotor2, 150);
}

void turnLeft() {
  analogWrite(leftMotor1, 0);
  analogWrite(leftMotor2, 200);
  analogWrite(rightMotor1, 200);
  analogWrite(rightMotor2, 0);
}

void turnRight() {
  analogWrite(leftMotor1, 200);
  analogWrite(leftMotor2, 0);
  analogWrite(rightMotor1, 0);
  analogWrite(rightMotor2, 200);
}

void stopp() {
  analogWrite(leftMotor1, 0);
  analogWrite(leftMotor2, 0);
  analogWrite(rightMotor1, 0);
  analogWrite(rightMotor2, 0);
}

const int L = 2;
const int C = 3;
const int R = 4;

const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;

const int ENB = 10;
const int IN3 = 8;
const int IN4 = 9;

const int spd = 180;

void setup() {
  pinMode(L, INPUT);
  pinMode(C, INPUT);
  pinMode(R, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int left = digitalRead(L);
  int center = digitalRead(C);
  int right = digitalRead(R);

  if (center == LOW && left == HIGH && right == HIGH) {
    move(spd, spd);
  } else if (left == LOW) {
    move(spd / 2, spd);
  } else if (right == LOW) {
    move(spd, spd / 2);
  } else {
    move(0, 0);
  }
}

void move(int ls, int rs) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, ls);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, rs);
}

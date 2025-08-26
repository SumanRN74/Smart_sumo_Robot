#define ENA 9     // Enable pin for Left Motor (PWM)
#define IN1 8     // Motor A input 1
#define IN2 7     // Motor A input 2
#define ENB 10    // Enable pin for Right Motor (PWM)
#define IN3 6     // Motor B input 1
#define IN4 5     // Motor B input 2

#define trigPin 3
#define echoPin 2
#define led1 13   // Power indicator LED

long duration;
int distance;

int motorSpeed = 255;  //  Adjust motor speed (0–255)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(led1, HIGH);  // LED ON when bot is powered
}

void loop() {
  distance = getDistance();

  if (distance > 0 && distance < 50) {
    //  Opponent detected → Move forward to push
    forward();
  } else {
    //  No opponent → Rotate right slightly, move forward 5cm, repeat
    rotateRight();
    delay(400);  
    forward();
    delay(300);
    stopMotors();
  }
}

// ---------------- MOTOR FUNCTIONS ----------------
void forward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);  // Right motor forward
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);   // Left motor backward
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);   // Right motor backward
  digitalWrite(IN4, HIGH);
}

void rotateRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);   // Right motor backward
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ---------------- ULTRASONIC FUNCTION ----------------
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // Timeout 30ms
  if (duration == 0) return -1;  // No echo detected

  int dist = duration * 0.034 / 2;
  return dist;
}

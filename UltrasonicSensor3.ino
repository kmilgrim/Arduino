// Kira Milgrim, June 2020
// This code is written to program a device that will detect obstacles 
// and alert a blind person upon approach.

// This project was completed for the summer 1 session of EK210

#define trigPin 8
#define echoPin 9
#define buzzer 10

long duration;
float distanceInch;
int timer;

void setup() {
  // assign the devices to pins and define them as input or output pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  
}

void loop() {
  // set up the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // extracting the information gathered by the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);

  // convert the duration of time reported by the sensor into a disntance (inches)
  //using the speed of light 0.0133
  distanceInch = duration * 0.0133 / 2;

  digitalWrite(buzzer, HIGH);
  // using delay(1) to make the buzzer sound more like a tick.
  delay(1);
  digitalWrite(buzzer, LOW);

  timer = distanceInch;

  // when the distance becomes shorter, so will the length of time between ticks.
  delay(timer);
}

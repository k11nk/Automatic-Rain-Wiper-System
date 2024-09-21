#include <Servo.h>

Servo myservo;
int pos = 0;
const int threshold = 570; // Define the threshold as a constant

void setup() {
  myservo.attach(9);
}

void loop() {
  int sensorValue = analogRead(A0);
  
  if (sensorValue > threshold) {
    // Sweep the servo from 0 to 160 degrees and back
    for (pos = 0; pos <= 160; pos += 1) {
      myservo.write(pos);
      delay(7); // Delay for a smoother sweep
    }
    for (pos = 160; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(7);
    }
  } else {
    myservo.write(15); // Move to a fixed position if below threshold
  }
}

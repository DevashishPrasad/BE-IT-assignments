#include <Servo.h>

int position = 0;

int i = 0;

int j = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

}

void loop()
{
  position = 0;
  for (position = 1; position <= 179; position += 1) {
    servo_9.write(position);
    delay(20); // Wait for 20 millisecond(s)
  }
  for (position = 179; position >= 1; position -= 1) {
    servo_9.write(position);
  }
}
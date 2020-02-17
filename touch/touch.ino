#define red 9
#define green 10
#define blue 11
int t = 500;

const int SENSOR_PIN = 7;

int lastState = LOW;
int currentState;

int p = 2000;
int light = 0;

int r, g, b;

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop()
{
  currentState = digitalRead(SENSOR_PIN);
  if (lastState == LOW && currentState == HIGH) {
    light = 1;
    randomSeed(random(64));
    r =  random(64)*4 - 1;
    g =  random(64)*4 - 1;
    b =  random(64)*4 - 1;
    analogWrite(red, r);
    analogWrite(blue, b);
    analogWrite(green, g);
    p = 2000;
    delay(t);
  }

  lastState = currentState;
  if (light == 1) {
    p--;
    delay(1);
    if (p == 0) {
      analogWrite(red, 0);
      analogWrite(blue, 0);
      analogWrite(green, 0);
      light = 0;
    }
  }
}

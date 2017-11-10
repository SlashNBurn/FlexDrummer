
static const int sensorPinThumb = A0;
static const int sensorPinIndex = A1;
static const int sensorPinMiddle = A2;
static const int sensorPinRing = A3;
static const int sensorPinPinky = A4;

const char outputValueThumb = 'H';
const char outputValueIndex = 'K';
const char outputValueMiddle = 'S';
const char outputValueRing = 'T';
const char outputValuePinky = 'R';

int sensorValueThumb;
int sensorValueIndex;
int sensorValueMiddle;
int sensorValueRing;
int sensorValuePinky;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  detectMovement(sensorValueThumb, sensorPinThumb, outputValueThumb);
  detectMovement(sensorValueIndex, sensorPinIndex, outputValueIndex);
  detectMovement(sensorValueMiddle, sensorPinMiddle, outputValueMiddle);
  detectMovement(sensorValueRing, sensorPinRing, outputValueRing);
  detectMovement(sensorValuePinky, sensorPinPinky, outputValuePinky);
} 

void detectMovement(int sensorValue, int sensorPin, char outputValue) {
  sensorValue = analogRead(sensorPin);
  Serial.print(outputValue);Serial.println(sensorValue);
}


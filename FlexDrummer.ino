/*
 * FlexDrummer
 * Contributor - Amogh Matt
 * 
 * Reads 5 analog input on pins 0,1,2,3,4, and sends the result to the serial monitor.
 * Connect the Flex sensorPin to the +5V and Ground and read the sensorValue from the positive terminal.
 * 
 */
// Declaring the sensorPins
static const int sensorPinThumb = A0;
static const int sensorPinIndex = A1;
static const int sensorPinMiddle = A2;
static const int sensorPinRing = A3;
static const int sensorPinPinky = A4;

/* Declaring the code for each finger.
 *  
 *  H - Hihat
 *  K - Kick
 *  S - Snare
 *  T - Floor Toms
 *  R - Ride/Cymbal
 */
const char outputValueThumb = 'H';
const char outputValueIndex = 'K';
const char outputValueMiddle = 'S';
const char outputValueRing = 'T';
const char outputValuePinky = 'R';

// Declaring variables for reading the sensor values.
int sensorValueThumb;
int sensorValueIndex;
int sensorValueMiddle;
int sensorValueRing;
int sensorValuePinky;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}


void loop() {

  // Call detectMovement for each finger.
  detectMovement(sensorValueThumb, sensorPinThumb, outputValueThumb);
  detectMovement(sensorValueIndex, sensorPinIndex, outputValueIndex);
  detectMovement(sensorValueMiddle, sensorPinMiddle, outputValueMiddle);
  detectMovement(sensorValueRing, sensorPinRing, outputValueRing);
  detectMovement(sensorValuePinky, sensorPinPinky, outputValuePinky);
} 

// Function to read the sensorValue and output it onto the serial port. 
// Along with the code for the finger.
void detectMovement(int sensorValue, int sensorPin, char outputValue) {
  sensorValue = analogRead(sensorPin);
  Serial.print(outputValue);Serial.println(sensorValue);
}


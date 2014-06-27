//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;  
// The time the device will stay on
int delayTime = 5000;

int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int relayPin = 3;
int pirState = LOW;             // we start, assuming no motion detected
int stateRelay = HIGH;
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(relayPin, OUTPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
  digitalWrite(relayPin, stateRelay);
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  //Serial.println(val);
  if (val == HIGH) { // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    delay(150);    
    
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    delay(300);    
      if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
  Serial.println(pirState);
  if(pirState == HIGH){
     digitalWrite(relayPin, LOW);
     delay(delayTime);
  } else {
     digitalWrite(relayPin, HIGH);
  }
}


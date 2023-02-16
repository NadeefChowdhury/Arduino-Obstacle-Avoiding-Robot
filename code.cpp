// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
//sensor pins
int trig_pin = A1; //analog input 1
int echo_pin = A2; //analog input 2


long duration, distance;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	// Set all the sensor pins to input
  	pinMode(trig_pin, OUTPUT);
	pinMode(echo_pin, INPUT);
	
  	delay(150);
}

void loop() {
  digitalWrite(trig_pin, LOW);

  delayMicroseconds(2);   

  digitalWrite(trig_pin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echo_pin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance

  delay(10);

  if(distance >= 19){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else{
    digitalWrite(in1, LOW); // Stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(1000);
    
    digitalWrite(in1, HIGH); // Turn Right
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);
    digitalWrite(in1, LOW); // Stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(1000);
    digitalWrite(in1, HIGH); // Move Forward
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
}




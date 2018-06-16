
int motor1_forward = D0;
int motor1_backward = D1;

int motor2_left = D2;
int motor2_right = D3;

int carSpeed = 70;

int cmd;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motor1_forward, OUTPUT);
  pinMode(motor1_backward, OUTPUT);
  pinMode(motor2_left, OUTPUT);
  pinMode(motor2_right, OUTPUT);

	Serial.begin(38400);

	
}


void loop() {
  if (Serial.available()){
    cmd = Serial.read();
    switch (cmd){
      case 'W' : {
        car_start();
        break;  
      }
      case 'S' : {
        car_stop();
        break;  
      }
      case 'A' : {
        turn_left();
        break;  
      }
      case 'D' : {
        turn_left();
        break;  
      }
      case 'Q' : {
        accelerate();
        break;  
      }
      case 'E' : {
        decelerate();
        break;  
      }
    }
  }
}

void turn_right() {
	digitalWrite(motor2_right, HIGH);
  	delay(500);
  	digitalWrite(motor2_right, LOW);
}

void turn_left() {
	digitalWrite(motor2_left, HIGH);
  	delay(500);
  	digitalWrite(motor2_left, LOW);
}

void car_start() {
	analogWrite(motor1_forward, carSpeed);	
}

void car_stop() {
	analogWrite(motor1_forward, 0);	
	analogWrite(motor1_backward, 0);	
}

void accelerate() {
	if (carSpeed < 255) {
		carSpeed += 10;
	}
}

void decelerate() {
	carSpeed -= 10;
	if (carSpeed < 0) {
		carSpeed = 0;
	}
}

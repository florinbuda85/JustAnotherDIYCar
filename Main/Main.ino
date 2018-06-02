
int motor1_forward = D0;
int motor1_backward = D1;

int motor2_left = D2;
int motor2_right = D3;

int carSpeed = 70;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motor1_forward, OUTPUT);
  pinMode(motor1_backward, OUTPUT);
  pinMode(motor2_left, OUTPUT);
  pinMode(motor2_right, OUTPUT);
}


void loop() {
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
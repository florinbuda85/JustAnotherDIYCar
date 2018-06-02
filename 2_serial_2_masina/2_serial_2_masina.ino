
int m1_f = D0;
int m1_s = D1;

int m2_f = D2;
int m2_s = D3;

int cmd;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(m1_f, OUTPUT);
  pinMode(m1_s, OUTPUT);
  pinMode(m2_f, OUTPUT);
  pinMode(m2_s, OUTPUT);

  Serial.begin(38400);
}



void loop() {
    if (Serial.available()){
      
    
  cmd = Serial.read(); 



  switch (cmd){
    
    case 'W' : {
      motor2_go();
      break;  
      }

    case 'S' : {
      motor2_stop();
      break;  
      }

    case 'A' : {
      turn_left();
      break;  
      }

    case 'D' : {
      turn_right();
      break;  
      }

      
    }
  }
}

void motor2_go() {
  digitalWrite(m1_f, HIGH);
}

void motor2_stop() {
  digitalWrite(m1_f, LOW);
}



void turn_left() {
  digitalWrite(m2_f, HIGH);
  delay(500);
  digitalWrite(m2_f, LOW);
}

void turn_right() {
  digitalWrite(m2_s, HIGH);
  delay(500);
  digitalWrite(m2_s, LOW);
}


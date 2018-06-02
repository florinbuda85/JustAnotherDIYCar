
int m1_f = D0;
int m1_s = D1;

int m2_f = D2;
int m2_s = D3;

int cmd;

int cspeed = 255;

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
    
    case 'Q' : {
      speed_minus();
      break;  
      }

    case 'E' : {
      speed_plus();
      break;  
      }

    case 'W' : {
      motor2_go();
      break;  
      }

    case 'S' : {
      motor2_stop();
      break;  
      }
      
    }
  }
}

void speed_minus() {
  cspeed = cspeed - 20;
}

void speed_plus() {
  cspeed = cspeed + 20;
}

void motor2_go() {
  analogWrite(m1_f, cspeed);
}

void motor2_stop() {
  analogWrite(m1_f, 0);
}




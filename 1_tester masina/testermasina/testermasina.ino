
int m1_f = D0;
int m1_s = D1;

int m2_f = D2;
int m2_s = D3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(m1_f, OUTPUT);
  pinMode(m1_s, OUTPUT);
  pinMode(m2_f, OUTPUT);
  pinMode(m2_s, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(m1_f, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(m1_f, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(m1_s, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(m1_s, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(m2_f, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(m2_f, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(m2_s, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(m2_s, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
}

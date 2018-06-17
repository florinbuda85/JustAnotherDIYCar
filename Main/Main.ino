#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid     = "virus33";
const char* password = "testtest";  

WiFiClient client;

ESP8266WebServer server(80);

void handleRoot();              // function prototypes for HTTP handlers
void handleForward();
void handleStop();
void handleAccelerate();
void handleDecelerate();
void handleTurnRight();
void handleTurnLeft();
void handleNotFound();


int motor1_forward = D0;
int motor1_backward = D1;

int motor2_left = D2;
int motor2_right = D3;

int carSpeed = 250;
int maxSpeed = 1023;

void setup() {

  Serial.begin(115200);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motor1_forward, OUTPUT);
  pinMode(motor1_backward, OUTPUT);
  pinMode(motor2_left, OUTPUT);
  pinMode(motor2_right, OUTPUT);


  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  server.on("/", HTTP_GET, handleRoot); 
  server.on("/W", HTTP_GET, handleForward); 
  server.on("/S", HTTP_GET, handleStop); 
  server.on("/Q", HTTP_GET, handleAccelerate); 
  server.on("/E", HTTP_GET, handleDecelerate); 
  server.on("/D", HTTP_GET, handleTurnRight); 
  server.on("/A", HTTP_GET, handleTurnLeft); 
  server.begin();
  
}

void handleRoot() {
  server.send(200, "text/html", "" + String(carSpeed));
}

void handleForward() {
  car_forward();
  server.sendHeader("Location","/");
  server.send(303);
  //server.send(200, "text/html", "" + String(carSpeed));
}

void handleStop() {
  car_stop();
  server.sendHeader("Location","/");
  server.send(303); 
}

void handleAccelerate() {
  accelerate();
  server.sendHeader("Location","/");
  server.send(303); 
}

void handleDecelerate() {
  decelerate();
  server.sendHeader("Location","/");
  server.send(303); 
}

void handleTurnRight() {
  turn_right();
  server.sendHeader("Location","/");
  server.send(303); 
}

void handleTurnLeft() {
  turn_left();
  server.sendHeader("Location","/");
  server.send(303); 
}

void loop() {
  server.handleClient();
}

void turn_right() {
  digitalWrite(motor2_right, HIGH);
  delay(700);
  digitalWrite(motor2_right, LOW);
}

void turn_left() {
	digitalWrite(motor2_left, HIGH);
  delay(700);
  digitalWrite(motor2_left, LOW);
}

void car_forward() {
	analogWrite(motor1_forward, carSpeed);	
  //digitalWrite(motor1_forward, 1);  
  Serial.println(carSpeed);
}

void car_stop() {
	analogWrite(motor1_forward, 0);	
	analogWrite(motor1_backward, 0);	
}

void accelerate() {
  carSpeed += 50;
	if (carSpeed > maxSpeed) {
		carSpeed = maxSpeed;
	}
 car_forward();
}

void decelerate() {
	carSpeed -= 5;
	if (carSpeed < 50) {
		carSpeed = 0;
	}
 car_forward();
}

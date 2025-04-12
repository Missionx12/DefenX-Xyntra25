#include <SoftwareSerial.h>

SoftwareSerial sim(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  sim.begin(9600);
 
  sim.write("AT+CSCS=\"GSM\"\r");
  delay(3000);// give time for GSM module to register on network.
  sim.println("AT+CMGF=1\r"); // set SMS mode to text
  delay(200);
  sim.println("AT+CNMI=2,2,0,0,0\r");
}

void loop() {

}

#include <SoftwareSerial.h>

SoftwareSerial sim(2, 3); // RX, TX

const int relay= 4;
const int buzzer=8;
int n=0;

void setup() {
  Serial.begin(9600);
  sim.begin(9600);

  pinMode(button, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  sim.write("AT+CSCS=\"GSM\"\r");
  delay(3000);// give time for GSM module to register on network.
  sim.println("AT+CMGF=1\r"); // set SMS mode to text
  delay(200);
  sim.println("AT+CNMI=2,2,0,0,0\r");
}

void loop() {
  state1=digitalRead(button);
  if(state1==LOW && n==0){
    Serial.print("Alert send");
    digitalWrite(relay, HIGH);
    sim.println("AT");
    delay(100);
    sim.println("AT+CSMP=17,167,0,0");
    delay(100);
    sim.println("AT+CSCA?");
    delay(100);
    sim.println("AT+CMGF=1");
    delay(100);
    sim.println("AT+CMGS=\"+919042824227\"");
    delay(100);
    sim.println("i need help."); 
    
                    delay(100);
                    sim.println((char)26);
                    delay(100);
                    sim.println();
                    delay(1000);
                    
                   digitalWrite(buzzer, HIGH);
                   delay(100);
                   
                    sim.println("AT");
    delay(1000);
                    //sim.println("ATH");
  delay(1000);

    // Dial num
  sim.println("ATD+919042824227;"); // The ';' is important for calling
  Serial.println("Calling...");
  delay(15000); // Wait 10 secs
  sim.println("ATH");
     n=1;
     digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(relay, LOW);
  }
}

#define ONBOARD_LED 2

int val = 0;

void setup() {
  pinMode(ONBOARD_LED,OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  /*
  // put your main code here, to run repeatedly:
  val = hallRead();


  // print the results to the serial monitor:
  //Serial.print("sensor = ");
  Serial.println(val);  //to graph
  */

  delay(100);
  digitalWrite(ONBOARD_LED,LOW);
  delay(100);
  digitalWrite(ONBOARD_LED,HIGH);

}
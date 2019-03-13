//variables related to ultrasonic sensor
int trigger=2;
int echo=3;
int intruderBuzzer=12;
const unsigned long duration=0;
int distance=0;


const unsigned int BAUD_RATE=9600;

void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(intruderBuzzer, INPUT);

Serial.begin(BAUD_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigger,HIGH);
  delay(1000);
  digitalWrite(trigger, LOW);

  duration=pulseIn(echo,HIGH);
  distance=(duration/2)/29.1;
  Serial.print("cm = ");
  Serial.print(distance);
  if (Distance<50)
  {
   digitalWrite(intruderBuzzer,HIGH);
   delay(1000);
  }
 else 
 digitalWrite(intruderBuzzer,LOW);

 delay(200);

}

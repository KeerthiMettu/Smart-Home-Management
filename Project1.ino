//variables related to ultrasonic sensor
int trigger=2;
int echo=3;
int intruderBuzzer=12;
unsigned long duration;
int distance=0;
int entranceHeight=180; //180 cms


const unsigned int BAUD_RATE=9600;

void setup() {
  // put your setup code here, to run once:
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(intruderBuzzer, OUTPUT);

Serial.begin(BAUD_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigger,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);

  duration=pulseIn(echo,HIGH);
  if(duration==0)
  {
    Serial.println("Warning from Ultrasonic sensor");
  }
  distance=(duration/2)/29.1;
  Serial.print("cm = ");
  Serial.println(distance);
  if (distance<140)
  {
   digitalWrite(intruderBuzzer,HIGH);
   Serial.print(entranceHeight-distance);
   Serial.println("- this is intruder height");
   delay(10);
  }
 else 
 digitalWrite(intruderBuzzer,LOW);
 delay(20);

}

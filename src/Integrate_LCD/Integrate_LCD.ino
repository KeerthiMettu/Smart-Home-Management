#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Adafruit_Fingerprint.h>
#include <dht.h>

LiquidCrystal lcd(0, 1, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

SoftwareSerial mySerial(2, 3); //ports utilized by fingerprint sensor

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

dht DHT;

#define DHT11_PIN 11

//variables related to ultrasonic sensor
int trigger = 8;
int echo = 9;
int Buzzer = 10;
unsigned long duration;
int distance = 0;
int entranceHeight = 180; //180 cms
int intruderHeight = 0;

//variables related to flame sensor
int flame_sensor = A0;
int flame_detected;
int thresholdValue=700;

int reading = 0;
int idleFlag = 1;

//RGB LED variables
int redPin = A5;
int greenPin = A4;
int bluePin = A3;
int turnOffLED=0;

//IR sensor related variables
const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display }
  // Serial.begin(9600);
  irrecv.enableIRIn();

  finger.begin(57600);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(flame_sensor, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}


void loop() {
  flame_detected = analogRead(flame_sensor);
  //if flame sensor detects signals
  if (flame_detected > thresholdValue)
  {
    FireAlarm();
   flame_detected = 0;
  }
  else
  {
    digitalWrite(Buzzer, LOW);
  }

  //if IR sensor detects signals
  if (irrecv.decode(&results)) {
    idleFlag = 0;
    // Serial.println(results.value, HEX);
    irrecv.resume();
    lcd.clear();
    //lcd.print(results.value);
    translateIR(results.value);
    lcd.clear();
  }
  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  //when the ultrasonic sensor is non functional
  if (duration == 0)
  {
    lcd.clear();
    lcd.print("Warning-Ultrasonic sensor");
    delay(2000);
    //idleFlag=0;
  }
  distance = (duration / 2) / 29.1;
  if (distance < 100)
  {
    IntruderAlarmBuzzer();
  }
  else
  {
    digitalWrite(Buzzer, LOW);
    idleFlag = 1;
  }
  delay(200);
  lcd.clear();

  if (idleFlag)
  {
    systemIdle();
  }
  //glow white colour in RGB LED when normal
  if(turnOffLED==0)
  {
      setLEDColor(255, 255, 255);
  }
  else
  {
    TurnOffRGB();
  }
  
}
//fire detection module
void FireAlarm()
{
  //Serial.println("Flame detected...! take action immediately.");
  digitalWrite(Buzzer, HIGH);
  lcd.clear();
  lcd.print("Fire detected");
  lcd.setCursor(0, 1);
  lcd.print("Run to safe zone");
  delay(1000);
  //glow red colour in RGB LED
  setLEDColor(0, 0, 255);
  idleFlag = 1;
}

// user intrusion detection module
void IntruderAlarmBuzzer()
{
    digitalWrite(Buzzer, HIGH);
    intruderHeight = entranceHeight - distance;
    lcd.clear();
    lcd.print("intruder entered");
    lcd.setCursor(0, 1);
    lcd.print("Height: ");
    lcd.print(intruderHeight);
    delay(500);
    //glow blue colour in RGB LED
    
    setLEDColor(255, 0, 0);
}


//this method should be called only when other sensors are not working
void systemIdle()
{
  reading = DHT.read11(DHT11_PIN);

  lcd.print("Temp= "); // Prints "Arduino" on the LCD
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1500); // 2 seconds delay
  //lcd.clear();
}

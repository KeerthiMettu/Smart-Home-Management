#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Adafruit_Fingerprint.h>
#include <dht.h>

LiquidCrystal lcd(0, 1, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

dht DHT;

#define DHT11_PIN 11

//variables related to ultrasonic sensor
int trigger = 8;
int echo = 9;
int intruderBuzzer = 10;
unsigned long duration;
int distance = 0;
int entranceHeight = 180; //180 cms
int intruderHeight = 0;

int flame_sensor = A0;
int flame_detected;

int reading = 0;
int idleFlag = 1;

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
  pinMode(intruderBuzzer, OUTPUT);
  pinMode(flame_sensor, INPUT);

}


void loop() {
  flame_detected = analogRead(flame_sensor);
  //if flame sensor detects signals
  if (flame_detected == 1)
  {
    FireAlarm();
    flame_detected = 0;
  }
  else
  {
    digitalWrite(intruderBuzzer, LOW);
    //    digitalWrite(buzzer, LOW);
    //    digitalWrite(LED, LOW);
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
  if (duration == 0)
  {
    //Serial.println("Warning from Ultrasonic sensor");
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
    digitalWrite(intruderBuzzer, LOW);
    idleFlag = 1;
  }
  delay(200);
  lcd.clear();

  if (idleFlag)
  {
    systemIdle();
  }
}

void FireAlarm()
{
  //Serial.println("Flame detected...! take action immediately.");
  digitalWrite(intruderBuzzer, HIGH);
  lcd.clear();
  lcd.print("Fire detected");
  lcd.setCursor(0, 1);
  lcd.print("Run to safe zone");
  delay(2000);
  //    digitalWrite(LED, HIGH);
  //    delay(200);
  //    digitalWrite(LED, LOW);
  //    delay(200);
  idleFlag = 1;
}

void IntruderAlarmBuzzer()
{
  //while (distance < 50)
  {
    digitalWrite(intruderBuzzer, HIGH);
    intruderHeight = entranceHeight - distance;
    lcd.clear();
    lcd.print("intruder entered");
    lcd.setCursor(0, 1);
    lcd.print("Height: ");
    lcd.print(intruderHeight);
    delay(1000);
    //digitalWrite(intruderBuzzer, HIGH);
  }
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
  delay(2000); // 2 seconds delay
  lcd.clear();
}

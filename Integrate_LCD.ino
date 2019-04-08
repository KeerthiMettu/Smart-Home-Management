#include <LiquidCrystal.h>
#include <IRremote.h>
#include <dht.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
dht DHT;

#define DHT11_PIN 11

#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232
#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

//variables related to ultrasonic sensor
int trigger = 8;
int echo = 9;
int intruderBuzzer = 10;
unsigned long duration;
int distance = 0;
int entranceHeight = 180; //180 cms
int intruderHeight = 0;

int flame_sensor = 3;
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

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(intruderBuzzer, OUTPUT);
  pinMode(flame_sensor, INPUT);

}


void loop() {
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
    FireAlarm();
  }
  else
  {
    Serial.println("No flame detected. stay cool");
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
    //idleFlag=1;
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
  //    digitalWrite(LED, HIGH);
  //    delay(200);
  //    digitalWrite(LED, LOW);
  //    delay(200);
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

void translateIR(long value)
{
  //lcd.print("Pressed key is");
  lcd.setCursor(2, 1);
  delay(1000);
  switch (value)
  {
    case 16753245:
      lcd.print("CH-");
      break;
    case 16736925:
      //lcd.print("CH");
      {
        lcd.clear();
        lcd.print("Loading.");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.clear();
        lcd.print("Press Play");
      }
      break;
    case 16769565:
      lcd.print("CH+");
      break;
    case 16720605:
      lcd.print("PREV");
      break;
    case 16712445:
      lcd.print("NEXT");
      break;
    case 16761405:
      // lcd.print("PLAY/PAUSE");
      {
        lcd.clear();
        lcd.print("Select Song");
        lcd.setCursor(0, 1);
        lcd.print("+:Song List");
      }
      break;
    case 16769055:
      lcd.print("VOL-");
      break;
    case 16754775:
      //lcd.print("VOL+");
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Smoke On The Water: 1   Jingle Bells: 2");
        for (int positionCounter = 0; positionCounter < 64; positionCounter++)
        {
          lcd.scrollDisplayLeft();
          delay(300);
        }
      }
      break;

    case 16748655:
      //lcd.print("EQ");
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Exiting the music track");
        for (int positionCounter = 0; positionCounter < 25; positionCounter++)
        {
          lcd.scrollDisplayLeft();
          delay(1000);
        }
        idleFlag = 1;
      }
      break;
    case 16738455:
      lcd.print("0");
      break;
    case 16750695:
      lcd.print("100+");
      break;
    case 16756815:
      lcd.print("200+");
      break;
    case 16724175:
      lcd.print("1");
      {
        lcd.setCursor(0, 0);
        lcd.print("Playing track 1");
        Smoke();
      }
      break;
    case 16718055:
      lcd.print("2");
      {
        lcd.setCursor(0, 0);
        lcd.print("Playing track 2");
        Jingle();
      }
      break;
    case 16743045:
      lcd.print("3");
      break;
    case 16716015:
      lcd.print("4");
      break;
    case 16726215:
      lcd.print("5");
      break;
    case 16734885:
      lcd.print("6");
      break;
    case 16728765:
      lcd.print("7");
      break;
    case 16730805:
      lcd.print("8");
      break;
    case 16732845:
      lcd.print("9");
      break;
    default:
      lcd.print("other button");
  }
  delay(3000);
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

void beep (int speakerPin, int freqHz, long timeMs)
{
  double timeDelay = (double)(1000000 / freqHz);
  double timeLoop = (double)((timeMs * 1000) / (timeDelay * 2));
  for (int i = 0; i < timeLoop; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(timeDelay);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(timeDelay);
  }
  delay(20);
}

void Smoke()
{
  beep(intruderBuzzer, cH, 500);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, fH, 500);
  delay(250);
  beep(intruderBuzzer, cH, 500);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, fHS, 250);
  beep(intruderBuzzer, fH, 550);
  delay(350);
  beep(intruderBuzzer, cH, 500);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, fH, 500);
  delay(250);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, cH, 1500);
  delay(250);
}

void Jingle()
{
  beep(intruderBuzzer, e, 300);
  beep(intruderBuzzer, e, 300);
  beep(intruderBuzzer, e, 500);
  delay(250);
  beep(intruderBuzzer, e, 300);
  beep(intruderBuzzer, e, 300);
  beep(intruderBuzzer, e, 500);
  delay(350);
  beep(intruderBuzzer, e, 350);
  beep(intruderBuzzer, g, 350);
  beep(intruderBuzzer, c, 350);
  beep(intruderBuzzer, d, 350);
  beep(intruderBuzzer, e, 1000);
  delay(250);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, f, 300);
  beep(intruderBuzzer, f, 300);
  beep(intruderBuzzer, e, 320);
  beep(intruderBuzzer, e, 320);
  beep(intruderBuzzer, e, 150);
  beep(intruderBuzzer, e, 150);
  beep(intruderBuzzer, e, 150);
  beep(intruderBuzzer, d, 340);
  beep(intruderBuzzer, d, 340);
  beep(intruderBuzzer, e, 440);
  beep(intruderBuzzer, d, 540);
  beep(intruderBuzzer, g, 440);
  delay(2000);
}

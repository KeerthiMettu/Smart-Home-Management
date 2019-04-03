#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

//variables related to ultrasonic sensor
int trigger = 8;
int echo = 9;
int intruderBuzzer = 10;
unsigned long duration;
int distance = 0;
int entranceHeight = 180; //180 cms
int intruderHeight=0;

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

}


void loop() {
  //  lcd.clear();
  lcd.print("Arduino"); // Prints "Arduino" on the LCD
  delay(2000); // 3 seconds delay
  lcd.clear();

  if (irrecv.decode(&results)) {
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
//  if (duration == 0)
//  {
//    //Serial.println("Warning from Ultrasonic sensor");
//    lcd.clear();
//    lcd.print("Warning from Ultrasonic sensor");
//    delay(2000);
//  }
  distance = (duration / 2) / 29.1;
  if (distance < 100)
  {
    digitalWrite(intruderBuzzer, HIGH);
    intruderHeight=entranceHeight - distance;
   // Serial.print(entranceHeight - distance);
    //Serial.println("- is the intruder height");
    //    lcd.clear();
        lcd.print("An intruder entered");
    delay(2000);
    digitalWrite(intruderBuzzer, HIGH);
  }
  else
    digitalWrite(intruderBuzzer, LOW);
  delay(200);
  lcd.clear();
}

void translateIR(long value)
{
  lcd.print("Pressed key is");
  lcd.setCursor(2,1);
  delay(1000);
  switch (value)
  {
    case 16753245:
      lcd.print("CH-");
      break;
    case 16736925:
      lcd.print("CH");
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
      lcd.print("PLAY/PAUSE");
      break;
    case 16769055:
      lcd.print("VOL-");
      break;
    case 16754775:
      lcd.print("VOL+");
      break;
    case 16748655:
      lcd.print("EQ");
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
      break;
    case 16718055:
      lcd.print("2");
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

#include<IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

//variables related to ultrasonic sensor
int trigger = 8;
int echo = 9;
int intruderBuzzer = 12;
unsigned long duration;
int distance = 0;
int entranceHeight = 180; //180 cms

//variables related to IR sensor
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

const unsigned int BAUD_RATE = 9600;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(intruderBuzzer, OUTPUT);

  irrecv.enableIRIn();

  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height)

  Serial.begin(BAUD_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    Serial.println(results.value, HEX);
    //     lcd.clear();
    //      lcd.print("Pressed key is : ");
    translateIR(results.value);
    irrecv.resume();
  }

  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  if (duration == 0)
  {
    Serial.println("Warning from Ultrasonic sensor");
    lcd.clear();
    lcd.print("Warning from Ultrasonic sensor");
    delay(1000);
  }
  distance = (duration / 2) / 29.1;
  //  Serial.print("cm = ");
  //  Serial.println(distance);
  if (distance < 140)
  {
    digitalWrite(intruderBuzzer, HIGH);
    Serial.print(entranceHeight - distance);
    Serial.println("- is the intruder height");
    //    lcd.clear();
    //    lcd.print("An intruder entered");
    delay(100);
    digitalWrite(intruderBuzzer, HIGH);
  }
  else
    digitalWrite(intruderBuzzer, LOW);
  delay(200);

}


void translateIR(long value)
{
  lcd.print("Pressed key is");
  switch (value)
  {
    case 16753245:
      Serial.println(" CH- is pressed on remote control ");
      lcd.clear();
      lcd.print("CH-");
      break;
    case 16736925:
      Serial.println(" CH is pressed on remote control  ");
      lcd.clear();
      lcd.print("CH");
      break;
    case 16769565:
      Serial.println(" CH+ is pressed on remote control ");
      lcd.clear();
      lcd.print("CH+");
      break;
    case 16720605:
      Serial.println(" PREV is pressed on remote control ");
      lcd.clear();
      lcd.print("PREV");
      break;
    case 16712445:
      Serial.println(" NEXT is pressed on remote control ");
      lcd.clear();
      lcd.print("NEXT");
      break;
    case 16761405:
      Serial.println(" PLAY/PAUSE is pressed on remote control ");
      lcd.clear();
      lcd.print("PLAY/PAUSE");
      break;
    case 16769055:
      Serial.println(" VOL- is pressed on remote control ");
      lcd.clear();
      lcd.print("VOL-");
      break;
    case 16754775:
      Serial.println(" VOL+ is pressed on remote control ");
      lcd.clear();
      lcd.print("VOL+");
      break;
    case 16748655:
      Serial.println(" EQ is pressed on remote control ");
      lcd.clear();
      lcd.print("EQ");
      break;
    case 16738455:
      Serial.println(" 0 is pressed on remote control ");
      lcd.clear();
      lcd.print("0");
      break;
    case 16750695:

      lcd.clear();
      lcd.print("100+");
      Serial.println(" 100+ is pressed on remote control ");
      break;
    case 16756815:
      
      lcd.clear();
      lcd.print("200+");
      Serial.println(" 200+ is pressed on remote control ");
      break;
    case 16724175:
      
      lcd.clear();
      lcd.print("1");
      delay(200);
      Serial.println(" 1 is pressed on remote control ");
      break;
    case 16718055:
      
      lcd.clear();
      lcd.print("2");
      Serial.println(" 2 is pressed on remote control ");
      delay(200);
      break;
    case 16743045:
      Serial.println(" 3 is pressed on remote control ");
      lcd.clear();
      lcd.print("3");
      delay(200);
      break;
    case 16716015:
      Serial.println(" 4  is pressed on remote control ");
      lcd.clear();
      lcd.print("4");
      break;
    case 16726215:
      Serial.println(" 5 is pressed on remote control ");
      lcd.clear();
      lcd.print("5");
      break;
    case 16734885:
      Serial.println(" 6 is pressed on remote control ");
      lcd.clear();
      lcd.print("6");
      break;
    case 16728765:
      Serial.println(" 7 is pressed on remote control ");
      lcd.clear();
      lcd.print("7");
      break;
    case 16730805:
      Serial.println(" 8 is pressed on remote control ");
      lcd.clear();
      lcd.print("8");
      break;
    case 16732845:
      Serial.println(" 9 is pressed on remote control ");
      lcd.clear();
      lcd.print("9");
      break;
    default:
      Serial.println(" other button is pressed on remote control ");
      lcd.clear();
      //lcd.print("other button");
  }
  delay(5000);
}


long int previousState = 0;
long int currentState = 0;
int authorizeFlag = 0;

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
        previousState = 0;
        currentState = 16736925;
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
      if (currentState != 16736925)
      {
        lcd.print("PLAY/PAUSE");
      }
      else
      {
        previousState = currentState;
        currentState = 16761405;
        lcd.clear();
        lcd.print("place ur finger");
        lcd.setCursor(0, 1);
        lcd.print("get ready");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.print(".");
        delay(1000);
        lcd.print(".");
        delay(1000);
        int fingerID = getFingerprintIDez();
        delay(100);
        String user = getfingerName(fingerID);
        lcd.clear();
        if (user != "")
        {
          authorizeFlag = 1;
          lcd.print("Hello... "); lcd.print(user);
          delay(1500);
          lcd.clear();
          lcd.print("Select Song");
          lcd.setCursor(0, 1);
          lcd.print("Press + for list");
        }
        else
        {
          lcd.print("Unauthorized access");
        }
        delay(3000);
      }
      break;
    case 16769055:
      lcd.print("VOL-");
      break;
    case 16754775:
      if (currentState == 16736925 && authorizeFlag == 1)
      {
        previousState = currentState;
        currentState = 16754775;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Smoke On The Water: 1   Jingle Bells: 2   Custom made: 3");
        for (int positionCounter = 0; positionCounter < 84; positionCounter++)
        {
          lcd.scrollDisplayLeft();
          delay(300);
        }

      }
      else
      {
        lcd.print("VOL+");
      }
      break;

    case 16748655:
      if (if (previousState != 0 && authorizeFlag == 1))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("  Exiting the music track");
          for (int positionCounter = 0; positionCounter < 20; positionCounter++)
          {
            lcd.scrollDisplayLeft();
            delay(1000);
          }
          idleFlag = 1;
          authorizeFlag = 0;
        }
        else
        {
          lcd.clear();
          lcd.print("EQ is pressed");
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
      {
        lcd.setCursor(0, 0);
        lcd.print("Playing track 3");
        Sections();
      }
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
  delay(2000);
}

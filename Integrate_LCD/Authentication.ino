//finger detection module

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  lcd.clear();
  delay(200);
  lcd.print("Found ID#");  lcd.print(finger.fingerID);
  lcd.setCursor(0, 1);
  lcd.print(finger.confidence);  lcd.print("% confidence");


  return finger.fingerID;
}

String getfingerName(int id)
{
  String idName = "";
  if (id == 1 || id == 3)
  {
    idName = "Keerthi";
  }
  if (id == 2)
  {
    idName = "Mettu";
  }
  return idName;
}

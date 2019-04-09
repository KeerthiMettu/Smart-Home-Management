
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

void Sections()
{
  //first sec
  beep(intruderBuzzer, a, 500);
  beep(intruderBuzzer, a, 500);
  beep(intruderBuzzer, a, 500);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, cH, 150);
  beep(intruderBuzzer, a, 500);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, cH, 150);
  beep(intruderBuzzer, a, 650);

  delay(500);

  beep(intruderBuzzer, eH, 500);
  beep(intruderBuzzer, eH, 500);
  beep(intruderBuzzer, eH, 500);
  beep(intruderBuzzer, fH, 350);
  beep(intruderBuzzer, cH, 150);
  beep(intruderBuzzer, gS, 500);
  beep(intruderBuzzer, f, 350);
  beep(intruderBuzzer, cH, 150);
  beep(intruderBuzzer, a, 650);

  delay(500);

  //second sec
  beep(intruderBuzzer, aH, 500);
  beep(intruderBuzzer, a, 300);
  beep(intruderBuzzer, a, 150);
  beep(intruderBuzzer, aH, 500);
  beep(intruderBuzzer, gHS, 325);
  beep(intruderBuzzer, gH, 175);
  beep(intruderBuzzer, fHS, 125);
  beep(intruderBuzzer, fH, 125);    
  beep(intruderBuzzer, fHS, 250);
 
  delay(325);
 
  beep(intruderBuzzer, aS, 250);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, dH, 325);  
  beep(intruderBuzzer, cHS, 175);  
  beep(intruderBuzzer, cH, 125);  
  beep(intruderBuzzer, b, 125);  
  beep(intruderBuzzer, cH, 250);  
 
  delay(350);

  //Variant 1
  beep(intruderBuzzer, f, 250);  
  beep(intruderBuzzer, gS, 500);  
  beep(intruderBuzzer, f, 350);  
  beep(intruderBuzzer, a, 125);
  beep(intruderBuzzer, cH, 500);
  beep(intruderBuzzer, a, 375);  
  beep(intruderBuzzer, cH, 125);
  beep(intruderBuzzer, eH, 650);
 
  delay(500);
 
  //Repeat second section
  //second sec
  beep(intruderBuzzer, aH, 500);
  beep(intruderBuzzer, a, 300);
  beep(intruderBuzzer, a, 150);
  beep(intruderBuzzer, aH, 500);
  beep(intruderBuzzer, gHS, 325);
  beep(intruderBuzzer, gH, 175);
  beep(intruderBuzzer, fHS, 125);
  beep(intruderBuzzer, fH, 125);    
  beep(intruderBuzzer, fHS, 250);
 
  delay(325);
 
  beep(intruderBuzzer, aS, 250);
  beep(intruderBuzzer, dHS, 500);
  beep(intruderBuzzer, dH, 325);  
  beep(intruderBuzzer, cHS, 175);  
  beep(intruderBuzzer, cH, 125);  
  beep(intruderBuzzer, b, 125);  
  beep(intruderBuzzer, cH, 250);  
 
  delay(350);
 
  //Variant 2
  beep(intruderBuzzer, f, 250);  
  beep(intruderBuzzer, gS, 500);  
  beep(intruderBuzzer, f, 375);  
  beep(intruderBuzzer, cH, 125);
  beep(intruderBuzzer, a, 500);  
  beep(intruderBuzzer, f, 375);  
  beep(intruderBuzzer, cH, 125);
  beep(intruderBuzzer, a, 650);  
 
  delay(650);
  
}

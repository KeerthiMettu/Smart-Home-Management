
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

//Song 1
void Smoke()
{
  beep(Buzzer, cH, 500);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, fH, 500);
  delay(250);
  beep(Buzzer, cH, 500);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, fHS, 250);
  beep(Buzzer, fH, 550);
  delay(350);
  beep(Buzzer, cH, 500);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, fH, 500);
  delay(250);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, cH, 1500);
  delay(250);
}

//Song 2
void Jingle()
{
  beep(Buzzer, e, 300);
  beep(Buzzer, e, 300);
  beep(Buzzer, e, 500);
  delay(250);
  beep(Buzzer, e, 300);
  beep(Buzzer, e, 300);
  beep(Buzzer, e, 500);
  delay(350);
  beep(Buzzer, e, 350);
  beep(Buzzer, g, 350);
  beep(Buzzer, c, 350);
  beep(Buzzer, d, 350);
  beep(Buzzer, e, 1000);
  delay(250);
  beep(Buzzer, f, 350);
  beep(Buzzer, f, 350);
  beep(Buzzer, f, 350);
  beep(Buzzer, f, 300);
  beep(Buzzer, f, 300);
  beep(Buzzer, e, 320);
  beep(Buzzer, e, 320);
  beep(Buzzer, e, 150);
  beep(Buzzer, e, 150);
  beep(Buzzer, e, 150);
  beep(Buzzer, d, 340);
  beep(Buzzer, d, 340);
  beep(Buzzer, e, 440);
  beep(Buzzer, d, 540);
  beep(Buzzer, g, 440);
  delay(2000);
}

//Song 3
void Sections()
{
  //first sec
  beep(Buzzer, a, 500);
  beep(Buzzer, a, 500);
  beep(Buzzer, a, 500);
  beep(Buzzer, f, 350);
  beep(Buzzer, cH, 150);
  beep(Buzzer, a, 500);
  beep(Buzzer, f, 350);
  beep(Buzzer, cH, 150);
  beep(Buzzer, a, 650);

  delay(500);

  beep(Buzzer, eH, 500);
  beep(Buzzer, eH, 500);
  beep(Buzzer, eH, 500);
  beep(Buzzer, fH, 350);
  beep(Buzzer, cH, 150);
  beep(Buzzer, gS, 500);
  beep(Buzzer, f, 350);
  beep(Buzzer, cH, 150);
  beep(Buzzer, a, 650);

  delay(500);

  //second sec
  beep(Buzzer, aH, 500);
  beep(Buzzer, a, 300);
  beep(Buzzer, a, 150);
  beep(Buzzer, aH, 500);
  beep(Buzzer, gHS, 325);
  beep(Buzzer, gH, 175);
  beep(Buzzer, fHS, 125);
  beep(Buzzer, fH, 125);    
  beep(Buzzer, fHS, 250);
 
  delay(325);
 
  beep(Buzzer, aS, 250);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, dH, 325);  
  beep(Buzzer, cHS, 175);  
  beep(Buzzer, cH, 125);  
  beep(Buzzer, b, 125);  
  beep(Buzzer, cH, 250);  
 
  delay(350);

  //Variant 1
  beep(Buzzer, f, 250);  
  beep(Buzzer, gS, 500);  
  beep(Buzzer, f, 350);  
  beep(Buzzer, a, 125);
  beep(Buzzer, cH, 500);
  beep(Buzzer, a, 375);  
  beep(Buzzer, cH, 125);
  beep(Buzzer, eH, 650);
 
  delay(500);
 
  //Repeat second section
  //second sec
  beep(Buzzer, aH, 500);
  beep(Buzzer, a, 300);
  beep(Buzzer, a, 150);
  beep(Buzzer, aH, 500);
  beep(Buzzer, gHS, 325);
  beep(Buzzer, gH, 175);
  beep(Buzzer, fHS, 125);
  beep(Buzzer, fH, 125);    
  beep(Buzzer, fHS, 250);
 
  delay(325);
 
  beep(Buzzer, aS, 250);
  beep(Buzzer, dHS, 500);
  beep(Buzzer, dH, 325);  
  beep(Buzzer, cHS, 175);  
  beep(Buzzer, cH, 125);  
  beep(Buzzer, b, 125);  
  beep(Buzzer, cH, 250);  
 
  delay(350);
 
  //Variant 2
  beep(Buzzer, f, 250);  
  beep(Buzzer, gS, 500);  
  beep(Buzzer, f, 375);  
  beep(Buzzer, cH, 125);
  beep(Buzzer, a, 500);  
  beep(Buzzer, f, 375);  
  beep(Buzzer, cH, 125);
  beep(Buzzer, a, 650);  
 
  delay(650);
  
}

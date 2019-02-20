const int A_0 = 4;
const int A_1 = 2;
const int A_2 = 1;
const int A_3 = 3;
const int B_0 = 8;
const int B_1 = 6;
const int B_2 = 5;
const int B_3 = 7;
const int C_0 = 12;
const int C_1 = 10;
const int C_2 = 9;
const int C_3 = 11;
const int D_0 = A3;
const int D_1 = A1;
const int D_2 = A0;
const int D_3 = A2;

#include <Wire.h>
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);

int hour = 0;
int mins = 0;

int hour1 = 0;
int hour2 = 0;
int mins1 = 0;
int mins2 = 0;

void setup()
{ 
  pinMode(A_0, OUTPUT);
  pinMode(A_1, OUTPUT);
  pinMode(A_2, OUTPUT);
  pinMode(A_3, OUTPUT);
  pinMode(B_0, OUTPUT);
  pinMode(B_1, OUTPUT);
  pinMode(B_2, OUTPUT);
  pinMode(B_3, OUTPUT);
  pinMode(C_0, OUTPUT);
  pinMode(C_1, OUTPUT);
  pinMode(C_2, OUTPUT);
  pinMode(C_3, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Rtc.Begin();        
  Rtc.Enable32kHzPin(false);
  Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone); 
}

void loop()
{
  delay (1000);
  //hibakezelés
  if (!Rtc.IsDateTimeValid()) 
    {        
        hour1 = 1;
        hour2 = 1;
        mins1 = 1;
        mins2 = 1;
    }
  //pontos idő lekérdezése
  RtcDateTime now = Rtc.GetDateTime();

  //Változókba beállítani az értékeket
  
  hour = now.Hour();    
  mins = now.Minute();
            
  hour1 = hour / 10;
  hour2 = hour % 10;
  mins1 = mins / 10;
  mins2 = mins % 10;

  //első karakter elrejtése
  if (hour1 == 0) {

    digitalWrite(A_3, HIGH);  //D
    digitalWrite(A_2, LOW);   //C
    digitalWrite(A_1, HIGH);  //B
    digitalWrite(A_0, LOW);   //A
  }
  else {

      switch(hour1)
      {        
        case 1:   displayNumber1(A_0, A_1, A_2, A_3);  
                    break;
        case 2:   displayNumber2(A_0, A_1, A_2, A_3);
                    break;        
      }
  }

  switch(hour2)
  {
    case 0:   displayNumber0(B_0, B_1, B_2, B_3);
                break;
    case 1:   displayNumber1(B_0, B_1, B_2, B_3);  
                break;
    case 2:   displayNumber2(B_0, B_1, B_2, B_3);
                break;
    case 3:   displayNumber3(B_0, B_1, B_2, B_3);  
                break;
    case 4:   displayNumber4(B_0, B_1, B_2, B_3);
                break;
    case 5:   displayNumber5(B_0, B_1, B_2, B_3);  
                break;
    case 6:   displayNumber6(B_0, B_1, B_2, B_3);
                break;
    case 7:   displayNumber7(B_0, B_1, B_2, B_3);  
                break;
    case 8:   displayNumber8(B_0, B_1, B_2, B_3);
                break;
    case 9:   displayNumber9(B_0, B_1, B_2, B_3);  
                break;
  }

  switch(mins1)
  {
    case 0:   displayNumber0(C_0, C_1, C_2, C_3);
                break;
    case 1:   displayNumber1(C_0, C_1, C_2, C_3);  
                break;
    case 2:   displayNumber2(C_0, C_1, C_2, C_3);
                break;
    case 3:   displayNumber3(C_0, C_1, C_2, C_3);  
                break;
    case 4:   displayNumber4(C_0, C_1, C_2, C_3);
                break;
    case 5:   displayNumber5(C_0, C_1, C_2, C_3);  
                break;
    case 6:   displayNumber6(C_0, C_1, C_2, C_3);
                break;
    case 7:   displayNumber7(C_0, C_1, C_2, C_3);  
                break;
    case 8:   displayNumber8(C_0, C_1, C_2, C_3);
                break;
    case 9:   displayNumber9(C_0, C_1, C_2, C_3);  
                break;
  }

  switch(mins2)
  {
    case 0:   displayNumber0(D_0, D_1, D_2, D_3);
                break;
    case 1:   displayNumber1(D_0, D_1, D_2, D_3);  
                break;
    case 2:   displayNumber2(D_0, D_1, D_2, D_3);
                break;
    case 3:   displayNumber3(D_0, D_1, D_2, D_3);  
                break;
    case 4:   displayNumber4(D_0, D_1, D_2, D_3);
                break;
    case 5:   displayNumber5(D_0, D_1, D_2, D_3);  
                break;
    case 6:   displayNumber6(D_0, D_1, D_2, D_3);
                break;
    case 7:   displayNumber7(D_0, D_1, D_2, D_3);  
                break;
    case 8:   displayNumber8(D_0, D_1, D_2, D_3);
                break;
    case 9:   displayNumber9(D_0, D_1, D_2, D_3);  
                break;
  }
}

void displayNumber0(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, LOW);  //A
}

void displayNumber1(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, HIGH); //A
}

void displayNumber2(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, HIGH); //B
  digitalWrite(tube_0, LOW);  //A
}

void displayNumber3(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, HIGH); //B
  digitalWrite(tube_0, HIGH); //A
}

void displayNumber4(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, HIGH); //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, LOW);  //A
}

void displayNumber5(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, HIGH); //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, HIGH); //A
}

void displayNumber6(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, HIGH); //C
  digitalWrite(tube_1, HIGH); //B
  digitalWrite(tube_0, LOW);  //A
}

void displayNumber7(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, LOW);  //D
  digitalWrite(tube_2, HIGH); //C
  digitalWrite(tube_1, HIGH); //B
  digitalWrite(tube_0, HIGH); //A
}

void displayNumber8(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, HIGH); //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, LOW);  //A
}

void displayNumber9(int tube_0, int tube_1, int tube_2, int tube_3) {
  digitalWrite(tube_3, HIGH); //D
  digitalWrite(tube_2, LOW);  //C
  digitalWrite(tube_1, LOW);  //B
  digitalWrite(tube_0, HIGH); //A
}

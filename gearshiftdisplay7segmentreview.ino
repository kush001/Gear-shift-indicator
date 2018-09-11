  
   
  /*Gear Shift Display On 7 Segment
   * Created By: Kushagra Pandey
   * Date: 15/01/2017
   * BE, EnTC
   */



#include <Arduino.h>
#include <Bounce2.h>
const int upShift =2; // Pin used for Up Shift trigger
Bounce upButton = Bounce(upShift, 200);
const int dwnShift = 3; // Pin used for Down Shift trigger
Bounce dwnButton = Bounce(dwnShift, 300);
int currentPos=0; // Variable for current gear position
int newPos=0; // Variable for calculated next gear position
char NeutralFlag=1; // Sets to 0 or 1 if in neutral. Used to determine next gear selection and display output

void setup()   
{                
  pinMode(upShift, INPUT_PULLUP); // Sets analog pin 2 as input from up shift sensor
  pinMode(dwnShift, INPUT_PULLUP); // Sets analog pin 3 as input from down shift sensor 
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,INPUT);
  draw_N();
}

void loop() {
  upButton.update();
  int currentUpButtonState = upButton.read();
  if(upButton.risingEdge() && NeutralFlag ==1){
    newPos = 2;
    NeutralFlag = 0;
    updatedisplay();
  }
  if(upButton.fallingEdge() && newPos >= 6){
    newPos = 6;
    updatedisplay();
   }
    else if(upButton.fallingEdge() && NeutralFlag ==0){
    newPos = currentPos + 1;
    updatedisplay();  
    }
  dwnButton.update();
  int currentDwnButtonState = dwnButton.read();
  if(dwnButton.risingEdge() && NeutralFlag ==1){
    newPos = 1;
    NeutralFlag = 0;
    updatedisplay();
  }

   if(dwnButton.fallingEdge() && newPos <= 1){
    newPos = 1;
    updatedisplay();
  }
  else if (dwnButton.fallingEdge()){ 
    newPos = currentPos -1;
     updatedisplay();
  }

}

//Functions

void updatedisplay(){
 currentPos = newPos; 
  if(newPos == 0 ){
  draw_N    ();
 }
 if(newPos == 1){
  draw_one();
 }
 if(newPos == 2){
  draw_two();
 }
 if(newPos == 3){
  draw_three();
 }
 if(newPos == 4){
  draw_four();
 }
 if(newPos == 5){
  draw_five();
 }
 if(newPos == 6){
  draw_six();
 }
 
}
void neutraldisplay(){
  if(NeutralFlag == 1){
    draw_N();
}
}

void draw_one(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
}

void draw_two(){
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(10,HIGH);
}

void draw_three(){
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(10,HIGH);
}

void draw_four(){
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void draw_five(){
  digitalWrite(4,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
}

void draw_six(){
  digitalWrite(4,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,HIGH);
}

void draw_N(){
  digitalWrite(10,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}



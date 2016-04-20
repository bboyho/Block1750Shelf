/* Block1750 Shelve Lighting
 
 Illuminating the Block's kitchen shelves with RGB LED Strips.
 
 */

#define redPin 3
#define greenPin 6
#define bluePin 11

void setup(){
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);
  Serial.println("Begin lighting Block1750 Kitchen shelves!");
}

int brightness = 0;
int potValue = 0;
int fadeAmount = 5;

void loop(){//ROYGBIV
  /*
   red              = red[HIGH]
   tangerine orange = red[HIGH]+ green[50]
   yellow           = red[HIGH]+ green[HIGH]
   green            =          + green[HIGH]
   clear blue       =          + green[HIGH] + blue[HIGH]
   blue             =                        + blue[HIGH]
   magenta          = red[HIGH]+             + blue[HIGH]
   white            = red[HIGH]+ green[HIGH] + blue[HIGH]
   */

  //turn LEDs off
  analogWrite(redPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);

  //RED
  redON();
  //ORANGE and YELLOW
  greenON();
  //GREEN
  redOFF();
  //COOL BLUE
  blueON();
  //BLUE
  greenOFF();
  //MAGENTA
  redON();
  //WHITE
  greenON();
  //TURN OFF
  allOFF();
  
  delay(1000);

  /*
  potValue = analogRead(A0);
   //convert potentiometer to lower range for brightness
   brightness = map(potValue, 0, 1023, 0, 255); 
   Serial.println(potValue);
   
   analogWrite(greenPin, brightness);    
   */
}

void redON(){
  for(int r=0; r<256; r=r+fadeAmount){
    analogWrite(redPin,r);
    delay(30);//slow down 
  }
}

void redOFF(){
  for(int r=255; r>=0; r = r - fadeAmount){
    analogWrite(redPin,r);
    delay(30);//slow down 
  }
}
void blueON(){
  for(int b=0; b<256; b=b+fadeAmount){
    analogWrite(bluePin,b);
    delay(30);
  }
}
void blueOFF(){
  for(int b=255; b>=0; b = b - fadeAmount){
    analogWrite(bluePin,b);
    delay(30);
  }
}
void greenON(){
  for(int g=0; g<256; g=g+fadeAmount){
    analogWrite(greenPin,g);
    delay(30);
  }
}
void greenOFF(){
  for(int g=255; g>=0; g = g - fadeAmount){
    analogWrite(greenPin,g);
    delay(30);
  }
}

void allOFF(){
  for(int all=255; all>=
  0; all = all - fadeAmount){
    analogWrite(redPin,all);
    analogWrite(greenPin,all);
    analogWrite(bluePin,all);
    delay(30);
  }
}

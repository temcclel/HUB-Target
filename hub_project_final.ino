#include <Adafruit_NeoPixel.h>

  // Which pin on the Arduino is connected to the NeoPixels?
  // On a Trinket or Gemma we suggest changing this to 1:
  #define LED_PIN1    8
  #define LED_PIN2   9

  // How many NeoPixels are attached to the Arduino?
  #define LED_COUNT1 3
  #define LED_COUNT2 19
  
  #define TARGET1 11
  #define TARGET2 12
  #define TARGET3 13

  #define BUTTON1 7
  #define BUTTON2 6
  #define BUTTON3 5

  #define DIM 5

  // Declare our NeoPixel strip object:
  Adafruit_NeoPixel strip1(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel strip2(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ800);


    uint32_t correctCol = strip2.Color(0, 20, 0);
    uint32_t wrongCol = strip2.Color(20,0,0);
void correctAni(){
 /* for(int i = 0; i < 4; i++){
    strip2.fill(correctCol);
    strip2.show();
    delay(200);
    strip2.clear();
    strip2.show();
    delay(200);
  }*/
  for(int i = 0; i < 10; i++){
    strip2.fill(correctCol, 9 - i, 1+(2*i));
    delay(50);
    strip2.show();
  }
  for(int i = 0; i < 4; i++){
    strip2.fill(correctCol);
    strip2.show();
    delay(200);
    strip2.clear();
    strip2.show();
    delay(200);
  }
}

  void setup() {
    pinMode(TARGET1, INPUT);
    pinMode(TARGET2, INPUT);
    pinMode(TARGET3, INPUT);
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);

    Serial.begin(9600);

    strip1.begin();
    strip1.show(); // Initialize all pixels to 'off'
    strip2.begin();
    strip2.show();
  }
    int correctAns;

  void loop() {
    // put your main code here, to run repeatedly:
    if(digitalRead(BUTTON1) == HIGH){
      strip1.setPixelColor(2,DIM,0,0);
      strip1.setPixelColor(0,0,0,0);
      strip1.setPixelColor(1,0,0,0);
      strip1.show();
            Serial.println("Button 1");
      correctAns = 1;
    }
    if(digitalRead(BUTTON2) == HIGH){
      strip1.setPixelColor(1,0,DIM,0);
      strip1.setPixelColor(0,0,0,0);
      strip1.setPixelColor(2,0,0,0);
      strip1.show();
            Serial.println("Button 2");
      correctAns = 2;
    }

  if(digitalRead(BUTTON3) == HIGH){
        strip1.setPixelColor(0,0,0,DIM);
        strip1.setPixelColor(1,0,0,0);
        strip1.setPixelColor(2,0,0,0);
        strip1.show();
        Serial.println("Button 3");
        correctAns = 3;
    }
    
    if(digitalRead(TARGET1) == HIGH){
      if(correctAns == 1){
        correctAni();
      } else{
        strip2.fill(wrongCol);
        strip2.show();
      }
    }
    if(digitalRead(TARGET2) == HIGH){
      if(correctAns == 2){
        correctAni();
      } else{
        strip2.fill(wrongCol);
        strip2.show();
      }
    }
    if(digitalRead(TARGET3) == HIGH){
      if(correctAns == 3){
        correctAni();
      } else{
        strip2.fill(wrongCol);
        strip2.show();
      }
    }



    






  }

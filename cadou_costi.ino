//5V is 1  (rubber ducko things)
//1 is also returned when unplugged

//GND is 0 (normal arduino behaviour)
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_sv_SE.h>
#include <string.h>

/*
Fetching IP...
sharing location (harta cu romania)

uploading /Pictures...

linking to the botnet
*/

const int pin = 2;
const int KEY_WAIT_TIME = 25;
const int LOAD_WAIT_TIME = 1000;
const int LOADING_BAR_LENGTH = 40;
const int timeToWait[LOADING_BAR_LENGTH] = { 10, 15, 15, 20, 10, 60, 10, 11};


void setup() {
  Keyboard.begin();
  pinMode(pin, INPUT);
  Serial.begin(9600);
  delay(1000);
}

void typeKey(uint8_t key) {
  Keyboard.press(key);
  delay(KEY_WAIT_TIME);
  Keyboard.release(key);
}

void typeCombination(uint8_t key1, uint8_t key2) {
  Keyboard.press(key1);
  Keyboard.press(key2);

  delay(KEY_WAIT_TIME);
  Keyboard.releaseAll();
}

void typePhrase(char* s){
  for(int i = 0; i < strlen(s); i++){
    typeKey(s[i]);
  }
}

void loadingBar(){
  for(int i = 0; i < LOADING_BAR_LENGTH; i++){
    typeKey('#');
    delay(timeToWait[i/5] * 3);
  }
  typeKey('\n');
}

void initPhase(){
  delay(LOAD_WAIT_TIME);
  typeCombination(KEY_LEFT_GUI, 't');
  delay(LOAD_WAIT_TIME);
  typePhrase("echo '\n");
}

void endPhase(){
  typePhrase("' >> la_multi_ani.txt\n");
}

void loadingPercentage(){
  for(int i = 0; i < 99; i++){
    if(i < 10){
      typeKey((char)i);
    }
    else{
      typeKey((char)(i/10));
      typeKey((char)(i%10));
    }
    delay(10);
    typeKey(KEY_BACKSPACE);
    if(i >= 10){
      typeKey(KEY_BACKSPACE);
    }
  }
  typePhrase("100\n");
}

//looks like it doesn't work unless i put the code in the loop
void loop() {
  if (digitalRead(pin)) {
    // this is a comment
    initPhase();

    typePhrase("deleting all files...\n");
    loadingBar();
    typePhrase("Done\n\n");

    typePhrase("replacing /rust with /c...\n");
    loadingBar();
    typePhrase("Done\n\n");

    typePhrase("Downloading RAM... \n");
    loadingPercentage();
    typePhrase("Done\n\n");

    endPhase();
  } 
  else {
  
  }
  delay(10000);
}
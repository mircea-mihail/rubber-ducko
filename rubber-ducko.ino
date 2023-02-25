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

const int pin = 2;
const int KEY_WAIT_TIME = 25; //time to wait after pressing any key
const int LOAD_WAIT_TIME = 1000; //for the init phase
//for loading bar
const int LOADING_BAR_LENGTH = 40;
const int bar_wait[LOADING_BAR_LENGTH] = { 10, 15, 15, 20, 10, 5, 5, 5};
//for loading percentage
const int ASCII_OFFSET = 48;
const int percentage_wait[10] = {4, 16, 23, 55, 56, 59, 71, 88, 97, 99};


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
    delay(bar_wait[i/5] * 3);
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
  typePhrase("' >> happy_birthday.txt\n");
}

  //ascii 0 - 48
  //ascii 9 - 57

void loadingPercentage(){
    for(int i = 0; i < 10; i++){
    if(percentage_wait[i] < 10){
      typeKey(percentage_wait[i] + ASCII_OFFSET);
      typeCombination(KEY_LEFT_SHIFT, 5 + ASCII_OFFSET);
    }
    else{
      typeKey((percentage_wait[i]/10) + ASCII_OFFSET);
      typeKey((percentage_wait[i]%10) + ASCII_OFFSET);
      typeCombination(KEY_LEFT_SHIFT, 5 + ASCII_OFFSET);
    }
    delay(100);
    typeKey(KEY_BACKSPACE);
    typeKey(KEY_BACKSPACE);

    if(percentage_wait[i] >= 10){
      typeKey(KEY_BACKSPACE);
    }
  }
  typePhrase("100%\n");
}

const int DOT_WAIT_TIME = 200;

void loadingDots(int less_loops = 0){
  for(int i = 0; i < 3 - less_loops; i++){
    for(int i = 0; i < 3; i++){
      typeKey('.');
      delay(DOT_WAIT_TIME);
    }
    typeKey(KEY_BACKSPACE);
    typeKey(KEY_BACKSPACE);
    typeKey(KEY_BACKSPACE);
  }
  for(int i = 0; i < 3; i++){
    typeKey('.');
    delay(DOT_WAIT_TIME);
  }
}

void funnyProcesses(){
  typePhrase("Fetching IP");
  loadingDots(2);
  typePhrase("\nDone\n\n");

  typePhrase("Triangulating your exact coordinates using NASA satellites");
  loadingDots();
  typePhrase("\nDone\n\n");

  typePhrase("Sending organ collectors (the musical type)");
  loadingDots(3);
  typePhrase("\nDone\n\n");

  typePhrase("Downloading RAM... ");
  loadingPercentage();
  typePhrase("Done\n\n");

  typePhrase("Linking the system to the botnet... ");
  loadingPercentage();
  typePhrase("Done\n\n");

  typePhrase("Uploading /Pictures to fake chinese Kaufland site for cash cash...\n");
  loadingBar();
  typePhrase("Done\n\n");

  typePhrase("Renaming Shellsec to MirceaSec for clout...\n");
  loadingBar();
  typePhrase("Done\n\n");

  typePhrase("Replacing all rust code with vulnerable C99 alternatives...\n");
  loadingBar();
  typePhrase("Done\n\n");

  typePhrase("Encrypting all files for ransom...\n");
  loadingBar();
  typePhrase("Done\n\n");
}

//looks like it doesn't work unless i put the code in the loop
void loop() {
  if (digitalRead(pin)) {
    // this is a comment
    initPhase();
    
    funnyProcesses();

    endPhase();

    typePhrase("xdg-open https://github.com/mircea-mihail/rubber-ducko \n");
  } 
  else {
  
  }
  delay(5000);
}
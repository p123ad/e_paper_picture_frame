/**
notes: 
  - Some very short delays have been inserted because Serial Monitor sometimes didn't showed complete messages
**/

#include "Pictures.h"
#include "epaper.h"
#include "deepSleep.h"

#define uS_TO_S_FACTOR 1000000ULL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  24*60*60        /* ESP32 will go to sleep for 24 hours (in seconds) */


#define Threshold 40 /* Greater the value, more the wakeup sensitivity of touch wakeup */
RTC_DATA_ATTR int bootCount = 0; //store a value on RTC Memory, data is not erased during deep sleep
RTC_DATA_ATTR int nextPic=0; 

void callback(){
  //placeholder callback function
}

void showNewSequenceImage(){
  //initialize communication and save memory for image buffer 
  initializePaperDisplay();
  delay(10);
  
  switch(nextPic){

    case 0  :   displayPicture(myPic1); Serial.println("Show Pic1"); break;
    case 1  :   displayPicture(myPic2); Serial.println("Show Pic2"); break;
    case 2  :   displayPicture(myPic3); Serial.println("Show Pic3"); break;
    case 3  :   displayPicture(myPic4); Serial.println("Show Pic4"); break;
    case 4  :   displayPicture(myPic5); Serial.println("Show Pic5"); break;
    case 5  :   displayPicture(myPic6); Serial.println("Show Pic6"); break;
    case 6  :   displayPicture(myPic7); Serial.println("Show Pic7"); break;
    case 7  :   displayPicture(myPic8); Serial.println("Show Pic8"); break;
    case 8  :   displayPicture(myPic9); Serial.println("Show Pic9"); break;
    case 9  :   displayPicture(myPic10); Serial.println("Show Pic10"); break;
    case 10  :   displayPicture(myPic11); Serial.println("Show Pic11"); break;
    case 11  :   displayPicture(myPic12); Serial.println("Show Pic12"); break;
    case 12  :   displayPicture(myPic13); Serial.println("Show Pic13"); break;
    case 13  :   displayPicture(myPic14); Serial.println("Show Pic14"); break;
    case 14  :   displayPicture(myPic15); Serial.println("Show Pic15"); break;
    case 15  :   displayPicture(myPic16); Serial.println("Show Pic16"); break;
    case 16  :   displayPicture(myPic17); Serial.println("Show Pic17"); break;
  }

  nextPic++;

  if(nextPic > 13)
    nextPic = 0;

}


void showNewRandomImage(){
  //initialize communication and save memory for image buffer 
  initializePaperDisplay();
  delay(10);

  //Generate random image number
  int picNumber = random(14);

  //display the random image 
  switch(picNumber){
    case 0  :   displayPicture(myPic1); Serial.println("Show Pic1"); break;
    case 1  :   displayPicture(myPic2); Serial.println("Show Pic2"); break;
    case 2  :   displayPicture(myPic3); Serial.println("Show Pic3"); break;
    case 3  :   displayPicture(myPic4); Serial.println("Show Pic4"); break;
    case 4  :   displayPicture(myPic5); Serial.println("Show Pic5"); break;
    case 5  :   displayPicture(myPic6); Serial.println("Show Pic6"); break;
    case 6  :   displayPicture(myPic7); Serial.println("Show Pic7"); break;
    case 7  :   displayPicture(myPic8); Serial.println("Show Pic8"); break;
    case 8  :   displayPicture(myPic9); Serial.println("Show Pic9"); break;
    case 9  :   displayPicture(myPic10); Serial.println("Show Pic10"); break;
    case 10  :   displayPicture(myPic11); Serial.println("Show Pic11"); break;
    case 11  :   displayPicture(myPic12); Serial.println("Show Pic12"); break;
    case 12  :   displayPicture(myPic13); Serial.println("Show Pic13"); break;
    case 13  :   displayPicture(myPic14); Serial.println("Show Pic14"); break;
    case 14  :   displayPicture(myPic15); Serial.println("Show Pic15"); break;
    case 15  :   displayPicture(myPic16); Serial.println("Show Pic16"); break;
    case 16  :   displayPicture(myPic17); Serial.println("Show Pic17"); break;
  }
  //now clear memory and set display in sleep mode
  sleepPaperDisplay();
}

void setup() {
  Serial.begin(115200);
  delay(1000); //Take some time to open up the Serial Monitor

  //Increment boot number and print it every reboot
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
  delay(10);

  //Print the wakeup reason for ESP32 and touchpad too
  print_wakeup_reason();
  print_wakeup_touchpad();
  delay(10);

  //print new picture to the Display
  showNewSequenceImage();


  //Setup interrupt on Touch Pad 3 (A4 / GPIO15)
  touchAttachInterrupt(T3, callback, Threshold);

  //Configure Touchpad as wakeup source
  esp_sleep_enable_touchpad_wakeup();

  //Configure Timer as wakeup source too
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); //accepts a uint64_t value (range: 2^64 − 1 which equals 18.446.744.073.709.551.615)
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
  delay(10);


  //Go to sleep now
  Serial.println("Going to sleep now...");
  Serial.flush(); //Waits for the transmission of outgoing serial data to complete
  esp_deep_sleep_start();
  Serial.println("This will never be printed");

}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}



#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include <stdlib.h>

  //Create a new image cache
  UBYTE *BlackImage;

void initializePaperDisplay(){

  DEV_Module_Init();
  Serial.println("EPD_7IN5_HD_test Demo");
  Serial.println("e-Paper Init and Clear...");
  EPD_7IN5_HD_Init();
  EPD_7IN5_HD_Clear();
  DEV_Delay_ms(500);



  /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
  UWORD Imagesize = ((EPD_7IN5_HD_WIDTH % 8 == 0) ? (EPD_7IN5_HD_WIDTH / 8 ) : (EPD_7IN5_HD_WIDTH / 8 + 1)) * EPD_7IN5_HD_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    Serial.println("Failed to apply for black memory...");
    while(1);
  }

  Serial.println("Generate new buffer image...");
  Paint_NewImage(BlackImage, EPD_7IN5_HD_WIDTH, EPD_7IN5_HD_HEIGHT , 0, WHITE);

}



void displayPicture(const unsigned char *picture){
  Serial.println("Display new Picture...");
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawImage(picture,0,0,880,528); 
  EPD_7IN5_HD_Display(BlackImage);
  //DEV_Delay_ms(10000);

}


void sleepPaperDisplay(){

  Serial.println("EPaper goto Sleep mode...");
  EPD_7IN5_HD_Sleep();
  Serial.println("free image memory...");
  free(BlackImage);
  BlackImage = NULL;

}
#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
/*
Safe to use pin
VN(GPIO39) inp only 23
32          22
25          19
26          18
           17
           16*/
//------display----

#define TFT_CS    -1
#define TFT_DC    15  // on choice
#define TFT_RST   17 // on choice
#define TFT_MOSI 23 // Mosi VSPI pin SDA on display
#define TFT_SCLK 18 // SCK VSPI pin SCL on display
#define TFT_BLK 19 // to control blk
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  pinMode(TFT_BLK, OUTPUT);
  digitalWrite(TFT_BLK, LOW);// to set the display off
  tft.init(240, 240, SPI_MODE3); // Initialize the display with the correct dimensions
  // SPi mode3. why? idk my oled is shit
  tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(10, 40);
    tft.setRotation(2);
    
    tft.setTextSize(3);
    tft.print("System Ready");
    delay(5000);
  // put your setup code here, to run once:
}

void loop() {
      tft.setCursor(10, 40);
      // remember to set the cursor wo it doesnt overlap and the place change
      tft.fillScreen(ST77XX_BLUE);
      tft.printf("System Ready");
      
      delay(1000);
      tft.fillScreen(ST77XX_BLACK);
      delay(1000);
      tft.fillScreen(ST77XX_CYAN);

      delay(1000);

      
  // put your main code here, to run repeatedly:
}
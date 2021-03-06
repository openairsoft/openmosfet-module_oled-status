#include <Arduino.h>
#include <U8g2lib.h>
#include <openMosfetEspNow.h>

u8g2_uint_t firemodeXBMWidth = 62;
u8g2_uint_t firemodeXBMHeight = 21;

static const unsigned char firemode_safe_xbm[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x3B, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xBE, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 
  0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6E, 0x2F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xB4, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 
  0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };
  
static const unsigned char firemode_semi_xbm[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFE, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
  0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x2F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFC, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
  0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

static const unsigned char firemode_auto_xbm[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 0xF0, 
  0x1F, 0xE0, 0x3F, 0x00, 0x00, 0xFE, 0x1F, 0xFC, 0x3F, 0xF8, 0x7F, 0x00, 
  0x00, 0xFF, 0x17, 0xFE, 0x2F, 0xFC, 0x5F, 0x00, 0x80, 0xFF, 0x17, 0xFF, 
  0x2F, 0xFE, 0x5F, 0x00, 0x00, 0xFF, 0x17, 0xFE, 0x2F, 0xFC, 0x5F, 0x00, 
  0x00, 0xFE, 0x17, 0xFC, 0x2F, 0xF8, 0x5F, 0x00, 0x00, 0xF8, 0x0F, 0xF0, 
  0x1F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void drawBbsFired(unsigned long bbsFired) {
  u8g2.setFont(u8g2_font_logisoso30_tn);

  String bbsFiredText(bbsFired);
  u8g2_uint_t xOrigin = (127 - (u8g2.getUTF8Width(bbsFiredText.c_str()))) / 2;
  u8g2.drawStr(xOrigin, 36, bbsFiredText.c_str());
}

void drawBatteryVoltage(float batteryVoltage) {
  //todo: we also need the percentage to "fill" the battery logo
  u8g2.setFont(u8g2_font_freedoomr10_tu);

  String batteryVoltageText = String(batteryVoltage, 2) + String('V');
  u8g2_uint_t xOrigin = 101 - (u8g2.getUTF8Width(batteryVoltageText.c_str()) / 2);
  u8g2.drawStr(xOrigin, 59, batteryVoltageText.c_str());

  // float tmpBatteryRatio = 0.7236;//todo: replace with real value when api allows it
  // u8g2.setDrawColor(0);
  // u8g2.drawRBox(67,46,8,13,0);
  // u8g2_uint_t batteryFillHeight = (u8g2_uint_t) (tmpBatteryRatio * (float)13);
  // u8g2.setDrawColor(1);
  // u8g2.drawRBox(67,46 + (13 - batteryFillHeight),8,batteryFillHeight,0);
}

void drawSelectorState(uint8_t selectorState) {
  switch (selectorState)
  {
    case 0:
      #ifdef DEBUG
        Serial.println("Safe");
      #endif
      u8g2.drawXBMP(1, 42, firemodeXBMWidth, firemodeXBMHeight, firemode_safe_xbm);
      break;
    case 1:
      #ifdef DEBUG
        Serial.println("Semi");
      #endif
      u8g2.drawXBMP(1, 42, firemodeXBMWidth, firemodeXBMHeight, firemode_semi_xbm);
      break;
    case 2:
      #ifdef DEBUG
        Serial.println("Auto");
      #endif
      u8g2.drawXBMP(1, 42, firemodeXBMWidth, firemodeXBMHeight, firemode_auto_xbm);
      break;
  }
  
}

#define FRAMES_PER_SECOND 15
unsigned int millisBetweenFrames_ms = 1000/FRAMES_PER_SECOND;
unsigned long nextFrame_ms = 0;

void setup(){
  Serial.begin(115200);
  // OpenMosfetEspNowClient::begin(&drawBbsFired, &drawBatteryVoltage, &drawSelectorState);
  OpenMosfetEspNowClient::begin(NULL, NULL, NULL);
  u8g2.begin();
  u8g2.setBitmapMode(0);
  u8g2.clearBuffer();
  // outlines
  u8g2.drawRFrame(0,0,128,64,0);
  u8g2.drawLine(1, 41, 126, 41);
  u8g2.drawLine(63, 42, 63, 62);
  // battery frame
  u8g2.drawRFrame(66,45,10,15,0);
  u8g2.drawLine(69, 44, 72, 44);

  //test
  // drawBbsFired(138);
  // drawBatteryVoltage(10.7236);
  // drawSelectorState(0);

  u8g2.sendBuffer();
}

void loop(){
  if(nextFrame_ms <= millis())
  {
    nextFrame_ms = millis() + millisBetweenFrames_ms;
    drawBbsFired(OpenMosfetEspNowClient::getCurrentBbsFired());
    drawBatteryVoltage(OpenMosfetEspNowClient::getCurrentBatteryVoltage());
    drawSelectorState(OpenMosfetEspNowClient::getCurrentSelectorState());
    u8g2.sendBuffer();
  }
}
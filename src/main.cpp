/*
**********************************************************************************
M5 ATOM Lite 
SK6812 LED グラデーション表示
   ※using libratries=> M5ATOM, FastLED
**********************************************************************************
*/
#include <M5Atom.h>
#include "myGraphics.hpp"
#include "mySerialBT.hpp"
#include "famicon.hpp"
#include "myTask.hpp"



uint cnt= 0; 

/// @brief セットアップ
void setup() 
{
  int i;
  // 本体初期化（UART有効, I2C無効, LED有効）
  M5.begin(true,false,true);
  delay(50);
  Serial.println("Start");
  uint8_t bt_mac[6];
  esp_read_mac(bt_mac, ESP_MAC_BT);
  Serial.printf("%02X:%02X:%02X:%02X:%02X:%02X\n",
                 bt_mac[0], bt_mac[1], bt_mac[2], bt_mac[3], bt_mac[4], bt_mac[5]);
  for(i=0; i<=1; i++)
  {
    M5.dis.drawpix(0, 0x000FFF000);
    delay(500);
    M5.dis.drawpix(0, 0x000000);
    delay(500); 
  }
  //bluetooth開始-----------------
  SerialBT.begin("M5 ATOM01");
  //SSD1306初期化-----------------
  lcd.init();
  canvas.createSprite(lcd.width(), lcd.height());
  canvas.setTextWrap(true);      //自動折返し：無し
  canvas.fillScreen(TFT_BLACK);   //背景塗りつぶし
  canvas.setTextColor(TFT_WHITE); //文字色

  famiconInit();
  //タスク開始---------------------
  setupTask();
  //グローバル変数　カウント値初期化
  cnt=0;
}

/// @brief メインループ
void loop() 
{
  M5.dis.drawpix(0, 0x000FFF000);
  delay(500);
  M5.dis.drawpix(0, 0x000000);
  delay(500); 
}


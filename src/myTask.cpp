#include "myTask.hpp"
#include "mySerialBT.hpp"
#include "famicon.hpp"
#include "myGraphics.hpp"

void setupTask()
{
    xTaskCreate(my_task, "my_task", 2048, NULL, 1, NULL);
}

void my_task(void *arg) 
{
  uint16_t buttonState; 
  String buttonName; 
  while (1) 
  {
    buttonState = famiconGetButtonState();
    if(buttonState!=0xFFF0)
    {
        //famiconPrintButtonState(buttonState);
        SerialBT.printf("%04X\n",buttonState);
        buttonName = famiconGetButtonName(buttonState);
        //SSD1306 表示------------------------------------
        canvas.startWrite();//通信を開始する。（ペリフェラルを占有する）
        canvas.fillScreen(TFT_BLACK);    // 背景塗り潰し
        canvas.setTextSize(1);
        canvas.setCursor(0,0, &Font4);
        canvas.printf("%s\n",buttonName);
        canvas.pushSprite(0,0);
        canvas.endWrite();//通信を終了する。（ペリフェラルの占有を終了する)
    }else{
      SerialBT.printf("%04X\n",0xFFF0);
    }
    vTaskDelay(INTERVAL_TASK / portTICK_RATE_MS);
  }
}
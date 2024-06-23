
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <Wire.h>

class LGFX_SSD1306 : public lgfx::LGFX_Device
{
  lgfx::Panel_SSD1306 _panel_instance;  // SSD1306
  lgfx::Bus_I2C       _bus_instance;    // バス設定用構造体

  //コンストラクタ
  public:
    LGFX_SSD1306()
    {
      //I2Cバスクラス構造体
      {
        auto cfg = _bus_instance.config();  //I2Cバス構造体インスタンスの取得
        cfg.i2c_port = 1; //Wire1を選択
        cfg.freq_write  = 400000;     // 送信時のクロック ｸﾛｯｸ周波数
        cfg.freq_read   = 400000;     // 受信時のクロック ｸﾛｯｸ周波数
        cfg.pin_sda     = 25;         // SDAを接続しているピン番号 SDAピン
        cfg.pin_scl     = 21;         // SCLを接続しているピン番号 SCLピン
        cfg.i2c_addr    = 0x3C;       // I2Cデバイスのアドレス スレーブアドレス
        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
      }
      {
        auto cfg = _panel_instance.config();
        cfg.offset_rotation = 2;
        _panel_instance.config(cfg);
      }
      setPanel(&_panel_instance);
    }
};

extern LGFX_SSD1306 lcd;
extern LGFX_Sprite  canvas;
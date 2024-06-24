#include "famicon.hpp"
#include "mySerialBT.hpp"

/// @brief スーファミコントローラ初期化
void famiconInit(void)
{
    pinMode(PS,OUTPUT);
    pinMode(CLK,OUTPUT);
    pinMode(DATA1,INPUT);
}

/// @brief スーファミコントローラ押下状況取得
/// @param  
/// @return 16bitデータ上位１２ビットが押下状況。アクティブロー。
uint16_t famiconGetButtonState(void)
{
    uint16_t w_val;
    uint8_t cnt;
    w_val=0x0000;
    cnt=0;
        
    //最初の1ビット　PS端子と同期を取る。
    digitalWrite(PS,HIGH);
    digitalWrite(CLK,HIGH);
    delayMicroseconds(10);
    digitalWrite(PS,LOW);
    digitalWrite(CLK,LOW);
    delayMicroseconds(10);
        

    w_val|=digitalRead(DATA1);
    w_val<<=1;
    cnt++;

    //2ビット目以降のデータ取得
    do{
        digitalWrite(CLK,HIGH);
        delayMicroseconds(10);
        digitalWrite(CLK,LOW);
        // __delay_us(5);
        w_val|=digitalRead(DATA1);
        if(cnt!=15)
        {
            w_val<<=1;
        }
        cnt++;
    }while(cnt!=16);
    w_val&=0xFFF0;//上位１２ビットが押下状況。
    return w_val;
}


/// @brief スーファミコントローラ押下状況シリアルBT出力
/// @param buttonValue 
void famiconPrintButtonState(uint16_t buttonValue)
{
     if(buttonValue!=0xFFF0)    
        {
            if((buttonValue&0x8000)==0x0)
            {
                SerialBT.printf("B ");
            }
            
            if((buttonValue&0x4000)==0x0)
            {
                SerialBT.printf("Y ");
            }
            
            if((buttonValue&0x2000)==0x0)
            {
                SerialBT.printf("SELECT ");
            }
            
            if((buttonValue&0x1000)==0x0)
            {
                SerialBT.printf("START ");
            }
            
            if((buttonValue&0x0800)==0x0)
            {
                SerialBT.printf("UP ");             
            }
                        
            if((buttonValue&0x0400)==0x0)
            {
                SerialBT.printf("DOWN ");
            }
            
            if((buttonValue&0x0200)==0x0)
            {
                SerialBT.printf("LEFT ");
            }
            
            if((buttonValue&0x0100)==0x0)
            {
                SerialBT.printf("RIGHT ");
            }
            
            if((buttonValue&0x0080)==0x0)
            {
                SerialBT.printf("A ");
            }
            
            if((buttonValue&0x0040)==0x0)
            {
                SerialBT.printf("X ");
            }
            
            if((buttonValue&0x0020)==0x0)
            {
                SerialBT.printf("L ");
            }
            
            if((buttonValue&0x0010)==0x0)
            {
                SerialBT.printf("R ");
            }
            SerialBT.printf("%04x\n",buttonValue);
        }
}

/// @brief スーファミコントローラ押下ボタン名取得
/// @param buttonValue 
/// @return ボタン名
String famiconGetButtonName(uint16_t buttonValue) 
{
    String buttonName;
    if(buttonValue!=0xFFF0)    
        {
            if((buttonValue&0x8000)==0x0)
            {
                buttonName+="B ";
            }
            
            if((buttonValue&0x4000)==0x0)
            {
                buttonName+="Y ";
            }
            
            if((buttonValue&0x2000)==0x0)
            {
                buttonName+="SELECT ";
            }
            
            if((buttonValue&0x1000)==0x0)
            {
                buttonName+="START ";
            }
            
            if((buttonValue&0x0800)==0x0)
            {
                buttonName+="UP ";             
            }
                        
            if((buttonValue&0x0400)==0x0)
            {
                buttonName+="DOWN ";
            }
            
            if((buttonValue&0x0200)==0x0)
            {
                buttonName+="LEFT ";
            }
            
            if((buttonValue&0x0100)==0x0)
            {
                buttonName+="RIGHT ";
            }
            
            if((buttonValue&0x0080)==0x0)
            {
                buttonName+="A ";
            }
            
            if((buttonValue&0x0040)==0x0)
            {
                buttonName+="X ";
            }
            
            if((buttonValue&0x0020)==0x0)
            {
                buttonName+="L ";
            }
            
            if((buttonValue&0x0010)==0x0)
            {
                buttonName+="R ";
            }
            return buttonName;
        }
}
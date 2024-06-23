/* 
 * File:   famicon.h
 * Author: H
 *
 * Created on 2024/05/31, 10:23
 */

#ifndef FAMICON_H
#define	FAMICON_H

#include <stdint.h>
#include <M5Atom.h>
    
//PS:オレンジ
//CLK:黄
//DATA1:赤
#define PS      G19
#define CLK     G23
#define DATA1   G33

extern  void famiconInit(void);    
extern  uint16_t famiconGetButtonState(void);
extern  void famiconPrintButtonState(uint16_t);
extern  String famiconGetButtonName(uint16_t);    
   


#endif	/* FAMICON_H */


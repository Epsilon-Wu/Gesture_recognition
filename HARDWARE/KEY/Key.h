#ifndef __KEY_H
#define __KEY_H
#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "sys.h"
#include "Display.h"

#define Guang_biao_switch_key_press  PAin(12)==0
#define Confirm_key_press  					 PAin(15)==0
#define Back_key_press  					 	 PBin(6)==0

void Key_Init(void);//按键初始化
void Flag_Reverse(void);//光标反转
void Confirm_Press (void);//确认键按下
u8 	 Back_Press (void);//返回键按下
#endif

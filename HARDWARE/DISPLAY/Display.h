#ifndef __DISPLAY_H
#define __DISPLAY_H
#include "sys.h"
#include "oled.h"

#include "delay.h"
#include "Key.h"
void Start_Display (void);       //开机动画显示
void Level0_Display (void);      //第一级菜单显示
void Level1_Display (void);      //第二级菜单显示
void Level2_Display (void);      //第三级菜单显示
void Flag_Display (void);        //光标显示
void Screen_Display (void);      //界面显示
void ChuShi (void);              //"请出示手势"
void CaiQuan_Dispay (uint8_t t); //猜拳判断结果显示
void HuaQuan_Dispay (uint8_t t); //划拳判断结果显示 
void TrainFinish_Dispay (void);   //训练结束显示
void Enviro_Init_Dispaly (void);   //环境检测展示
void Learning_Dispaly (void);      //学习中展示
#endif

#ifndef __DISPLAY_H
#define __DISPLAY_H
#include "sys.h"
#include "oled.h"

#include "delay.h"
#include "Key.h"
void Start_Display (void);       //����������ʾ
void Level0_Display (void);      //��һ���˵���ʾ
void Level1_Display (void);      //�ڶ����˵���ʾ
void Level2_Display (void);      //�������˵���ʾ
void Flag_Display (void);        //�����ʾ
void Screen_Display (void);      //������ʾ
void ChuShi (void);              //"���ʾ����"
void CaiQuan_Dispay (uint8_t t); //��ȭ�жϽ����ʾ
void HuaQuan_Dispay (uint8_t t); //��ȭ�жϽ����ʾ 
void TrainFinish_Dispay (void);   //ѵ��������ʾ
void Enviro_Init_Dispaly (void);   //�������չʾ
void Learning_Dispaly (void);      //ѧϰ��չʾ
#endif

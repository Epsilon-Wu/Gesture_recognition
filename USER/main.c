#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "Key.h"
#include "sys.h"
#include "oled.h"
#include "Display.h"
#include "Encoder.h"
#include "fdc2214.h"
#include "usart.h"
#include "Judge.h"
#include "timer.h"

uint8_t flag = 0; //���
uint8_t confirm = 0; //ȷ�ϼ�
uint8_t back = 0; //���ؼ�
uint8_t level = 0; //����㼶
uint8_t mode = 0; //ģʽѡ��
uint8_t game = 0; //��Ϸѡ��

float temp0;
float res0;
float all;
uint8_t XunLian_step = 1;
float XunLian_fig[5];   //��ȭѵ��ֵ
float XunLian_ges[4];   //��ȭѵ��ֵ
void Sys_Init(void);


int main(void)
{
    Sys_Init();
    Start_Display();
    while (1)
    {

        Flag_Display();
        Flag_Reverse();
        Confirm_Press();
        Back_Press();
        Screen_Display();
        //		HuaQuan_judgement ();
    }

}

void Sys_Init(void)
{
    delay_init();	    							 								//��ʱ������ʼ��
    OLED_Init();																			//OLED��ʼ��
    Key_Init();
    Encoder_Init();
    NVIC_Configuration();
    uart_init(9600);
    while(FDC2214_Init());

    delay_ms(20);

}



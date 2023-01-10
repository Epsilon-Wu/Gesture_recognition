#include "Key.h"
#include "Display.h"
#include "delay.h"
#include "Judge.h"
#include "fdc2214.h"
extern float temp0;   				//��ʼֵ
extern uint8_t flag;  				//���
extern uint8_t level; 				//����㼶
extern uint8_t mode;   				//ģʽѡ��
extern uint8_t game;   				//��Ϸѡ��
extern uint8_t XunLian_step; //ѵ������
void Key_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_15 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6  ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

//uint8_t Key_GetNum(void)
//{
//	uint8_t KeyNum = 0;
//	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
//	{
//		Delay_ms(20);
//		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
//		Delay_ms(20);
//		KeyNum = 1;
//	}
//	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
//	{
//		Delay_ms(20);
//		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
//		Delay_ms(20);
//		KeyNum = 2;
//	}
//
//	return KeyNum;
//}
void Flag_Reverse(void)
{
    if (Guang_biao_switch_key_press)
    {
        delay_ms(20);
        while (Guang_biao_switch_key_press);
        delay_ms(20);
        flag = 1 - flag;
    }
}

void Confirm_Press (void)
{
    if (Confirm_key_press)
    {
        delay_ms(20);
        while (Confirm_key_press);
        delay_ms(20);
        OLED_Clear();
			
        if (level == 0)
        {
            mode = flag;
            level++;
        }
				else if(level == 1)
        {
            game = flag;
            level++;
        }
        else if(level ==2)
        {
            if (mode == 0)
            {
                if (game == 0)
                {
                    Enviro_Init_Dispaly();
										temp0=Cap_Calculate(0);
                    while (1)												//��ȭ�о�����
                    {


                       CaiQuan_judgement();										
                        if(Back_Press() == 1)			//�������˳������˳�����
                            break;
                    }
                    

                }
                else
                {
                    Enviro_Init_Dispaly();
										temp0=Cap_Calculate(0);
                    while (1) 										//��ȭ�о�����
                    {

                         HuaQuan_judgement();
											
                        if(Back_Press() == 1)   //�������˳������˳�����
                            break;
                    }
                }
            }
            else
            {
                if (game == 0)
                {
									  Enviro_Init_Dispaly();
										temp0=Cap_Calculate(0);			
//                    while (1) 									 //��ȭѵ������
//                    {
     
                       Caiquan_Pratice();
												


                }
                else
                {
																								
									  Enviro_Init_Dispaly();
										temp0=Cap_Calculate(0);

                       Huaquan_Pratice();
  
									
                }
            }
        }




    }
}

u8 Back_Press (void)
{
    if (Back_key_press)
    {
        delay_ms(20);
        while (Back_key_press);
        delay_ms(20);
        if(level != 0)
        {
            level--;
						 OLED_Clear();
        }
        return 1;
    }

    else
        return 0;
}




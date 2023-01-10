#include "Judge.h"
#include "stm32f10x.h"                  // Device header
#include "oled.h"
#include "fdc2214.h"
#include "kalman.h"
#include "delay.h"
#include "timer.h"
#include "Key.h"
#include "Display.h"
extern float all;
extern float res0;
extern float temp0;
extern uint8_t game;
extern uint8_t XunLian_step;
extern float XunLian_fig[6];    //划拳训练值
extern float XunLian_ges[4];	  //猜拳训练值
void HuaQuan_judgement (void)
{
    float t;
    uint8_t i = 0;
    uint8_t likely[6];
    uint8_t max, retall;

    for(i = 0; i < 6; i++)
        likely[i] = 0;


    for(i = 0; i < 200; i++)
    {
        res0 = Cap_Calculate(0) - temp0;		//通道0

        all = all + res0;
        t = t + 1;

        if(t == 10)
        {
            all = all / 10;
            all =  all * 1000;
//            OLED_ShowNum(0, 0, all, 4, 16, 1);

            if( all >= 200 && all < (XunLian_fig[1] + XunLian_fig[2]) / 2 )
            {
                likely[1]++;
            }

            else if((all >= (XunLian_fig[1] + XunLian_fig[2]) / 2) && (all < ( (XunLian_fig[2] + XunLian_fig[3]) / 2.0) - 35))
            {

                likely[2]++;
            }

            else if((all >= (((XunLian_fig[2] + XunLian_fig[3]) / 2.0) - 35)) && (all < (((XunLian_fig[3] + XunLian_fig[4]) / 2)) - 30))
            {

                likely[3]++;
            }

            else if((all >= (((XunLian_fig[3] + XunLian_fig[4]) / 2)) - 30) && (all < (XunLian_fig[4] + XunLian_fig[5]) / 2))
            {

                likely[4]++;
            }

            else if(all >= (XunLian_fig[4] + XunLian_fig[5]) / 2)
            {
                likely[5]++;
            }

            all = 0;
            t = 0;
        }

    }
    max = likely[0];
    retall = 0;

    for(i = 1; i <= 5; i++)
    {
        if(likely[i] > max)
        {
            max = likely[i];
            retall = i;
        }
    }
//    OLED_ShowNum(0, 16, retall, 1, 16, 1);
		OLED_ShowChinese(48, 16, retall+3 , 32, 1);
    OLED_Refresh();
}

void CaiQuan_judgement (void)
{

    float t;
    uint8_t i = 0;
    uint8_t likely[6];
    uint8_t max, retall;

    for(i = 0; i < 4; i++)
        likely[i] = 0;


    for(i = 0; i < 200; i++)
    {
        res0 = Cap_Calculate(0) - temp0;		//通道0
        all = all + res0;
        t = t + 1;
        if(t == 10)
        {
            all = all / 10;
            all =  all * 1000;
//            OLED_ShowNum(0, 0, all, 4, 16, 1);

                   if(all >= 150 && all < (XunLian_ges[1] + XunLian_ges[2]) / 2)
                    {

                        likely[1]++;    //剪刀
                    }
                    else if((all > (XunLian_ges[1] + XunLian_ges[2]) / 2) && (all < (XunLian_ges[2] + XunLian_ges[3]) / 2))
                    {
                        likely[2]++;   //石头
                    }
                    else if(all > (XunLian_ges[2] + XunLian_ges[3]) / 2)
                    {
                        likely[3]++;   //布
                    }					
                    else
                   {
                        likely[0]++;
                   }
						
            all = 0;
            t = 0;
        }

    }

    max = likely[0];
    retall = 0;

    for(i = 0; i <= 3; i++)
    {
        if(likely[i] >= max)
        {
            max = likely[i];
            retall = i;
        }
    }
    if(retall == 1)
    {
        OLED_ShowChinese(48, 16, 0 , 32, 1);
        OLED_Refresh();
    }
    else if(retall == 2)
    {
        OLED_ShowChinese(48, 16, 1 , 32, 1);
        OLED_Refresh();
    }
    else if(retall == 3)
    {
        OLED_ShowChinese(48, 16, 2, 32, 1);
        OLED_Refresh();
    }
    else
    {
        OLED_ShowChinese(48, 16, 3, 32, 1);
        OLED_Refresh();
    }

}

void Huaquan_Pratice(void)
{
    uint16_t i, j;
    uint8_t mark = 0, t;
    float sb1, h;


    if	(mark == 0)
    {
        for(i = 1; i <= 5; i++)
        {

					  ChuShi();
		        OLED_ShowChinese(48, 24, i+3 , 32, 1);
            OLED_Refresh();

            delay_ms(1000);
						if(Back_Press() == 1)
            {
							i=5;
						}					  
            delay_ms(1000);
						if(Back_Press() == 1)
            {
							i=5;
						}						
            delay_ms(1000);
						if(Back_Press() == 1)
            {
							i=5;
						}
            OLED_Clear();
						Learning_Dispaly();
            t = 0;
            for(j = 0; j < 20; j++)
            {
                 

                for(h = 0; h < 10; h++)
                {
                    res0 = Cap_Calculate(0) - temp0;		//通道0
                    sb1 = sb1 + res0;
                }
                all = sb1 / 10 + all;
                sb1 = 0;
                delay_ms(50);
								OLED_DrawLine(0,52,6*j,52,1);
								OLED_DrawLine(0,53,6*j,53,1);
								OLED_DrawLine(0,54,6*j,54,1);
								OLED_DrawLine(0,55,6*j,55,1);
								OLED_Refresh();
            }
						OLED_Clear();
						if(Back_Press() == 1)
            {
							i=5;
						}						
            all = all / 20;
            XunLian_fig[i] = all * 1000;
            if(i == 5)
            {
                mark = 1;

                 TrainFinish_Dispay ();   //训练结束显示
                delay_ms(1000);
            }
        }
    }

    OLED_Clear();
	}





void Caiquan_Pratice(void)
{
    uint16_t i, j;
    uint8_t mark = 0, t;
    float sb1, h;



    if(mark == 0)
    {

        for(i = 1; i <= 3; i++)
        {
						ChuShi();
					  OLED_ShowChinese(48, 24, i-1, 32, 1);
//          OLED_ShowNum(0, 16, i, 1, 16, 1);
            OLED_Refresh();
            delay_ms(1000);
					  if(Back_Press() == 1)
            {
							i=3;
						}
            delay_ms(1000);
						if(Back_Press() == 1)
            {
							i=3;
						}
            delay_ms(1000);
						
						OLED_Clear();
						Learning_Dispaly();
            t = 0;

            for(j = 0; j < 20; j++)
            {
                for(h = 0; h < 10; h++)
                {
                    res0 = Cap_Calculate(0) - temp0;		//通道0
                    sb1 = sb1 + res0;
                }
                all = sb1 / 10 + all;
                sb1 = 0;
                delay_ms(50);
								OLED_DrawLine(0,52,6*j,52,1);
								OLED_DrawLine(0,53,6*j,53,1);
								OLED_DrawLine(0,54,6*j,54,1);
								OLED_DrawLine(0,55,6*j,55,1);
								OLED_Refresh();
            }
						OLED_Clear();
            all = all / 20;
            XunLian_ges[i] = all * 1000;

            if(i == 3)
            {
              mark = 1;
							TrainFinish_Dispay ();   //训练结束显示
							delay_ms(1000);
            }
        }
    }
    OLED_Clear();
}







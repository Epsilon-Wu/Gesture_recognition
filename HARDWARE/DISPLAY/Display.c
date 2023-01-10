#include "Display.h"
#include "delay.h"
extern	uint8_t flag;
extern uint8_t level;
extern uint8_t mode;   //ģʽѡ��
extern uint8_t game;   //��Ϸѡ��




void Flag_Display (void)  //�����ʾ
{
if (level!=2)
{
	if (flag==0)
  {
		OLED_ShowChinese(80,16,19,16,1);// �س�
		OLED_ShowString(80,32,"  ",16,1);  //�ո�

  }else{
		OLED_ShowChinese(80,32,19,16,1);// �س�
		OLED_ShowString(80,16,"  ",16,1); //�ո�
	}
}
else
	{
		OLED_ShowString(80,32,"  ",16,1);//�ո�
    OLED_ShowString(80,16,"  ",16,1);//�ո�
	}
	
  
}
void Screen_Display (void)
{
	if (level==0) 
		Level0_Display(); 
	else if(level==1)	
		Level1_Display();	
	else
		Level2_Display();
	
	
}
void Level0_Display (void)   //��һ���˵���ʾ
{
	OLED_ShowChinese(0,0,4,16,0);//ģ 
	OLED_ShowChinese(16,0,5,16,0);//ʽ 
	OLED_ShowChinese(32,0,6,16,0);//ѡ 
	OLED_ShowChinese(48,0,7,16,0);//�� 
																														
			OLED_ShowNum(0 ,18,1,1,16,1);		//1     							
		 OLED_ShowChar(8,18,'.',16,1);		//.										
	OLED_ShowChinese(32-15,18,10,16,1);		//��
	OLED_ShowChinese(48-15,18,11,16,1);		//��
	OLED_ShowChinese(64-15,18,4,16,1);			//ģ
	OLED_ShowChinese(80-15,18,5,16,1);			//ʽ
	
	    OLED_ShowNum( 0,35,2,1,16,1);	  //2
	   OLED_ShowChar(8,35,'.',16,1);	  //.
	OLED_ShowChinese(32-15,35,8,16,1);		  //ѵ
	OLED_ShowChinese(48-15,35,9,16,1);		  //��
	OLED_ShowChinese(64-15,35,4,16,1);		  //ģ
	OLED_ShowChinese(80-15,35,5,16,1);		  //ʽ
	OLED_Refresh();
}

void Start_Display (void)   //����������ʾ
{
	OLED_ShowChinese(0,24,0,16,1);//��
	OLED_ShowChinese(16,24,1,16,1);//��
	OLED_ShowChinese(32,24,2,16,1);//ʶ
	OLED_ShowChinese(48,24,3,16,1);//��
	OLED_ShowChinese(64,24,43,16,1);//װ
	OLED_ShowChinese(80,24,44,16,1);//��
  OLED_ShowString(96,24,"V2.0",16,1);//V2.0
	OLED_Refresh();
	delay_ms(1000);
	OLED_Clear();
	
//	Level0_Display();
	
}

void Level1_Display (void)   //�ڶ����˵���ʾ
{
																							/////ͨ��
	OLED_ShowChinese(32,0,4,16,0);//ģ						//��һ��
	OLED_ShowChinese(48,0,5,16,0);//ʽ            //��һ��
	 
  			OLED_ShowNum(0 ,18,1,1,16,1);		//1     //�ڶ���
		 OLED_ShowChar(8,18,'.',16,1);			//.     //�ڶ���
			
	OLED_ShowChinese(32-15,18,12,16,1);//��						//�ڶ���
	OLED_ShowChinese(48-15,18,14,16,1);//ȭ					//�ڶ���
	
	
			OLED_ShowNum( 0,35,2,1,16,1);	  	//2			//������
	   OLED_ShowChar(8,35,'.',16,1);	  	//.			//������
	OLED_ShowChinese(32-15,35,13,16,1);//��						//�ڶ���
	OLED_ShowChinese(48-15,35,14,16,1);//ȭ					//�ڶ���

	
	if (mode==0)
  {
  
	OLED_ShowChinese(0,0,10,16,0);//��
	OLED_ShowChinese(16,0,11,16,0);//��
	OLED_ShowChinese(64-15,18,10,16,1);//��
	OLED_ShowChinese(80-15,18,11,16,1);//��
	OLED_ShowChinese(64-15,35,10,16,1);//��
	OLED_ShowChinese(80-15,35,11,16,1);//��
  }
  else
  {
	
	OLED_ShowChinese(0,0,8,16,0);					//ѵ
	OLED_ShowChinese(16,0,9,16,0);				//��

	OLED_ShowChinese(64-15,18,8,16,1);		//ѵ
	OLED_ShowChinese(80-15,18,9,16,1);		//��
		
	OLED_ShowChinese(64-15,35,8,16,1);		//ѵ
	OLED_ShowChinese(80-15,35,9,16,1);		//��
  }

	OLED_Refresh();
}
void Level2_Display (void)   //�������˵���ʾ
{

	if (mode==0)
  {
	OLED_ShowChinese(32,0,10,16,1);//��
	OLED_ShowChinese(48,0,11,16,1);//��		
  }
	else
  {
	OLED_ShowChinese(32,0,8,16,1);//ѵ
	OLED_ShowChinese(48,0,9,16,1);//��
  }
	
	if (game==0)
  {
	OLED_ShowChinese(0,0,12,16,1);//��
	OLED_ShowChinese(16,0,14,16,1);//ȭ
  }
  else
  {
	OLED_ShowChinese(0,0,13,16,1);//��
	OLED_ShowChinese(16,0,14,16,1);//ȭ
  }
	
//	OLED_ShowChinese(49,32,15,16,1);//��
//	OLED_ShowChinese(49+16,32,16,16,1);//��
//	OLED_ShowChinese(49,48,15,16,1);//��
//	OLED_ShowChinese(49+16,48,16,16,1);//��
	OLED_ShowChinese(49+16+16,32,17,16,1);//��
	OLED_ShowChinese(49+16+16+16,32,18,16,1);//ʼ	
	OLED_ShowChinese(49+16+16,48,45,16,1);//��
	OLED_ShowChinese(49+16+16+16,48,46,16,1);//��		
	OLED_ShowChinese(49+16+16+16+16,32,19,16,1);// �س�
	OLED_ShowChinese(49+16+16+16+16,48,19,16,1);// �س�
	OLED_Refresh();
}

void ChuShi (void)
{
	OLED_ShowChinese(0,0,25,16,1);//��
	OLED_ShowChinese(0+16,0,26,16,1);//��
	OLED_ShowChinese(0+16+16,0,27,16,1);//ʾ
	OLED_ShowChinese(0+16+16+16,0,28,16,1);//��
	OLED_ShowChinese(0+16+16+16+16,0,29,16,1);//��
}

void CaiQuan_Dispay (uint8_t t)
{
	switch (t)
     {
     	case 1:
				OLED_ShowChinese(48,24,20,16,1);     //ʯ
				OLED_ShowChinese(48+16,24,21,16,1);  //ͷ
				OLED_Refresh();
        break;
      case 2:
				OLED_ShowChinese(48,24,22,16,1);     //��
			  OLED_ShowChinese(48+16,24,23,16,1);  //��
				OLED_Refresh();
        break;
			case 3:
				OLED_ShowChinese(56,24,24,16,1);//��
        OLED_ShowString(48,24," ",16,1);//�ո�											
				OLED_ShowString(72,24," ",16,1);//�ո�
				OLED_Refresh();		
        break;
      default:
        OLED_ShowString(48,24,"    ",16,1);//�ո�											
				OLED_ShowString(48,24,"    ",16,1);//�ո�
				OLED_Refresh();						
        break;
     }
}

void HuaQuan_Dispay (uint8_t t)
{
	switch (t)
  {
  	case 1:
			OLED_ShowNum(56,24,1,1,16,1);
	  	OLED_Refresh();
  		break;
  	case 2:
			OLED_ShowNum(56,24,2,1,16,1);
	  	OLED_Refresh();
  		break;
		case 3:
			OLED_ShowNum(56,24,3,1,16,1);
	  	OLED_Refresh();
  		break;
		case 4:
			OLED_ShowNum(56,24,4,1,16,1);
	  	OLED_Refresh();
  		break;
		case 5:
			OLED_ShowNum(56,24,5,1,16,1);
		  OLED_Refresh();
  		break;
  	default:
			OLED_ShowString(56,24,"  ",16,1);//�ո�
	  	OLED_Refresh();
  		break;
  }
}
void TrainFinish_Dispay (void)
{
	  OLED_Clear();
    OLED_ShowChinese(0+32, 24, 8, 16, 1);  		//ѵ
    OLED_ShowChinese(16+32, 24, 9, 16, 1); 		//��
    OLED_ShowChinese(32+32, 24, 30, 16, 1);  	//��
    OLED_ShowChinese(48+32, 24, 31, 16, 1);  	//��
    OLED_Refresh();
}
void Enviro_Init_Dispaly (void)
{
	u8 i;
	OLED_ShowChinese(0,0,32,16,1);//��
	OLED_ShowChinese(16,0,33,16,2);//��
	OLED_ShowChinese(16+16,0,34,16,3);//��
	OLED_ShowChinese(16+16+16,0,35,16,4);//��
	OLED_ShowString(0,32,"SCANNING",16,1);
	OLED_Refresh();	
	for(i=0;i<128;i++)
  {
		OLED_DrawPoint(i,52,1);
		OLED_DrawPoint(i,53,1);
		OLED_DrawPoint(i,54,1);
		OLED_DrawPoint(i,55,1);
		delay_ms(10);
		OLED_Refresh();
  }
   OLED_Clear();
}
void Learning_Dispaly (void)
{
	OLED_ShowChinese(0,0,36,16,1);//ѧ
	OLED_ShowChinese(16,0,37,16,2);//ϰ
	OLED_ShowChinese(16+16,0,38,16,3);//��
  OLED_ShowChinese(0,16,39,16,1);//��
	OLED_ShowChinese(16,16,40,16,2);//��
	OLED_ShowChinese(16+16,16,47,16,3);//��
	OLED_ShowChinese(16+16+16,16,48,16,3);//��
	OLED_ShowString(0,32,"LEARNING",16,1);
	OLED_Refresh();
}

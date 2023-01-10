#include "Display.h"
#include "delay.h"
extern	uint8_t flag;
extern uint8_t level;
extern uint8_t mode;   //模式选择
extern uint8_t game;   //游戏选择




void Flag_Display (void)  //光标显示
{
if (level!=2)
{
	if (flag==0)
  {
		OLED_ShowChinese(80,16,19,16,1);// 回车
		OLED_ShowString(80,32,"  ",16,1);  //空格

  }else{
		OLED_ShowChinese(80,32,19,16,1);// 回车
		OLED_ShowString(80,16,"  ",16,1); //空格
	}
}
else
	{
		OLED_ShowString(80,32,"  ",16,1);//空格
    OLED_ShowString(80,16,"  ",16,1);//空格
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
void Level0_Display (void)   //第一级菜单显示
{
	OLED_ShowChinese(0,0,4,16,0);//模 
	OLED_ShowChinese(16,0,5,16,0);//式 
	OLED_ShowChinese(32,0,6,16,0);//选 
	OLED_ShowChinese(48,0,7,16,0);//择 
																														
			OLED_ShowNum(0 ,18,1,1,16,1);		//1     							
		 OLED_ShowChar(8,18,'.',16,1);		//.										
	OLED_ShowChinese(32-15,18,10,16,1);		//判
	OLED_ShowChinese(48-15,18,11,16,1);		//决
	OLED_ShowChinese(64-15,18,4,16,1);			//模
	OLED_ShowChinese(80-15,18,5,16,1);			//式
	
	    OLED_ShowNum( 0,35,2,1,16,1);	  //2
	   OLED_ShowChar(8,35,'.',16,1);	  //.
	OLED_ShowChinese(32-15,35,8,16,1);		  //训
	OLED_ShowChinese(48-15,35,9,16,1);		  //练
	OLED_ShowChinese(64-15,35,4,16,1);		  //模
	OLED_ShowChinese(80-15,35,5,16,1);		  //式
	OLED_Refresh();
}

void Start_Display (void)   //开机动画显示
{
	OLED_ShowChinese(0,24,0,16,1);//手
	OLED_ShowChinese(16,24,1,16,1);//势
	OLED_ShowChinese(32,24,2,16,1);//识
	OLED_ShowChinese(48,24,3,16,1);//别
	OLED_ShowChinese(64,24,43,16,1);//装
	OLED_ShowChinese(80,24,44,16,1);//置
  OLED_ShowString(96,24,"V2.0",16,1);//V2.0
	OLED_Refresh();
	delay_ms(1000);
	OLED_Clear();
	
//	Level0_Display();
	
}

void Level1_Display (void)   //第二级菜单显示
{
																							/////通用
	OLED_ShowChinese(32,0,4,16,0);//模						//第一行
	OLED_ShowChinese(48,0,5,16,0);//式            //第一行
	 
  			OLED_ShowNum(0 ,18,1,1,16,1);		//1     //第二行
		 OLED_ShowChar(8,18,'.',16,1);			//.     //第二行
			
	OLED_ShowChinese(32-15,18,12,16,1);//猜						//第二行
	OLED_ShowChinese(48-15,18,14,16,1);//拳					//第二行
	
	
			OLED_ShowNum( 0,35,2,1,16,1);	  	//2			//第三行
	   OLED_ShowChar(8,35,'.',16,1);	  	//.			//第三行
	OLED_ShowChinese(32-15,35,13,16,1);//划						//第二行
	OLED_ShowChinese(48-15,35,14,16,1);//拳					//第二行

	
	if (mode==0)
  {
  
	OLED_ShowChinese(0,0,10,16,0);//判
	OLED_ShowChinese(16,0,11,16,0);//决
	OLED_ShowChinese(64-15,18,10,16,1);//判
	OLED_ShowChinese(80-15,18,11,16,1);//决
	OLED_ShowChinese(64-15,35,10,16,1);//判
	OLED_ShowChinese(80-15,35,11,16,1);//决
  }
  else
  {
	
	OLED_ShowChinese(0,0,8,16,0);					//训
	OLED_ShowChinese(16,0,9,16,0);				//练

	OLED_ShowChinese(64-15,18,8,16,1);		//训
	OLED_ShowChinese(80-15,18,9,16,1);		//练
		
	OLED_ShowChinese(64-15,35,8,16,1);		//训
	OLED_ShowChinese(80-15,35,9,16,1);		//练
  }

	OLED_Refresh();
}
void Level2_Display (void)   //第三级菜单显示
{

	if (mode==0)
  {
	OLED_ShowChinese(32,0,10,16,1);//判
	OLED_ShowChinese(48,0,11,16,1);//决		
  }
	else
  {
	OLED_ShowChinese(32,0,8,16,1);//训
	OLED_ShowChinese(48,0,9,16,1);//练
  }
	
	if (game==0)
  {
	OLED_ShowChinese(0,0,12,16,1);//猜
	OLED_ShowChinese(16,0,14,16,1);//拳
  }
  else
  {
	OLED_ShowChinese(0,0,13,16,1);//划
	OLED_ShowChinese(16,0,14,16,1);//拳
  }
	
//	OLED_ShowChinese(49,32,15,16,1);//按
//	OLED_ShowChinese(49+16,32,16,16,1);//键
//	OLED_ShowChinese(49,48,15,16,1);//按
//	OLED_ShowChinese(49+16,48,16,16,1);//键
	OLED_ShowChinese(49+16+16,32,17,16,1);//开
	OLED_ShowChinese(49+16+16+16,32,18,16,1);//始	
	OLED_ShowChinese(49+16+16,48,45,16,1);//返
	OLED_ShowChinese(49+16+16+16,48,46,16,1);//回		
	OLED_ShowChinese(49+16+16+16+16,32,19,16,1);// 回车
	OLED_ShowChinese(49+16+16+16+16,48,19,16,1);// 回车
	OLED_Refresh();
}

void ChuShi (void)
{
	OLED_ShowChinese(0,0,25,16,1);//请
	OLED_ShowChinese(0+16,0,26,16,1);//出
	OLED_ShowChinese(0+16+16,0,27,16,1);//示
	OLED_ShowChinese(0+16+16+16,0,28,16,1);//手
	OLED_ShowChinese(0+16+16+16+16,0,29,16,1);//势
}

void CaiQuan_Dispay (uint8_t t)
{
	switch (t)
     {
     	case 1:
				OLED_ShowChinese(48,24,20,16,1);     //石
				OLED_ShowChinese(48+16,24,21,16,1);  //头
				OLED_Refresh();
        break;
      case 2:
				OLED_ShowChinese(48,24,22,16,1);     //剪
			  OLED_ShowChinese(48+16,24,23,16,1);  //刀
				OLED_Refresh();
        break;
			case 3:
				OLED_ShowChinese(56,24,24,16,1);//布
        OLED_ShowString(48,24," ",16,1);//空格											
				OLED_ShowString(72,24," ",16,1);//空格
				OLED_Refresh();		
        break;
      default:
        OLED_ShowString(48,24,"    ",16,1);//空格											
				OLED_ShowString(48,24,"    ",16,1);//空格
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
			OLED_ShowString(56,24,"  ",16,1);//空格
	  	OLED_Refresh();
  		break;
  }
}
void TrainFinish_Dispay (void)
{
	  OLED_Clear();
    OLED_ShowChinese(0+32, 24, 8, 16, 1);  		//训
    OLED_ShowChinese(16+32, 24, 9, 16, 1); 		//练
    OLED_ShowChinese(32+32, 24, 30, 16, 1);  	//完
    OLED_ShowChinese(48+32, 24, 31, 16, 1);  	//成
    OLED_Refresh();
}
void Enviro_Init_Dispaly (void)
{
	u8 i;
	OLED_ShowChinese(0,0,32,16,1);//环
	OLED_ShowChinese(16,0,33,16,2);//境
	OLED_ShowChinese(16+16,0,34,16,3);//检
	OLED_ShowChinese(16+16+16,0,35,16,4);//测
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
	OLED_ShowChinese(0,0,36,16,1);//学
	OLED_ShowChinese(16,0,37,16,2);//习
	OLED_ShowChinese(16+16,0,38,16,3);//中
  OLED_ShowChinese(0,16,39,16,1);//请
	OLED_ShowChinese(16,16,40,16,2);//勿
	OLED_ShowChinese(16+16,16,47,16,3);//移
	OLED_ShowChinese(16+16+16,16,48,16,3);//动
	OLED_ShowString(0,32,"LEARNING",16,1);
	OLED_Refresh();
}

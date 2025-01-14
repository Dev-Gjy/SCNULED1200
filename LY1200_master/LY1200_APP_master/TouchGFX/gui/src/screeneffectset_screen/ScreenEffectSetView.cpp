#include <gui/screeneffectset_screen/ScreenEffectSetView.hpp>
#include "math.h"
#include "control_box.h"
#include "system_data.h"
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
uint8_t FrequencySeting=0; //频率调节标志位
uint8_t EffectType;//特效类别标志位

extern char TouchGFX_Model_Choose;
extern "C"
{
	uint32_t EffSetcheckFinalCal(uint8_t Levels[]){	
		return 0x00000|(Levels[4]<<16)|(Levels[3])<<12|(Levels[2]<<8)|(Levels[1]<<4)|(Levels[0]);
	}
	uint64_t EffSetcalVarition (uint8_t GFXKeys, uint8_t Levels[]){ //按键对应的值
//	  EffectType=Levels[0];//记录选中特效编号0-7.
		switch ((GFXKeys&0xF0)>>4){
			case 0x00:				
				return EffSetcheckFinalCal(Levels);//0x10 11 12 13 14 15 16 17.
			
			case 0x01://knob1左移
			  return 0x00020;
			
			case 0x02://knob1右移
			  return 0x00030;				

			case 0x05://knob2 pressed 去调节频率
			 FrequencySeting=1;
			 Levels[0]=0;
			 Levels[MenuLevel+1]=1;
			 MenuLevel+=1;	
 			 MenuLevel=min(MenuLevel,2);
			 return EffSetcheckFinalCal(Levels);//show box 0x00110
			
			case 0x03://knob2左移	
        if(FrequencySeting == 0){				
					return 0x00040;
				}//temperature down
				else{
					return 0x00060;
				}//Frequency down
				
			case 0x04://knob2右移
        if(FrequencySeting == 0){		
					return 0x00050;
				}//temperature up
				else{
					return 0x00070;
				}//Frequency up
				
			case 0x07://key menu is pressed
//				Levels[0]=0;
//			  Levels[1]=0;
//			  Levels[2]=0;
			  memset(GFXLevels,0,sizeof(GFXLevels));//数组清为0				
				MenuLevel=0;
				return 0x0000c;//go to menu c只是数值 eg c d e 返回数组还是menu0x00000.
			case 0x08://key cct is pressed
			  memset(GFXLevels,0,sizeof(GFXLevels));//数组清为0	
				MenuLevel=0;//			
				return 0x0000d;			
			
			case 0x09://key effect is pressed
			  memset(GFXLevels,0,sizeof(GFXLevels));//数组清为0	
				MenuLevel=0;//等同back键 pressed 0x00000.			
				return 0x0000e;
			
		  case 0x0a://key back 
				FrequencySeting=0;
				Levels[0]=0;
				Levels[MenuLevel]=0;
			  MenuLevel-=1;	
 			  MenuLevel=max(MenuLevel,0);
			  return EffSetcheckFinalCal(Levels);//0x00000.0x00010
			
			default:
				return EffSetcheckFinalCal(Levels) ;
		}
	}
}

ScreenEffectSetView::ScreenEffectSetView()
{

}

char ScreenEffectSetView::LE_Model_ON()
{
	TouchGFX_Model_Choose = LIGHT_EFFECTS;
	return TouchGFX_Model_Choose;
};

char ScreenEffectSetView::LE_Model_OFF()
{
	TouchGFX_Model_Choose = MODEL_OFF;
	return TouchGFX_Model_Choose;
};	



void ScreenEffectSetView::GetEffectType(uint8_t EffectType)
{
	switch(EffectType){ //根据传入参数获取不同值
		case 0:
			Temperature_count=presenter->getPbadBulbsTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPbadBulbsLight();	
			Frequency_count=presenter->getPbadBulbsFrequency();
		break;
		
		case 1:
			Temperature_count=presenter->getPexplodeTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPexplodeLight();	
			Frequency_count=presenter->getPexplodeFrequency();			
		break;
				
		case 2:
			Temperature_count=presenter->getPfireworkTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPfireworkLight();	
			Frequency_count=presenter->getPfireworkFrequency();			
		break;
		
		case 3:
			Temperature_count=presenter->getPflashTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPflashLight();	
			Frequency_count=presenter->getPflashFrequency();			
		break;
				
		case 4:
			Temperature_count=presenter->getPlightingTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPlightingLight();	
			Frequency_count=presenter->getPlightingFrequency();			
		break;		

		case 5:
			Temperature_count=presenter->getPpaparazziTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPpaparazziLight();	
			Frequency_count=presenter->getPpaparazziFrequency();
		break;
		
		case 6:
			Temperature_count=presenter->getPpulseTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPpulseLight();	
			Frequency_count=presenter->getPpulseFrequency();			
		break;
				
		case 7:
			Temperature_count=presenter->getPtvTemperature();//刷新新界面，用指针presenter 读取记录好的数值
			Light_count=presenter->getPtvLight();	
			Frequency_count=presenter->getPtvFrequency();			
		break;		
		default:
		break;
		//...
	}
}

void ScreenEffectSetView::SaveEffectType(uint8_t ViewEffectType)
{
	switch(ViewEffectType){ //根据传入参数获取不同值
		case 0:
			presenter->savePbadBulbsLight(Light_count);
			presenter->savePbadBulbsTemperature(Temperature_count);
			presenter->savePbadBulbsFrequency(Frequency_count);
		break;
		
		case 1:			
			presenter->savePexplodeLight(Light_count);
			presenter->savePexplodeTemperature(Temperature_count);
			presenter->savePexplodeFrequency(Frequency_count);			
			break;
			//....	
		case 2:
			presenter->savePfireworkLight(Light_count);
			presenter->savePfireworkTemperature(Temperature_count);
			presenter->savePfireworkFrequency(Frequency_count);
		break;
		
		case 3:			//flash
			presenter->savePflashLight(Light_count);
			presenter->savePflashTemperature(Temperature_count);
			presenter->savePflashFrequency(Frequency_count);			
			break;		

		case 4:
			presenter->savePlightingLight(Light_count);
			presenter->savePlightingTemperature(Temperature_count);
			presenter->savePlightingFrequency(Frequency_count);
		break;
		
		case 5:			
			presenter->savePpaparazziLight(Light_count);
			presenter->savePpaparazziTemperature(Temperature_count);
			presenter->savePpaparazziFrequency(Frequency_count);			
			break;
			//....	
		case 6:
			presenter->savePpulseLight(Light_count);
			presenter->savePpulseTemperature(Temperature_count);
			presenter->savePpulseFrequency(Frequency_count);
		break;
		
		case 7:			//flash
			presenter->savePtvLight(Light_count);
			presenter->savePtvTemperature(Temperature_count);
			presenter->savePtvFrequency(Frequency_count);			
			break;			
		default:
			break;

	}
}


void ScreenEffectSetView::setupScreen()
{
	ScreenEffectSetViewBase::setupScreen();
	LE_Model_ON();
	//做标志位判断 确定存具体哪一个特效的.（枚举）
	GetEffectType(EffectType);	
////	Temperature_count=presenter->getTemperature();//刷新新界面，用指针presenter 读取记录好的数值
////	Light_count=presenter->getLight();	
////	Frequency_count=presenter->getFrequency();

	//通配符显示
  Unicode::snprintf(LightTextPgBuffer, LIGHTTEXTPG_SIZE, "%d", Light_count);
	Unicode::snprintf(TemperatureTextPgBuffer, TEMPERATURETEXTPG_SIZE, "%d", Temperature_count);
  //进度器显示
  LightingProgress.setValue(Light_count);
  TemperatureProgress.setValue(Temperature_count);
  FrequencyProgress.setValue(Frequency_count);
  FrequencyProgress.invalidate(); //更新显示进度条的值		
}

void ScreenEffectSetView::tearDownScreen()
{
	ScreenEffectSetViewBase::tearDownScreen();
	LE_Model_OFF();
	//函数保存当前三种值，很多种不同特效的
	SaveEffectType(EffectType);	
	
////	presenter->saveLight(Light_count);
////	presenter->saveTemperature(Temperature_count);
////	presenter->saveFrequency(Frequency_count);
}

void ScreenEffectSetView::handleKeyEvent(uint8_t key)
{
	ScreenMenuNumberGFX = EffSetcalVarition(key,GFXLevels);	

     switch (ScreenMenuNumberGFX) 
   { 
		 case 0x00020:
			 LightDown();
		 break;		
		 
		 case 0x00030:
			 LightUp();
		 break;
		 
		 case 0x00040:
			 TemperatureDown();
		 break;
		 
		 case 0x00050:
			 TemperatureUp();
		 break;
		 
		 case 0x00110:
			box2.setVisible(true);
			box2.invalidate();//show box
		 break;
		 
		 case 0x00010:
			box2.setVisible(false);
			box2.invalidate();				 
		 break;
		 
		 case 0x00060:
			 FrequencyDown();
		 break;
		 
		 case 0x00070:
			FrequencyUp();
		 break;
		 		 
		 case 0x0000c://key:menu back
			 application().gotoScreenMenuScreenNoTransition();
		 break;
		 
		 case 0x0000d:
			  application().gotoScreen1ScreenNoTransition();// go to cct
		 break;	
		 
		 case 0x00000:
		 case 0x0000e://key effect
			 application().gotoScreenEffectScreenNoTransition();
		 break;
		 			 
		 default:
		 break;
	 }
 }

void ScreenEffectSetView::LightDown()
{   
	Light_count--;
	Light_count=max(Light_count,0);
	SaveEffectType(EffectType);	
//	touchgfx_printf("Light_count %d\r\n", Light_count);//打印数据
	LightingProgress.setValue(Light_count);//给进度条设置亮度的值
	LightingProgress.invalidate(); //更新显示进度条的值
	//通配符显示
	Unicode::snprintf(LightTextPgBuffer, LIGHTTEXTPG_SIZE, "%d", Light_count);
	LightTextPg.invalidate();//更新显示		
	
//     LightingTextPg.updateValue(Light_count, 1000);
//     LightingTextPg.invalidate(); //文本进度条
}
void ScreenEffectSetView::LightUp()
{
	Light_count++;
	Light_count=min(Light_count,100);
	SaveEffectType(EffectType);	
//	touchgfx_printf("Light_count %d\r\n", Light_count);//打印数据
	LightingProgress.setValue(Light_count);//给进度条设置亮度的值
	LightingProgress.invalidate(); //更新显示进度条的值
	//通配符显示
	Unicode::snprintf(LightTextPgBuffer, LIGHTTEXTPG_SIZE, "%d", Light_count);
	LightTextPg.invalidate();//更新显示	
//     LightingTextPg.updateValue(Light_count, 1000);
//     LightingTextPg.invalidate(); //文本进度条	
}

void ScreenEffectSetView::TemperatureDown()
{
	Temperature_count-= 50;
	Temperature_count=max(Temperature_count,2700);
	SaveEffectType(EffectType);	
//	touchgfx_printf("Temperature_count %ld \r\n", Temperature_count);//打印数据
	TemperatureProgress.setValue(Temperature_count);//给进度条设置色温的值
	TemperatureProgress.invalidate(); //更新显示半环进度条的值
	//通配符显示
	Unicode::snprintf(TemperatureTextPgBuffer, TEMPERATURETEXTPG_SIZE, "%d", Temperature_count);
	TemperatureTextPg.invalidate();//更新显示
}
void ScreenEffectSetView::TemperatureUp()
{
	Temperature_count+= 50;
	Temperature_count=min(Temperature_count,6500);
	SaveEffectType(EffectType);	
//	touchgfx_printf("Temperature_count %ld \r\n", Temperature_count);//打印数据
	TemperatureProgress.setValue(Temperature_count);//给进度条设置色温的值
	TemperatureProgress.invalidate(); //更新显示半环进度条的值
	//通配符显示
	Unicode::snprintf(TemperatureTextPgBuffer, TEMPERATURETEXTPG_SIZE, "%d", Temperature_count);
	TemperatureTextPg.invalidate();//更新显示
}
void ScreenEffectSetView::FrequencyDown()
{	
	Frequency_count--;
	Frequency_count=max(Frequency_count,0);
	SaveEffectType(EffectType);	
//	presenter->saveFrequency(Frequency_count);//特效较多时，增加很多函数，用其他枚举
//	touchgfx_printf("Frequency_count %ld \r\n", Frequency_count);//打印数据
	FrequencyProgress.setValue(Frequency_count);//给进度条设置值
	FrequencyProgress.invalidate(); //更新显示进度条的值
}
void ScreenEffectSetView::FrequencyUp()
{
	Frequency_count++;
	Frequency_count=min(Frequency_count,10);
	SaveEffectType(EffectType);	
//	touchgfx_printf("Frequency_count %ld \r\n", Frequency_count);//打印数据
	FrequencyProgress.setValue(Frequency_count);//给进度条设置值
	FrequencyProgress.invalidate(); //更新显示进度条的值	
}
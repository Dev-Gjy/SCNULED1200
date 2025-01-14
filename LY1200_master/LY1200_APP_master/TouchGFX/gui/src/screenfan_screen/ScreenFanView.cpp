#include <gui/screenfan_screen/ScreenFanView.hpp>
#include "math.h"
#include "control_box.h"
#include <string.h>
#define max(x,y) ( x>y?x:y ) 
#define min(x,y) ( x<y?x:y )
uint8_t FanType;//风扇类别标志位

 //层级为第二层 0，1，2，3，4 数组索引
extern "C"
{	
	uint32_t FancheckFinalCal(uint8_t Levels[]){	
			uint32_t sore = 0x00000|(Levels[4]<<16)|(Levels[3])<<12|(Levels[2]<<8)|(Levels[1]<<4)|(Levels[0]);
		return 0x00000|(Levels[4]<<16)|(Levels[3])<<12|(Levels[2]<<8)|(Levels[1]<<4)|(Levels[0]);
	}
	uint64_t FancalVarition (uint8_t GFXKeys, uint8_t Levels[]){ //按键对应的值取高位进行case
		switch ((GFXKeys&0xF0)>>4){
			case 0x00:
				return FancheckFinalCal(Levels);
			case 0x01:
				Levels[MenuLevel] += (-1)*min((GFXKeys&0x0F),Levels[MenuLevel]);
			  Levels[MenuLevel] = max(Levels[MenuLevel],1);//转的范围			
				return FancheckFinalCal(Levels);//MenuLevel=1
			case 0x02:
				Levels[MenuLevel] += (GFXKeys&0x0F);
			  Levels[MenuLevel] = min(max(Levels[MenuLevel],1),4);//转的范围，应该写成循环
				return FancheckFinalCal(Levels);
			
			case 0x06://按下KNOB1
			  MenuLevel+=1;//层级加1 为2
				MenuLevel = min(MenuLevel,2);//层级边缘保护！！！
				Levels[MenuLevel] = 1;
				return FancheckFinalCal(Levels);
			case 0x07:
				Levels[MenuLevel]=0x00;//将该层数组值置为0 该层00000.			
			  MenuLevel=0;				
				return 0x00002;//返回menu
			case 0x08:
			  memset(GFXLevels,0,sizeof(GFXLevels));//数组清为0	
			  MenuLevel=0;
//			  Levels[0]=0x00; 
				return 0x0000d;//直接去cct界面
      case 0x09:
			  memset(GFXLevels,0,sizeof(GFXLevels));//数组清为0	,Levels[MenuLevel]=0x00;//将该层数组值置为0 该层00000.
			  MenuLevel=0; 
				return 0x0000e;//直接去effect界面	
     						
			case 0x0a:
				Levels[MenuLevel]=0;//MenuLevel=1
			  MenuLevel-=1;		
			  return FancheckFinalCal(Levels);//0x00002//返回menu
			default:
				return FancheckFinalCal(Levels) ;
		}
	}
}
ScreenFanView::ScreenFanView()
{

}

void ScreenFanView::setupScreen()
{
	ScreenFanViewBase::setupScreen();//刷新显示而已 type还是上次的值（否则默认为0）
		FanType=presenter->getFanType();//进入时读取type
}

void ScreenFanView::tearDownScreen()
{
    ScreenFanViewBase::tearDownScreen();
		presenter->saveFanType(FanType);//离开时记录
	
}

void ScreenFanView::hideBox()
{
			  box_0.setVisible(false);
        box_0.invalidate();
				box_1.setVisible(false);
        box_1.invalidate();
		    box_2.setVisible(false);
        box_2.invalidate();
		    box_3.setVisible(false);
        box_3.invalidate();
//				image1_0.setVisible(false);
//        image1_0.invalidate();
//				image1_1.setVisible(false);
//        image1_1.invalidate();
//		    image1_2.setVisible(false);
//        image1_2.invalidate();
//		    image1_3.setVisible(false);
//        image1_3.invalidate();
}

void ScreenFanView::handleKeyEvent(uint8_t key)
{
	ScreenMenuNumberGFX = FancalVarition(key,GFXLevels);	

     switch (ScreenMenuNumberGFX)  //这里屏幕转换要添加方框清0
   {
    case 0x0000012://BOX
		   	hideBox();
			  box_0.setVisible(true);
        box_0.invalidate();
		break;
    case 0x00022:
			  hideBox();
			  //Hide box Show box
				box_1.setVisible(true);
        box_1.invalidate();
		break;
    case 0x00032:
		      hideBox();
		      box_2.setVisible(true);
          box_2.invalidate();
		break;
    case 0x00042:
			    hideBox();
		      box_3.setVisible(true);
          box_3.invalidate();
		break;
		
		case 0x00002://当Level[1]=0
		     application().gotoScreenMenuScreenNoTransition();
		break;
		
		
		//knob1 pressed  
		case 0x00112:
			FanType = 0 ;//可以默认为此选项 智能
			presenter->saveFanType(FanType);
//		  image1_0.setVisible(true);
//			image1_0.invalidate();
		break;
		case 0x00122:
			FanType = 1 ;//高速
			presenter->saveFanType(FanType);
//		  image1_1.setVisible(true);
//			image1_1.invalidate();
		break;
		case 0x00132:
			FanType = 2 ;//中速
			presenter->saveFanType(FanType);
//		  image1_2.setVisible(true);
//			image1_2.invalidate();
		break;			
		case 0x00142:	//选中第四个组件 静音
			FanType = 3 ;
			presenter->saveFanType(FanType);
//		  image1_3.setVisible(true);
//			image1_3.invalidate();
		break;
		
		//快捷键
		case 0x0000d:
			   application().gotoScreen1ScreenNoTransition();// go to cct
		break;
		case 0x0000e:
			   application().gotoScreenEffectScreenNoTransition();// go to effect
		break;
					
		
		default:
			break;
	}
}

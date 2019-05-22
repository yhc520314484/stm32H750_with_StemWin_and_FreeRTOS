/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2012  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.16 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  ARM LIMITED whose registered office
is situated at  110 Fulbourn Road,  Cambridge CB1 9NJ,  England solely
for  the  purposes  of  creating  libraries  for  ARM7, ARM9, Cortex-M
series,  and   Cortex-R4   processor-based  devices,  sublicensed  and
distributed as part of the  MDK-ARM  Professional  under the terms and
conditions  of  the   End  User  License  supplied  with  the  MDK-ARM
Professional. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUI_TOUCH_X.C
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/
#include "GUI.h"
#include "./touch/bsp_touch_gtxx.h"
#include "./touch/bsp_i2c_touch.h"
#include "./lcd/bsp_lcd.h"
#include "./TIMER/timer.h"
void GUI_TOUCH_X_ActivateX(void) 
{
 // XPT2046_WriteCMD(0x90);
}


void GUI_TOUCH_X_ActivateY(void)
{
  //XPT2046_WriteCMD(0xd0);
}

int  GUI_TOUCH_X_MeasureX(void) 
{
	int32_t xvalue = 0;
	static int32_t bef_xvalue = 0;
	xvalue=pre_x;
//	printf("Enter!X\r\n");
	if(xvalue != bef_xvalue && xvalue != 0 && xvalue != -1){
		if(xvalue != 0 && xvalue != -1) printf("xp: %d, xv: %d, xb: %d\n",pre_x, xvalue, bef_xvalue);
		bef_xvalue = xvalue;
		pre_x = -1;
		return xvalue;
	}
	return 0xFFFF;

}

int  GUI_TOUCH_X_MeasureY(void) 
{	
	int32_t yvalue = 0;
	static int32_t bef_yvalue = 0;
//	printf("Enter!X\r\n");
	yvalue=pre_y;
	if(yvalue != bef_yvalue && yvalue != 0 && yvalue != -1){
		if(yvalue != 0 && yvalue != -1) printf("yp: %d, yv: %d, yb: %d\n",pre_y, yvalue, bef_yvalue);
		bef_yvalue = yvalue;
		pre_y = -1;
		return yvalue;
	}
	return 0xFFFF;
}


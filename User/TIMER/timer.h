#ifndef _TIMER_H
#define _TIMER_H
#include "main.h"
#include "./touch/bsp_touch_gtxx.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32H7������
//��ʱ����������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/8/12
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
extern TIM_HandleTypeDef TIM3_Handler;      //��ʱ��3PWM��� 
//extern POINT pt;

void TIM3_Init(uint16_t arr,uint16_t psc);
void TIM4_Init(uint16_t arr,uint16_t psc);
#endif


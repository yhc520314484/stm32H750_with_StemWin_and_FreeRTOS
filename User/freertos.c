/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "GUIDEMO.h"
#include "./led/bsp_led.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
// /* 创建任务句柄 */
//static TaskHandle_t AppTaskCreate_Handle = NULL;
/* LED任务句柄 */
static TaskHandle_t LED_Task_Handle = NULL;
/* GUI任务句柄 */
static TaskHandle_t GUI_Task_Handle = NULL;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
//static void AppTaskCreate(void);/* 用于创建任务 */

static void LED_Task(void* pvParameters);/* LED_Task任务实现 */
static void GUI_Task(void* pvParameters);/* GUI_Task任务实现 */   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
//	BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
	
	   /* 创建AppTaskCreate任务 */
//  xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  /* 任务入口函数 */
//                        (const char*    )"AppTaskCreate",/* 任务名字 */
//                        (uint16_t       )512,  /* 任务栈大小 */
//                        (void*          )NULL,/* 任务入口函数参数 */
//                        (UBaseType_t    )1, /* 任务的优先级 */
//                        (TaskHandle_t*  )&AppTaskCreate_Handle);/* 任务控制块指针 */ 
//	if(pdPASS == xReturn) return;
//	else while(1);    /*  TODO:Error Handler */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
  BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
  
  taskENTER_CRITICAL();           //进入临界区
  
  /* 创建LED_Task任务 */
  xReturn = xTaskCreate((TaskFunction_t )LED_Task, /* 任务入口函数 */
                        (const char*    )"LED_Task",/* 任务名字 */
                        (uint16_t       )512,   /* 任务栈大小 */
                        (void*          )NULL,	/* 任务入口函数参数 */
                        (UBaseType_t    )2,	    /* 任务的优先级 */
                        (TaskHandle_t*  )&LED_Task_Handle);/* 任务控制块指针 */
  if(pdPASS == xReturn)
    printf("创建LED_Task任务成功!\r\n");
	else while(1);    /*  TODO:Error Handler */
  
	/* 创建GUI_Task任务 */
  xReturn = xTaskCreate((TaskFunction_t )GUI_Task, /* 任务入口函数 */
                        (const char*    )"GUI_Task",/* 任务名字 */
                        (uint16_t       )2048,   /* 任务栈大小 */
                        (void*          )NULL,	/* 任务入口函数参数 */
                        (UBaseType_t    )3,	    /* 任务的优先级 */
                        (TaskHandle_t*  )&GUI_Task_Handle);/* 任务控制块指针 */
  if(pdPASS == xReturn)
    printf("创建GUI_Task任务成功!\r\n");
	else while(1);    /*  TODO:Error Handler */

	
  vTaskDelete(defaultTaskHandle); //删除AppTaskCreate任务
  
  taskEXIT_CRITICAL();            //退出临界区
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/**********************************************************************
  * @ 函数名  ： LED_Task
  * @ 功能说明： LED_Task任务主体
  * @ 参数    ：   
  * @ 返回值  ： 无
  ********************************************************************/
static void LED_Task(void* parameter)
{	
    while (1)
    {
				LED1( ON );	
        vTaskDelay(500);   /* 延时500个tick */
        printf("LED1_Task Running,LED1_ON\r\n");
        
        LED1( OFF );
        vTaskDelay(500);   /* 延时500个tick */		 		
        printf("LED1_Task Running,LED1_OFF\r\n");
    }
}

/**********************************************************************
  * @ 函数名  ： LED_Task
  * @ 功能说明： LED_Task任务主体
  * @ 参数    ：   
  * @ 返回值  ： 无
  ********************************************************************/
static void GUI_Task(void* parameter)
{	
    while (1)
    {
				GUIDEMO_Main();
        vTaskDelay(500);   /* 延时500个tick */		 		
    }
}

     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

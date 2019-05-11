#include "stm32f10x.h"
#include "step_motor.h"

extern int speed;
int temp;

void EXTI0_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOA clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/* Configure PA.00 pin as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Enable AFIO clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/* Connect EXTI0 Line to PA.00 pin */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); //管脚选择

	/* Configure EXTI0 line */
	EXTI_InitStructure.EXTI_Line = EXTI_Line0; //线路选择
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //事件选择
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //触发模式
	EXTI_InitStructure.EXTI_LineCmd = ENABLE; //启动中断
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void)
{   
   Delay(50000);
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
	{
		if(speed != 0)
		{
			temp = speed;
		  speed = 0;
		}
		else
		{
			speed = temp;
		}
	}
    
    EXTI_ClearITPendingBit(EXTI_Line0); 
}

void EXTI9_5_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOB clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/* Configure PB.09 pin as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Enable AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	/* Connect EXTI9 Line to PB.09 pin */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5|GPIO_PinSource6);

	/* Configure EXTI9 line */
	EXTI_InitStructure.EXTI_Line = EXTI_Line5|EXTI_Line6; //线路选择
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //触发模式
	EXTI_InitStructure.EXTI_LineCmd = ENABLE; //启动中断
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI9_5 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);
}
void EXTI9_5_IRQHandler(void)
{   
    Delay(50000);
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5) == 0)
	{
		if(speed >= 0x4000)
		  speed = speed - 0x1000;
		else if(speed == 0)
		  speed = 0x8000;
	}
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6) == 0)
	{
		if(speed < 0x9000&&speed != 0)
		  speed = speed + 0x1000;
	} 
	EXTI_ClearITPendingBit(EXTI_Line5|EXTI_Line6);
}

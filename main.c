#include "stm32f10x.h"
#include "step_motor.h"

int speed;

int main(void)
{
   
  SystemInit();	// 配置系统时钟为72M 	
  PORT_GPIO_Config(); //端口初始化 
	PORT_OUT_GPIO_Config();
		
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
  EXTI0_Config();
	EXTI9_5_Config();
	
  speed = 0x8000;
  while (1)
   {
		if(speed != 0)
		STEP_MOTOE_RUN(speed);
    LED_START(speed);
   }
}

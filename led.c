#include "stm32f10x.h"
#include "step_motor.h"

void LED_START(int speed)
{
	int num,num1,num2,num3;
	if(speed != 0)
	{num = (speed-0x3000)/0x1000;
	
	num1 = num/4;
	num2 = (num-num1*4)/2;
	num3 = num - num1*4 - num2*2;
	
	LED1( num1 );
	LED2( num2 );
	LED3( num3 );
	}
	else{
	LED1( OFF );
	LED2( OFF );
	LED3( OFF );
	}	
}

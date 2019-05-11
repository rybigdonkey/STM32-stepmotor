
#include "stm32f10x.h"
#include "step_motor.h"

void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

void STEP_MOTOE_RUN(__IO u32 Delay_time)
{
		  STEP4( ON );
  		STEP1( ON );			 
	    Delay(Delay_time/2);//4+1
			STEP4( OFF );
      Delay(Delay_time/2);//1
	    STEP2( ON );
	    Delay(Delay_time/2);//1+2
		  STEP1( OFF );		
      Delay(Delay_time/2);//2	
	   	STEP3( ON );
		  Delay(Delay_time/2);//2+3
		  STEP2( OFF );
	    Delay(Delay_time/2);//3
	    STEP4( ON );
      Delay(Delay_time/2);//3+4
			STEP3( OFF ); 
    	Delay(Delay_time/2);//4
			STEP4( OFF );
}

#ifndef __PORT_H
#define	__PORT_H

#include "stm32f10x.h"

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  0
#define OFF 1

#define STEP1(a)	if (a)	\
					GPIO_ResetBits(GPIOA,GPIO_Pin_1);\
					else		\
					GPIO_SetBits(GPIOA,GPIO_Pin_1)

#define STEP2(a)	if (a)	\
					GPIO_ResetBits(GPIOA,GPIO_Pin_2);\
					else		\
					GPIO_SetBits(GPIOA,GPIO_Pin_2)

#define STEP3(a)	if (a)	\
					GPIO_ResetBits(GPIOA,GPIO_Pin_3);\
					else		\
					GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define STEP4(a)	if (a)	\
					GPIO_ResetBits(GPIOA,GPIO_Pin_4);\
					else		\
					GPIO_SetBits(GPIOA,GPIO_Pin_4)
					
#define LED1(a)	if (a)	\
					GPIO_ResetBits(GPIOC,GPIO_Pin_13);\
					else		\
					GPIO_SetBits(GPIOC,GPIO_Pin_13)
	
#define LED2(a)	if (a)	\
					GPIO_ResetBits(GPIOC,GPIO_Pin_14);\
					else		\
					GPIO_SetBits(GPIOC,GPIO_Pin_14)
					
#define LED3(a)	if (a)	\
					GPIO_ResetBits(GPIOC,GPIO_Pin_15);\
					else		\
					GPIO_SetBits(GPIOC,GPIO_Pin_15)
					

void PORT_GPIO_Config(void);

void PORT_OUT_GPIO_Config(void);

void STEP_MOTOE_RUN(__IO u32 Delay_time);
					
void LED_START(int speed);

void EXTI0_Config(void);

void EXTI9_5_Config(void);

#endif /* __PORT_H */

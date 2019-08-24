#include "motor.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "timer.h"
#include "sys.h"

int main(void)
{
	vu8 key=0;
	u16 pwml;
	u8 i=1;
	Motor_Config();
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	KEY_Init();
	TIM3_PWM_Init(899,0);
	delay_ms(500);
	while(1)
	{
	key=KEY_Scan(0);
	if(key)
	{
		switch(key)
		{
			case KEY0_PRES:
			while(1)
			{
			delay_ms(1000);
			Motor_1_PRUN();
			if(i) 
				pwml++;
			else 
				pwml--;
			if(pwml>300) 
				i=0;
			if(pwml==0) 
				 i=1;
			TIM_SetCompare2(TIM3,pwml);
			}	
			
			case KEY1_PRES:
			while(1)
			{
			delay_ms(1000);
			Motor_1_NRUN();
			if(i) pwml++;
			else pwml--;
			if(pwml>300) i=0;
			if(pwml==0) i=1;
			TIM_SetCompare2(TIM3,pwml);
			}
			
			case WKUP_PRES:
			while(1)
			{
			delay_ms(1000);
			Motor_1_STOP();
			}
		}
	}
	else
		while(1)
		{
		LED1=1;
		delay_ms(500);
	  LED1=0;
		delay_ms(500);
		}
	}
}
	
	

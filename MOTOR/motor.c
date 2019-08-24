#include "motor.h"
#include "delay.h"
#include "sys.h"

void Motor_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
	void Motor_1_STOP(void)
	{
		IN1(High);
		IN2(High);
	}
	void Motor_1_PRUN(void)
	{
		IN1(Low);IN2(High);
	}
	void Motor_1_NRUN(void)
	{
		IN1(High);IN2(Low);
	}
	void Motor_2_STOP(void)
	{
		IN1(High);IN2(High);
	}
	void Motor_2_PRUN(void)
	{
		IN1(Low);IN2(High);
	}
	void Motor_2_NRUN(void)
	{
		IN1(High);IN2(Low);
	}




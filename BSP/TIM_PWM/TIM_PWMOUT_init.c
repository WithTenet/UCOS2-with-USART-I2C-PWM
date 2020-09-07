#include "TIM_PWMOUT_init.h"

void PWMOUT_Init(void)
{  
	printf("PWMOUT");
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
                                                             
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);  
 
    GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType      = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd       = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	
    GPIO_InitStructure.GPIO_Pin        = PWMOTPUT_PIN6;
	GPIO_Init(PWMOTPUT_PORT,& GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = PWMOTPUT_PIN7;
	GPIO_Init(PWMOTPUT_PORT,& GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = PWMOTPUT_PIN8;
    GPIO_Init(PWMOTPUT_PORT,& GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = PWMOTPUT_PIN9;
	GPIO_Init(PWMOTPUT_PORT,& GPIO_InitStructure);
	 
	 
	GPIO_PinAFConfig(PWMOTPUT_PORT,PWMOTPUT_PINSOURCE6  ,PWMOTPUT_GPIO_AF);
	GPIO_PinAFConfig(PWMOTPUT_PORT,PWMOTPUT_PINSOURCE7  ,PWMOTPUT_GPIO_AF);
	GPIO_PinAFConfig(PWMOTPUT_PORT,PWMOTPUT_PINSOURCE8  ,PWMOTPUT_GPIO_AF);
	GPIO_PinAFConfig(PWMOTPUT_PORT,PWMOTPUT_PINSOURCE9  ,PWMOTPUT_GPIO_AF);
	
 
	
	TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_PERIOD1  ; 
	TIM_TimeBaseStructure.TIM_Prescaler =ADVANCE_TIM_PSC ; 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); 
 
 
	TIM_OCInitStructure.TIM_OCMode      =       TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState =       TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse       =       0; 
	TIM_OCInitStructure.TIM_OCPolarity  =       TIM_OCPolarity_High; 
	TIM_OC1Init(TIM8, &TIM_OCInitStructure); 
	
	
	TIM_OCInitStructure.TIM_OCMode      =       TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState =       TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse       =       0; 
	TIM_OCInitStructure.TIM_OCPolarity  =       TIM_OCPolarity_High; 
	TIM_OC2Init(TIM8, &TIM_OCInitStructure); 
	
	
	TIM_OCInitStructure.TIM_OCMode      =       TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState =       TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse       =       0; 
	TIM_OCInitStructure.TIM_OCPolarity  =       TIM_OCPolarity_High; 
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);  
	
	
	TIM_OCInitStructure.TIM_OCMode      =       TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState =       TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse       =       0; 
	TIM_OCInitStructure.TIM_OCPolarity  =       TIM_OCPolarity_High; 
	TIM_OC4Init(TIM8, &TIM_OCInitStructure);  
 
    
 
	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  
	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);  
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);  
	TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);  
	TIM_CtrlPWMOutputs(TIM8,ENABLE);	
	
	TIM_ARRPreloadConfig(TIM8, ENABLE); 
	
	TIM_Cmd(TIM8, ENABLE); 
	printf("PWM OUT Init complete!");
}

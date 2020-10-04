#include "stm32f4xx.h"
#include <stdio.h>
#define PWMOTPUT_TIM                 TIM8
#define PWMOTPUT_TIM_CLK             RCC_APB2Periph_TIM8


#define PWMOTPUT_PORT                GPIOC
#define PWMOTPUT_PIN6                GPIO_Pin_6
#define PWMOTPUT_PIN7                GPIO_Pin_7
#define PWMOTPUT_PIN8                GPIO_Pin_8
#define PWMOTPUT_PIN9                GPIO_Pin_9
#define PWMOTPUT_PINSOURCE6          GPIO_PinSource6
#define PWMOTPUT_PINSOURCE7          GPIO_PinSource7
#define PWMOTPUT_PINSOURCE8          GPIO_PinSource8
#define PWMOTPUT_PINSOURCE9          GPIO_PinSource9
#define PWMOTPUT_GPIO_AF             GPIO_AF_TIM8

#define PWMOTPUT_PIN6_CHANNEL1       TIM_Channel_1 
#define PWMOTPUT_PIN7_CHANNEL2       TIM_Channel_2 
#define PWMOTPUT_PIN8_CHANNEL3       TIM_Channel_3 
#define PWMOTPUT_PIN9_CHANNEL4       TIM_Channel_4 



/*******************************************/

#define PWMOTPUT_PORT_CLK            RCC_AHB1Periph_GPIOC

//#define PWMOTPUT_IRQn                TIM1_CC_IRQn
//#define PWMOTPUT_IRQHandler          TIM1_CC_IRQHandler

#define ADVANCE_TIM_PERIOD1           (20000-1)
#define ADVANCE_TIM_PSC              (168-1)
 
void PWMOUT_Init(void);

/**********************
pwm period 20000
full 2000
empty 1000

**********************/
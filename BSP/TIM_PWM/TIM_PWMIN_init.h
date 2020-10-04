

//TIM_RECEIVE 
//TIM 1 PAB-11 CH1-4 For receive | TIM8 CH1-4 PC6-9 for output 


/******************************TIM 1 DEFINE************************/
#define PWMINPUT_TIM                 TIM1
#define PWMINPUT_TIM_CLK             RCC_APB2Periph_TIM1


#define PWMINPUT_PORT                GPIOA 
#define PWMINPUT_PIN8                GPIO_Pin_8
#define PWMINPUT_PIN9                GPIO_Pin_9
#define PWMINPUT_PIN10               GPIO_Pin_10
#define PWMINPUT_PIN11               GPIO_Pin_11
#define PWMINPUT_PINSOURCE8          GPIO_PinSource8
#define PWMINPUT_PINSOURCE9          GPIO_PinSource9
#define PWMINPUT_PINSOURCE10         GPIO_PinSource10
#define PWMINPUT_PINSOURCE11         GPIO_PinSource11
#define PWMINPUT_GPIO_AF             GPIO_AF_TIM1

#define PWMINPUT_PIN8_CHANNEL1        TIM_Channel_1 
#define PWMINPUT_PIN9_CHANNEL2        TIM_Channel_2 
#define PWMINPUT_PIN10_CHANNEL3       TIM_Channel_3 
#define PWMINPUT_PIN11_CHANNEL4       TIM_Channel_4 





#define PWMINPUT_PORT_CLK            RCC_AHB1Periph_GPIOA

#define PWMINPUT_IRQn                TIM1_CC_IRQn
#define PWMINPUT_IRQHandler          TIM1_CC_IRQHandler

#define ADVANCE_TIM_PERIOD           (1000-1)
#define ADVANCE_TIM_PSC              (168-1)


/*******************************INIT_FUNCTION*****************************/

void PWMINPUT_Config(void);
void TIM1_CC_IRQHandler(void);












	

	
	


	
	
	
	
	
	
	
	
	
	
	

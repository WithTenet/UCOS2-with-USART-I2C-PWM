#include "TIM_PWMIN_init.h"
#include  <stdio.h>



void PWMINPUT_Config(void)
{
	 NVIC_InitTypeDef                NVIC_InitStructure ;
	 TIM_TimeBaseInitTypeDef         TIM_TimeBaseStructure;
	 TIM_ICInitTypeDef               TIM_ICInitStructure;
	 GPIO_InitTypeDef                GPIO_InitStructure;
   //GPIO_CLK ENABLE	
	 RCC_AHB1PeriphClockCmd(PWMINPUT_PORT_CLK,ENABLE);
	 //TIM CLK ENABLE
	 RCC_APB2PeriphClockCmd(PWMINPUT_TIM_CLK,ENABLE);

	
	//GPIO Define 
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
     GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_InitStructure.GPIO_Pin   = PWMINPUT_PIN8;
	 GPIO_Init(PWMINPUT_PORT,& GPIO_InitStructure);
	 GPIO_InitStructure.GPIO_Pin   = PWMINPUT_PIN9;
	 GPIO_Init(PWMINPUT_PORT,& GPIO_InitStructure);
	 GPIO_InitStructure.GPIO_Pin   = PWMINPUT_PIN10;
	 GPIO_Init(PWMINPUT_PORT,& GPIO_InitStructure);
	 GPIO_InitStructure.GPIO_Pin   = PWMINPUT_PIN11;
	 GPIO_Init(PWMINPUT_PORT,& GPIO_InitStructure);
	 
	//Alter Function link 
	 GPIO_PinAFConfig(PWMINPUT_PORT,PWMINPUT_PINSOURCE8  ,PWMINPUT_GPIO_AF);
	 GPIO_PinAFConfig(PWMINPUT_PORT,PWMINPUT_PINSOURCE9  ,PWMINPUT_GPIO_AF);
	 GPIO_PinAFConfig(PWMINPUT_PORT,PWMINPUT_PINSOURCE10 ,PWMINPUT_GPIO_AF);
	 GPIO_PinAFConfig(PWMINPUT_PORT,PWMINPUT_PINSOURCE11 ,PWMINPUT_GPIO_AF);
	
	//Timebase init 
	 TIM_TimeBaseStructure.TIM_Period            = ADVANCE_TIM_PERIOD;
	 TIM_TimeBaseStructure.TIM_Prescaler         = ADVANCE_TIM_PSC ;
	 TIM_TimeBaseStructure.TIM_ClockDivision     = TIM_CKD_DIV1;
     TIM_TimeBaseStructure.TIM_CounterMode       = TIM_CounterMode_Up;
     TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;	
	 TIM_TimeBaseInit(PWMINPUT_TIM, &TIM_TimeBaseStructure);
  
	
	 //Input catch init 
	  //TIM2_CH1输入捕获初始化
     TIM_ICInitStructure.TIM_Channel =PWMINPUT_PIN8_CHANNEL1 ;
     TIM_ICInitStructure.TIM_ICFilter = 0x00;                            //不滤波
     TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;        //上升沿捕获
     TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;                //输入器不分频
     TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;    //映射到IC1
     TIM_ICInit(TIM1, &TIM_ICInitStructure);
    
    TIM_ICInitStructure.TIM_Channel = PWMINPUT_PIN9_CHANNEL2 ;
    TIM_ICInitStructure.TIM_ICFilter = 0x00;                            //不滤波
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;        //上升沿捕获
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;                //输入器不分频
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;    //映射到IC2
    TIM_ICInit(TIM1, &TIM_ICInitStructure);
    
    TIM_ICInitStructure.TIM_Channel = PWMINPUT_PIN10_CHANNEL3;
    TIM_ICInitStructure.TIM_ICFilter = 0x00;                            //不滤波
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;        //上升沿捕获
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;                //输入器不分频
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;    //映射到IC3
    TIM_ICInit(TIM1, &TIM_ICInitStructure);
    
    TIM_ICInitStructure.TIM_Channel = PWMINPUT_PIN11_CHANNEL4;
    TIM_ICInitStructure.TIM_ICFilter = 0x00;                            //不滤波
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;        //上升沿捕获
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;                //输入器不分频
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;    //映射到IC4
    TIM_ICInit(TIM1, &TIM_ICInitStructure);
    
    
    //中断分组初始化
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel                     =   TIM1_CC_IRQn ;
    NVIC_InitStructure.NVIC_IRQChannelCmd                  =   ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority   =   1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority          =   1;
    NVIC_Init(&NVIC_InitStructure);    
    
    TIM_ITConfig(TIM1, TIM_IT_CC1|TIM_IT_CC2|TIM_IT_CC3|TIM_IT_CC4, ENABLE);            //更新中断和CC1IE捕获中断
    
    TIM_Cmd(TIM1, ENABLE);
    printf("TIM1 4CH Init SCU\n");
	
}
	








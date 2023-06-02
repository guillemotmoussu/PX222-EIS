#include "stm8s.h"

void delay_ms(int ms)
{
    int i;
    int j;
    for (i = 0; i <= ms; i++)
    {
        for (j = 0; j < 120; j++) {_asm("nop");}
    }
}

void main(void)
{
    GPIO_DeInit(GPIOD);
    TIM2_DeInit();
    GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);
    TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 1000, TIM2_OCPOLARITY_HIGH);
    TIM2_TimeBaseInit(TIM2_PRESCALER_1, 500);
    TIM2_Cmd(ENABLE);
    while (TRUE)
    {
        signed int pwm_duty = 500;
        TIM2_SetCompare1(pwm_duty);
    }
}
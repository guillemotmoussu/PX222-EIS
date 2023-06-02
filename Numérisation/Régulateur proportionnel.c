#include "stm8s.h"
#include "stm8s_adc1.h"
#include "stm8s_tim1.h"

// Paramètre du régulateur proportionnel
#define KP 1.0

// Variables globales
volatile uint16_t consigne = 0;
volatile uint16_t adc_value = 0;

void main(void) {
    // Initialisation des périphériques (ADC, TIM1, etc.)
    System_Init();

    while (1) {
        adc_value = ADC1_GetConversionValue(); // Lecture de la valeur ADC
        regulation_P(); // Appel de la fonction de régulation proportionnelle
    }
}

void System_Init() {
    // Configuration ADC
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_0, ADC1_PRESSEL_FCPU_D2, ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL0, DISABLE);
    ADC1_StartConversion();

    // Configuration TIM1 pour PWM
    TIM1_TimeBaseInit(0xFFFF, TIM1_COUNTERMODE_UP, 0, 0);
    TIM1_OC1Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 0, TIM1_OCPOLARITY_HIGH);
    TIM1_Cmd(ENABLE);
    TIM1_CtrlPWMOutputs(ENABLE);

    // Configuration du GPIO pour la sortie PWM
    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_FAST);

    // Configuration du GPIO pour l'entrée analogique (ADC)
    GPIO_Init(GPIOA, GPIO_PIN_0, GPIO_MODE_IN_FL_NO_IT);
}

// Fonction de mise à jour de la consigne
void set_consigne(uint16_t value) {
    consigne = value;
}

// Fonction de régulation proportionnelle
void regulation_P() {
    float erreur = (float)consigne - (float)adc_value;
    float sortie = KP * erreur;

    // Limiter la sortie entre 0 et la valeur maximale du compteur (ici 0xFFFF)
    if (sortie < 0) {
        sortie = 0;
    } else if (sortie > 0xFFFF) {
        sortie = 0xFFFF;
    }

    // Mise à jour de la sortie PWM
    TIM1_SetCompare1((uint16_t)sortie);
}

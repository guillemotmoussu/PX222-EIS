#include "stm8s.h"
#include "stm8s_adc1.h"
#include "stm8s_tim1.h"

// Paramètres du régulateur PID
#define KP 1.0
#define KI 0.1
#define KD 0.01

// Variables globales
volatile uint16_t consigne = 0;
volatile float erreur_precedente = 0;
volatile float somme_erreurs = 0;
volatile uint16_t adc_value = 0;

void main(void) {
    // Initialisation des périphériques (ADC, TIM1, etc.)
    System_Init();
    enableInterrupts();

    while (1) {
        // Traitement de la boucle principale si nécessaire
    }
}

void System_Init() {
    // Configuration ADC
    // ...

    // Configuration TIM1 pour PWM
    // ...

    // Configuration de l'interruption de temporisation
    // ...
}

// Fonction de mise à jour de la consigne
void set_consigne(uint16_t value) {
    consigne = value;
}

// Fonction de régulation PID
void regulation_PID() {
    float erreur = (float)consigne - (float)adc_value;
    float erreur_derivee = erreur - erreur_precedente;
    somme_erreurs += erreur;

    float sortie = KP * erreur + KI * somme_erreurs + KD * erreur_derivee;
    erreur_precedente = erreur;

    // Limiter la sortie entre 0 et la valeur maximale du compteur (ici 0xFFFF)
    if (sortie < 0) {
        sortie = 0;
    } else if (sortie > 0xFFFF) {
        sortie = 0xFFFF;
    }

    // Mise à jour de la sortie PWM
    TIM1_SetCompare1((uint16_t)sortie);
}

// Interruption de temporisation pour exécuter la boucle PID
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23) {
    adc_value = ADC1_GetConversionValue(); // Lecture de la valeur ADC
    regulation_PID(); // Appel de la fonction de régulation PID

    TIM4_ClearFlag(TIM4_FLAG_UPDATE); // Effacer le drapeau de mise à jour
    TIM4_ClearITPendingBit(TIM4_IT_UPDATE); // Effacer la demande d'interruption en attente
}

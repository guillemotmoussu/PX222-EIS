#include "stm8s.h"
#include "stm8s103_adc.h"
#include "stm8s103_serial.h"

void main()
{
    // Declarations de variables
    unsigned int ADC_value_1 = 0;
    int ADC_voltage_1 = 0;

    CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE); // Activer l'horloge peripherique pour l'ADC
    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_FL_IT);      // Initialiser le pin PB0 en entree

    Serial_begin(9600);
    Serial_print_string("Bonjour !");
    Serial_newline();
    delay_ms(5000);

    while (1)
    {
        ADC_value_1 = ADC_Read(AIN2);
        ADC_voltage_1 = ADC_value_1 * (2.933); //(3000/1023 =~ 2.933) 
        Serial_print_string("B0: ");
        Serial_print_string(ADC_value_1);
        Serial_print_string(" -> ");
        Serial_print_string(ADC_voltage_1);
        Serial_print_string(" mV");
        Serial_newline();
        delay_ms(500);
    }
}
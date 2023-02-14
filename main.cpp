/*
    *Autor: Hugo Campos
    *Objetivo: Esse código tem como objetivo fazer com que o robo siga uma linha 
    *Data: 13/02/2023
    *Status: Funcionando
    *Observações: 
*/

#include "mbed.h"

PwmOut   MA1 (D5);
PwmOut   MA2 (D6);

PwmOut   MB1 (D9);
PwmOut   MB2 (D10);

AnalogIn S1 (A0);
AnalogIn S2 (A1);

DigitalIn bt (PC_13);
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

int s1_value;
int s2_value;

float pwm = 0.2;

int main()
{
    MA1 = 0;
    MA2 = 0;
    MB1 = 0;
    MB2 = 0;
    wait_us(1000);
    MA1.period(0.020);
    MA2.period(0.020);
    MB1.period(0.020);
    MB2.period(0.020);
    

    while (true) {
        s0_value = S1.read()*1000;
        s1_value = S2.read()*1000;
        /*
        printf("Valor S1= %d\n\r", s1_value);
        printf("Valor S2= %d\n\r", s2_value);
        ThisThread::sleep_for(BLINKING_RATE);
        */
        // Frente
        if ((s1_value<200) && (s2_value<200)){
            MA1 = pwm;
            MA2 = 0;
            MB1 = pwm;
            MB2 = 0;
        }
        //Esquerda
        if ((s1_value<200) && (s2_value>200)){
            MA1 = 0;
            MA2 = 0;
            MB1 = pwm;
            MB2 = 0;
        }
        //Direita
        if ((s1_value>200) && (s2_value<200)){
            MA1 = pwm;
            MA2 = 0;
            MB1 = 0;
            MB2 = 0;
        }
    }
}

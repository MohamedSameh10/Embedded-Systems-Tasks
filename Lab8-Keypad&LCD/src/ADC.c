/*
 * Author : Abdullah Drwesh
 * Date   : 12/12/2021
 * Version: 1.0.0
 */
#include "DIO.h"
#include "avr/io.h"

void ADC_Init(void) {

  // Enable ADC
  ADCSRA |= (1 << 7);

  // Select Reference (to be AVCC)
  ADMUX |= (1 << 6);
  ADMUX &= ~(1 << 7);

  // Configure the right adjust
  ADMUX &= ~(1 << 5);

  // Select frequency prescaler (max input frequency of AVR ADC is 200 KHZ )
  ADCSRA |= 0x07;
}

void ADC_SelectChannel(unsigned char ChannelNum) {

  // configure it as input
  DIO_SetPinDirection('C', ChannelNum, INPUT);

  // Select channel
  ADMUX &= ~0x1f;
  ADMUX |= ChannelNum;
}

unsigned short ADC_ReadChannel(unsigned char ChannelNum) {

  // Check if channel selected
  // if selected
  if ( (ADMUX & 0x1f) == ChannelNum) {
    // Start conversion(Start ADC read)
    ADCSRA |= (1 << 6);
    // wait until conversion is complete
    while (ADCSRA & (1 << 6));
    
    return ADC;
  } else {
    return -1;
  }
}
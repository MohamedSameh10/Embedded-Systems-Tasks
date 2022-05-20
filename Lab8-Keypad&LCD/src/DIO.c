/*
 * Author : Abdullah Drwesh
 * Date   : 12/12/2021
 * Version: 1.0.0
 */

#include "DIO.h"

#include "avr/io.h"

void DIO_SetPinDirection(char PortName, unsigned char PinNum,
                      unsigned char Direction) {
  switch (PortName) {
    case 'B':
      if (Direction == INPUT) {
        DDRB &= ~(1 << PinNum);
      } else {
        DDRB |= (1 << PinNum);
      }
      break;
    case 'C':
      if (Direction == INPUT) {
        DDRC &= ~(1 << PinNum);
      } else {
        DDRC |= (1 << PinNum);
      }
      break;
    case 'D':
      if (Direction == INPUT) {
        DDRD &= ~(1 << PinNum);
      } else {
        DDRD |= (1 << PinNum);
      }
      break;
    default:
      break;
  }
}


void DIO_SetPortDirection(char PortName, unsigned char Direction){
  switch (PortName)
  {
  case 'B':
    if(Direction == INPUT){
      DDRB = 0x00;
    }else {
      DDRB = 0xff;
    }
    break;
  case 'C':
    if(Direction == INPUT){
      DDRC = 0x00;
    }else {
      DDRC = 0xff;
    }
    break;
  case 'D':
    if(Direction == INPUT){
      DDRD = 0x00;
    }else {
      DDRD = 0xff;
    }
    break;
  default:
    break;
  }
}

void DIO_WritePin(char PortName, unsigned char PinNum, unsigned char Data) {
  switch (PortName) {
    case 'B':
      if (Data) {
        PORTB |= (1 << PinNum);
      } else {
        PORTB &= ~(1 << PinNum);
      }
      break;
    case 'C':
      if (Data) {
        PORTC |= (1 << PinNum);
      } else {
        PORTC &= ~(1 << PinNum);
      }
      break;
    case 'D':
      if (Data) {
        PORTD |= (1 << PinNum);
      } else {
        PORTD &= ~(1 << PinNum);
      }
      break;
    default:
      break;
  }
}

void DIO_WritePort(char PortName, unsigned char Data) {
  switch (PortName) {
    case 'B':
      PORTB = Data;
      break;
    case 'C':
      PORTC = Data;
      break;
    case 'D':
      PORTD = Data;
      break;
    default:
      break;
  }
}

unsigned char DIO_ReadPin(char PortName, unsigned char PinNum) {
  unsigned char data = 0;
  switch (PortName) {
    case 'B':
      data = (PINB & (1 << PinNum)) >> PinNum;
      break;
    case 'C':
      data = (PINC & (1 << PinNum)) >> PinNum;
      break;
    case 'D':
      data = (PIND & (1 << PinNum)) >> PinNum;
      break;
    default:
      break;
  }
  return data;
}

unsigned char DIO_ReadPort(char PortName) {
  unsigned char data = 0;
  switch (PortName) {
    case 'B':
      data = PINB;
      break;
    case 'C':
      data = PINC;
      break;
    case 'D':
      data = PIND;
      break;
    default:
      break;
  }
  return data;
}

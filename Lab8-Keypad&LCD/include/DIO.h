/*
 * Author : Abdullah Drwesh
 * Date   : 12/12/2021
 * Version: 1.0.0
 */
#ifndef DIO_H
#define DIO_H


/* Directions */
#define INPUT 0
#define OUTPUT 1

void DIO_SetPinDirection(char PortName, unsigned char PinNum, unsigned char Direction);

void DIO_SetPortDirection(char PortName, unsigned char Direction);

void DIO_WritePin(char PortName, unsigned char PinNum, unsigned char Data);

void DIO_WritePort(char PortName, unsigned char Data);

unsigned char DIO_ReadPin(char PortName, unsigned char PinNum);

unsigned char DIO_ReadPort(char PortName);


#endif /* DIO_H */

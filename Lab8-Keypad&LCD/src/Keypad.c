#include "DIO.h"
#include "avr/io.h"
#include <util/delay.h> //delay header

#define KEY_PRT PORTB //keyboard PORT
#define KEY_DDR DDRB //keyboard DDR
#define KEY_PIN PINB //keyboard PIN

unsigned char keypad[4][3] ={ '1','2','3',
                              '4','5','6',
                              '7','8','9',
                              '*','0','#'};

unsigned char colloc, rowloc;

void delay_ms(unsigned int d)
{
  _delay_ms(d);
}

void Keypad_Init(void)
{
  DDRD = 0xFF;
  KEY_DDR = 0b1111000;
  KEY_PRT = 0xFF;

}

unsigned char Keypad_GetKey(void)
{
    while(1)
  {
    do
    {
      KEY_PRT &= 0b00000111; //ground all rows at once
      colloc = (KEY_PIN & 0b00000111); //read the columns
    } while(colloc != 0b00000111); //check until all keys released
    do
    {
      do
      {
        delay_ms(20); //call delay
        colloc =(KEY_PIN&0b00000111); //see if any key is pressed
      } while(colloc == 0b00000111); //keep checking for key press
      delay_ms(20); //call delay for debounce
      colloc = (KEY_PIN & 0b00000111); //read columns
    }while(colloc == 0b00000111); //wait for key press
    
    while(1)
    {
      KEY_PRT = 0b11110111; //ground row 0
      colloc = (KEY_PIN & 0b00000111); //read the columns
      if(colloc != 0b00000111) //column detected
      {
        rowloc = 0; //save row location
        break; //exit while loop
      }
      KEY_PRT = 0b11101111; //ground row 1
      colloc = (KEY_PIN & 0b00000111); //read the columns
      if(colloc != 0b00000111) //column detected
      {
        rowloc = 1; //save row location
        break; //exit while loop
      }
      KEY_PRT = 0b11011111; //ground row 2
      colloc = (KEY_PIN & 0b00000111); //read the columns
      if(colloc != 0b00000111) //column detected
      {
        rowloc = 2; //save row location
        break; //exit while loop
      }
      KEY_PRT = 0b10111111; //ground row 3
      colloc = (KEY_PIN & 0b00000111); //read the columns
      if(colloc != 0b00000111) //column detected
      {
        rowloc = 3; //save row location
        break; //exit while loop
      }
    }
    //check column and send result to Port D
    if(colloc == 0x06)
    {
      return keypad[rowloc][0];
    }else if(colloc == 0x05)
    {
      return keypad[rowloc][1];
    }else if(colloc == 0x03){
      return keypad[rowloc][2];
    }
  }
}

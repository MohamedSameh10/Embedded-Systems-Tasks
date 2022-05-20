#include <avr/io.h> //standard AVR header
#include "Keypad.h"
#include "LCD.h"

int main(void)
{
  unsigned char key;
  LCD_Init();
  Keypad_Init();
  while (1)
  {
    key=Keypad_GetKey();
    LCD_SetCursorAt(1,1);
    unsigned char str[]={key};
    LCD_Print(str);
  }
  return 0 ;
}
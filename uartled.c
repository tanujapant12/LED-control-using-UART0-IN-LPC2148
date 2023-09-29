#include "LPC214X.h"
#define LED_PIN (1 << 9)
#define LED_PIN1 (1 << 8)
unsigned char receive()
{
 while (!(U0LSR & 0x01));
 return (U0RBR);
}
void transmit(unsigned char ch)
{
 while (!(U0LSR & 0x20));
 U0THR = ch;
}
void putChar(char c)
{
 transmit(c);
}
char getChar()
{
 return receive();
}
int main()
{
 IO0DIR |= LED_PIN;
 IO0DIR |= LED_PIN1;
 PINSEL0 = 0x00000005;
 U0LCR = 0x83;
 U0DLM = 0x00;
 U0DLL = 97;
 U0LCR = 0x03;
 while (1)
 {
 char command = getChar(); // Receive a character from UART
 // If the received command is '1', turn ON the LED; if '0', turn OFF the LED
 if (command == '1')
 {
 IO0SET = LED_PIN;
 IO0CLR = LED_PIN1; // Turn ON the LED
 putChar('o'); // Send 'o' to indicate the LED is ON
 putChar('n'); // Send 'n' to indicate the LED is ON
 }
 else if (command == '0')
 {
 IO0CLR = LED_PIN; // Turn OFF the LED
 IO0SET = LED_PIN1;
 putChar('o'); // Send 'o' to indicate the LED is OFF
 putChar('f'); // Send 'f' to indicate the LED is OFF
 putChar('f'); // Send 'f' to indicate the LED is OFF
 }
 }
return 0;
}
# LED-control-using-UART0-IN-LPC2148
algorithm :
Define Constants: Define constants for controlling LEDs (LED_PIN and 
LED_PIN1) and create functions for sending and receiving characters via 
UART.
2. UART Initialization: Configure the UART communication by setting the 
necessary registers. Set the PINSEL0 register to enable UART0 
communication on the respective pins (TXD0 and RXD0). Configure 
UART0 to use 8 data bits, 1 stop bit, and no parity .
3. Main Loop: Enter an infinite loop (while(1)) to continuously listen for 
commands.
4. Receive Command: Inside the loop, use the getChar() function to receive 
a character/command from UART. This function waits until a character is 
received .
5. Process Command: Check the received character/command:
6. If the received command is '1', it turns ON one LED (IO0SET = 
LED_PIN) and turns OFF another (IO0CLR = LED_PIN1).
7. It sends the characters 'o', 'n' to indicate that the LED is turned ON, and 
these characters are transmitted via UART using the putChar() function.
8. If the received command is '0', it does the opposite: turns OFF one LED 
(IO0CLR = LED_PIN) and turns ON another (IO0SET = LED_PIN1).
9. It sends the characters 'o', 'f', 'f' to indicate that the LED is turned OFF

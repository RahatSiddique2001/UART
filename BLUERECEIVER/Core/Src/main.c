#include "main.h"



int main(void)
{
	// Enable the Alternate Function for PINs and Enable GPIOA
		RCC->APB2ENR |= 5;

		GPIOA->CRL &= ~(0xFFFFFFFF);   // Clear bits for PA0 - PA7
    GPIOA->CRL |=  (0x33330033);   // Set mode and confuguration for PA0 - PA7

		// Enable UART2
		RCC->APB1ENR |=0x20000;

		// Enable the related PINs. Set GPIOA 2 pin as TX and GRIOA 3 as RX
		GPIOA->CRL |= (0xB00);
		GPIOA->CRL |= (0x8000);


		// Setup the baude rate for 9600 bps
    uint32_t system_clock = 36000000;
    uint32_t baud_rate = 9600;
    USART2->BRR = (system_clock + (baud_rate / 2)) / baud_rate; // Correct BRR calculation

		// Enable Uart Transmit
		USART2->CR1 |= 8;

		// Enable Uart Recive
		USART2->CR1 |= 4;

		// Enable Uart
		USART2->CR1 |= 0x2000;

		//set word length
		USART2->CR1 |= 0x1000;


while(1)
	{
		char chat;

		// wait until data transmission is complete
		while(!(USART2->SR & (1<<6)))
		{};

		//Receive data
		chat = USART2->DR;

		char message[2];

		message[0]=chat;
		message[1]='\0';


	}
}

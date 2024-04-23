#include"MCAL/MRCC/MRCC_int.h"
#include"MCAL/MGPIO/MGPIO_int.h"
#include"MCAL/MNVIC/MNVIC_int.h"
#include"MCAL/MEXTI/MEXTI_int.h"
#include"MCAL/MIWDT/MIWDT_int.h"
#include"MCAL/MSTK/MSYSTICK_int.h"
#include"MCAL/MSPI/MSPI_int.h"
#include"MCAL/MRCC/MRCC_private.h"
#include"MCAL/MUART/MUSART_Interface.h"
#include"MCAL/MUART/MUSART_Config.h"
#include"MCAL/MUART/MUSART_Private.h"
int main (void){

	MRCC_vInit();
	MRCC_vEnableClock(GPIOA_EN);
	MRCC_vEnableClock(GPIOC_EN);
	MRCC_vEnableClock(SYSCFG_EN);
	MRCC_vEnableClock(USART1_EN);
	//********************************************************
	//UART1
	MGPIO_vSetPinMode(PORTA, PIN9 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN9, AF7);// Tx
	MGPIO_vSetPinMode(PORTA, PIN10 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN10, AF7); //Rx
	//**************UART*********************
	u8 arr_tx[20] = {1,2,3,4,5,6,7,8};
	u8 arr_rx[8] ;
	u8* data = "1" ;
	MUART_Enable(UART1);
	while(1){
		u8 data_rx ;
		data_rx = MUART_Receive_Byte(UART1);

		if (data_rx == 'f'){
			MGPIO_vSetPinMode(PORTC, PIN13, OUTPUT);
			MGPIO_vSetPinValue(PORTC, PIN13, LOW);
		}
		else if (data_rx == 'b'){
			MGPIO_vSetPinMode(PORTC, PIN14, OUTPUT);
			MGPIO_vSetPinValue(PORTC, PIN14, HIGH);
		}
		else if (data_rx == 'r'){
			MGPIO_vSetPinMode(PORTC, PIN15, OUTPUT);
			MGPIO_vSetPinValue(PORTC, PIN15, HIGH);
		}
		else
		{
			u8 angle=data_rx - 40;
		}
	}

}

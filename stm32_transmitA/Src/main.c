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
//#include"APP/Inc/Path_Tracking.h"

int main (void){

	MRCC_vInit();
	MRCC_vEnableClock(GPIOA_EN);
	MRCC_vEnableClock(GPIOB_EN);
	MRCC_vEnableClock(GPIOC_EN);
	MRCC_vEnableClock(SYSCFG_EN);
	MRCC_vEnableClock(USART1_EN);
	MRCC_vEnableClock(USART2_EN);
	MRCC_vEnableClock(USART6_EN);



	//********************************************************
	//UART1
	MGPIO_vSetPinMode(PORTA, PIN9 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN9, AF7);// Tx
	MGPIO_vSetPinMode(PORTA, PIN10 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN10, AF7); //Rx

	//UART2
	MGPIO_vSetPinMode(PORTA, PIN2 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN2, AF7);
	MGPIO_vSetPinMode(PORTA, PIN3 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN3, AF7);

	//UART6
	MGPIO_vSetPinMode(PORTA, PIN11 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN11, AF8);
	MGPIO_vSetPinMode(PORTA, PIN12 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN12, AF8);




	//********************************************************


	//**************UART*********************
	u8 arr_tx[20] = {1,2,3,4,5,6,7,8};
	u8 arr_rx[8] ;
	u8* data = "1" ;
	//	MUART_Init();
	MUART_Enable(UART1);
	MUART_Enable(UART2);
	MUART_Enable(UART6);


for(int i=0;i<8;i++)
{
	MUART_Send_Byte(UART1, arr_tx[i]);
}

MGPIO_vSetPinMode(PORTC, PIN13, OUTPUT);
MGPIO_vSetPinValue(PORTC, PIN13, LOW);

	while(1){

	}

}

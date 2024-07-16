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
void Rx_callback()
{
u8 data_rx ;
data_rx = MUART_Receive_Data(UART1);
//MGPIO_vSetPinValue(PORTC, PIN13, LOW);
if (data_rx == 'f' || data_rx == 102 ){
//MGPIO_vSetPinValue(PORTC, PIN13, LOW);
}
else if (data_rx == 'b'){
//MGPIO_vSetPinValue(PORTC, PIN13, LOW);
//MGPIO_vSetPinValue(PORTC, PIN14, HIGH);
}
else if (data_rx == 'r'){
//MGPIO_vSetPinValue(PORTC, PIN15, HIGH);
}
else if (data_rx == 'x' || data_rx == 120 ){
MGPIO_vSetPinValue(PORTC, PIN13, LOW);
// Navigation Mode
}
else if (data_rx == 'y' || data_rx == 121){
MGPIO_vSetPinValue(PORTC, PIN14, HIGH);
// Auto-Parking Mode
}
else if (data_rx == 'z' || data_rx == 122){
// Drive Back Mode
}
else if (data_rx == '{' || data_rx == 123){
// Record Mode
}
else if (data_rx == '|' || data_rx == 124){
// Replay park Mode
}
else{
//MGPIO_vSetPinValue(PORTC, PIN14, HIGH);
u8 Angle = data_rx - 40 ;
}
}

void Tx_to_uart(u8 Tx_Data[])
{
	MUART_Send_Byte(UART1,Tx_Data[0]);
	MUART_Send_Byte(UART1,Tx_Data[1]);
	MUART_Send_Byte(UART1,Tx_Data[2]);
	MUART_Send_Byte(UART1,Tx_Data[3]);
	MUART_Send_Byte(UART1,Tx_Data[4]);
	MUART_Send_Byte(UART1,Tx_Data[5]);
	MUART_Send_Byte(UART1,Tx_Data[6]);
	MUART_Send_Byte(UART1,Tx_Data[7]);
}
int main (void){

	MRCC_vInit();
	MRCC_vEnableClock(GPIOA_EN);
	MRCC_vEnableClock(GPIOB_EN);
	MRCC_vEnableClock(GPIOC_EN);
	MRCC_vEnableClock(SYSCFG_EN);
	MRCC_vEnableClock(USART1_EN);

	//********************************************************
	//UART1
	MGPIO_vSetPinMode(PORTA, PIN9 , ALTFUNC);
	MGPIO_vSetAlternativeFunction(PORTA, PIN9, AF7);// Tx
	MGPIO_vSetPinOutPutType(PORTA, PIN9,GPIO_PUSH_PULL);
	MGPIO_vSetPinOutPutSpeed(PORTA, PIN9,MGPIO_SPEED_MEDIUM);
	MGPIO_vSetPinInPutType(PORTA, PIN9,PULLUP);

	MGPIO_vSetPinMode(PORTA, PIN10 , ALTFUNC);
	MGPIO_vSetPinInPutType(PORTA, PIN10,PULLUP);
	MGPIO_vSetAlternativeFunction(PORTA, PIN10, AF7); //Rx

	MGPIO_vSetPinMode(PORTC, PIN13, OUTPUT);
	MGPIO_vSetPinValue(PORTC, PIN13, HIGH);
	MGPIO_vSetPinMode(PORTC, PIN14, OUTPUT);
	MGPIO_vSetPinMode(PORTC, PIN15, OUTPUT);


	//**************UART*********************
	u8 arr_tx[20] = {1,2,3,4,5,6,7,8};
	MUART_vSetRxCallBackFunc(MUART1,Rx_callback);
	MUART_Enable(UART1);
	u8 Ultra_CF = 20;                                // add data to JSON object
	u8 Ultra_CB = 15;                                // add data to JSON object
	u8 Ultra_LC = 76;                                // add data to JSON object
	u8 Ultra_RC = 23;                                // add data to JSON object
	u8 Ultra_LB = 23;                                // add data to JSON object
	u8 Ultra_RB = 12;							     //
	u8  ENC  = 123;                                  // add data to JSON object
	u8  SERV = 56;
	u8 Tx_Data[]={Ultra_CF,Ultra_CB,Ultra_LC,Ultra_RC,Ultra_LB,Ultra_RB,ENC,SERV};
	Tx_to_uart(Tx_Data);

	while(1){


	}

}



/*******************************************************************************************************/
/* Author            : Amr Elmaghraby                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 5 nov 2023                                                                      */
/* Description       : Private File Can`t Be Edit By User                                              */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

/*******************************************************************************************************/
/*                                       LIB                                                           */
/*******************************************************************************************************/
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

/*******************************************************************************************************/
/*                                    Base Address Of EXTI Register                                    */
/*******************************************************************************************************/
#define EXTI_BASE_ADD		0x40013C00
#define SYSCFG_BASE_ADD		0x40013800

/********************************************************************************************************/
/*                                            macros of EXTI                                            */
/********************************************************************************************************/
#define PIN_PER_REG		4
#define	BIT_PER_PIN		4
#define MASK4			15

/**************************************************************************/
/* Register Definition :-                                                 */
/* Features    : Private File Can`t Be Edit By User                       */
/* Description :-                                                         */
/*               - #define :      YES                                     */
/*               - union   :      NO                                      */
/*               - struct  :      YES                                     */
/**************************************************************************/
typedef struct{
	u32 IMR;
	u32	EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}	EXTI_MemMap_t;

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 Reserved[2];
	u32 CMPCR;
} SYSCFG_MemMap_t;

/***************************************************************************/
/*                     Struct Macro Base Address Of RCC                    */
/***************************************************************************/
#define EXTI		((volatile EXTI_MemMap_t *) EXTI_BASE_ADD)
#define SYSCFG		((volatile SYSCFG_MemMap_t *) SYSCFG_BASE_ADD)


#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */

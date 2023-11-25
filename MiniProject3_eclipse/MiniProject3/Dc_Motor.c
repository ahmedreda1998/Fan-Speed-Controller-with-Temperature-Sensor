 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.c
 *
 * Description: source file for the DC Motor (Fan)
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/

#include "DC_Motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "PWM.h"

void DcMotor_Init(void)
{
	/* The First two lines is responsible for making the two pins as output pins */
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	/* the following two lines are responsible for making the motor stop at first */

	GPIO_writePin(PORTB_ID,PIN0_ID ,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID ,LOGIC_LOW);

}

void DcMotor_Rotate (DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle= (uint8) (  (speed/100.0f)*255 ) ;
	PWM_Timer0_Start(duty_cycle); //generate duty cycle
	if (state == STOP)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID ,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID ,LOGIC_LOW);
	}
	else if (state == CW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID ,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID ,LOGIC_LOW);
	}
	else if (state == ACW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID ,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID ,LOGIC_HIGH);
	}



}




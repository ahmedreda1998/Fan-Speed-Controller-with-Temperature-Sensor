/******************************************************************************
 *
 * Module: main application
 *
 * File Name: main.c
 *
 * Description: source file for the main application
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/
#include "lcd.h"
#include "adc.h"
#include "DC_Motor.h"
#include "lm35_sensor.h"
#include "PWM.h"
int main (void)
{	uint8 temp;
ADC_ConfigType ADC_Config = {internal,F_CPU_8};
LCD_init();
DcMotor_Init();
ADC_init(&ADC_Config);

while (1)
{
	temp= LM35_getTemperature();
	if (temp < 30)
	{
		LCD_displayStringRowColumn(0,2,"FAN is OFF");
		DcMotor_Rotate(STOP,0);
	}
	else if ((temp >= 30) && (temp<60) )
	{
		LCD_moveCursor(0,11);
		LCD_displayCharacter(' ');
		LCD_displayStringRowColumn(0,2,"FAN is ON");
		DcMotor_Rotate(CW,25);
	}
	else if ((temp >= 60) && (temp< 90) )
	{
		LCD_displayStringRowColumn(0,2,"FAN is ON");
		DcMotor_Rotate(CW,50);
	}
	else if ((temp >=90) && (temp < 120))
	{
		LCD_displayStringRowColumn(0,2,"FAN is ON");
		DcMotor_Rotate(CW,75);
	}
	else if ((temp >=120))
	{
		LCD_displayStringRowColumn(0,2,"FAN is ON");
		DcMotor_Rotate(CW,100);
	}
	LCD_displayStringRowColumn(1,2,"Temp = ");
	LCD_intgerToString(temp);
	if ((temp >=0) && (temp <10))
	{
		LCD_displayCharacter(' ');
		LCD_displayCharacter(' ');
		LCD_displayCharacter('C');
	}
	else if ((temp>=10) && (temp <100))
	{
		LCD_displayCharacter(' ');
		LCD_displayCharacter('C');
	}
	else if (temp >= 100)
	{
		LCD_displayCharacter('C');
	}
}
return 0;
}

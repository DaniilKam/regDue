/*
  regDUE.h - Library for easy work with registers (PIO and ADC) on Arduino DUE.
  Created by Daniil Kamishov, September 5, 2019.
  Released into the public domain.
*/

#include <regDUE.h>
#include <Arduino.h>

//PIO
void regPinMode(byte pin, bool mode)
{
	byte pin_group = 0;
	byte i;

	for (i = pin; i >= 32; i -= 32)
	{
		pin_group++;
	}

	if (mode = true)
	{
		//OUTPUT
		switch (pin_group)
		{
			case 0:
				PIOA->PIO_OER |= (1 << i);
				PIOA->PIO_OWER &= ~(1 << i);
				break;
			case 1:
				PIOB->PIO_OER |= (1 << i);
				PIOB->PIO_OWER &= ~(1 << i);
				break;
			case 2:
				PIOC->PIO_OER |= (1 << i);
				PIOC->PIO_OWER &= ~(1 << i);
				break;
			case 3:
				PIOD->PIO_OER |= (i << i);
				PIOD->PIO_OWER &= ~(1 << i);
				break;
		}
	}
	else
	{
		//INPUT
		switch (pin_group)
		{
			case 0:
				PIOA->PIO_OWER |= (1 << i);
				PIOA->PIO_OER &= ~(1 << i);
				break;
			case 1:
				PIOB->PIO_OWER |= (1 << i);
				PIOB->PIO_OER &= ~(1 << i);
				break;
			case 2:
				PIOC->PIO_OWER |= (1 << i);
				PIOC->PIO_OER &= ~(1 << i);
				break;
			case 3:
				PIOD->PIO_OWER |= (i << i);
				PIOD->PIO_OER &= ~(1 << i);
				break;
		}
	}
}

void regDigitalWrite(byte pin, bool pos)
{
	byte pin_group = 0;
	byte i;

	for (i = pin; i >= 32; i -= 32)
	{
		pin_group++;
	}
	bool w_enable = false;
	switch (pin_group)
	{
		case 0:
			if ((PIOA->PIO_OWSR >> i) & 1 == 1)
				w_enable = true;
			break;
		case 1:
			if ((PIOB->PIO_OWSR >> i) & 1 == 1)
				w_enable = true;
			break;
		case 2:
			if ((PIOC->PIO_OWSR >> i) & 1 == 1)
				w_enable = true;
			break;
		case 3:
			if ((PIOD->PIO_OWSR >> i) & 1 == 1)
				w_enable = true;
			break;
	}

	if (w_enable == true)
	{
		if (pos == true)
		{
			switch (pin_group)
			{
				case 0:
					PIOA->PIO_ODSR |= (1 << i);
					break;
				case 1:
					PIOB->PIO_ODSR |= (1 << i);
					break;
				case 2:
					PIOC->PIO_ODSR |= (1 << i);
					break;
				case 3:
					PIOD->PIO_ODSR |= (1 << i);
					break;
			}
		}
		else
		{
			switch (pin_group)
			{
				case 0:
					PIOA->PIO_ODSR &= ~(1 << i);
					break;
				case 1:
					PIOB->PIO_ODSR &= ~(1 << i);
					break;
				case 2:
					PIOC->PIO_ODSR &= ~(1 << i);
					break;
				case 3:
					PIOD->PIO_ODSR &= ~(1 << i);
					break;
			}
		}
	}
}

byte regDigitalRead(byte pin)
{	
	byte pin_group = 0;
	byte i;

	for (i = pin; i >= 32; i -= 32)
	{
		pin_group++;
	}
	bool r_enable = false;
	switch (pin_group)
	{
		case 0:
			if ((PIOA->PIO_OSR >> i) & 1 == 1)
				r_enable = true;
			break;
		case 1:
			if ((PIOB->PIO_OSR >> i) & 1 == 1)
				r_enable = true;
			break;
		case 2:
			if ((PIOC->PIO_OSR >> i) & 1 == 1)
				r_enable = true;
			break;
		case 3:
			if ((PIOD->PIO_OSR >> i) & 1 == 1)
				r_enable = true;
			break;
	}

	if (r_enable == true)
	{
		switch (pin_group)
		{
			case 0:
				return (PIOA->PIO_ODSR >> i) & 1;
				break;
			case 1:
				return (PIOB->PIO_ODSR >> i) & 1;
				break;
			case 2:
				return (PIOC->PIO_ODSR >> i) & 1;
				break;
			case 3:
				return (PIOD->PIO_ODSR >> i) & 1;
				break;
		}
	}
	else
	{
		return 0;
	}
}

//ADC
unsigned int regAnalogRead(byte pin)
{
	#ifndef _REG_ADC_INIT
	#define _REG_ADC_INIT
	ADC->ADC_MR |= 0x80;
	ADC->ADC_CR = 2;
	ADC->ADC_CHER = 0xFF;
	#endif
	byte i = 0x01 << pin;
	while ((ADC->ADC_ISR & i) != i);
	unsigned int a = ADC->ADC_CDR[pin];
	return a;
}


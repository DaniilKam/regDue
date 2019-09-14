/*
  regDUE.h - Replacement by standard method for faster Arduino DUE operation
  Created by Daniil Kamishov, September 5, 2019.
  Released into the public domain.
  
  Updated by Daniil Kamishov, September 7, 2019.
*/


#ifndef regDUE_h
#define regDUE_h

#include <Arduino.h>

#define rD0 8
#define rD1 9
#define rD2 57
#define rD3 92
#define rD4 90
#define rD5 89
#define rD6 88
#define rD7 87
#define rD8 86
#define rD9 85
#define rD10 93
#define rD11 103
#define rD12 104
#define rD13 59
#define rD14 100
#define rD15 101
#define rD16 13
#define rD17 12
#define rD18 11
#define rD19 10
#define rD20 44
#define rD21 45
#define rD22 58
#define rD23 14
#define rD24 15
#define rD25 96
#define rD26 97
#define rD27 98
#define rD28 99
#define rD29 102
#define rD30 105
#define rD31 7
#define rD32 106
#define rD33 65
#define rD34 66
#define rD35 67
#define rD36 68
#define rD37 69
#define rD38 70
#define rD39 71
#define rD40 72
#define rD41 73
#define rD42 19
#define rD43 20
#define rD44 83
#define rD45 82
#define rD46 81
#define rD47 80
#define rD48 79
#define rD49 78
#define rD50 77
#define rD51 76
#define rD52 53
#define rD53 46

#define rA0 16
#define rA1 24
#define rA2 23
#define rA3 22
#define rA4 6
#define rA5 4
#define rA6 5
#define rA7 2
#define rA8 49
#define rA9 50
#define rA10 51
#define rA11 52

//PIO
void regPinMode(byte pin, bool mode);
void regDigitalWrite(byte pin, bool pos);
byte regDigitalRead(byte pin);

//ADC
unsigned int regAnalogRead(byte pin);

#endif

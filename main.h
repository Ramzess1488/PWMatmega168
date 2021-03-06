#ifndef MAIN_H_
#define MAIN_H_


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "eeprom.h"
#include "led.h"

//------------------------------------------------------------------------------
// дефайним порты
//------------------------------------------------------------------------------
//#define INVERT_MOD          // раскоментировать для инвертированого режима
#define   NONINVERT_MOD       // раскоментировать для не инвертированого режима

#define BUZERON        PORTD |= 0x20
#define BUZEROFF       PORTD &= ~ 0x20
#define BUZERINVERT    PORTD ^= 0x20
#define KNOPKAENC    ~ PIND &  0x04
#define ENCPOVOROT   ~ PIND &  0x10
#define LEDON          PORTD |= 0x02
#define LEDOFF         PORTD &= ~ 0x02
#define Q1ON           PORTB |= 0x01
#define Q1OFF          PORTB &= ~ 0x01
#define Q2ON           PORTD |= 0x80
#define Q2OFF          PORTD &= ~ 0x80
#define Q3ON           PORTD |= 0x40
#define Q3OFF          PORTD &= ~ 0x40
#ifdef NONINVERT_MOD
#define GOOPWM         TCCR1A  |= 0x82
#define STOPPWM        TCCR1A  &= ~ 0x82
#endif
#ifdef INVERT_MOD
#define GOOPWM         TCCR1A  |= 0xC0
#define STOPPWM        TCCR1A  &= ~ 0xC0
#endif
#define ODIN 1             
#define PYAT 5
//------------------------------------------------------------------------------
// объявляем прототипы функций
//------------------------------------------------------------------------------
void init (void);
void razbivaem_razryad (unsigned int vhod_chislo);
void pik_pik (void);
void piknut (int kolichestvo, int dlitelnost);
void read_encoder (void);


#endif /* MAIN_H_ */

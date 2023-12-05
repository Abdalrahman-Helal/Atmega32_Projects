;
; interrupt_LED.asm
;
; Created: 10/8/2023 11:41:27 PM
; Author : Abdalrahman
;


; Replace with your application code

.INCLUDE <m32adef.inc>

.ORG 0x0000
	JMP Init
	JMP Interrupt1
	JMP Interrupt2


init:
	;init SP 
	LDI R16,LOW(RAMEND)
	OUT SPL,R16
	LDI R16,HIGH(RAMEND)
	OUT SPH,R16

	SBI DDRB,2
	SBI DDRB,3

	; initialize PORTB0 as output
	SBI DDRB,0
	; initialize PORTB1 as output
	SBI DDRB,1

	; Configure Int0 to PIND2 as input
	CBI DDRD,2

	;Set PD2 as Pull-up
	SBI PORTD,2

	;Configure Int1 to PIND3 as input
	CBI DDRD,3

	;Set PD3 as Pull-up
	SBI PORTD,3

	

	;configure Int1 on falling edge 
	LDI R18,(1<<ISC11)
	OUT MCUCR,R18

	;configure INT0 on falling egde 
	LDI R18,(1<<ISC01)
	OUT MCUCR,R18
	
	;enable Int1 and Int0 as interrupt
	LDI R16,(1<<INT1 | 1<<INT0)
	OUT GICR,R16 ; Enable INT1, INT0 as Interrupt in Global interrupt Control Register

	; enable Globla interrupt mask
	LDI R17,(1<<SREG_I)
	OUT SREG, R17


main:
	SBI PORTB,2
	Call Delay
	CBI PORTB,2
	

	SBI PORTB,3
	Call Delay
	CBI PORTB,3
	rjmp main 
	

Interrupt1:
	SBI PORTB,0
	CBI PORTB,1
	RETI

Interrupt2:
	CBI PORTB,0
	SBI PORTB,1
	RETI

	

	Delay:
	
start:
	LDI R18,2
	nop

	LDI R19,63
DEL:
	DEC R19
	BRNE DEL

loop0:
	LDI R16,255
loop1:
	LDI R17,243
	nop
loop2:
	DEC R17
	nop
	BRNE loop2
	DEC R16
	nop
	nop
	nop
	nop
	BRNE loop1
	DEC R18
	nop
	BRNE loop0
	
	RET

	































































	

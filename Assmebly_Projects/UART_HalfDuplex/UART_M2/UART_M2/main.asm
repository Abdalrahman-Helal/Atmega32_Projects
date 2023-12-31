;
; UART_M2.asm
;
; Created: 11/30/2023 11:31:04 AM
; Author : Abdalrahman
;


; Replace with your application code

init:
	LDI R16, LOW(RAMEND)
	OUT SPL,R16
	LDI R16, HIGH(RAMEND)
	OUT SPH,R16
 
; intialize PORTD as an output
	LDI R17 , $FF
	OUT DDRD ,R17
	NOP 
; CLEAR PORTD 
	LDI R17,$00
	OUT PORTD,R17
; intialize PORTA0 as an input
	CBI DDRA,0
MAIN:
	SBIS PINA, 0
	CALL READ
	RJMP MAIN
READ:
	CALL DELAY 
;READ START BIT
	CALL DELAY
	CALL DELAY
; READ BUTTON0 VALUE
	SBIC PINA,0
	SBI PORTD,0
	SBIS PINA,0
	CBI PORTD,0
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON1 VALUE
	SBIC PINA,0
	sBI PORTD,1
	SBIS PINA,0
	CBI PORTD,1
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON2 VALUE
	SBIC PINA,0
	SBI PORTD,2
	SBIS PINA,0
	CBI PORTD,2
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON3 VALUE
	SBIC PINA,0
	SBI PORTD,3
	SBIS PINA,0
	CBI PORTD,3
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
; READ BUTTON4 VALUE
	SBIC PINA,0
	SBI PORTD,4
	SBIS PINA,0
	CBI PORTD,4
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON5 VALUE
	SBIC PINA,0
	SBI PORTD,5
	SBIS PINA,0
	CBI PORTD,5
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON6 VALUE
	SBIC PINA,0
	SBI PORTD,6
	SBIS PINA,0
	CBI PORTD,6
	NOP
	NOP
	CALL DELAY 
	CALL DELAY 
 ; READ BUTTON7 VALUE
	SBIC PINA,0
	SBI PORTD,7
	SBIS PINA,0
	CBI PORTD,7
	NOP
	NOP
	CALL DELAY
; wait for the stop bit to finish
	CALL DELAY 
	CALL DELAY
	RET		
	; Return from READ -> reading one byte


DELAY :
	LDI R16,14
	NOP
	NOP
LOOP:
	DEC R16
	BRNE LOOP
	RET
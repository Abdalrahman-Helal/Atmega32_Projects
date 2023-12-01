;
; Delay.asm
;
; Created: 9/15/2023 9:56:13 AM
; Author : Abdalrahman
;


; Replace with your application code

;Delay:
	
;start:
;	LDI R18,2
;	nop
;	LDI R19,3
;DEL:
;	DEC R19
;	BRNE DEL ; branch if not equal zero , skip if equal zero
;loop0:
;	LDI R16,255
;loop1:
;
;	rjmp start
;
;	RET

init:
	;init SP 
	LDI R16,LOW(RAMEND)
	OUT SPL,R16
	LDI R16,HIGH(RAMEND)
	OUT SPH,R16

main:
	call Delay

	RJMP main

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





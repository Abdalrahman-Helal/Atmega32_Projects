;
; PUSH_RAM.asm
;
; Created: 9/16/2023 6:48:28 PM
; Author : Abdalrahman
;


; Replace with your application code
	
.INCLUDE <m32def.inc>

init:
	LDI R16,HIGH(RAMEND) 
	OUT SPH,R16
	LDI R16,LOW(RAMEND)
	OUT SPL,R16

	LDI R17,$FF
	LDI R18,23

loop2:
	LDI R19,89
	
loop:
	PUSH R17
	DEC R19
	BRNE loop
	DEC R18
	BRNE loop2
	PUSH R17

	LDI R20,$FD


	

		























	/*DELAY:

	LDI R16,17 //17 22
start:
	LDI R17,29
loop1:
	DEC R17
	nop
	BRNE loop1
	DEC R16
	BRNE start


	LDI R18,4
loop2:
	DEC R18
	nop
	nop
	BRNE loop2
	ret*/







	// 2047

/*


	delay :
   ldi r16 ,197

   loop1 :
   ldi r17, 253

   loop2 : 
   dec r17 
   brne loop2
   dec r16
   brne loop1 
  ret*/
			


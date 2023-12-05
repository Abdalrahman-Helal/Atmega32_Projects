;
; pop.asm
;
; Created: 9/17/2023 2:32:53 PM
; Author : Abdalrahman
;


; Replace with your application code

init:
	LDI R16,$08
	OUT $3E,R16
	LDI R16,$5F
	OUT $3D,R16 // OUT Need Relative address 

_PUSH:
	LDI R18,$53

	LDI R27,$08
	LDI R26,$5F
	ST X, R18

	DEC R26
	OUT $3D,R26

	LDI R20,$25

_POP: //085E

	INC R26

	LDI R29,$08
	MOV R28,R26 //085F

	OUT $3D,R26

	LD R21,Y



	




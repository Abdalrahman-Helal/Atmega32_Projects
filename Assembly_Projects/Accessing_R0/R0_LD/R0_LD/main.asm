;
; R0_LD.asm
;
; Created: 9/16/2023 6:31:37 PM
; Author : Abdalrahman
;


; Replace with your application code
init:
   LDI R16,$08
   OUT $3E,R16 
   LDI R16,$5F
   OUT $3D,R16 

start:
	LDI R27,$08
	LDI R26,$5F

	LDI R16,$FF

	ST X,R16

	LD R0,X

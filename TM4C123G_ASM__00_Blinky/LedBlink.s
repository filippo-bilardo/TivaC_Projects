;*************************************************************************
;
;	Blink LED
;
;*************************************************************************
  		.thumb
SYSCTL_RCGC2_R 			.EQU 0x400FE108
SYSCTL_RCGC2_GPIOF		.EQU 0x20  		;Port F Clock Gating Control
GPIO_PORTF_DIR_R		.EQU 	0x40025400	;Port F Data Direction Register
GPIO_PORTF_DATA_R  		.EQU	0x400253FC	;Port F Data Register
GPIO_PORTF_DEN_R  		.EQU	0x4002551C	;Port F Data Enable Register
GPIO_PORTF_LOCK_R		.EQU	0x40025520	;Port F Unlock Register
GPIO_PORTF_CR_R			.EQU	0x40025524	;Port F Allow changes
GPIO_PORTF_AMSEL_R      .EQU	0x40025528	;PortF Analog function
GPIO_PORTF_AFSEL_R      .EQU	0x40025420	;Port F	Alternate function select
GPIO_PORTF_PCTL_R       .EQU	0x4002552C	;Port F Select regular function
GPIO_PORTF_PUR_R      	 .EQU	0x40025510  ;Port F enable pullup
;Enable the GPIO pin for the LEDs 
;Set the direction as output, and enable the GPIO pin for digital function
GPIO_PORTF_DIR_R_SET 	.EQU 0x0E;
GPIO_PORTF_DEN_R_SET	.EQU 0x01F;
GPIO_PORTF_PULLUP_SET	.EQU 0x11
GPIO_PORTF_DATA_RESET	.EQU 0xFFFFFF01;
GPIO_PORTF_LED_SET		.EQU 0xE;
GPIO_PORTF_UNLOCK_WORD	.EQU 0x4C4F434B
GPIO_PORTF_ALLOW_CHANGE	.EQU 0x1F	;allow changes to PF4-0
;
;DELAY					.EQU 400000
DELAY					.EQU 1200000
;*************************************************************************
;
		.data
   		.align 4
;
; Allocazione dello spazio riservato ai tre vettori aleatori
Counter	.field 32
;*************************************************************************
* DEFINIZIONE DELLO STACK
*
;		.global __stack
;STACKSIZE 	.set 256
;__stack:	.usect ".stack", STACKSIZE, 4
*
************************************************************************
; Definizione dell'area istruzioni
		.text
		
SysClkCtlAdr	.field SYSCTL_RCGC2_R, 32
PortFDirReg		.field GPIO_PORTF_DIR_R, 32
PortFDataReg	.field GPIO_PORTF_DATA_R, 32
PortFDataEnReg	.field GPIO_PORTF_DEN_R, 32
PortFUnlockReg	.field GPIO_PORTF_LOCK_R
PortFAllChange	.field GPIO_PORTF_CR_R
PortFAMSelReg	.field GPIO_PORTF_AMSEL_R
PortFAFSelReg	.field GPIO_PORTF_AFSEL_R
PortF_Pctl_Reg	.field GPIO_PORTF_PCTL_R
PortF_Pullu_Reg	.field GPIO_PORTF_PUR_R
CounterAdr		.field	Counter, 32
DelayValue		.field DELAY, 32
ClearAllLED		.field GPIO_PORTF_DATA_RESET, 32	
UnlockWord		.field GPIO_PORTF_UNLOCK_WORD, 32

			
		.global main

main: 	.asmfunc
	;STEP1: SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;
	LDR	R0, SysClkCtlAdr		;Abilita il clock del PORTF
	ORR	R1, R1, #SYSCTL_RCGC2_GPIOF
	STR	R1, [R0]
	NOP							;allow time for clock to start
	NOP
	;STEP2: GPIO_PORTF_LOCK_R = 0x4C4F434B;   unlock GPIO Port F
	LDR	R0, PortFUnlockReg
	LDR R1, UnlockWord
	STR	R1, [R0]
	;allow changes to PF4-0
	LDR	R0, PortFAllChange
	MOV R1, #GPIO_PORTF_ALLOW_CHANGE
	STR	R1, [R0]
	;STEP3: GPIO_PORTF_AMSEL_R = 0x00;   disable analog on PF
	LDR	R0, PortFAMSelReg
	EOR R1, R1;R1
	STR	R1, [R0]
	;STEP4: GPIO_PORTF_PCTL_R = 0x00000000;   PCTL GPIO on PF4-0
	LDR	R0, PortF_Pctl_Reg
	STR	R1, [R0]
	;STEP5: GPIO_PORTF_DIR_R = 0x0E; PF4,PF0 in, PF3-1 out
	LDR	R0, PortFDirReg		;Imposta i Bit321 del PORTF come out
	MOV	R1, #GPIO_PORTF_DIR_R_SET
	STR	R1, [R0]
	;STEP6: GPIO_PORTF_AFSEL_R = 0x00;  disable alt funct on PF7-0
	LDR	R0, PortFAFSelReg
	EOR R1, R1;R1
	STR	R1, [R0]
	;GPIO_PORTF_PUR_R = 0x11;    enable pull-up on PF0 and PF4
	LDR	R0, PortF_Pullu_Reg
	MOV R1, #GPIO_PORTF_PULLUP_SET
	STR	R1, [R0]	
	;STEP7:  GPIO_PORTF_DEN_R = 0x04; enable digital I/O on PF4-PF0
	LDR	R0, PortFDataEnReg		
	MOV	R1, #GPIO_PORTF_DEN_R_SET
	STR	R1, [R0]
	;	
	LDR	R3, PortFDataReg	; R3 pointer al Registro Data del PORTF
	;
Loop_1
	LDR	R1, [R3]
	ORR	R1, R1, #GPIO_PORTF_LED_SET	;LED ON => Forza a 1 i 3 led
	STR	R1, [R3]
	;
	;Loop di ritardo
	LDR R0, DelayValue 	;Load delay count
	;
Loop_2
	NOP
	NOP
	SUBS R0,R0,#1
	BNE	Loop_2
	;
	;
	LDR	R1, ClearAllLED	;Azzera i led
	LDR	R2, [R3]
	AND	R1, R2, R1
	STR	R1, [R3]
	;
	;Loop di ritardo
	LDR R0, DelayValue 	;Load delay count
	;
Loop_3
	NOP
	NOP
	SUBS R0,R0,#1
	BNE	Loop_3	
	;
	B Loop_1 ; Branch forever
	;
	.endasmfunc
;    	
; Fine del programma
		.end

	
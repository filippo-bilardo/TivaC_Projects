//==========================================================================================
//
// Project:	LedBlink
// Date:	13.11.15
// Author:	Filippo Bilardo
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  Lampeggio di un led presente nella scheda utilizzando un delay
//
//  Nota: includere nel progetto:
//	nel file search path del linker il file della TI driverlib.lib
//  e nell'include path dell'Arm compiler la cartella TivaWare
//
// Ver		Date		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C1.0		13.11.15	Versione iniziale. Il firmware � realizzato utilizzando le librerie
//						fornite dalla TI
// C1.1		13.11.15	Integrazione delle librerie fornite dalla TI con dei driver
//						personalizzati di secondo livello per l'accesso all'hardware
// C1.2		14.11.15	Aggiunta di un livello di astrazione dell'hardware (HAL)
//						che permette di utilizzare lo stesso progetto su pi� hardware simili
//
//==========================================================================================
//------------------------------------------------------------------------------------------
//=== Includes =============================================================================
//------------------------------------------------------------------------------------------
#include "DRIVERS/HwConfig.h"	// Hardware Abstraction Layer Drivers
#include "LIBS/Led.h"			// Led Library
#include "LIBS/Uart.h"			// Uart Library
#include "LIBS/SysTick.h"		// SysTick Library

//--------------------------------------------------------------------------------------------------
//=== Main =========================================================================================
//--------------------------------------------------------------------------------------------------
int main(void)
{
	// Inizializzazioni
	LedInit();
	UartInit();

	// Autodiagnostica
	LedGreenOn();
	//UartTest();		// Echo read chars fino alla pressione del del tasto Return
	DelayMs(500);
	LedGreenOff();

	// Ciclo infinito
	for(;;)
	{
		Led1On();
		DelayMs(100);
		Led1Off();
		DelayMs(900);
	}
}
//--------------------------------------------------------------------------------------------------
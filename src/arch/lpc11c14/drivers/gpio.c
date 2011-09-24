/****************************************************************************
 *   $Id:: gpio.c 4785 2010-09-03 22:39:27Z nxp21346                        $
 *   Project: NXP LPC11xx GPIO example
 *
 *   Description:
 *     This file contains GPIO code example which include GPIO 
 *     initialization, GPIO interrupt handler, and related APIs for 
 *     GPIO access.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include <project/driver_config.h>

#include <arch/gpio.h>

#if CONFIG_GPIO_DEFAULT_PIOINT0_IRQHANDLER==1
volatile uint32_t gpio0_counter = 0;
volatile uint32_t p0_1_counter  = 0;

void PIOINT0_IRQHandler(void) {
  uint32_t regVal;

  gpio0_counter++;
  regVal = GPIOIntStatus( PORT0, 1 );
  if ( regVal )
  {
	p0_1_counter++;
	GPIOIntClear( PORT0, 1 );
  }		
  return;
}
#endif

#if CONFIG_GPIO_DEFAULT_PIOINT1_IRQHANDLER==1
volatile uint32_t gpio1_counter = 0;
volatile uint32_t p1_1_counter  = 0;

void PIOINT1_IRQHandler(void) {
  uint32_t regVal;

  gpio1_counter++;
  regVal = GPIOIntStatus( PORT1, 1 );
  if ( regVal )
  {
	p1_1_counter++;
	GPIOIntClear( PORT1, 1 );
  }		
  return;
}
#endif

#if CONFIG_GPIO_DEFAULT_PIOINT2_IRQHANDLER==1
volatile uint32_t gpio2_counter = 0;
volatile uint32_t p2_1_counter  = 0;

void PIOINT2_IRQHandler(void) {
  uint32_t regVal;

  gpio2_counter++;
  regVal = GPIOIntStatus( PORT2, 1 );
  if ( regVal )
  {
	p2_1_counter++;
	GPIOIntClear( PORT2, 1 );
  }		
  return;
}
#endif

#if CONFIG_GPIO_DEFAULT_PIOINT3_IRQHANDLER==1
volatile uint32_t gpio3_counter = 0;
volatile uint32_t p3_1_counter  = 0;

void PIOINT3_IRQHandler(void) {
  uint32_t regVal;

  gpio3_counter++;
  regVal = GPIOIntStatus( PORT3, 1 );
  if ( regVal )
  {
	p3_1_counter++;
	GPIOIntClear( PORT3, 1 );
  }		
  return;
}
#endif //#if CONFIG_GPIO_DEFAULT_PIOINT3_IRQHANDLER==1

void GPIO_SetFunction(uint32_t port, uint32_t bit, uint32_t func) {

	/* for the specified port and pin, first set the function bits to 0 and then
	 * to the function we actually want */

	/* this chip is retarded. every IOCON register has different meanings for the
	 * bits. I'm starting to hate this chip */

	switch (port) {
	 case 0:
		switch (bit) {
		 case 0:
			/* this is the reset pin, we can't use it */
			return;
			LPC_IOCON->RESET_PIO0_0 &= ~0x07;
			LPC_IOCON->RESET_PIO0_0 |= (func+1);
			break;
		 case 1:
			LPC_IOCON->PIO0_1 &= ~0x07;
			LPC_IOCON->PIO0_1 |= func;
			break;
		 case 2:
			LPC_IOCON->PIO0_2 &= ~0x07;
			LPC_IOCON->PIO0_2 |= func;
			break;
		 case 3:
			LPC_IOCON->PIO0_3 &= ~0x07;
			LPC_IOCON->PIO0_3 |= func;
			break;
		 case 4:
			LPC_IOCON->PIO0_4 &= ~0x07;
			LPC_IOCON->PIO0_4 |= func;
			break;
		 case 5:
			LPC_IOCON->PIO0_5 &= ~0x07;
			LPC_IOCON->PIO0_5 |= func;
			break;
		 case 6:
			LPC_IOCON->PIO0_6 &= ~0x07;
			LPC_IOCON->PIO0_6 |= func;
			break;
		 case 7:
			LPC_IOCON->PIO0_7 &= ~0x07;
			LPC_IOCON->PIO0_7 |= func;
			break;
		 case 8:
			LPC_IOCON->PIO0_8 &= ~0x07;
			LPC_IOCON->PIO0_8 |= func;
			break;
		 case 9:
			/* this is TDO, it's used for programming */
			return;
		 case 10:
			/* this is TCLK, it's used for programming */
			return;
		 case 11:
			LPC_IOCON->R_PIO0_11 &= ~0x07;
			LPC_IOCON->R_PIO0_11 |= (func+1);
			break;
		}
		break;

	 case 1:
		switch (bit) {
		 case 0:
			LPC_IOCON->R_PIO1_0 &= ~0x07;
			LPC_IOCON->R_PIO1_0 |= (func+1);
			break;
		 case 1:
			LPC_IOCON->R_PIO1_1 &= ~0x07;
			LPC_IOCON->R_PIO1_1 |= (func+1);
			break;
		 case 2:
			LPC_IOCON->R_PIO1_2 &= ~0x07;
			LPC_IOCON->R_PIO1_2 |= (func+1);
			break;
		 case 3:
			/* this is TMS, it's used for programming */
			return;
		 case 4:
			LPC_IOCON->PIO1_4 &= ~0x07;
			LPC_IOCON->PIO1_4 |= func;
			break;
		 case 5:
			LPC_IOCON->PIO1_5 &= ~0x07;
			LPC_IOCON->PIO1_5 |= func;
			break;
		 case 6:
			LPC_IOCON->PIO1_6 &= ~0x07;
			LPC_IOCON->PIO1_6 |= func;
			break;
		 case 7:
			LPC_IOCON->PIO1_7 &= ~0x07;
			LPC_IOCON->PIO1_7 |= func;
			break;
		 case 8:
			LPC_IOCON->PIO1_8 &= ~0x07;
			LPC_IOCON->PIO1_8 |= func;
			break;
		 case 9:
			LPC_IOCON->PIO1_9 &= ~0x07;
			LPC_IOCON->PIO1_9 |= func;
			break;
		 case 10:
			LPC_IOCON->PIO1_10 &= ~0x07;
			LPC_IOCON->PIO1_10 |= func;
			break;
		 case 11:
			LPC_IOCON->PIO1_11 &= ~0x07;
			LPC_IOCON->PIO1_11 |= func;
			break;
		}
		break;

	 case 2:
		switch (bit) {
		 case 0:
			/* this is used for programming */
			return;
			LPC_IOCON->PIO2_0 &= ~0x07;
			LPC_IOCON->PIO2_0 |= func;
			break;
		 case 1:
			LPC_IOCON->PIO2_1 &= ~0x07;
			LPC_IOCON->PIO2_1 |= func;
			break;
		 case 2:
			LPC_IOCON->PIO2_2 &= ~0x07;
			LPC_IOCON->PIO2_2 |= func;
			break;
		 case 3:
			LPC_IOCON->PIO2_3 &= ~0x07;
			LPC_IOCON->PIO2_3 |= func;
			break;
		 case 4:
			LPC_IOCON->PIO2_4 &= ~0x07;
			LPC_IOCON->PIO2_4 |= func;
			break;
		 case 5:
			LPC_IOCON->PIO2_5 &= ~0x07;
			LPC_IOCON->PIO2_5 |= func;
			break;
		 case 6:
			LPC_IOCON->PIO2_6 &= ~0x07;
			LPC_IOCON->PIO2_6 |= func;
			break;
		 case 7:
			LPC_IOCON->PIO2_7 &= ~0x07;
			LPC_IOCON->PIO2_7 |= func;
			break;
		 case 8:
			LPC_IOCON->PIO2_8 &= ~0x07;
			LPC_IOCON->PIO2_8 |= func;
			break;
		 case 9:
			LPC_IOCON->PIO2_9 &= ~0x07;
			LPC_IOCON->PIO2_9 |= func;
			break;
		 case 10:
			LPC_IOCON->PIO2_10 &= ~0x07;
			LPC_IOCON->PIO2_10 |= func;
			break;
		 case 11:
			LPC_IOCON->PIO2_11 &= ~0x07;
			LPC_IOCON->PIO2_11 |= func;
			break;
		}
		break;

	 case 3:
		switch (bit) {
		 case 0:
			LPC_IOCON->PIO3_0 &= ~0x07;
			LPC_IOCON->PIO3_0 |= func;
			break;
		 case 1:
			LPC_IOCON->PIO3_1 &= ~0x07;
			LPC_IOCON->PIO3_1 |= func;
			break;
		 case 2:
			LPC_IOCON->PIO3_2 &= ~0x07;
			LPC_IOCON->PIO3_2 |= func;
			break;
		 case 3:
			LPC_IOCON->PIO3_3 &= ~0x07;
			LPC_IOCON->PIO3_3 |= func;
			break;
		 case 4:
			LPC_IOCON->PIO3_4 &= ~0x07;
			LPC_IOCON->PIO3_4 |= func;
			break;
		 case 5:
			LPC_IOCON->PIO3_5 &= ~0x07;
			LPC_IOCON->PIO3_5 |= func;
			break;
		}
		break;
	}
}

void GPIO_Init( void ) {
  /* Enable AHB clock to the GPIO domain. */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);

#ifdef __JTAG_DISABLED  
  LPC_IOCON->R_PIO1_1  |= 0x01;
#endif

  /* Set up NVIC when I/O pins are configured as external interrupts. */
#if CONFIG_GPIO_DEFAULT_PIOINT0_IRQHANDLER==1
  NVIC_EnableIRQ(EINT0_IRQn);
#endif
#if CONFIG_GPIO_DEFAULT_PIOINT1_IRQHANDLER==1
  NVIC_EnableIRQ(EINT1_IRQn);
#endif
#if CONFIG_GPIO_DEFAULT_PIOINT2_IRQHANDLER==1
  NVIC_EnableIRQ(EINT2_IRQn);
#endif
#if CONFIG_GPIO_DEFAULT_PIOINT3_IRQHANDLER==1
  NVIC_EnableIRQ(EINT3_IRQn);
#endif
  return;
}

/*****************************************************************************
** Function name:		GPIOSetInterrupt
**
** Descriptions:		Set interrupt sense, event, etc.
**						edge or level, 0 is edge, 1 is level
**						single or double edge, 0 is single, 1 is double 
**						active high or low, etc.
**
** parameters:			port num, bit position, sense, single/doube, polarity
** Returned value:		None
** 
*****************************************************************************/
void GPIO_SetInterrupt( uint32_t portNum, uint32_t bitPosi, uint32_t sense,
			uint32_t single, uint32_t event )
{
  switch ( portNum )
  {
	case PORT0:
	  if ( sense == 0 )
	  {
		LPC_GPIO0->IS &= ~(0x1<<bitPosi);
		/* single or double only applies when sense is 0(edge trigger). */
		if ( single == 0 )
		  LPC_GPIO0->IBE &= ~(0x1<<bitPosi);
		else
		  LPC_GPIO0->IBE |= (0x1<<bitPosi);
	  }
	  else
	  	LPC_GPIO0->IS |= (0x1<<bitPosi);
	  if ( event == 0 )
		LPC_GPIO0->IEV &= ~(0x1<<bitPosi);
	  else
		LPC_GPIO0->IEV |= (0x1<<bitPosi);
	break;
 	case PORT1:
	  if ( sense == 0 )
	  {
		LPC_GPIO1->IS &= ~(0x1<<bitPosi);
		/* single or double only applies when sense is 0(edge trigger). */
		if ( single == 0 )
		  LPC_GPIO1->IBE &= ~(0x1<<bitPosi);
		else
		  LPC_GPIO1->IBE |= (0x1<<bitPosi);
	  }
	  else
	  	LPC_GPIO1->IS |= (0x1<<bitPosi);
	  if ( event == 0 )
		LPC_GPIO1->IEV &= ~(0x1<<bitPosi);
	  else
		LPC_GPIO1->IEV |= (0x1<<bitPosi);  
	break;
	case PORT2:
	  if ( sense == 0 )
	  {
		LPC_GPIO2->IS &= ~(0x1<<bitPosi);
		/* single or double only applies when sense is 0(edge trigger). */
		if ( single == 0 )
		  LPC_GPIO2->IBE &= ~(0x1<<bitPosi);
		else
		  LPC_GPIO2->IBE |= (0x1<<bitPosi);
	  }
	  else
	  	LPC_GPIO2->IS |= (0x1<<bitPosi);
	  if ( event == 0 )
		LPC_GPIO2->IEV &= ~(0x1<<bitPosi);
	  else
		LPC_GPIO2->IEV |= (0x1<<bitPosi);  
	break;
	case PORT3:
	  if ( sense == 0 )
	  {
		LPC_GPIO3->IS &= ~(0x1<<bitPosi);
		/* single or double only applies when sense is 0(edge trigger). */
		if ( single == 0 )
		  LPC_GPIO3->IBE &= ~(0x1<<bitPosi);
		else
		  LPC_GPIO3->IBE |= (0x1<<bitPosi);
	  }
	  else
	  	LPC_GPIO3->IS |= (0x1<<bitPosi);
	  if ( event == 0 )
		LPC_GPIO3->IEV &= ~(0x1<<bitPosi);
	  else
		LPC_GPIO3->IEV |= (0x1<<bitPosi);	  
	break;
	default:
	  break;
  }
  return;
}

void GPIO_IntEnable( uint32_t portNum, uint32_t bitPosi ) {
  switch ( portNum )
  {
	case PORT0:
	  LPC_GPIO0->IE |= (0x1<<bitPosi); 
	break;
 	case PORT1:
	  LPC_GPIO1->IE |= (0x1<<bitPosi);	
	break;
	case PORT2:
	  LPC_GPIO2->IE |= (0x1<<bitPosi);	    
	break;
	case PORT3:
	  LPC_GPIO3->IE |= (0x1<<bitPosi);	    
	break;
	default:
	  break;
  }
  return;
}

void GPIO_IntDisable( uint32_t portNum, uint32_t bitPosi ) {
  switch ( portNum )
  {
	case PORT0:
	  LPC_GPIO0->IE &= ~(0x1<<bitPosi); 
	break;
 	case PORT1:
	  LPC_GPIO1->IE &= ~(0x1<<bitPosi);	
	break;
	case PORT2:
	  LPC_GPIO2->IE &= ~(0x1<<bitPosi);	    
	break;
	case PORT3:
	  LPC_GPIO3->IE &= ~(0x1<<bitPosi);	    
	break;
	default:
	  break;
  }
  return;
}

uint32_t GPIOIntStatus( uint32_t portNum, uint32_t bitPosi ) {
  uint32_t regVal = 0;

  switch ( portNum )
  {
	case PORT0:
	  if ( LPC_GPIO0->MIS & (0x1<<bitPosi) )
		regVal = 1;
	break;
 	case PORT1:
	  if ( LPC_GPIO1->MIS & (0x1<<bitPosi) )
		regVal = 1;	
	break;
	case PORT2:
	  if ( LPC_GPIO2->MIS & (0x1<<bitPosi) )
		regVal = 1;		    
	break;
	case PORT3:
	  if ( LPC_GPIO3->MIS & (0x1<<bitPosi) )
		regVal = 1;		    
	break;
	default:
	  break;
  }
  return ( regVal );
}

void GPIO_IntClear( uint32_t portNum, uint32_t bitPosi ) {
  switch ( portNum )
  {
	case PORT0:
	  LPC_GPIO0->IC |= (0x1<<bitPosi); 
	break;
 	case PORT1:
	  LPC_GPIO1->IC |= (0x1<<bitPosi);	
	break;
	case PORT2:
	  LPC_GPIO2->IC |= (0x1<<bitPosi);	    
	break;
	case PORT3:
	  LPC_GPIO3->IC |= (0x1<<bitPosi);	    
	break;
	default:
	  break;
  }
  return;
}

void GPIO_SetValue( uint32_t portNum, uint32_t bitPosi, uint32_t bitVal ) {
	LPC_GPIO[portNum]->MASKED_ACCESS[(1<<bitPosi)] = (bitVal<<bitPosi);
}

uint32_t GPIO_GetValue( uint32_t portNum, uint32_t bitPosi) {
	return LPC_GPIO[portNum]->MASKED_ACCESS[(1<<bitPosi)];
}

void GPIO_ToggleValue(uint32_t portNum, uint32_t bitPosi) {
	LPC_GPIO[portNum]->MASKED_ACCESS[(1<<bitPosi)] ^= (1<<bitPosi);
}

void GPIO_SetDir( uint32_t portNum, uint32_t bitPosi, uint32_t dir ) {
	if(dir)
		LPC_GPIO[portNum]->DIR |= 1<<bitPosi;
	else
		LPC_GPIO[portNum]->DIR &= ~(1<<bitPosi);
}

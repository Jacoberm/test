#ifndef CYGONCE_HAL_PLF_IO_H
#define CYGONCE_HAL_PLF_IO_H
//=============================================================================
//
//      plf_io.h
//
//      Platform specific registers
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2012 Free Software Foundation, Inc.                        
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   ilijak
// Date:        2012-02-25
// Purpose:     TWR-K70F120M platform specific registers
// Description:
// Usage:       #include <cyg/hal/plf_io.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================

#include <pkgconf/hal.h>
#include <pkgconf/hal_cortexm_kinetis_core_k70f150m.h>


// UART PINs
#ifndef CYGHWR_HAL_FREESCALE_UART3_PIN_RX
# define CYGHWR_HAL_FREESCALE_UART3_PIN_RX CYGHWR_HAL_KINETIS_PIN(C, 16, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART3_PIN_TX CYGHWR_HAL_KINETIS_PIN(C, 17, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART3_PIN_RTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE
# define CYGHWR_HAL_FREESCALE_UART3_PIN_CTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE

# define CYGHWR_IO_FREESCALE_UART3_PIN_RX CYGHWR_HAL_FREESCALE_UART3_PIN_RX
# define CYGHWR_IO_FREESCALE_UART3_PIN_TX CYGHWR_HAL_FREESCALE_UART3_PIN_TX
# define CYGHWR_IO_FREESCALE_UART3_PIN_RTS CYGHWR_HAL_FREESCALE_UART3_PIN_RTS
# define CYGHWR_IO_FREESCALE_UART3_PIN_CTS CYGHWR_HAL_FREESCALE_UART3_PIN_CTS
#endif

#ifndef CYGHWR_HAL_FREESCALE_UART2_PIN_RX
# define CYGHWR_HAL_FREESCALE_UART2_PIN_RX CYGHWR_HAL_KINETIS_PIN(E, 17, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART2_PIN_TX CYGHWR_HAL_KINETIS_PIN(E, 16, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART2_PIN_RTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE
# define CYGHWR_HAL_FREESCALE_UART2_PIN_CTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE

# define CYGHWR_IO_FREESCALE_UART2_PIN_RX CYGHWR_HAL_FREESCALE_UART2_PIN_RX
# define CYGHWR_IO_FREESCALE_UART2_PIN_TX CYGHWR_HAL_FREESCALE_UART2_PIN_TX
# define CYGHWR_IO_FREESCALE_UART2_PIN_RTS CYGHWR_HAL_FREESCALE_UART2_PIN_RTS
# define CYGHWR_IO_FREESCALE_UART2_PIN_CTS CYGHWR_HAL_FREESCALE_UART2_PIN_CTS
#endif

#ifndef CYGHWR_HAL_FREESCALE_UART1_PIN_RX
# define CYGHWR_HAL_FREESCALE_UART1_PIN_RX CYGHWR_HAL_KINETIS_PIN(C, 3, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART1_PIN_TX CYGHWR_HAL_KINETIS_PIN(C, 4, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART1_PIN_RTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE
# define CYGHWR_HAL_FREESCALE_UART1_PIN_CTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE

# define CYGHWR_IO_FREESCALE_UART1_PIN_RX CYGHWR_HAL_FREESCALE_UART1_PIN_RX
# define CYGHWR_IO_FREESCALE_UART1_PIN_TX CYGHWR_HAL_FREESCALE_UART1_PIN_TX
# define CYGHWR_IO_FREESCALE_UART1_PIN_RTS CYGHWR_HAL_FREESCALE_UART1_PIN_RTS
# define CYGHWR_IO_FREESCALE_UART1_PIN_CTS CYGHWR_HAL_FREESCALE_UART1_PIN_CTS
#endif

#ifndef CYGHWR_HAL_FREESCALE_UART0_PIN_RX
# define CYGHWR_HAL_FREESCALE_UART0_PIN_RX CYGHWR_HAL_KINETIS_PIN(A, 1, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART0_PIN_TX CYGHWR_HAL_KINETIS_PIN(A, 2, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART0_PIN_RTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE
# define CYGHWR_HAL_FREESCALE_UART0_PIN_CTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE

# define CYGHWR_IO_FREESCALE_UART0_PIN_RX CYGHWR_HAL_FREESCALE_UART1_PIN_RX
# define CYGHWR_IO_FREESCALE_UART0_PIN_TX CYGHWR_HAL_FREESCALE_UART1_PIN_TX
# define CYGHWR_IO_FREESCALE_UART0_PIN_RTS CYGHWR_HAL_FREESCALE_UART1_PIN_RTS
# define CYGHWR_IO_FREESCALE_UART0_PIN_CTS CYGHWR_HAL_FREESCALE_UART1_PIN_CTS
#endif

// ENET PINs

// MDIO
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_MDIO    CYGHWR_HAL_KINETIS_PIN(B, 0, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_MDC     CYGHWR_HAL_KINETIS_PIN(B, 1, 4, 0)
// Both RMII and MII interface
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXER    CYGHWR_HAL_KINETIS_PIN(A, 5, 4, \
                                                    CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXD1    CYGHWR_HAL_KINETIS_PIN(A, 12, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXD0    CYGHWR_HAL_KINETIS_PIN(A, 13, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXEN    CYGHWR_HAL_KINETIS_PIN(A, 15, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXD0    CYGHWR_HAL_KINETIS_PIN(A, 16, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXD1    CYGHWR_HAL_KINETIS_PIN(A, 17, 4, 0)
// RMII interface only
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_CRS_DV  CYGHWR_HAL_KINETIS_PIN(A, 14, 4, 0)
// MII interface only
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_RXD3     CYGHWR_HAL_KINETIS_PIN(A, 9, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_RXD2     CYGHWR_HAL_KINETIS_PIN(A, 10, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_RXCLK    CYGHWR_HAL_KINETIS_PIN(A, 11, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_TXD2     CYGHWR_HAL_KINETIS_PIN(A, 24, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_TXCLK    CYGHWR_HAL_KINETIS_PIN(A, 25, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_TXD3     CYGHWR_HAL_KINETIS_PIN(A, 26, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_CRS      CYGHWR_HAL_KINETIS_PIN(A, 27, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MIIO_TXER     CYGHWR_HAL_KINETIS_PIN(A, 28, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_MII0_COL      CYGHWR_HAL_KINETIS_PIN(A, 29, 4, 0)
// IEEE 1588 timers
#define CYGHWR_IO_FREESCALE_ENET0_PIN_1588_CLKIN    CYGHWR_HAL_KINETIS_PIN(E, 26, 4, 0)

#if defined(CYGHWR_HAL_FREESCALE_ENET0_E0_1588_PORT_B)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR0  CYGHWR_HAL_KINETIS_PIN(B, 2, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR1  CYGHWR_HAL_KINETIS_PIN(B, 3, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR2  CYGHWR_HAL_KINETIS_PIN(B, 4, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR3  CYGHWR_HAL_KINETIS_PIN(B, 5, 4, 0)
#elif defined(CYGHWR_HAL_FREESCALE_ENET0_E0_1588_PORT_C)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR0  CYGHWR_HAL_KINETIS_PIN(C, 16, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR1  CYGHWR_HAL_KINETIS_PIN(C, 17, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR2  CYGHWR_HAL_KINETIS_PIN(C, 18, 4, 0)
# define CYGHWR_IO_FREESCALE_ENET0_PIN_E0_1588_TMR3  CYGHWR_HAL_KINETIS_PIN(C, 19, 4, 0)
#endif

// DSPI
// DSPI Pins
//DSPI1
#define KINETIS_PIN_SPI0_OUT_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
#define KINETIS_PIN_SPI0_SCK_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M)
#define KINETIS_PIN_SPI0_CS_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)

#define KINETIS_PIN_SPI0_IN_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)
#define KINETIS_PIN_SPI0_0_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)

#define CYGHWR_IO_FREESCALE_SPI0_PIN_SIN  CYGHWR_HAL_KINETIS_PIN(D, 3, 2, KINETIS_PIN_SPI0_IN_OPT)
#define CYGHWR_IO_FREESCALE_SPI0_PIN_SOUT CYGHWR_HAL_KINETIS_PIN(D, 2, 2, KINETIS_PIN_SPI0_OUT_OPT)
#define CYGHWR_IO_FREESCALE_SPI0_PIN_SCK  CYGHWR_HAL_KINETIS_PIN(D, 1, 2, KINETIS_PIN_SPI0_SCK_OPT)

#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS0  CYGHWR_HAL_KINETIS_PIN(D, 0, 2, KINETIS_PIN_SPI0_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS1  CYGHWR_HAL_KINETIS_PIN_NONE  //CYGHWR_HAL_KINETIS_PIN(D, 4, 2, KINETIS_PIN_SPI0_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS2  CYGHWR_HAL_KINETIS_PIN(C, 2, 2, KINETIS_PIN_SPI0_CS_OPT)//CYGHWR_HAL_KINETIS_PIN_NONE  //
#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS3  CYGHWR_HAL_KINETIS_PIN(C, 1, 2, KINETIS_PIN_SPI0_CS_OPT) //CYGHWR_HAL_KINETIS_PIN_NONE  //
#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS4  CYGHWR_HAL_KINETIS_PIN(C, 0, 2, KINETIS_PIN_SPI0_CS_OPT) //CYGHWR_HAL_KINETIS_PIN_NONE
#define CYGHWR_IO_FREESCALE_SPI0_PIN_CS5  CYGHWR_HAL_KINETIS_PIN_NONE

//DSPI1
#define KINETIS_PIN_SPI1_OUT_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
#define KINETIS_PIN_SPI1_SCK_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M)
#define KINETIS_PIN_SPI1_CS_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)

#define KINETIS_PIN_SPI1_IN_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)
#define KINETIS_PIN_SPI1_0_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)

#define CYGHWR_IO_FREESCALE_SPI1_PIN_SIN  CYGHWR_HAL_KINETIS_PIN(E, 1, 7, KINETIS_PIN_SPI1_IN_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_SOUT CYGHWR_HAL_KINETIS_PIN(E, 3, 7, KINETIS_PIN_SPI1_OUT_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_SCK  CYGHWR_HAL_KINETIS_PIN(E, 2, 2, KINETIS_PIN_SPI1_SCK_OPT)

#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS0  CYGHWR_HAL_KINETIS_PIN(E, 4, 2, KINETIS_PIN_SPI1_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS1  CYGHWR_HAL_KINETIS_PIN(E, 0, 2, KINETIS_PIN_SPI1_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS2  CYGHWR_HAL_KINETIS_PIN(E, 5, 2, KINETIS_PIN_SPI1_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS3  CYGHWR_HAL_KINETIS_PIN(E, 6, 2, KINETIS_PIN_SPI1_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS4  CYGHWR_HAL_KINETIS_PIN_NONE
#define CYGHWR_IO_FREESCALE_SPI1_PIN_CS5  CYGHWR_HAL_KINETIS_PIN_NONE

//DSPI2
#define KINETIS_PIN_SPI2_OUT_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
#define KINETIS_PIN_SPI2_SCK_OPT (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M)
#define KINETIS_PIN_SPI2_CS_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
                                  CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)

#define KINETIS_PIN_SPI2_IN_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)
#define KINETIS_PIN_SPI2_0_OPT  (CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)

#define CYGHWR_IO_FREESCALE_SPI2_PIN_SIN  CYGHWR_HAL_KINETIS_PIN(B, 23, 2, KINETIS_PIN_SPI2_IN_OPT)
#define CYGHWR_IO_FREESCALE_SPI2_PIN_SOUT CYGHWR_HAL_KINETIS_PIN(B, 22, 2, KINETIS_PIN_SPI2_OUT_OPT)
#define CYGHWR_IO_FREESCALE_SPI2_PIN_SCK  CYGHWR_HAL_KINETIS_PIN(B, 21, 2, KINETIS_PIN_SPI2_SCK_OPT)

#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS0  CYGHWR_HAL_KINETIS_PIN(B, 20, 2, KINETIS_PIN_SPI2_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS1  CYGHWR_HAL_KINETIS_PIN_NONE  //CYGHWR_HAL_KINETIS_PIN(D, 15, 2, KINETIS_PIN_SPI2_CS_OPT)
#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS2  CYGHWR_HAL_KINETIS_PIN_NONE
#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS3  CYGHWR_HAL_KINETIS_PIN_NONE
#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS4  CYGHWR_HAL_KINETIS_PIN_NONE
#define CYGHWR_IO_FREESCALE_SPI2_PIN_CS5  CYGHWR_HAL_KINETIS_PIN_NONE

// I2C
// I2C Pins

# define CYGHWR_IO_I2C_FREESCALE_I2C0_PIN_SDA CYGHWR_HAL_KINETIS_PIN(E, 18, 4, 0)
# define CYGHWR_IO_I2C_FREESCALE_I2C0_PIN_SCL CYGHWR_HAL_KINETIS_PIN(E, 19, 4, 0)

// CAN
// CANA Pins
# define CYGHWR_IO_FREESCALE_FLEXCANA_PIN_RX CYGHWR_HAL_KINETIS_PIN(B, 19, 2, 0)
# define CYGHWR_IO_FREESCALE_FLEXCANA_PIN_TX CYGHWR_HAL_KINETIS_PIN(B, 18, 2, 0)
// CANB Pins
# define CYGHWR_IO_FREESCALE_FLEXCANB_PIN_RX CYGHWR_HAL_KINETIS_PIN(F, 24, 2, 0)
# define CYGHWR_IO_FREESCALE_FLEXCANB_PIN_TX CYGHWR_HAL_KINETIS_PIN(F, 25, 2, 0)

// NFC
// NFC Pins
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_ALE 	CYGHWR_HAL_KINETIS_PIN(D,  9, 6, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_CE 		CYGHWR_HAL_KINETIS_PIN(C, 17, 6, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_CLE 	CYGHWR_HAL_KINETIS_PIN(D,  8, 6, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_RB 		CYGHWR_HAL_KINETIS_PIN(C, 16, 6, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_RE 		CYGHWR_HAL_KINETIS_PIN(D, 10, 6, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_WE 		CYGHWR_HAL_KINETIS_PIN(C, 11, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D0 		CYGHWR_HAL_KINETIS_PIN(D,  5, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D1 		CYGHWR_HAL_KINETIS_PIN(D,  4, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D2		CYGHWR_HAL_KINETIS_PIN(C, 10, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D3 		CYGHWR_HAL_KINETIS_PIN(C,  9, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D4 		CYGHWR_HAL_KINETIS_PIN(C,  8, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D5 		CYGHWR_HAL_KINETIS_PIN(C,  7, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D6 		CYGHWR_HAL_KINETIS_PIN(C,  6, 5, 0)
#define CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D7 		CYGHWR_HAL_KINETIS_PIN(C,  5, 5, 0)

// LCDC
// LCDC Pins
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_PCLK 		CYGHWR_HAL_KINETIS_PIN(F, 0, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_DE 		CYGHWR_HAL_KINETIS_PIN(F, 1, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_HSYNC 	CYGHWR_HAL_KINETIS_PIN(F, 2, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_VSYNC 	CYGHWR_HAL_KINETIS_PIN(F, 3, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D0 	CYGHWR_HAL_KINETIS_PIN(F,  4, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D1 	CYGHWR_HAL_KINETIS_PIN(F,  5, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D2	CYGHWR_HAL_KINETIS_PIN(F,  6, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D3 	CYGHWR_HAL_KINETIS_PIN(F,  7, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D4 	CYGHWR_HAL_KINETIS_PIN(F,  8, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D5 	CYGHWR_HAL_KINETIS_PIN(F,  9, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D6 	CYGHWR_HAL_KINETIS_PIN(F, 10, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D7 	CYGHWR_HAL_KINETIS_PIN(F, 11, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D8 	CYGHWR_HAL_KINETIS_PIN(F, 12, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D9 	CYGHWR_HAL_KINETIS_PIN(F, 13, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D10	CYGHWR_HAL_KINETIS_PIN(F, 14, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D11	CYGHWR_HAL_KINETIS_PIN(F, 15, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D12	CYGHWR_HAL_KINETIS_PIN(F, 16, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D13	CYGHWR_HAL_KINETIS_PIN(F, 17, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D14	CYGHWR_HAL_KINETIS_PIN(F, 18, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D15	CYGHWR_HAL_KINETIS_PIN(F, 19, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D16	CYGHWR_HAL_KINETIS_PIN(F, 20, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D17	CYGHWR_HAL_KINETIS_PIN(F, 21, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D18	CYGHWR_HAL_KINETIS_PIN(F, 22, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D19	CYGHWR_HAL_KINETIS_PIN(F, 23, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D20	CYGHWR_HAL_KINETIS_PIN(F, 24, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D21	CYGHWR_HAL_KINETIS_PIN(F, 25, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D22	CYGHWR_HAL_KINETIS_PIN(F, 26, 7, 0)
#define CYGHWR_IO_LCDC_FREESCALE_LCDC_PIN_D23	CYGHWR_HAL_KINETIS_PIN(F, 27, 7, 0)
//=============================================================================
// Memory access checks.
//
// Accesses to areas not backed by real devices or memory can cause
// the CPU to hang. These macros allow the GDB stubs to avoid making
// accidental accesses to these areas.

__externC int cyg_hal_stub_permit_data_access( void* addr, cyg_uint32 count );

#define CYG_HAL_STUB_PERMIT_DATA_READ(_addr_, _count_) cyg_hal_stub_permit_data_access( _addr_, _count_ )

#define CYG_HAL_STUB_PERMIT_DATA_WRITE(_addr_, _count_ ) cyg_hal_stub_permit_data_access( _addr_, _count_ )

//=============================================================================


#ifdef CYGPKG_DEVS_SND_VS1063A
#define KINETIS_PIN_IN_PULLUP  ( CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)

#define KINETIS_PIN_PULLUP  (CYGHWR_HAL_KINETIS_PORT_PCR_DSE_M | CYGHWR_HAL_KINETIS_PORT_PCR_PS_M | \
		CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
/*_
//Define the pin of addr for device
#define	DEV_ADDR0  CYGHWR_HAL_KINETIS_PIN(D, 11, 1, 0)
#define	DEV_ADDR1  CYGHWR_HAL_KINETIS_PIN(D, 12, 1, 0)
#define	DEV_ADDR2  CYGHWR_HAL_KINETIS_PIN(D, 13, 1, 0)
#define	DEV_ADDR3  CYGHWR_HAL_KINETIS_PIN(D, 14, 1, 0)
#define	DEV_ADDR4  CYGHWR_HAL_KINETIS_PIN(B, 3, 1, 0)

#define	TYPE_ADDR0  CYGHWR_HAL_KINETIS_PIN(C, 0, 1, 0)
#define	TYPE_ADDR1  CYGHWR_HAL_KINETIS_PIN(C, 2, 1, 0)

#define	DEV_ADDR_INIT() \
		{\
			hal_set_pin_function( DEV_ADDR0);\
			hal_gpio_pin_ddr_in( DEV_ADDR0);\
			hal_set_pin_function( DEV_ADDR1);\
			hal_gpio_pin_ddr_in( DEV_ADDR1);\
			hal_set_pin_function( DEV_ADDR2);\
			hal_gpio_pin_ddr_in( DEV_ADDR2);\
			hal_set_pin_function(DEV_ADDR3);\
			hal_gpio_pin_ddr_in( DEV_ADDR3);\
			hal_set_pin_function( DEV_ADDR4);\
			hal_gpio_pin_ddr_in( DEV_ADDR4);\
			hal_set_pin_function( TYPE_ADDR0);\
			hal_gpio_pin_ddr_in( TYPE_ADDR0);\
			hal_set_pin_function( TYPE_ADDR1);\
			hal_gpio_pin_ddr_in( TYPE_ADDR1);\
		}

#define READ_DEVICE_TYPE(con)  {\
								con=0;\
								if(hal_gpio_get_pin( DEV_ADDR0 )) con=con|0x08;\
								if(hal_gpio_get_pin( DEV_ADDR1 )) con=con|0x10;\
								if(hal_gpio_get_pin( DEV_ADDR2 )) con=con|0x20;\
								if(hal_gpio_get_pin( DEV_ADDR3 )) con=con|0x40;\
								if(hal_gpio_get_pin( DEV_ADDR4 )) con=con|0x80;\
								if(hal_gpio_get_pin( TYPE_ADDR0 )) con=con|1;\
								if(hal_gpio_get_pin( TYPE_ADDR1 )) con=con|2;\
			}

*/

#define  _DREQ_SET()  CYGHWR_HAL_KINETIS_PIN(A, 19, 1, KINETIS_PIN_IN_PULLUP)
#define  DREQ_SET()   _DREQ_SET()

#define  DREQ_PIN   19

#define QREQ_INIT() \
		hal_set_pin_function( DREQ_SET() );\
		hal_gpio_pin_ddr_in( DREQ_SET() )



#define READ_DREQ(__value )   \
		__value =  hal_gpio_get_pin( DREQ_SET() )

#ifdef CYGINT_IO_SND_INT_SUPPORT_REQUIRED
// Register this as your DSR within your driver: it will cause your deliver
// routine to be called from the audio thread.  The "data" parameter
// *must* be your own "struct cyg_audio_dev *dev" pointer.
extern void snd_drv_dsr( cyg_vector_t vector,
        cyg_ucount32 count,
        cyg_addrword_t data );
#endif //CYGINT_IO_SND_INT_SUPPORT_REQUIRED



struct cyg_audio_dev;
__externC void cyg_devs_cortexm_stm32_vs1063a_init( struct cyg_audio_dev * );

#ifdef CYGSEM_HAL_5034_V1_DEVICES_TYPE_EAMP  //|| CYGSEM_HAL_MK7-_V1_DEVICES_TYPE_EAMP

#define PA_OCCUPY_PIN CYGHWR_HAL_KINETIS_PIN(D, 11, 1, 0)
#define RS485_EN_PIN  CYGHWR_HAL_KINETIS_PIN(C,  1, 1, KINETIS_PIN_PULLUP)

#define LS1_CTRL0  //CYGHWR_HAL_KINETIS_PIN(E,  3, 1, KINETIS_PIN_PULLUP)
#define LS1_CTRL1  //CYGHWR_HAL_KINETIS_PIN(B,  3, 1, KINETIS_PIN_PULLUP)
#define LS1_CTRL2  //CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)//dac1_out
#define LS1_CTRL3  //CYGHWR_HAL_KINETIS_PIN(A, 10, 1, KINETIS_PIN_PULLUP)
#define LS1_CTRL4  CYGHWR_HAL_KINETIS_PIN(E,  4, 1, KINETIS_PIN_PULLUP)

#define LS2_CTRL0  //CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)  //adc0_se16
#define LS2_CTRL1  //CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)  //adc1_se16
#define LS2_CTRL2 // CYGHWR_HAL_KINETIS_PIN(B, 22, 1, KINETIS_PIN_PULLUP)
#define LS2_CTRL3  //CYGHWR_HAL_KINETIS_PIN(B, 20, 1, KINETIS_PIN_PULLUP)
#define LS2_CTRL4  CYGHWR_HAL_KINETIS_PIN(A,  9, 1, KINETIS_PIN_PULLUP)



#define EAMP_6W5_1_MUTE   CYGHWR_HAL_KINETIS_PIN(D, 14, 1, KINETIS_PIN_PULLUP)
#define EAMP_6W5_1_GAIN0  CYGHWR_HAL_KINETIS_PIN(E,  1, 1, KINETIS_PIN_PULLUP)
#define EAMP_6W5_1_GAIN1  CYGHWR_HAL_KINETIS_PIN(E,  0, 1, KINETIS_PIN_PULLUP)
#define EAMP_6W5_2_MUTE   CYGHWR_HAL_KINETIS_PIN(C,  2, 1, KINETIS_PIN_PULLUP)
#define EAMP_6W5_2_GAIN0  CYGHWR_HAL_KINETIS_PIN(B,  2, 1, KINETIS_PIN_PULLUP)
#define EAMP_6W5_2_GAIN1  CYGHWR_HAL_KINETIS_PIN(B, 22, 1, KINETIS_PIN_PULLUP)   //dac0_out

#define EAMP_30W_1_MUTE  LS1_CTRL1
#define EAMP_30W_2_MUTE  LS1_CTRL2

#define EAMP_30W_1_DB36  LS1_CTRL4
#define EAMP_30W_2_DB36  LS2_CTRL4



#define	EAMP_PIN_INIT() \
		{\
			hal_set_pin_function( EAMP_6W5_1_MUTE);\
			hal_gpio_pin_ddr_out( EAMP_6W5_1_MUTE);\
			hal_gpio_pin_set( EAMP_6W5_1_MUTE);\
			hal_set_pin_function( EAMP_6W5_1_GAIN1);\
			hal_gpio_pin_ddr_out( EAMP_6W5_1_GAIN1 );\
			hal_gpio_pin_set( EAMP_6W5_1_GAIN1);\
			hal_set_pin_function( EAMP_6W5_1_GAIN0);\
			hal_gpio_pin_ddr_out( EAMP_6W5_1_GAIN0);\
			hal_gpio_pin_set( EAMP_6W5_1_GAIN0);\
			hal_set_pin_function( EAMP_6W5_2_MUTE);\
			hal_gpio_pin_ddr_out( EAMP_6W5_2_MUTE);\
			hal_gpio_pin_set( EAMP_6W5_2_MUTE );\
			hal_set_pin_function( EAMP_6W5_2_GAIN1);\
			hal_gpio_pin_ddr_out( EAMP_6W5_2_GAIN1 );\
			hal_gpio_pin_set( EAMP_6W5_2_GAIN1 );\
			hal_set_pin_function( EAMP_6W5_2_GAIN0);\
			hal_gpio_pin_ddr_out( EAMP_6W5_2_GAIN0);\
			hal_gpio_pin_set( EAMP_6W5_2_GAIN0 );\
			hal_set_pin_function(EAMP_30W_1_DB36);\
			hal_gpio_pin_ddr_out( EAMP_30W_1_DB36);\
			hal_gpio_pin_set( EAMP_30W_1_DB36 );\
			hal_set_pin_function( EAMP_30W_2_DB36);\
			hal_gpio_pin_ddr_out( EAMP_30W_2_DB36);\
			hal_gpio_pin_set( EAMP_30W_2_DB36 );\
			hal_set_pin_function( PA_OCCUPY_PIN );\
			hal_gpio_pin_ddr_in( PA_OCCUPY_PIN );\
			hal_set_pin_function( RS485_EN_PIN);\
			hal_gpio_pin_ddr_out( RS485_EN_PIN);\
			hal_gpio_pin_clear( RS485_EN_PIN );\
		}

#define eamp_read_pa_occupy_status(void) hal_gpio_get_pin( PA_OCCUPY_PIN )

//__externC bool read_button_snd(void) ;

#endif  //CYGSEM_HAL_MK70_V1_DEVICES_TYPE_EAMP


//define IO for PECU
#ifdef CYGSEM_HAL_5034_V1_DEVICES_TYPE_PECU  //|| CYGSEM_HAL_MK7-_V1_DEVICES_TYPE_PECU

#define	PECU_BUTTON_PIN  CYGHWR_HAL_KINETIS_PIN(A, 9, 1, 0)

#define PECU_LED_R_PIN   CYGHWR_HAL_KINETIS_PIN(D, 12, 1, KINETIS_PIN_PULLUP)
#define PECU_LED_G0_PIN   CYGHWR_HAL_KINETIS_PIN(E, 18, 1, KINETIS_PIN_PULLUP)
#define PECU_LED_G1_PIN   CYGHWR_HAL_KINETIS_PIN(E, 19, 1, KINETIS_PIN_PULLUP)

#define PECU_6W5_1_MUTE   CYGHWR_HAL_KINETIS_PIN(E, 5, 1, KINETIS_PIN_PULLUP)
#define PECU_6W5_1_GAIN0  CYGHWR_HAL_KINETIS_PIN(E, 0, 1, KINETIS_PIN_PULLUP)
#define PECU_6W5_1_GAIN1  CYGHWR_HAL_KINETIS_PIN(E, 1, 1, KINETIS_PIN_PULLUP)

#define	PECU_PIN_INIT() \
		{\
			hal_set_pin_function( PECU_LED_R_PIN );\
			hal_gpio_pin_ddr_out( PECU_LED_R_PIN );\
			hal_gpio_pin_set( PECU_LED_R_PIN );\
			hal_set_pin_function( PECU_LED_G0_PIN );\
			hal_gpio_pin_ddr_out( PECU_LED_G0_PIN );\
			hal_gpio_pin_clear( PECU_LED_G0_PIN );\
			hal_set_pin_function( PECU_LED_G1_PIN );\
			hal_gpio_pin_ddr_out( PECU_LED_G1_PIN );\
			hal_gpio_pin_clear( PECU_LED_G1_PIN );\
			hal_set_pin_function( PECU_6W5_1_MUTE);\
			hal_gpio_pin_ddr_out( PECU_6W5_1_MUTE);\
			hal_gpio_pin_set( PECU_6W5_1_MUTE);\
			hal_set_pin_function( PECU_6W5_1_GAIN1);\
			hal_gpio_pin_ddr_out( PECU_6W5_1_GAIN1 );\
			hal_gpio_pin_clear( PECU_6W5_1_GAIN1);\
			hal_set_pin_function( PECU_6W5_1_GAIN0);\
			hal_gpio_pin_ddr_out( PECU_6W5_1_GAIN0);\
			hal_gpio_pin_set( PECU_6W5_1_GAIN0);\
			hal_set_pin_function( PECU_BUTTON_PIN);\
			hal_gpio_pin_ddr_in( PECU_BUTTON_PIN);\
		}

#define PECU_LED_G_0_SET(__value) \
		{		\
			if(__value==1)hal_gpio_pin_clear( PECU_LED_G0_PIN );\
			else hal_gpio_pin_clear( PECU_LED_G0_PIN );\
		}

#define PECU_LED_G_1_SET(__value1) \
		{		\
			if(__value1==1)hal_gpio_pin_clear( PECU_LED_G1_PIN );\
			else hal_gpio_pin_clear( PECU_LED_G1_PIN );\
		}

__externC bool eamp_read_pa_occupy_status(void);

__externC bool read_button_snd(void) ;


#endif  //CYGSEM_HAL_MK70_V1_DEVICES_TYPE_PECU

//define IO for CCU
#ifdef CYGSEM_HAL_5034_V1_DEVICES_TYPE_CCU  //|| CYGSEM_HAL_MK7-_V1_DEVICES_TYPE_CCU

#define CCU_6W5_1_MUTE   CYGHWR_HAL_KINETIS_PIN(E, 4, 1, KINETIS_PIN_PULLUP)
#define CCU_6W5_1_GAIN0  CYGHWR_HAL_KINETIS_PIN(E, 0, 1, KINETIS_PIN_PULLUP)
#define CCU_6W5_1_GAIN1  CYGHWR_HAL_KINETIS_PIN(E, 1, 1, KINETIS_PIN_PULLUP)
//#define CCU_6W5_2_MUTE   CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)
//#define CCU_6W5_2_GAIN0  CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)
//#define CCU_6W5_2_GAIN1  CYGHWR_HAL_KINETIS_PIN(D, 11, 1, KINETIS_PIN_PULLUP)


__externC bool eamp_read_pa_occupy_status(void);

__externC bool read_button_snd(void) ;


#endif  //CYGSEM_HAL_MK70_V1_DEVICES_TYPE_CCU

#endif  //CYGPKG_DEVS_SND_VS1063A





//-----------------------------------------------------------------------------
// end of plf_io.h
#endif // CYGONCE_HAL_PLF_IO_H


#ifndef CYGONCE_HAL_VAR_IO_NFC_H
#define CYGONCE_HAL_VAR_IO_NFC_H
//===========================================================================
//
//      var_io_nfc.h
//
//      Kinetis Nand flash control specific registers
//
//===========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2011 Free Software Foundation, Inc.                        
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
//===========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):     benty king <bentyking@126.com>
// Date:          2015-01-30
// Purpose:       Kinetis variant specific registers
// Description:
// Usage:         #include <cyg/hal/var_io.h>  // var_io.h includes this file
//
//####DESCRIPTIONEND####
//
//===========================================================================


//---------------------------------------------------------------------------
//NFC :  NAND FLASH CONTROL

#define CYGNUM_HAL_KINETIS_NFC_CMD_N 2  // Number of DDRMC control registers
#define CYGNUM_HAL_KINETIS_NFC_SR_N 2  // Number of DDRMC control registers

typedef volatile struct cyghwr_hal_kinetis_nfc_s {
    cyg_uint32 cmd[CYGNUM_HAL_KINETIS_NFC_CMD_N ]; // Control registers  //
    cyg_uint32 car;														//8
    cyg_uint32 rar;															//0xC
    cyg_uint32 rpt;														//0x10
    cyg_uint32 rai;														//0x14
    cyg_uint32 sr[CYGNUM_HAL_KINETIS_NFC_SR_N ];						//0x1C
    cyg_uint32 dma1;													//0x20
    cyg_uint32 dmacfg;
    cyg_uint32 swap;
    cyg_uint32 secsz;
    cyg_uint32 cfg;
    cyg_uint32 dma2;
    cyg_uint32 isr;
} cyghwr_hal_kinetis_nfc_t;

#define CYGHWR_HAL_KINETIS_NFC_P  ((cyghwr_hal_kinetis_nfc_t *)0x400abf00)
// Clocking
#define CYGHWR_IO_NFC_FREESCALE_NFC_CLOCK hal_get_peripheral_clock()
#define CYGHWR_IO_FREESCALE_NFC_CLK  CYGHWR_HAL_KINETIS_SIM_SCGC_NFC

// Pins
# define CYGHWR_IO_FREESCALE_NFC_PIN(__pin) hal_set_pin_function(__pin)

/***************** Module-Relative Register Offsets *************************/
#define CYGHWR_HAL_KINETIS_NFC_BASE					0x400a8000
#define CYGHWR_HAL_KINETIS_NFC_BUFFER1				0x0000
#define CYGHWR_HAL_KINETIS_NFC_BUFFER2				0x1000
#define CYGHWR_HAL_KINETIS_NFC_BUFFER3				0x2000
#define CYGHWR_HAL_KINETIS_NFC_BUFFER4				0x3000
#define CYGHWR_HAL_KINETIS_NFC_CMD1					0x3F00
#define CYGHWR_HAL_KINETIS_NFC_CMD2					0x3F04
#define CYGHWR_HAL_KINETIS_NFC_COL_ADDR				0x3F08
#define CYGHWR_HAL_KINETIS_NFC_ROW_ADDR				0x3F0c
#define CYGHWR_HAL_KINETIS_NFC_COMMAND_REPEAT		0x3F10
#define CYGHWR_HAL_KINETIS_NFC_ROW_ADDR_INC			0x3F14
#define CYGHWR_HAL_KINETIS_NFC_STATUS1				0x3F18
#define CYGHWR_HAL_KINETIS_NFC_STATUS2				0x3F1c
#define CYGHWR_HAL_KINETIS_NFC_DMA1_ADDR			0x3F20
#define CYGHWR_HAL_KINETIS_NFC_DMA2_ADDR			0x3F34
#define CYGHWR_HAL_KINETIS_NFC_DMA_CONFIG			0x3F24
#define CYGHWR_HAL_KINETIS_NFC_CACHE_SWAP			0x3F28
#define CYGHWR_HAL_KINETIS_NFC_SECTOR_SIZE			0x3F2c
#define CYGHWR_HAL_KINETIS_NFC_CONFIG				0x3F30
#define CYGHWR_HAL_KINETIS_NFC_IRQ_STATUS			0x3F38

// CMD1 - NAND Flash command1
// CMD1 Bit FieldsL
//CMD1 BYTE2
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2_M     	0xFF000000
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2_S     	24
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2(__val)  	VALUE_(CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2_S, __val)


//CMD1 BYTE3
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE3_M     	0x00FF0000
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE3_S     	16
#define CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE3(__val)  	VALUE_(CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE3_S, __val)

// CMD2 - NAND Flash command2
// CMD2 Bit Fields
//CMD2 BYTE1
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1_M     	0xFF000000
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1_S     	24
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1(__val)  	VALUE_(CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1_S, __val)


//CMD2 CODE
#define CYGHWR_HAL_KINETIS_NFC_CMD2_CODE_M			0x00FFFF00
#define CYGHWR_HAL_KINETIS_NFC_CMD2_CODE_S     		8
#define CYGHWR_HAL_KINETIS_NFC_CMD2_CODE(__val)  	VALUE_(CYGHWR_HAL_KINETIS_NFC_CMD2_CODE_S, __val )


#define CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_M			0x00000006
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_S     	1
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO(__val)  	VALUE_(CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_S, __val )

#define CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_M	0x00000001
#define CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_S	0


// CAR - NAND Flash Column address
// CAR Bit Fields
// CAR ADDRESS
#define CYGHWR_HAL_KINETIS_NFC_CAR_M     			0x0000FFFF
#define CYGHWR_HAL_KINETIS_NFC_CAR_S     			0
#define CYGHWR_HAL_KINETIS_NFC_CAR(__val)  			VALUE_(CYGHWR_HAL_KINETIS_NFC_CAR_S, __val)
// CAR BYTE1
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE1_M     		0x000000FF
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE1_S     		0
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE1(__val)		VALUE_(CYGHWR_HAL_KINETIS_NFC_CAR_BYTE1_S, __val)
//CAR BYTE2
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE2_M			0x0000FF00
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE2_S			8
#define CYGHWR_HAL_KINETIS_NFC_CAR_BYTE2(__val)		VALUE_(CYGHWR_HAL_KINETIS_NFC_CAR_BYTE2_S, __val )

// RAR - NAND Flash Row address
// RAR Bit Fields
// RAR CS1
#define CYGHWR_HAL_KINETIS_NFC_RAR_CS1_M     0x20000000
#define CYGHWR_HAL_KINETIS_NFC_RAR_CS1_S     29
// RAR CS0
#define CYGHWR_HAL_KINETIS_NFC_RAR_CS0_M     0x10000000
#define CYGHWR_HAL_KINETIS_NFC_RAR_CS0_S     28
// RAR RB1
#define CYGHWR_HAL_KINETIS_NFC_RAR_RB1_M     0x02000000
#define CYGHWR_HAL_KINETIS_NFC_RAR_RB1_S     25
// RAR RB0
#define CYGHWR_HAL_KINETIS_NFC_RAR_RB0_M     0x01000000
#define CYGHWR_HAL_KINETIS_NFC_RAR_RB0_S     24
//RAR ADDRESS
#define CYGHWR_HAL_KINETIS_NFC_RAR_M		0x00FFFFFF
#define CYGHWR_HAL_KINETIS_NFC_RAR_S     	0
#define CYGHWR_HAL_KINETIS_NFC_RAR(__val)	VALUE_(CYGHWR_HAL_KINETIS_NFC_RAR_S, __val )
//RAR BYTE3
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE3_M		0x00FF0000
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE3_S     	16
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE3(__val)  VALUE_(CYGHWR_HAL_KINETIS_NFC_RAR_BYTE3_S, __val )
//RAR BYTE2
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE2_M		0x0000FF00
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE2_S     	8
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE2(__val)  VALUE_(CYGHWR_HAL_KINETIS_NFC_RAR_BYTE2_S, __val )
//RAR BYTE1
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE1_M		0x000000FF
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE1_S     	0
#define CYGHWR_HAL_KINETIS_NFC_RAR_BYTE1(__val)  VALUE_(CYGHWR_HAL_KINETIS_NFC_RAR_BYTE1_S, __val )


// RPT - NAND  Flash command repeat
// RPT Bit Fields
// RPT COUNT
#define CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_M		0x0000FFFF
#define CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S     	0
#define CYGHWR_HAL_KINETIS_NFC_RPT_COUNT(__val)  VALUE_(CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S, __val )


// RAI - NAND  Flash Row address increment
// RAI Bit Fields
// RAI COUNT
#define CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_M		0x00FFFFFF
#define CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_S     	0


// SR1 - NAND  Flash status 1
// SR1 Bit Fields
// SR1 ID1-4
#define CYGHWR_HAL_KINETIS_NFC_SR1_M		0xFFFFFFFF
#define CYGHWR_HAL_KINETIS_NFC_SR1_S     	0
// SR1 ID4
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID4_M		0x000000FF
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID4_S     	0
// SR1 ID3
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID3_M		0x0000FF00
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID3_S     	8
// SR1 ID2
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID2_M		0x00FF0000
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID2_S     	16
// SR1 ID1
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID1_M		0xFF000000
#define CYGHWR_HAL_KINETIS_NFC_SR1_ID1_S     	24


// SR2 - NAND  Flash status 1
// SR2 Bit Fields
// SR2 STATUS1
#define CYGHWR_HAL_KINETIS_NFC_SR2_STATUS1_M		0x0000FFFF
#define CYGHWR_HAL_KINETIS_NFC_SR2_STATUS1_S     	0
// SR2 ID5
#define CYGHWR_HAL_KINETIS_NFC_SR2_ID5_M		0xFF000000
#define CYGHWR_HAL_KINETIS_NFC_SR2_ID5_S     	24


// DMA1 - DMA channel 1 address
// DMA1 Bit Fields
// DMA1
#define CYGHWR_HAL_KINETIS_NFC_DMA1_ADDRESS_M		0xFFFFFFFF
#define CYGHWR_HAL_KINETIS_NFC_DMA1_ADDRESS_S     	0


// DMACFG - DMA configuration
// DMACFG Bit Fields
// DMACFG
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_COUNT1_M		0xFFF00000
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_COUNT1_S     	20
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_COUNT2_M		0x000FE000
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_COUNT2_S     	13
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_OFFSET2_M		0x00001E00
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_OFFSET2_S     9
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_ACT1_M		0x00000002
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_ACT1_S     	1
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_ACT2_M		0x00000001
#define CYGHWR_HAL_KINETIS_NFC_DMACFG_ACT2_S     	0


// SWAP - // Cach swap
// SWAP Bit Fields
// SWAP
#define CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_M		0x0FFE0000
#define CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_S     	17
#define CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_M		0x00000FFE
#define CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_S     	1


// SECSZ - // Sector size
// SECSZ Bit Fields
// SECSZ
#define CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_M			0x00001FFF
#define CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_S     	0


// CFG - //Flash configuration
// CFG Bit Fields
// CFG
#define CYGHWR_HAL_KINETIS_NFC_CFG_STOPWERR_M		0x80000000
#define CYGHWR_HAL_KINETIS_NFC_CFG_STOPWERR_S     	31
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_M			0x7FC00000
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S     		22
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD(__val)  VALUE_( CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S , __val )

#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_M			0x00200000
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_S     		21
#define CYGHWR_HAL_KINETIS_NFC_CFG_DMAREQ_M				0x00100000
#define CYGHWR_HAL_KINETIS_NFC_CFG_DMAREQ_S     		20

#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_M			0x000E0000
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S     		17
#define CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE(__val)  VALUE_( CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S , __val )

#define CYGHWR_HAL_KINETIS_NFC_ECC_BYPASS			0x0
#define CYGHWR_HAL_KINETIS_NFC_ECC_8_BYTE			0x1
#define CYGHWR_HAL_KINETIS_NFC_ECC_12_BYTE			0x2
#define CYGHWR_HAL_KINETIS_NFC_ECC_15_BYTE			0x3
#define CYGHWR_HAL_KINETIS_NFC_ECC_23_BYTE			0x4
#define CYGHWR_HAL_KINETIS_NFC_ECC_30_BYTE			0x5
#define CYGHWR_HAL_KINETIS_NFC_ECC_45_BYTE			0x6
#define CYGHWR_HAL_KINETIS_NFC_ECC_60_BYTE			0x7
#define CYGHWR_HAL_KINETIS_NFC_ECC_ERROR			1
#define CYGHWR_HAL_KINETIS_NFC_ECC_RIGHT			0

#define CYGHWR_HAL_KINETIS_NFC_CFG_FAST_M				0x00010000
#define CYGHWR_HAL_KINETIS_NFC_CFG_FAST_S     			16
#define CYGHWR_HAL_KINETIS_NFC_CFG_IDCNT_M				0x0000E000
#define CYGHWR_HAL_KINETIS_NFC_CFG_IDCNT_S     			13
#define CYGHWR_HAL_KINETIS_NFC_CFG_TIMEOUT_M			0x00001F00
#define CYGHWR_HAL_KINETIS_NFC_CFG_TIMEOUT_S     		8
#define CYGHWR_HAL_KINETIS_NFC_CFG_TIMEOUT(__val)  VALUE_( CYGHWR_HAL_KINETIS_NFC_CFG_TIMEOUT_S , __val )

#define CYGHWR_HAL_KINETIS_NFC_CFG_BITWIDTH_M			0x00000080
#define CYGHWR_HAL_KINETIS_NFC_CFG_BITWIDTH_S     		7
#define CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M				0x00000020
#define CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S     			5
#define CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M				0x00000010
#define CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S     			4
#define CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT_M			0x0000000F
#define CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT_S 			0
#define CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT(__val)		VALUE_( CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT_S  , __val )


// DMA2 - //DMA channel 2 address
// DMA2 Bit Fields
// DMA2
#define CYGHWR_HAL_KINETIS_NFC_DMA2_ADDRESS_M			0xFFFFFFFF
#define CYGHWR_HAL_KINETIS_NFC_DMA2_ADDRESS_S 			0
#define CYGHWR_HAL_KINETIS_NFC_DMA2_ADDRESS(__val)		VALUE_( CYGHWR_HAL_KINETIS_NFC_DMA2_ADDRESS_S  , __val )


// ISR - //DMA channel 2 address
// ISR Bit Fields
// ISR
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERR_M				0x80000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERR_S 				31
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONE_M				0x40000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONE_S 				30
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_M				0x20000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_S 				29
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERRNS_M				0x08000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERRNS_S 			27
#define CYGHWR_HAL_KINETIS_NFC_ISR_CMDBUSY_M			0x04000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_CMDBUSY_S 				26
#define CYGHWR_HAL_KINETIS_NFC_ISR_RESBUSY_M			0x02000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_RESBUSY_S 				25
#define CYGHWR_HAL_KINETIS_NFC_ISR_ECCBUSY_M			0x01000000
#define CYGHWR_HAL_KINETIS_NFC_ISR_ECCBUSY_S 				24
#define CYGHWR_HAL_KINETIS_NFC_ISR_DMABUSY_M			0x00800000
#define CYGHWR_HAL_KINETIS_NFC_ISR_DMABUSY_S 				23
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERREN_M				0x00400000
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERREN_S 				22
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONEEN_M				0x00200000
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONEEN_S 				21
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLEEN_M				0x00100000
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLEEN_S 				20
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_M			0x00080000
#define CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_S 				19
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M			0x00040000
#define CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_S 				18
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M			0x00020000
#define CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S 				17
#define CYGHWR_HAL_KINETIS_NFC_ISR_RESBN_M				0x0000030
#define CYGHWR_HAL_KINETIS_NFC_ISR_RESBN_S 				4
#define CYGHWR_HAL_KINETIS_NFC_ISR_ECCBN_M				0x000000C
#define CYGHWR_HAL_KINETIS_NFC_ISR_ECCBN_S 				2
#define CYGHWR_HAL_KINETIS_NFC_ISR_DMABN_M				0x0000003
#define CYGHWR_HAL_KINETIS_NFC_ISR_DMABN_S 				0

/* Addresses for NFC MAIN RAM BUFFER areas */
#define CYGHWR_HAL_KINETIS_NFC_MAIN_AREA(n)		((n) *  0x1000)

/* Addresses for NFC SPARE BUFFER areas */
#define CYGHWR_HAL_KINETIS_NFC_SPARE_BUFFERS		8
#define CYGHWR_HAL_KINETIS_NFC_SPARE_LEN			0x10
#define CYGHWR_HAL_KINETIS_NFC_SPARE_AREA(n)		(0x800 + ((n) * CYGHWR_HAL_KINETIS_NFC_SPARE_LEN))

#define PAGE_2K				0x0800
#define PAGE_64				0x0040


// Typical Flash Commands /


///////////////////////////Module-Relative Register Reset Value
#define CYGHWR_HAL_KINETIS_NFC_SRAM_BUFFER_RSTVAL			0x00000000
#define CYGHWR_HAL_KINETIS_NFC_FLASH_CMD1_RSTVAL			0x30FF0000
#define CYGHWR_HAL_KINETIS_NFC_FLASH_CMD2_RSTVAL			0x007EE000
#define CYGHWR_HAL_KINETIS_NFC_COL_ADDR_RSTVAL			0x00000000
#define CYGHWR_HAL_KINETIS_NFC_ROW_ADDR_RSTVAL			0x11000000
#define CYGHWR_HAL_KINETIS_NFC_FLASH_COMMAND_REPEAT_RSTVAL		0x00000000
#define CYGHWR_HAL_KINETIS_NFC_ROW_ADDR_INC_RSTVAL			0x00000001
#define CYGHWR_HAL_KINETIS_NFC_FLASH_STATUS1_RSTVAL		0x00000000
#define CYGHWR_HAL_KINETIS_NFC_FLASH_STATUS2_RSTVAL		0x00000000
#define CYGHWR_HAL_KINETIS_NFC_DMA1_ADDR_RSTVAL			0x00000000
#define CYGHWR_HAL_KINETIS_NFC_DMA2_ADDR_RSTVAL			0x00000000
#define CYGHWR_HAL_KINETIS_NFC_DMA_CONFIG_RSTVAL			0x00000000
#define CYGHWR_HAL_KINETIS_NFC_CACHE_SWAP_RSTVAL			0x0FFE0FFE
#define CYGHWR_HAL_KINETIS_NFC_SECTOR_SIZE_RSTVAL			0x00000420
#define CYGHWR_HAL_KINETIS_NFC_FLASH_CONFIG_RSTVAL			0x000EA631
#define CYGHWR_HAL_KINETIS_NFC_IRQ_STATUS_RSTVAL			0x04000000

#ifndef __ASSEMBLER__

// Pin configuration related functions
__externC void  hal_set_pin_function(cyg_uint32 pin);
__externC void  hal_dump_pin_function(cyg_uint32 pin);
__externC void  hal_dump_pin_setting(cyg_uint32 pin);

#endif

# define CYGHWR_IO_FREESCALE_NFC_PIN(__pin) \
        hal_set_pin_function(__pin)


//-----------------------------------------------------------------------------
// end of var_io_nfc.h
#endif // CYGONCE_HAL_VAR_IO_NFC_H

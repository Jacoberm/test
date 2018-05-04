#ifndef CYGONCE_MT29F_GENERIC_H
#define CYGONCE_MT29F_GENERIC_H
//=============================================================================
//
//      nfc_generic.h
//
//      Definitions header for the nand flash control of KINETIS  family
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2010 eCosCentric Limited.
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
// Author(s):   huibin
// Date:        2015-03-26
// Description: Early definitions for the driver.
//
//####DESCRIPTIONEND####
//=============================================================================

#include <pkgconf/io_nand.h>
#include <pkgconf/devs_nand_fsl_kinetis_nfc.h>
#include <cyg/hal/hal_io.h>
#include <cyg/nand/nand_device.h>
#include <cyg/hal/drv_api.h>
#include <cyg/infra/diag.h>
#include <pkgconf/hal_cortexm_kinetis_core_k70f150m.h>

struct _kinetis_nfc_subtype;
typedef struct _kinetis_nfc_subtype kinetis_nfc_subtype;

// Some delay macros ------------------------------------------------------
// Busy waiting delay
#define NFC_WAIT_US(__us) HAL_DELAY_US(__us)
// Delays / Timeouts
#define NFC_KINETIS_RESET_DELAY   1      // Enet reset [us]

/* Our private structure ======================================= */
// Every instance of the chip needs its own copy of this struct.
// N.B. that this is too big to go on the stack in certain
// eCos configurations; it should normally be static.

#if (CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE == 2048)
#define _CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT 1
#elif (CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE == 4096)
#define _CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT 2
#else
#define _CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT 4
#endif
#define CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT _CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT
#define _VIRTUAL_PAGE_MAIN_SIZE 		CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE/CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT
#define _VIRTUAL_PAGE_SPARE_SIZE 	CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_SPARE_SIZE/CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT

#define VIRTUAL_PAGE_MAIN_SIZE _VIRTUAL_PAGE_MAIN_SIZE
#define VIRTUAL_PAGE_SPARE_SIZE _VIRTUAL_PAGE_SPARE_SIZE

#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
#define KINETIS_NFC_SWAP_ADDR1 	((VIRTUAL_PAGE_MAIN_SIZE + VIRTUAL_PAGE_SPARE_SIZE) - CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_SPARE_SIZE ) >>3
#define KINETIS_NFC_SWAP_ADDR2  (VIRTUAL_PAGE_MAIN_SIZE)>>3
#endif
#define KINETIS_NFC_SWAP_ADDR_DEFAULT  0X7FF

#define KINETIS_NFC_BUFFER_SIZE 	0x8FF

#define KINETIS_NFC_ECC_BUF_ADDR 			((2048 + 256 - 8 ) >>3)
#define KINETIS_NFC_ECC_STATUS_MASK	0x80
#define KINETIS_NFC_ECC_ERR_COUNT	0x3F
#define KINETIS_NFC_ECC_OFFSET   7
#define _CYGHWR_HAL_KINETIS_NFC_BASE				CYGHWR_HAL_KINETIS_NFC_BASE
#define KINETIS_NFC_BASE	((CYG_ADDRWORD)_CYGHWR_HAL_KINETIS_NFC_BASE)

#define KINETIS_NFC_BUFFER_AREA(n)		((n) *  0x1000)

struct _nfc_subtype;
typedef struct _nfc_subtype nfc_subtype;

// Resources borrowed from HAL

static const cyg_uint32 const nfc_pins[] = {
    // Both RMII and MII interface
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_ALE ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_CE ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_CLE ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_RB ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_RE ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_WE ,
#ifdef CYGNUM_DEVS_NAND_KINETIS_NFC_DATA_BUS_16
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D15,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D14,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D13,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D12,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D11,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D10 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D9 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D8
#endif
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D7 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D6 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D5 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D4 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D3 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D2 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D1 ,
	CYGHWR_IO_NFC_FREESCALE_NFC_PIN_D0
};

typedef struct _nfc_priv_s {
    CYG_ADDRWORD nfc_base;               // NFC base address
    cyghwr_hal_kinetis_nfc_t *nfc_reg;
    cyg_uint8 nfc_completed;
    kinetis_nfc_subtype *supported_chips; // Must be set by the platform HAL. Terminate with a zero-entry! See nfc_SUPPORT_LIST below.
    void *plat_priv; // For use by the platform HAL, if desired.
    // ------------ //
    cyg_nand_page_addr pagestash; // Guarded by dev lock.
    CYG_BYTE row_addr_size; // Set up by devinit after chip detection.
#ifdef CYGSEM_IO_NAND_USE_BBT
// The in-RAM BBT for a device is fixed at 2 bits per eraseblock.
// See nand_bbt.c for more.
    unsigned char bbt_data[CYGNUM_DEVS_NAND_FSL_KINETIS_BBT_DATASIZE];
#endif
    cyg_uint32 clock;                     // Clock gating
    const cyg_uint32 *pins_p;             // NFC pin configuration data
    cyg_uint8 pins_n;					//Number of NFC
    cyg_drv_mutex_t nfc_lock;          // For synchronizing between DSR and ISR
#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
                                     // foreground
    cyg_drv_cond_t  nfc_wait;
    cyg_uint32 nfc_isr_id;
    cyg_uint32 nfc_isr_pri;
    cyg_interrupt nfc_interrupt;
    cyg_handle_t  nfc_interrupt_handle;
#endif // CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
}nfc_priv_t;


// Macro to instantiate a KINETIS NFC device
#define KINETIS_NFC_DEVICE(_structname_, _chips_list_, _devname_, _priv_, _ecc_, _oob_)\
struct _nfc_priv_s  _structname_##_priv =                                 \
{ 																		\
	.nfc_base =  KINETIS_NFC_BASE,								\
    .nfc_reg = CYGHWR_HAL_KINETIS_NFC_P,								\
	.supported_chips = _chips_list_,										\
    .plat_priv = _priv_,												\
    .clock = CYGHWR_IO_FREESCALE_NFC_CLK,							\
	.pins_p = nfc_pins ,											\
	.pins_n = sizeof(nfc_pins)/sizeof(nfc_pins[0]),				\
};                                                                     \
CYG_NAND_DEVICE(_structname_, _devname_, &kinetis_nfc_funs_with_ecc,    \
                &_structname_##_priv, _ecc_, _oob_);

/* Prototypes for functions to be provided by the platform driver ==== */

// Chip BUSY line access / fallback -----------------

/* Waits either for the !BUSY line to signal that the device is finished,
 * or (if not available) polls the chip by sending the Read Status command
 * and waits for (response & mask) to be non-zero. */
static void wait_ready_or_status(cyg_nand_device *ctx, CYG_BYTE mask);

// Chip concurrent-access protection ----------------
// (This need not do anything, if the library-provided
//  per-device locking is sufficient.)
 
//static inline void nfc_devlock(cyg_nand_device *ctx);
//static inline void nfc_devunlock(cyg_nand_device *ctx);

// Initialisation hooks -----------------------------

/* Platform-specific chip initialisation.
 * Set up chip access lines, GPIO config, &c; should also set up
 * locking to guard against concurrent access.
 * Return 0 on success, or a negative error code. */
static int nfc_plf_init(cyg_nand_device *ctx);

/* (N.B. There is no deinit hook, as the library does not currently 
 *  support a device being deconfigured.) */

/* Platform-specific in-memory partition table setup.
 * Return 0 on success, or a negative error code.
 * (This is called at the end of devinit, so you can read from the chip
 * if need be.) */
static int nfc_plf_partition_setup(cyg_nand_device *dev);

// Internal entrypoints (used by some large page ECC drivers)
#ifdef CYGFUN_NAND_KINETIS_NFC_LP
static inline void change_read_column_lp(cyg_nand_device *dev, cyg_nand_column_addr col);
#endif

// Family support -----------------------------------

// Basic definitions for nfc subtypes

struct _kinetis_nfc_subtype {
    CYG_BYTE ident1, ident3;
    const char *descriptor;
    CYG_BYTE page_bits;
    CYG_BYTE spare_per_page;
    CYG_BYTE block_page_bits;
    CYG_BYTE blockcount_bits;
    CYG_BYTE chipsize_log;
    CYG_BYTE row_address_size;
    CYG_BYTE sp; // set non-0 if device is small-page
};

// Callers should not use NFC_SUBTYPE directly.
// Instead the known subtypes are defined in nfc_generic.inl.
#define KINETIS_NFC_SUBTYPE(id1,id3,desc,pb,spp,bpb,bcb,csl,ras) { id1, id3, desc,pb,spp,bpb, bcb, csl, ras, 0 }
#define KINETIS_NFC_SUBTYPE_SP(id1,id3,desc,pb,spp,bpb,bcb,csl,ras) { id1, id3, desc,pb,spp,bpb, bcb, csl, ras, 1 }

// A list of supported subtypes must be zero-terminated!
#define KINETIS_NFC_SUBTYPE_SENTINEL { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

// For a list of implemented subtypes, refer to the bottom of mt29f_generic.inl.

#endif

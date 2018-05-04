//=============================================================================
//
//      nfc_generic.inl
//
//      Inline include file for the Kinetis Nand flash control
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
// Author(s):   Huibin
// Date:        2015-03-26
//
//####DESCRIPTIONEND####
//=============================================================================

#include <pkgconf/io_nand.h>
#include <cyg/devs/nand/nfc_kinetis.h>
#include <cyg/infra/cyg_ass.h>

#define LOCK(dev)       cyg_drv_mutex_lock(&(kinetis_nfc_lock));
#define UNLOCK(dev)     cyg_drv_mutex_unlock(&(kinetis_nfc_lock));
#define INITLOCK(dev)   cyg_drv_mutex_init(&(kinetis_nfc_lock));
    cyg_drv_mutex_t kinetis_nfc_lock;
//static cyg_uint8 bufno_r = 0 ,bufno_w = 0 ;
static void
nfc_cfg_pins(nfc_priv_t * nfc_priv_p)
{
    const cyg_uint32 *pin_p;

    if((pin_p = nfc_priv_p->pins_p)) {
        for(;
            pin_p < nfc_priv_p->pins_p + nfc_priv_p->pins_n;
            CYGHWR_IO_FREESCALE_NFC_PIN(*pin_p++));
    }
}
static inline void
kinetis_nfc_set_field( cyg_nand_device *dev, CYG_ADDRWORD  reg_addr, cyg_uint32 mask, cyg_uint32 shift, cyg_uint32 val)
{
	cyg_uint32 reg_value;
	HAL_READ_UINT32( reg_addr, reg_value );
    HAL_WRITE_UINT32( reg_addr,( reg_value & (~mask)) | (val << shift)) ;
}

static inline cyg_uint32
kinetis_nfc_get_field( cyg_nand_device *dev,  CYG_ADDRWORD reg_addr, cyg_uint32 mask)
{
	cyg_uint32 reg_value =0 ;
    HAL_READ_UINT32( reg_addr, reg_value ) ;
    return (reg_value&mask) ;
}



static inline void kinetis_nfc_set_command( cyg_nand_device *dev, cyg_uint32 cmd_byte1,
		cyg_uint32 cmd_byte2, cyg_uint32 cmd_code)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t *nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	//set the command byte1
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg-> cmd[1], CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1_M, CYGHWR_HAL_KINETIS_NFC_CMD2_BYTE1_S, cmd_byte1 );
	//set the command byte2
	kinetis_nfc_set_field( dev,  (CYG_ADDRWORD)&nfc_reg-> cmd[0],CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2_M, CYGHWR_HAL_KINETIS_NFC_CMD1_BYTE2_S, cmd_byte2 );
	//set the cmd code 
	kinetis_nfc_set_field( dev,  (CYG_ADDRWORD)&nfc_reg-> cmd[1], CYGHWR_HAL_KINETIS_NFC_CMD2_CODE_M, CYGHWR_HAL_KINETIS_NFC_CMD2_CODE_S, cmd_code )	;
	
	//set buffer number  -----I think the buffer number should be set in somewhere in which set aiad and aibn
	
 //   write_addrbytes(dev, &addr[0], priv->row_addr_size);
}

static inline void write_addr_row(cyg_nand_device *dev, cyg_nand_page_addr row)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t *nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	kinetis_nfc_set_field( dev,  (CYG_ADDRWORD)&nfc_reg->rar, CYGHWR_HAL_KINETIS_NFC_RAR_M, CYGHWR_HAL_KINETIS_NFC_RAR_S, row ) ;	
}

static inline void write_addr_col_lp( cyg_nand_device *dev, cyg_nand_column_addr col)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t *nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;

	kinetis_nfc_set_field( dev,  (CYG_ADDRWORD)&nfc_reg-> car, CYGHWR_HAL_KINETIS_NFC_CAR_M , CYGHWR_HAL_KINETIS_NFC_CAR_S, col ) ;
}

static inline void write_addr_col_row_lp(cyg_nand_device *dev,
        cyg_nand_column_addr c, cyg_nand_page_addr r)
{
    write_addr_col_lp(dev, c);
    write_addr_row(dev, r);
}

/* Copy data from/to NFC main and spare buffers */
static void
kinetis_nfc_buf_copy(cyg_nand_device *dev , cyg_uint8 *buf, cyg_uint16 column , size_t len, cyg_uint8 wr ,cyg_uint8 bufno_)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
//	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;

	if (wr)
		memcpy( (cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(bufno_) + column), (void *)buf, len);
	else {
			memcpy(buf,(const void *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(bufno_) + column), len);
	}
}

#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
// Interrupt service routine
static cyg_uint32
kinetis_nfc_isr(cyg_vector_t vec, cyg_addrword_t data)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *) data;
    cyghwr_hal_kinetis_nfc_t *nfc_reg_p  = ( cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
    cyg_uint8            sr;
    cyg_uint32           result = CYG_ISR_HANDLED | CYG_ISR_CALL_DSR ;

    // Read current status
    sr = (cyg_uint8) nfc_reg_p->sr[1];

    // clear interrupt
    nfc_reg_p->isr |= CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M | CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M;

    HAL_INTERRUPT_ACKNOWLEDGE (nfc_priv_p -> nfc_isr_id);

    return result;
}

// Deferred interrupt service routine
static void
kinetis_nfc_dsr(cyg_vector_t vec, cyg_ucount32 count, cyg_addrword_t data)
{
    kinetis_nfc_priv_t *extra = (kinetis_nfc_priv_t *) data;
 
    NAND_CHATTER(8,dev, "NFC DSR -- finishing off\n");

    extra->nfc_completed = 1;
    cyg_drv_cond_signal(&(extra->nfc_wait));
}
#endif

// A command sequence has been started. Wait for completion
static inline void
kinetis_nfc_doit( cyg_nand_device *dev)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
    cyg_drv_mutex_lock(&(nfc_priv_p->nfc_lock));
    cyg_drv_dsr_lock();
#else    
    cyg_drv_mutex_lock(&(nfc_priv_p->nfc_lock)); 
#endif
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
//	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_S,1 );
//	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_S,1 );
	//Set start bit in code  and wait to finish
	kinetis_nfc_set_field( dev,(CYG_ADDRWORD) &nfc_reg-> cmd[1] , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_M , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_S ,1 );
	
    nfc_priv_p->nfc_completed = 0;
#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED	
    while (!nfc_priv_p->nfc_completed) {
        NFC_TRACE ("Waiting ...\n");
        
        cyg_drv_cond_wait(&(extra->nfc_wait));
    }
#else
	//if not use the interrupt ,polled the isr idle status
	cyg_uint16 wait_counter  = 0;
	while( !(nfc_reg->isr & CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_M))
	{
		NFC_WAIT_US(1) ;//wait for 1 us	
	    wait_counter++;
	    if(wait_counter >3000)
	    {
	    	NAND_ERROR(dev, "nfc:Do it Time out\n"); 
	    	break; 
	    }
	}
#endif	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
//	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_S,1 );
//	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_WERRCLR_S,1 );
#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
    cyg_drv_dsr_unlock();
    cyg_drv_mutex_unlock(&(nfc_priv_p->nfc_lock));
#else    
    cyg_drv_mutex_unlock(&(nfc_priv_p->nfc_lock));  
#endif

}

static inline CYG_BYTE kinetis_nfc_read_status(cyg_nand_device *dev)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	CYG_BYTE rv = 0;
	
		kinetis_nfc_set_command(dev, CYGHWR_HAL_NFC_READ_STATUS_CMD1_BYTE3 ,0 , CYGHWR_HAL_NFC_STATUS_READ_CMD_CODE) ;
		kinetis_nfc_doit(dev) ;
	rv = (CYG_BYTE)(nfc_reg->sr[1]) ;
	
	NAND_CHATTER(8,dev, "Read status \n") ;
	return rv;
}

/* Sends a reset command and waits for the RDY signal (or timeout) before
 * returning.
 * Timeout is tRST:
 *   5us during a Read or idle; 10us during Program; 500us during Erase.
 */
static void kinetis_nfc_reset(cyg_nand_device *dev)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint32 reg_value;
	
	NAND_CHATTER(8,dev, "reset  \n" ) ;

/*
		NAND_CHATTER(8,dev, "nfc_reg->isr   %x \n",nfc_reg->isr ) ;
		NAND_CHATTER(8,dev, "nfc_reg->rar %8x \n", nfc_reg->rar ) ;
		NAND_CHATTER(8,dev, "nfc_reg->cfg %8x \n", nfc_reg->cfg ) ;	
		NAND_CHATTER(8,dev, "nfc_reg->rpt %8x \n", nfc_reg->rpt ) ;			
		NAND_CHATTER(8,dev, "nfc_reg->cmd[1] %8x \n", nfc_reg->cmd[1] ) ;
		NAND_CHATTER(8,dev, "PTc5  D0 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[5]);				
		NAND_CHATTER(8,dev, "PTc6  D1 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[6]);
		NAND_CHATTER(8,dev, "PTc7  D2 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[7]);				
		NAND_CHATTER(8,dev, "PTc8  D3 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[8]);
		NAND_CHATTER(8,dev, "PTc9  D4 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[9]);				
		NAND_CHATTER(8,dev, "PTc10 D5 pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[10]);
		NAND_CHATTER(8,dev, "PTD4  D6 pcr %x\n",CYGHWR_HAL_KINETIS_PORTD_P->pcr[4]); 		
		NAND_CHATTER(8,dev, "PTD5  D7 pcr %x\n",CYGHWR_HAL_KINETIS_PORTD_P->pcr[5]); 			

		NAND_CHATTER(8,dev, "PTc16  rb pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[16]);
		NAND_CHATTER(8,dev, "PTc17  ce pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[17]);		
		NAND_CHATTER(8,dev, "PTD10  RE pcr %x\n",CYGHWR_HAL_KINETIS_PORTD_P->pcr[10]); 		
		NAND_CHATTER(8,dev, "PTc11 -we pcr %x\n",CYGHWR_HAL_KINETIS_PORTC_P->pcr[11]);	
		NAND_CHATTER(8,dev, "PTD8  CLE pcr %x\n",CYGHWR_HAL_KINETIS_PORTD_P->pcr[8]); 			
		NAND_CHATTER(8,dev, "PTD0  ALE pcr %x\n",CYGHWR_HAL_KINETIS_PORTD_P->pcr[9]); 						
			NAND_CHATTER(8,dev, "nfc_reg->isr %8x \n", nfc_reg->isr ) ;
*/	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
	
	kinetis_nfc_set_command(dev, CYGHWR_HAL_NFC_RESET_CMD2_BYTE1 ,0 ,CYGHWR_HAL_NFC_RESET_CMD_CODE ) ;
	//Set start bit	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cmd[1] , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_M , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_S ,1 );
	
	//wait for NFC_ISR idle done ,how long need to be wait?
	cyg_uint16 wait_counter  = 0;
	while( !(nfc_reg->isr & CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_M))
	{
		NFC_WAIT_US(1) ;//wait for 100 us	
	    wait_counter++;
	    if(wait_counter >5000)
	    {
	    	NAND_ERROR(dev, "nfc:Reset get IDLE Time out\n"); 
	    	break; 
	    }
	}
 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );	
    NAND_CHATTER(8,dev, "Resetting device\n");
}

static void kinetis_nfc_read_id(cyg_nand_device *dev,   cyg_uint32 *id )
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint32 reg_value;
	CYG_BYTE *sr_p ;
	cyg_uint32 reg_status1;
//	cyg_uint32 reg_status2;

	NAND_CHATTER(8,dev, "Nfc read_id \n") ;
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_IDCNT_M, CYGHWR_HAL_KINETIS_NFC_CFG_IDCNT_S,5 );	
 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_S,1 );
	
	kinetis_nfc_set_command(dev, CYGHWR_HAL_NFC_READ_ID_CMD2_BYTE1 ,0 ,CYGHWR_HAL_NFC_READ_ID_CMD_CODE ) ;
	kinetis_nfc_set_field( dev,(CYG_ADDRWORD) &nfc_reg-> cmd[1] , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_M , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_S ,1 );
	
	//wait for NFC_ISR idle done 
	NAND_CHATTER(8,dev, "wait for NFC_ISR idle done \n") ;
	cyg_uint16 wait_counter  = 0;
	while( !(nfc_reg->isr & CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_M & CYGHWR_HAL_KINETIS_NFC_ISR_DONE_M))
	{
		NFC_WAIT_US(1) ;//wait for 1 us	
	    wait_counter++;
	    if(wait_counter >5000)
	    {
	    	NAND_ERROR(dev, "nfc:Get IDLE Time out\n"); 
	    	break; 
	    }
	}
	
	//Read ID1 5 from NFC_SR1 and NFC_SR2
 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_DONECLR_S,1 );
	
     NAND_CHATTER(2,dev, "nfc_reg->sr[0] %x\n",nfc_reg->sr[0]);
	*id =  nfc_reg->sr[0]; 

	return ;
}

/* Entrypoints ================================================= */

int kinetis_nfc_devinit(cyg_nand_device *dev)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
    CYG_BYTE id[4] ,id_r[4];
    int rv = 0;
    NAND_CHATTER(5,dev, "nfc_devinit...  \n" );
    // We are protected by the master devinit lock, so we are safe
    // in the knowledge that there's only one of us running right now.
    // (We still need to take out the chip-lock, though, in case there's
    //  another thread trying to access another device which interferes
    //  with us.)

    // Bring clock to the sevice
    CYGHWR_IO_CLOCK_ENABLE(nfc_priv_p->clock);
    
   // rv = nfc_plf_init(dev); // sets up device locking as necessary
	nfc_cfg_pins(nfc_priv_p);	
	INITLOCK(dev);
    LOCK(dev); // 
#define ER(x) do { rv = (x); if (rv != ENOERR) goto err_exit; } while(0)
    kinetis_nfc_reset( dev ); //Reset the device

	//set the bit of aibn, aiad, bitwidth, fast, eccad, eccsram, dmareq, eccmode, pagecnt, 		
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S,CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_MODE  );											 
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S, KINETIS_NFC_ECC_BUF_ADDR );	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_M, CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_S, 0);										 								 
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_PAGECNT_S, CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT );									 
#if CYGNUM_DEVS_NAND_KINETIS_NFC_EDO_MODE
	//kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_FAST_M, CYGHWR_HAL_KINETIS_NFC_CFG_FAST_S, 1);
#else
	//kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_FAST_M, CYGHWR_HAL_KINETIS_NFC_CFG_FAST_S, 0);
#endif								 
#ifdef CYGNUM_DEVS_NAND_KINETIS_NFC_DATA_BUS_16
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_BITWIDTH_M, CYGHWR_HAL_KINETIS_NFC_CFG_BITWIDTH_S, 1);
#endif									 																			

    NAND_CHATTER(8,dev, "Start reading device ID...  \n" );
	kinetis_nfc_read_id( dev, (cyg_uint32 *) id_r ) ;
	
	id[0] = id_r[3] ;
	id[1] = id_r[2] ;
	id[2] = id_r[1] ;
	id[3] = id_r[0] ;
    NAND_CHATTER(2,dev, "Reading device ID... %x %x %x %x\n", id[0], id[1], id[2], id[3]);
    if ( ( id[0] != MANUFACTURER_CODE ) && ( id[0] != MANUFACTURER_CODE_1 ) &&  ( id[0] != MANUFACTURER_CODE_2 )) {
        NAND_CHATTER(1,dev, "Unrecognised manufacturer code %02x (expected MANUFACTURER_CODE  %02x)\n", id[0] ,MANUFACTURER_CODE);
        ER(-ENODEV);
    }

    // Now match against the table to find the chip.
    kinetis_nfc_subtype *matchlist = nfc_priv_p->supported_chips;
//    kinetis_nfc_subtype *matchlist_devs = NULL;
    dev->blockcount_bits = 0;

    while (matchlist && matchlist->descriptor ) 
    {
        if (id[1] == matchlist->ident1) 
        {
          //  if (id[3] == matchlist->ident3) 
            {
                NAND_CHATTER(8,dev, "Chip descriptor %s: %u blocks, total 2^%u bytes, 8-bit data bus\n",
                        matchlist->descriptor,
                        1<<matchlist->blockcount_bits,
                        matchlist->chipsize_log);

                dev->blockcount_bits = matchlist->blockcount_bits  ;
                dev->chipsize_log = matchlist->chipsize_log;
                nfc_priv_p->row_addr_size = matchlist->row_address_size;
#ifdef CYGSEM_IO_NAND_USE_BBT
                dev->bbt.data = nfc_priv_p->bbt_data;
                dev->bbt.datasize = sizeof(nfc_priv_p->bbt_data);
                NAND_CHATTER(6,dev, "  %x bbt.data , total %d bytes bbt.datasize\n",
                        dev->bbt.data,
                        dev->bbt.datasize);
                // Sanity check: Four blocks take up one byte of RAM in-memory,
                // so subtract two from the log of the blockcount to get the
                // necessary BBT size.
                if (dev->bbt.datasize < (1<<(dev->blockcount_bits-2))) 
                {
                    NAND_ERROR(dev, "In-RAM BBT is not large enough (have %u, need %u)\n", dev->bbt.datasize, 1<<(dev->blockcount_bits-2));
                    ER(-ENODEV);
                }
#endif
                break;
            }
        }
        matchlist++;
    }

    if (!dev->blockcount_bits) {
        NAND_ERROR(dev, "kinetis nfc: no chip driver found for chip with ident %02x %02x %02x %02x\n", id[0], id[1], id[2], id[3]);
        ER(-ENODEV);
    }

    if (matchlist->sp) {
        //dev->page_bits = 9;
    } else {
        dev->page_bits = matchlist->page_bits  ;//(id[3] & 3) + 10; // 00 -> 1kbyte; 01 -> 2k.  //Todo
    }
    int bytes_per_page = 1 << (dev->page_bits);
    CYG_ASSERT(bytes_per_page <= CYGNUM_NAND_PAGEBUFFER, "max pagebuffer not big enough");
    NAND_CHATTER(6,dev, "Page size: %u bytes (2^%u)\n", bytes_per_page, dev->page_bits);

    if (matchlist->sp) {
        //dev->spare_per_page = ;
    } else {
        int spp = matchlist->spare_per_page ;//(id[3] >> 2) & 3;
  //      CYG_ASSERT(spp == 1, "unhandled spare area size marker");
        dev->spare_per_page = matchlist->spare_per_page;
        (void) spp;
    }
    NAND_CHATTER(6,dev, "Spare per page: %u bytes\n", dev->spare_per_page);

    dev->block_page_bits = matchlist->block_page_bits ;//log2_blocksize - dev->page_bits;
    NAND_CHATTER(6,dev, "Pages per block: %u (2^%u)\n", 1<<dev->block_page_bits, dev->block_page_bits);

    if (dev->chipsize_log !=
            (dev->page_bits + dev->block_page_bits + dev->blockcount_bits) ) {
        NAND_ERROR(dev, "NAND device error: Coded chip size (2^%u bytes) does not match computed (2^%u by/pg, 2^%u pg/bl,\
         2^%u bl/chip)\n", dev->chipsize_log, dev->page_bits, dev->block_page_bits, dev->blockcount_bits);
        ER(-ENODEV);
    }

    // Could read the serial-access timing as well and configure a delay loop?

    ER(kinetis_nfc_plf_partition_setup(dev));
     	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
    NAND_CHATTER(8,dev, "CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE: %d  \n", CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE);  
    NAND_CHATTER(8,dev, "VIRTUAL_PAGE_SPARE_SIZE: %d\n", VIRTUAL_PAGE_SPARE_SIZE);
#ifdef CYGINT_IO_NFC_INT_SUPPORT_REQUIRED
    cyg_drv_mutex_init(&nfc_priv_p->nfc_lock);
    cyg_drv_cond_init(&nfc_priv_p->nfc_wait, &&nfc_priv_p->nfc_lock);
    cyg_drv_interrupt_create(nfc_priv_p->nfc_isr_id,
                             nfc_priv_p->nfc_isr_pri,
                             (cyg_addrword_t)nfc_priv_p,
                             &kinetis_nfc_isr,
                             &kinetis_nfc_dsr,
                             &(nfc_priv_p->nfc_interrupt_handle),
                             &(nfc_priv_p->nfc_interrupt_data));
    cyg_drv_interrupt_attach(nfc_priv_p->nfc_interrupt_handle);
    
    // Interrupts can now be safely unmasked
    HAL_INTERRUPT_UNMASK(nfc_priv_p->nfc_isr_id);
#endif
err_exit:
    UNLOCK(dev); // ------------------------------------------------
    return rv;
}
#undef ER

int kinetis_nfc_erase_block(cyg_nand_device *dev, cyg_nand_block_addr blk)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
   	cyg_nand_page_addr page  = ( cyg_nand_page_addr) blk << (dev->block_page_bits);
    int rv = 0;
    NAND_CHATTER(5,dev, "erase_block\n" );
    LOCK(dev);	
	
    nfc_priv_p->pagestash = page ;
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S,CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_MODE  );	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S, KINETIS_NFC_ECC_BUF_ADDR );									 
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_M, CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_S, 0);

//#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S, 0 );
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S, 0 );		
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rpt, CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_M, \
											CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S, 0 );
//#endif

	//clear the value of rai
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rai, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_M, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_S, 0 );	
							

    write_addr_col_row_lp(dev, 0, page);
	kinetis_nfc_set_command(dev, CYGHWR_HAL_NFC_ERASE_CMD2_BYTE1, CYGHWR_HAL_NFC_ERASE_CMD1_BYTE2, CYGHWR_HAL_NFC_ERASE_CMD_CODE ) ;
 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );

	kinetis_nfc_set_field( dev,(CYG_ADDRWORD) &nfc_reg-> cmd[1] , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_M , CYGHWR_HAL_KINETIS_NFC_CMD2_BUSY_START_S ,1 );
	
	//set the number of sram buffer

	//wait for NFC_ISR idle done ,how long need to be wait?
	cyg_uint16 wait_counter  = 0;
	while( !(nfc_reg->isr & CYGHWR_HAL_KINETIS_NFC_ISR_IDLE_M))
	{
		NFC_WAIT_US(1) ;//wait for 100 us	
	    wait_counter++;
	    if(wait_counter > 3000)
	    {
	    	NAND_ERROR(dev, "nfc:Reset get IDLE Time out\n"); 
	    	break; 
	    }
	}
// 	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->isr, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_M, CYGHWR_HAL_KINETIS_NFC_ISR_IDLECLR_S,1 );
    unsigned stat = kinetis_nfc_read_status(dev);  
    if (stat & 1) {
        rv = -EIO;
        NAND_ERROR(dev, "nfc: Erasing block %u failed.\n",blk);
        goto done;
    }
    
    NAND_CHATTER(7,dev, "Erased block %u OK\n", blk);
done:
    UNLOCK(dev);
    return rv;
}

int kinetis_nfc_read_begin(cyg_nand_device *dev, cyg_nand_page_addr read_page)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	
	cyg_nand_page_addr page = 0;
	cyg_uint32 reg_value = 0;
	    LOCK(dev);
	page = read_page  ;
	
	NAND_CHATTER(7,dev,"nfc_read\n");

    nfc_priv_p->pagestash = page ;
	NAND_CHATTER(6,dev,"R begin in read page %x\n",read_page);
 //   NAND_CHATTER(7,dev,"R begin in page %x\n",page);
    
    
	//set the number of sram buffer
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cmd[1], CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_M, CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_S,  0 );
    write_addr_col_row_lp(dev, 0, page);
	//set the valuse of sector size for 
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->secsz, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_M, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_S, \
							VIRTUAL_PAGE_MAIN_SIZE +VIRTUAL_PAGE_SPARE_SIZE );
							
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S,CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_MODE  );	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S, KINETIS_NFC_ECC_BUF_ADDR );									 
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_M, CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_S, 1);								
	//clear the value of rai
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rai, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_M, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_S, 0 );										
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rpt, CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_M, \
											CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S, CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT  );

#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1 )
//fs  NAND_CHATTER(7,dev,"CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE >2048\n");
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S, 1 );
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S, 1 );	
#else
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S, 0 );
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S, 0 );
#endif
						
#ifndef CYGFUN_NAND_KINETIS_NFC_LP
	kinetis_nfc_set_command( dev, CYGHWR_HAL_NFC_PAGE_READ_CMD2_BYTE1 , CYGHWR_HAL_NFC_PAGE_READ_CMD1_BYTE2 , CYGHWR_HAL_NFC_SP_READ_PAGE_CMD_CODE ) ;
#else
	kinetis_nfc_set_command(dev,  CYGHWR_HAL_NFC_PAGE_READ_CMD2_BYTE1 , CYGHWR_HAL_NFC_PAGE_READ_CMD1_BYTE2 , CYGHWR_HAL_NFC_LP_READ_PAGE_CMD_CODE ) ;
#endif

#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT >1)
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_S, KINETIS_NFC_SWAP_ADDR1);
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_S, KINETIS_NFC_SWAP_ADDR2);
#endif																


//#if DEBUG
			NAND_CHATTER(8,dev, "R reg->isr   %x \n",nfc_reg->isr ) ;
		NAND_CHATTER(8,dev, "R reg->rar %8x \n", nfc_reg->rar ) ;
				NAND_CHATTER(8,dev, "R reg->car %8x \n", nfc_reg->car ) ;
	NAND_CHATTER(8,dev, "R reg->swap %8x \n", nfc_reg->swap ) ;
		NAND_CHATTER(8,dev, "R reg->rpt %8x \n", nfc_reg->rpt ) ;	
				//NAND_CHATTER(8,dev, "CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT %8x \n", CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT ) ;	
				NAND_CHATTER(8,dev, "R reg->secsz %8x \n", nfc_reg->secsz ) ;	
				NAND_CHATTER(8,dev, "R reg->cfg %8x \n", nfc_reg->cfg) ;
//#endif
								
								
    //wait the signal from isr until the command is idle 
        cyg_uint32 ecc_status =0;
    HAL_WRITE_UINT32((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status   );
    HAL_WRITE_UINT32((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(1) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status   );
 //   ecc_status =*((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(bufno_r) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET )) ;
 //   NAND_CHATTER(6,dev,"R begin ecc_status %x\n" ,(cyg_uint8) ecc_status );
    
    kinetis_nfc_doit( dev ) ;
        
    return 0;
}


int kinetis_nfc_read_stride(cyg_nand_device *dev, void * dest, size_t size)
{
   // nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	//cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint8 *buf = (cyg_uint8 *)dest ;
	//read the main area of data
	if( size <= CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE )
	{

#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
		cyg_uint8 i=0 ;
		for( i=0 ;i<CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT;i++)
		{
    		kinetis_nfc_buf_copy( dev , buf + i*(size>>1), 0 , size/2, 0 , i) ;
			NAND_CHATTER(7,dev,"Read stride size %d  buf %d\n", size/2, i);    		
    	}
#else
    	kinetis_nfc_buf_copy( dev , buf, 0 , size, 0 , 0) ;
    			NAND_CHATTER(7,dev,"Read  stride size %d  buf %d\n", size, 0);
#endif
    	return 0;
    }
    else
    {
    	NAND_ERROR(dev, "size >VIRTUAL_PAGE_MAIN_SIZE\n" );
    	return EINVAL ;
    }
}

int kinetis_nfc_read_finish(cyg_nand_device *dev, void * spare, size_t spare_size)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	//cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint8 *buf = (cyg_uint8 *)spare ;
	size_t size =  spare_size/CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT ;
	int rv = 0;
//	NAND_CHATTER(7,dev,"read_finish spare_size, %d  buf %d\n", spare_size, bufno_r);
	
	if(	spare_size <= CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_SPARE_SIZE )
	{
	    if (spare && spare_size) {
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
		cyg_uint8 i=0 ;
		for( i=0 ;i<CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT;i++)
			kinetis_nfc_buf_copy( dev , buf + i*size, VIRTUAL_PAGE_MAIN_SIZE, size, 0 , i);
#else

	    	kinetis_nfc_buf_copy( dev , buf,  1 << dev->page_bits, spare_size, 0 , 0);
#endif	    	
	    }
	}
	else
	{
	    NAND_ERROR(dev, "nfc: Real spare size is %u smaller than want be %u\n", VIRTUAL_PAGE_SPARE_SIZE, spare_size);
		rv = EINVAL ;
	}	
    UNLOCK(dev);
    return rv;
}

int kinetis_nfc_read_finish_check(cyg_nand_device *dev, void * spare, size_t spare_size)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint8 *buf = (cyg_uint8 *)spare ;
	size_t size = spare_size/CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT ;
	cyg_uint8 ecc_status[CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT] = { 0 };
    int rv = 0;

    if(	spare_size <= CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_SPARE_SIZE )
	{
	    if (spare && spare_size) {
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
		cyg_uint8 i=0 ;
		for( i=0 ;i<CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT;i++)
		{
			kinetis_nfc_buf_copy( dev , buf + i*size,  VIRTUAL_PAGE_MAIN_SIZE, size, 0 , i);
	    	ecc_status[i] = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(i) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET));		
	    	    	NAND_CHATTER(7,dev,"read_check spare_size, %d  buf %d\n",size, i);
		}
#else
    	NAND_CHATTER(7,dev,"read_check spare_size, %d  buf %d\n", spare_size, 0);
    	kinetis_nfc_buf_copy( dev , buf,  1 << dev->page_bits, spare_size, 0 , 0);
    	ecc_status[0] = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET));
#endif
	    }
	}
	else
	{
		NAND_ERROR(dev, "nfc: Real spare size is %u smaller than want be %u", VIRTUAL_PAGE_SPARE_SIZE, spare_size);
		rv = EINVAL ;
	}

    if (kinetis_nfc_read_status(dev)& 1) {
  // if (ecc_status[0] & ecc_status[1]&KINETIS_NFC_ECC_STATUS_MASK ){
        NAND_ERROR(dev, "nfc: Read failed ECC check! Page %u \n", nfc_priv_p->pagestash);
       rv =-EIO;
    }
    UNLOCK(dev);
    return rv;
}

/**Do not support in this driver
***int kinetis_nfc_read_part(cyg_nand_device *dev, void *dest,
***                        cyg_nand_page_addr page, size_t offset, size_t length)
***{
***}
***/

int kinetis_nfc_write_begin(cyg_nand_device *dev, cyg_nand_page_addr write_page)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
//	cyg_nand_page_addr page = write_page;
	cyg_uint32 reg_value = 0;

	LOCK(dev);
   
	//If the last bit is one ,the virtual page is high half of actual page ,means buffer 0,else is low
 
	NAND_CHATTER(6,dev,"WR begin in write page %x\n",write_page);
   // NAND_CHATTER(7,dev,"WR begin in page %x\n",page);
    	    
    nfc_priv_p->pagestash = write_page ;
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT >1)
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_S, KINETIS_NFC_SWAP_ADDR1);
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_S, KINETIS_NFC_SWAP_ADDR2);
#endif	

    write_addr_col_row_lp(dev, 0, write_page);		
    
    return 0 ;

}

int kinetis_nfc_write_stride(cyg_nand_device *dev, const void * src, size_t size)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint8 *buf = (cyg_uint8 *)src ;
    	NAND_CHATTER(7,dev,"WR stride  \n");
	//write the main area of data
	if( size <= CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE )
	{
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
		cyg_uint8 i=0 ;
		for( i=0 ;i<CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT;i++)
		{
    		kinetis_nfc_buf_copy( dev , buf + i*VIRTUAL_PAGE_MAIN_SIZE, 0 , VIRTUAL_PAGE_MAIN_SIZE, 1 , i) ;
    				NAND_CHATTER(7,dev,"WR stride size %d  buf %d\n", VIRTUAL_PAGE_MAIN_SIZE, i);
    	}
#else
    	kinetis_nfc_buf_copy( dev , buf, 0 , size, 1 , 0) ;
    	NAND_CHATTER(7,dev,"WR stride size %d  buf %d\n", size, 0);
#endif
    	return 0;
    }
    else
    {
            NAND_ERROR(dev, "WR size %d > VIRTUAL_PAGE_MAIN_SIZE %d!  ", size  , VIRTUAL_PAGE_MAIN_SIZE);
    	return EINVAL ;
    }
}

int kinetis_nfc_write_finish(cyg_nand_device *dev, const void * spare, size_t spare_size)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_uint8 *buf = (cyg_uint8 *)spare ;
		size_t size = spare_size/CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT ;
    int rv = 0;
    cyg_uint8 wait_counter = 0 ;

	//read the main area of data

    
    if(	size <= CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_SPARE_SIZE )
	{
	    if (spare && size) {
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
 cyg_uint32 ecc_status =0;
		cyg_uint8 i=0 ;
		for( i=0 ;i<CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT;i++)
		{
			HAL_WRITE_UINT32((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(i) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status   );
			kinetis_nfc_buf_copy( dev , buf + i*size,  VIRTUAL_PAGE_MAIN_SIZE, size, 1 , i);
	    	//ecc_status[i] = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(i) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET));	
	    		      

	    			    NAND_CHATTER(7,dev,"WR spare %d in buf %d of addr %d\n",size ,i, VIRTUAL_PAGE_MAIN_SIZE );	
		}
#else
	    	kinetis_nfc_buf_copy( dev , buf,  1 << dev->page_bits, size, 1 , 0);
	    	//ecc_status = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET));
	    			    NAND_CHATTER(7,dev,"WR spare %d in buf %d of addr %d\n",size ,0,1 << dev->page_bits);
#endif
	    }
	}
	else
	{	    
	    	NAND_ERROR(dev,"WR size %d VIRTUAL_PAGE_SPARE_SIZE %d \n",size ,VIRTUAL_PAGE_SPARE_SIZE);
	    	return EINVAL ;
	    
    }						

	kinetis_nfc_set_command(dev, CYGHWR_HAL_NFC_PROGRAM_PAGE_CMD2_BYTE1, CYGHWR_HAL_NFC_PROGRAM_PAGE_CMD1_BYTE2, CYGHWR_HAL_NFC_PROGRAM_PAGE_CMD_CODE ) ;


	//set the number of sram buffer
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cmd[1], CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_M, CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_S,  0 );
	//clear the value of rai
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rai, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_M, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_S, 0 );	
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)	
		kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S, 1 );	
		kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S, 1 );
		kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rpt, CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_M, \
											CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S, CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT  );
#endif		
	//set the valuse of sector size for 

	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->secsz, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_M, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_S, \
							VIRTUAL_PAGE_MAIN_SIZE +VIRTUAL_PAGE_SPARE_SIZE );	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCMODE_S,CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_MODE  );	
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_M,\
									 CYGHWR_HAL_KINETIS_NFC_CFG_ECCAD_S, KINETIS_NFC_ECC_BUF_ADDR );									 
	kinetis_nfc_set_field( dev, (CYG_ADDRWORD)&nfc_reg->cfg , CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_M, CYGHWR_HAL_KINETIS_NFC_CFG_ECCSRAM_S,1);	

	
#if DEBUG
			NAND_CHATTER(8,dev, "W  reg->isr   %x \n",nfc_reg->isr ) ;
		NAND_CHATTER(8,dev, "W  reg->rar %8x \n", nfc_reg->rar ) ;
				NAND_CHATTER(8,dev, "nfc_reg->car %8x \n", nfc_reg->car ) ;
	NAND_CHATTER(8,dev, "W reg->swap %8x \n", nfc_reg->swap ) ;
		NAND_CHATTER(8,dev, "W reg->rpt %8x \n", nfc_reg->rpt ) ;	
				//NAND_CHATTER(8,dev, "CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT %8x \n", CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT ) ;	
				NAND_CHATTER(8,dev, "W reg->secsz %8x \n", nfc_reg->secsz ) ;	
				NAND_CHATTER(8,dev, "W reg->cfg %8x \n", nfc_reg->cfg) ;
#endif
			
	
	
    //wait the signal from isr until the command is idle 
    kinetis_nfc_doit( dev ) ;
    if (kinetis_nfc_read_status(dev) & 0x1) {
        NAND_ERROR(dev, "nfc: Programming failed! Page %u", nfc_priv_p->pagestash);
        rv =-EIO;
        goto done;
    } else {	
        NAND_CHATTER(8,dev, "Programmed %u OK\n", nfc_priv_p->pagestash);
;
    }
done:
    UNLOCK(dev);
  		NAND_CHATTER(8,dev, "WR page finish %8x \n",nfc_priv_p->pagestash ) ;	
//    kinetis_nfc_reset( dev);
    return rv;
}


// The spec sheet says to check the 1st OOB byte (address 2048) in
// both the 1st and 2nd page of the block. If both are 0xFF, the block is OK;
// else it's bad.
int kinetis_nfc_factorybad_lp(cyg_nand_device *dev, cyg_nand_block_addr blk)
{
    nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	
    cyg_nand_page_addr page = blk * (1<<dev->block_page_bits );
    const int col = CYGNUM_DEVS_NAND_KINETIS_NFC_FACTORY_BAD_COLUMN_ADDR;
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT >1)
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR1_S, KINETIS_NFC_SWAP_ADDR1);
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->swap, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_M, CYGHWR_HAL_KINETIS_NFC_SWAP_ADDR2_S, KINETIS_NFC_SWAP_ADDR2);
#endif																
    
	cyg_uint32 reg_value = 0;
	cyg_uint8 wait_counter = 0 ;
	
	
	//If the last bit is one ,the virtual page is high half of actual page ,means buffer 0,else is low
//	bufno = 0 ;
	//if the page is same with last time ,the data should be in sram buffer
	//if(last_page == page ) return 0 ;
	//last_page = page ;
    nfc_priv_p->pagestash = page ;

    LOCK(dev);

	//kinetis_nfc_set_field( cyg_nand_device *dev,  cyg_uint32  reg, cyg_uint32 mask, cyg_uint32 shift, cyg_uint32 val) ;
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIBN_S, 1 );
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cfg, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_M, CYGHWR_HAL_KINETIS_NFC_CFG_AIAD_S, 1 );	
#endif

	//clear the value of rai
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rai, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_M, CYGHWR_HAL_KINETIS_NFC_RAI_INCREMENT_S, 0 );	
#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1 )										
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->rpt, CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_M, \
											CYGHWR_HAL_KINETIS_NFC_RPT_COUNT_S, CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT  );
#endif	
	//set the valuse of sector size for 
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->secsz, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_M, CYGHWR_HAL_KINETIS_NFC_SECSZ_SIZE_S, \
							VIRTUAL_PAGE_MAIN_SIZE +VIRTUAL_PAGE_SPARE_SIZE );	
#ifdef CYGFUN_NAND_KINETIS_NFC_SP
	kinetis_nfc_set_command( dev, CYGHWR_HAL_NFC_PAGE_READ_CMD2_BYTE1 , CYGHWR_HAL_NFC_PAGE_READ_CMD1_BYTE2 , CYGHWR_HAL_NFC_SP_READ_PAGE_CMD_CODE ) ;
#else
	kinetis_nfc_set_command(dev,  CYGHWR_HAL_NFC_PAGE_READ_CMD2_BYTE1 , CYGHWR_HAL_NFC_PAGE_READ_CMD1_BYTE2 , CYGHWR_HAL_NFC_LP_READ_PAGE_CMD_CODE ) ;
#endif
	//set the number of sram buffer
	kinetis_nfc_set_field(dev, (CYG_ADDRWORD)&nfc_reg->cmd[1], CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_M, CYGHWR_HAL_KINETIS_NFC_CMD2_BUFNO_S,  0 );
	

	int rv = 0, i;
     cyg_uint8 bad_mark[2] = {0};
    write_addr_col_row_lp(dev, 0, page);
    //Start command and wait the signal from isr until the command is idle 
    kinetis_nfc_doit( dev ) ;

	kinetis_nfc_buf_copy( dev ,  &bad_mark[0], col , 1, 0 , CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT-1);
	
    write_addr_col_row_lp(dev, 0, page+1);
    //Start command and wait the signal from isr until the command is idle 
    kinetis_nfc_doit( dev ) ;

	kinetis_nfc_buf_copy( dev ,  &bad_mark[1], col , 1, 0 , CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT-1);	
	
	
	// NAND_CHATTER(8,dev,"swap  %x  \n",nfc_reg->swap );
	// NAND_CHATTER(8,dev,"blk %d  bad_mark %x  %x bufno %d in col %d \n", blk,bad_mark[0],bad_mark[1],CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT-1 , col );
    if((bad_mark[0] != 0xff )|| (bad_mark[1] != 0xff ))
    {
    	NAND_ERROR(dev, "blk %d  bad_mark %x  %x  \n", blk,bad_mark[0],bad_mark[1]);
    	 rv=1;
     }

    UNLOCK(dev);
    return rv;
}



//#define CYGNUM_DEVS_NAND_KINETIS_NFC_FACTORY_BAD_COLUMN_ADDR 2048

/* Hardware ECC ======================================================== */
// TODO This could live in the variant HAL?

static void core_k70f150m_ecc_init(cyg_nand_device *dev)
{
 ;
}

static void core_k70f150m_ecc_calc(cyg_nand_device *dev, const CYG_BYTE *dat, CYG_BYTE *ecc)
{
//	cyg_uint8 *buf = (cyg_uint8 *)ecc ;
 //   int rv = 0;
    
  //  if(	dat != NULL )
//	{
 //   	kinetis_nfc_buf_copy( dev , buf,  1 << dev->page_bits +VIRTUAL_PAGE_SPARE_SIZE - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE, CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE, 0 , bufno);

//	}

	NAND_CHATTER(6,dev, "core_k70f150m_ecc_calc\n");
}

static int core_k70f150m_ecc_repair(cyg_nand_device *dev,
                            CYG_BYTE *dat, size_t nbytes,
                            CYG_BYTE *read_ecc, const CYG_BYTE *calc_ecc)
{
	nfc_priv_t *nfc_priv_p = (nfc_priv_t *)dev->priv;
	cyghwr_hal_kinetis_nfc_t * nfc_reg = (cyghwr_hal_kinetis_nfc_t *)nfc_priv_p->nfc_reg;
	cyg_nand_oob_layout *oob = dev->oob;


#if (CYGNUM_DEVS_NAND_KINETIS_NFC_VIRTUAL_PAGE_CNT > 1)
	cyg_uint8 ecc_status[2];
	cyg_uint8 ecc_count[2];
    HAL_READ_UINT8((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status[0]   );
    HAL_READ_UINT8((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(1) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status[1]   );
   // ecc_status = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET )) ;
   // ecc_status = *((cyg_uint32 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET )) ;
    ecc_count[1] = ecc_status[1] & KINETIS_NFC_ECC_ERR_COUNT;
           NAND_CHATTER(6,dev," repaire ecc status %x bufno %d\n",(cyg_uint8 )ecc_status[0] , 0); 
           NAND_CHATTER(6,dev," repaire ecc status %x bufno %d\n",(cyg_uint8 )ecc_status[1] , 1); 
                              /* ECC failed. */
        if ( ecc_status[1] & KINETIS_NFC_ECC_STATUS_MASK ) 
        {
               NAND_ERROR(dev, "ecc_status[1] %x\n",ecc_status[1]);   
               return -1;
        }
        if ( ecc_status[1] & KINETIS_NFC_ECC_ERR_COUNT )
        {
                return 1;
                
		}
		        memset(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(1)+VIRTUAL_PAGE_MAIN_SIZE+ oob->ecc[0].pos, 0xff, oob->ecc[0].len);
#else	
	cyg_uint8 ecc_status;
	cyg_uint8 ecc_count;
    HAL_READ_UINT8((nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET ), ecc_status   );
   // ecc_status = *((cyg_uint8 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET )) ;
   // ecc_status = *((cyg_uint32 *)(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0) + KINETIS_NFC_ECC_BUF_ADDR*8 + KINETIS_NFC_ECC_OFFSET )) ;
    ecc_count = ecc_status & KINETIS_NFC_ECC_ERR_COUNT;
           NAND_CHATTER(6,dev," repaire ecc status %x bufno %d\n",(cyg_uint8 )ecc_status , 0); 
                              /* ECC failed. */
        if ( ecc_status & KINETIS_NFC_ECC_STATUS_MASK ) 
        {
               NAND_ERROR(dev, "ecc_status %x\n",ecc_status);   
               return -1;
        }
        if ( ecc_status & KINETIS_NFC_ECC_ERR_COUNT )
        {
                return 1;
                
		}
#endif	           


        memset(nfc_priv_p->nfc_base + KINETIS_NFC_BUFFER_AREA(0)+VIRTUAL_PAGE_MAIN_SIZE+ oob->ecc[0].pos, 0xff, oob->ecc[0].len);
    return 0;
}

static CYG_NAND_ECC_ALG_HW(core_k70f150m_ecc, CYGNUM_DEVS_NAND_KINETIS_NFC_PAGE_MAIN_SIZE, CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE, core_k70f150m_ecc_init, core_k70f150m_ecc_calc, core_k70f150m_ecc_repair);
//CYG_NAND_ECC_ALG_SW(mtd_ecc256_fast, 1, 3, 0, ecc256_fast, ecc256_repair);
// Need to use a slightly modified OOB layout to satisfy nand_lookup's paranoia checks
//TODO  need to resigned the position of ecc and app_size
static const cyg_nand_oob_layout core_k70f150m_oob = {
    .ecc_size = CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE ,
    .ecc = { { .pos=VIRTUAL_PAGE_SPARE_SIZE - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE   , .len= CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE} 
   // 	   , { .pos=VIRTUAL_PAGE_SPARE_SIZE*2 - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE , .len= CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE} 
    	   },
    /* 3, 6, 7 would be ECC in the Linux MTD world. 4/5 are avoided. */
//    .app_size = 8,
    .app_size =( VIRTUAL_PAGE_SPARE_SIZE - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE -2),
    .app = { { .pos=2, .len=VIRTUAL_PAGE_SPARE_SIZE - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE - 3 }  
//		    ,{ .pos=VIRTUAL_PAGE_SPARE_SIZE+2, .len=VIRTUAL_PAGE_SPARE_SIZE - CYGNUM_DEVS_NAND_KINETIS_NFC_ECC_SIZE - 2 } 
 		},
};




CYG_NAND_FUNS_V2(kinetis_nfc_funs, kinetis_nfc_devinit,
        kinetis_nfc_read_begin, kinetis_nfc_read_stride, kinetis_nfc_read_finish,
        NULL,
        kinetis_nfc_write_begin, kinetis_nfc_write_stride, kinetis_nfc_write_finish,
        kinetis_nfc_erase_block, kinetis_nfc_factorybad_lp);

/* Some newer chips have on-board ECC that requires you to perform
 * a READ_STATUS after reading out a page. */
CYG_NAND_FUNS_V2(kinetis_nfc_funs_with_ecc, kinetis_nfc_devinit,
        kinetis_nfc_read_begin, kinetis_nfc_read_stride, kinetis_nfc_read_finish_check,
        NULL,
        kinetis_nfc_write_begin, kinetis_nfc_write_stride, kinetis_nfc_write_finish,
        kinetis_nfc_erase_block, kinetis_nfc_factorybad_lp);

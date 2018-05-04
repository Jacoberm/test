#ifndef CYGONCE_DEVS_AUDIO_SPI_VS1063A_H_
#define CYGONCE_DEVS_AUDIO_SPI_VS1063A_H_

//=============================================================================
//
//      vs1063a_audio.h
//
//      SPI audio driver for Silicon Storage Technology VS1063A devices
//      and compatibles.
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2008, 2009, 2011 Free Software Foundation, Inc.
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
// Author(s):   ccoutand, updated for Silicon Storage Technology VS1063A
//              audio
// Original(s): Chris Holgate
// Purpose:     VSLI VS1063A SPI audio driver
//              implementation
//
//####DESCRIPTIONEND####
//
//=============================================================================

// Required data structures.
#include <cyg/io/audio/audio_dev.h>
#include <pkgconf/devs_snd_vs1063a.h>
#include <cyg/io/audio/vs1063a_snd.h>
// Exported handle on the driver function table.



#define VS1063A_SND_INTERRUPT_LEVEL_HIGH    (true)
#define VS1063A_SND_INTERRUPT_LEVEL_LOW     (false)
#define VS1063A_SND_INTERRUPT_EDGE_RISING   (true)
#define VS1063A_SND_INTERRUPT_EDGE_FALLING  (false)



struct AUDIOPTR {
	void *wr;       /* 0: write pointer */
	void *rd;       /* 1: read pointer */
	cyg_uint32 forwardModulo; /* 2: 0x8000 + size - 1 */
	cyg_uint16 leftVol;       /* 3: left volume,  default     -32768 =  1.0 */
	cyg_uint16 rightVol;      /* 4: right volume, differential 32767 = -1.0 */
	cyg_uint16 underflow;     /* 5: increased if underflow in dac interrupt */
	/* New fields we need: */
	cyg_uint32 changeTimer;   /*6: */
	cyg_uint32 newFctl;       /*7,8: */
	cyg_uint32 curFctl;       /*9,10: */
	cyg_uint16 newDacVol;     /*11*/
	cyg_uint32 oldRateTune;   /*12,13: */
	cyg_uint32  timeToRemovePDown; /*14: */
};

struct AGC {
	cyg_uint16 gain;
	cyg_uint32 lpRes;
	cyg_uint32 offset;
};

extern struct AdcControl {
	struct AGC agc[2];
	  cyg_uint16 adcMode;
	  cyg_uint16 encMode;
} adcControl;


//=============================================================================

//-----------------------------------------------------------------------------
#endif // CYGONCE_DEVS_AUDIO_SPI_VS1063A_H
// EOF vs1063a.h

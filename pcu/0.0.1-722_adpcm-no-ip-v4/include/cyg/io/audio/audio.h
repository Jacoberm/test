//==========================================================================
//
//      audio.h
//
//      Flash programming - external interfaces
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2009 Free Software Foundation, Inc.
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
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    benty king
//
// Date:         2012-10-17
// Purpose:      
// Description:  
//              
//####DESCRIPTIONEND####
//
//==========================================================================

#ifndef _IO_AUDIO_H_
#define _IO_AUDIO_H_

#include <pkgconf/system.h>
#include <pkgconf/io_audio.h>
#include <stddef.h>
#include <cyg/infra/cyg_type.h>
//#include <cyg/io/audio/audio_dev.h>
#ifdef CYGPKG_KERNEL
#include <cyg/kernel/kapi.h>
#endif

// Currently a 32-bit quantity. In future this may be 64-bits on some
// platforms, e.g. to support very large nand audioes which can only
// be accessed indirectly.
typedef CYG_ADDRESS cyg_audioaddr_t;

#define AUDIO_BUFFER_SIZE  1024

typedef struct cyg_audio_file_info
{
  cyg_uint32            rate;
  cyg_uint32            file_formats;
  cyg_uint32            buffer_len;
  cyg_uint8			  buf[AUDIO_BUFFER_SIZE ];
} cyg_audio_info;

// Information about what one device driver drives
typedef struct {             //
	cyg_uint32				playback_file_formats;                // Audio file format
	cyg_uint32				capture_file_formats;				// Audio file format
	cyg_uint32				playback_volume;                // Playback audio volume
	cyg_uint32				capture_volume;                // Capture audio volume
	cyg_uint32				playback_mode;                				// APCM,OGG,MP3,MP2 and so on
	cyg_uint32				capture_mode;                				// APCM,OGG,MP3,MP2 and so on
	cyg_uint32				codec_mode;
	cyg_uint32				mode;
	cyg_uint32				rates;   								// Rate of audio stream
	cyg_uint32				rate_min ;
	cyg_uint32				rate_max ;
	cyg_uint32				mono_stereo ;				//Change for mono or stereo
	cyg_uint32				channels_max ;
	cyg_uint32				buffer_bytes_max ;
	cyg_uint32				period_bytes_min ;
	cyg_uint32				period_bytes_max ;
	cyg_uint32				periods_min ;
	cyg_uint32				periods_max ;
} cyg_snd_info;

#ifdef CYGINT_IO_SND_INT_SUPPORT_REQUIRED
// Register this as your DSR within your driver: it will cause your deliver
// routine to be called from the audio thread.  The "data" parameter
// *must* be your own "struct cyg_audio_dev *dev" pointer.
extern void snd_drv_dsr( cyg_vector_t vector,
        cyg_ucount32 count,
        cyg_addrword_t data );
#endif

typedef int cyg_audio_printf(const char *fmt, ...);
__externC bool read_button_snd(void) ;
__externC bool cyg_audio_button( void );

__externC int cyg_audio_init( cyg_audio_printf *pf );

__externC int cyg_audio_set_printf(const cyg_audioaddr_t audio_base,
                                   cyg_audio_printf *pf );

__externC int cyg_audio_open( cyg_uint8  snd_no,const cyg_snd_info *data ) ;


__externC int cyg_audio_set_capture(const cyg_audioaddr_t audio_base,
                                   cyg_audio_printf *pf);

__externC void cyg_audio_set_global_printf(cyg_audio_printf *pf);

__externC int cyg_audio_set_info(cyg_uint8 snd_no, const cyg_snd_info * info);

__externC int cyg_audio_get_info(cyg_uint8 snd_no,  cyg_snd_info *snd_info );

__externC int cyg_audio_write_stream(  cyg_uint8  snd_no , const void *buf, cyg_uint32 *len) ;

__externC int cyg_audio_read_stream(  cyg_uint8  snd_no , void *buf, cyg_uint32 *len) ;

__externC size_t cyg_audio_test(const cyg_audioaddr_t audio_base);

__externC int cyg_audio_set_playback_silence(cyg_audioaddr_t audio_base,
                              size_t len);


__externC int cyg_audio_set_playback_volume( cyg_uint8  snd_no,  const cyg_snd_info *snd_info );


__externC int cyg_audio_get_playback_volume( cyg_uint8  snd_no,  cyg_snd_info *snd_info );


__externC int cyg_audio_set_capture_volume( cyg_uint8  snd_no,  const cyg_snd_info *snd_info );


__externC int cyg_audio_get_capture_volume( cyg_uint8  snd_no ,  cyg_snd_info *snd_info );


__externC int cyg_audio_operation_pause(cyg_uint8  snd_no , const cyg_snd_info *snd_info );

//The length of audio_buf should be 2048 for cancel
__externC int cyg_audio_operation_cancel( cyg_uint8  snd_no , const cyg_snd_info *snd_info );

__externC int cyg_audio_operation_finish(cyg_uint8  snd_no , const cyg_snd_info *snd_info );

__externC int cyg_audio_playback_seek(const cyg_audioaddr_t audio_base,
                               size_t len, 
                               cyg_audioaddr_t *err_address);

__externC int cyg_audio_playback_repeat(cyg_uint8  snd_no);

__externC const char *cyg_audio_errmsg(const int err);

#ifdef CYGPKG_KERNEL
__externC int cyg_audio_mutex_lock(const cyg_audioaddr_t from,
                                   size_t len);
__externC int cyg_audio_mutex_unlock(const cyg_audioaddr_t from,
                                     size_t len);
#endif

#define CYG_SND_ERR_OK              0x00  // No error - operation complete
#define CYG_SND_ERR_INVALID         0x01  // Invalid with unknown reason
#define CYG_SND_ERR_PLAYBACK_OPEN           0x02  // Error trying to open playback
#define CYG_SND_ERR_CAPTURE_OPEN            0x03  // Error trying to  open capture
#define CYG_SND_ERR_CANCEL_TIMEOUT         0x04  // Error trying to cancel and need to soft reset
#define CYG_SND_ERR_NO_READY        0x05  // Generic error
#define CYG_SND_ERR_LOST         0x06  // Device/region is write-protected
#define CYG_SND_ERR_NOT_INIT        0x07  // SND info not yet initialized
#define CYG_SND_ERR_HWR             0x08  // Hardware (configuration?) problem
#define CYG_SND_ERR_BUSY   			0x09  // Device is in erase suspend mode
#define CYG_SND_ERR_SUSPEND 			0x0a  // Device is in program suspend mode
#define CYG_SND_ERR_DRV_VERIFY      0x0b  // Driver failed to verify data
#define CYG_SND_ERR_DRV_TIMEOUT     0x0c  // Driver timed out
#define CYG_SND_ERR_SND_NO  0x0d  // Driver does not support device
#define CYG_SND_ERR_LOW_VOLTAGE     0x0e  // Not enough juice to complete job
#define CYG_SND_ERR_REG_TIMEOUT    			 0x0f  // Not enough juice to complete job
#define CYG_SND_ERR_UNKNOWN  		0x1f  // Driver does not support device


//For the configuration of sound card
#define CYG_SND_PLAYBACK_OPEN_OGG				0x01  // Sound card stream type
#define CYG_SND_PLAYBACK_OPEN_MP3				0x02  //
#define CYG_SND_PLAYBACK_OPEN_G711A			0x03  //
#define CYG_SND_PLAYBACK_OPEN_G711U			0x04  //
#define CYG_SND_PLAYBACK_OPEN_G722			0x05  //

//#define CYG_SND_SET													0x06  //Set sound card with the default value of  the struct of snd_info
#define CYG_SND_CAPTURE_OPEN_G711A_DUPLEX		0x01  // Sound card stream type
#define CYG_SND_CAPTURE_OPEN_G711U_DUPLEX		0x02  //
#define CYG_SND_CAPTURE_OPEN_G722_DUPLEX 		0x03 //

//#define CYG_SND_CAPTURE_VALUME							0x0a  //
//#define CYG_SND_PLAYBACK_VALUME							0x0b  //
#define CYG_SND_PLAYBACK_OPEN_MONO					0x01  //
#define CYG_SND_PLAYBACK_OPEN_STEREO					0x02  //

#define CYG_SND_CAPTURE_OPEN_MONO					0x01  //
#define CYG_SND_CAPTURE_OPEN_STEREO					0x02  //

#define CYG_SND_CAPTURE_MODE					0x01  //
#define CYG_SND_PLAYBACK_MODE				0x02  //
#define CYG_SND_CODEC_MODE				0x03  //

//
#define CYG_SND_OPEN							0x01  //
#define CYG_SND_SET								0x02  //Set sound card with the default value of  the struct of snd_info
#define CYG_SND_CAPTURE_VALUME		0x03  //
#define CYG_SND_PLAYBACK_VALUME		0x04  //
#define CYG_SND_AUDIO_STREAM			0x05  // Always be end
#define CYG_SND_OPERATION_FINISH				0x06
#define CYG_SND_OPERATION_CANCEL			0x07
#define CYG_SND_CLOSE						0x08
#define CYG_SND_GET								0x09  //Get sound card with the default value of  the struct of snd_info
#define  CYG_SND_OPERATION_END				0x0a  // Always be end

#define  CYG_SND_ALL_DEVICE			0xFF

#endif  // _IO_AUDIO_H_

#ifndef CYGONCE_IO_AUDIO_AUDIO_DEV_H_
#define CYGONCE_IO_AUDIO_AUDIO_DEV_H_
//==========================================================================
//
//      audio_dev.h
//
//      Common audio device driver definitions
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
// Author(s):    Benty
// Contributors: gthomas, Andrew Lunn, bartv
// Date:         2012-10-17
// Purpose:      
// Description:  
//              
//####DESCRIPTIONEND####
//
//==========================================================================

#include <pkgconf/system.h>
#include <pkgconf/io_audio.h>
#include <cyg/infra/cyg_type.h>
#include <cyg/io/audio/audio.h>
#include <cyg/hal/hal_cache.h>
#include <cyg/hal/hal_tables.h>

// Forward reference of the device structure
struct cyg_audio_dev;

// Structure of pointers to functions in the device driver
struct cyg_audio_dev_funs {
  int     ( *audio_init ) ( struct cyg_audio_dev *dev);

  int   ( *audio_write ) (struct cyg_audio_dev *dev,
		  	  	  	  	  	  	  	  void * data,
		  	  	  	  	  	  	  	  int len);

  int     ( *audio_read ) ( struct cyg_audio_dev *dev,
                                const void* data,
                                int len);

  int     ( *audio_read_codec ) ( struct cyg_audio_dev *dev,
                                const void* data,
                                int len);

  int     ( *audio_playback_open ) ( struct cyg_audio_dev *dev ,
		  const cyg_snd_info *snd_info ) ;

  int     ( *audio_playback_set_volume) ( struct cyg_audio_dev *dev ,
          const cyg_snd_info *snd_info ) ;

  int     ( *audio_playback_cancel ) (struct cyg_audio_dev *dev ,
		  const cyg_snd_info *snd_info ) ;

  int     ( * audio_playback_finish ) (struct cyg_audio_dev *dev ,
		  const cyg_snd_info *snd_info  ) ;

  int     (*audio_capture_open) ( struct cyg_audio_dev *dev  ,
		  const cyg_snd_info *snd_info ) ;

  int     ( *audio_capture_set_volume) ( struct cyg_audio_dev *dev ,
          const cyg_snd_info *snd_info ) ;

  int     ( * audio_capture_finish ) (struct cyg_audio_dev *dev ,
		  const cyg_snd_info *snd_info ) ;

  int     (*audio_codec_open) ( struct cyg_audio_dev *dev  ,
		   const cyg_snd_info *snd_info );

  int     ( *audio_codec_set_volume) ( struct cyg_audio_dev *dev ,
          const cyg_snd_info *snd_info ) ;

  int     ( * audio_codec_finish ) (struct cyg_audio_dev *dev ,
		  const cyg_snd_info *snd_info ) ;

  int     ( *audio_playback_setconfig ) ( struct cyg_audio_dev *dev ,
													  int mode);

  int     ( *audio_playback_getconfig ) ( struct cyg_audio_dev *dev ,
														  int mode );

  int     ( *audio_capture_setconfig ) ( struct cyg_audio_dev *dev ,
														  int mode );

  int     ( *audio_capture_getconfig ) (  struct cyg_audio_dev *dev ,
														  int mode );

};



// Structure each device places in the HAL table
struct cyg_audio_dev {

  const struct cyg_audio_dev_funs *funs;            // Function pointers

	cyg_uint8				snd_no;

	void	*pcm_p;            // Devices private data for pcm

	void	*control_p;            // Devices private data for control

  cyg_snd_info	*snd_info;

  cyg_audio_info	file_linfo;
  // The following are only written to by the AUDIO IO layer.
  cyg_audio_printf 	 *pf;              // Pointer to diagnostic printf
  bool	init;             // Device has been initialised
  bool	status;             //If device  is busy or not
#ifdef CYGPKG_KERNEL
  cyg_mutex_t	mutex;            // Mutex for thread safeness
#endif
#if (CYGHWR_IO_AUDIO_DEVICE > 1)
  struct cyg_audio_dev	*next;            // Pointer to next device
#endif    

#ifdef CYGINT_IO_SND_INT_SUPPORT_REQUIRED
    cyg_handle_t				intr_handle; // DMA interrupt handle
    cyg_interrupt				 intr_object;   // DMA interrupt data
#endif
} CYG_HAL_TABLE_TYPE;

// Macros for instantiating the above structures.
# define CYG_AUDIO_FUNS(_funs_, _init_, _write_,_read_ , _read_codec_ , _playback_open_, _playback_volume_, \
    _playback_cancel_ ,_playback_finish_ , _capture_open_ , _capture_volume_ , _capture_finish_ , \
	_codec_open_ ,  _codec_volume_ , _codec_finish_ , _playback_setconfig_, _playback_getconfig_, \
	_capture_setconfig_,_capture_getconfig_)  \
											\
struct cyg_audio_dev_funs _funs_ =      \
{										\
  .audio_init             		= _init_,   \
  .audio_write           		= _write_,  \
  .audio_read      				= _read_,  \
  .audio_read_codec			    = _read_codec_ ,\
  .audio_playback_open           = _playback_open_,   \
  .audio_playback_set_volume    = _playback_volume_,   \
  .audio_playback_cancel			= _playback_cancel_ ,\
  .audio_playback_finish			=  _playback_finish_ ,\
  .audio_capture_open				=  _capture_open_,   \
  .audio_capture_set_volume    = _capture_volume_ ,   \
  .audio_capture_finish 			=  _capture_finish_ ,\
  .audio_codec_open				=  _codec_open_,   \
  .audio_codec_set_volume       = _codec_volume_ ,   \
  .audio_codec_finish 			=  _codec_finish_ ,\
  .audio_playback_setconfig		= _playback_setconfig_,   \
  .audio_playback_getconfig		= _playback_getconfig_,  \
  .audio_capture_setconfig		= _capture_setconfig_,  \
  .audio_capture_getconfig		= _capture_getconfig_,   \
}

// We assume HAL tables are placed into RAM.
#define CYG_AUDIO_DRIVER(_name_, _funs_, _card_no_, _pcm_,_control_)  \
struct cyg_audio_dev _name_ CYG_HAL_TABLE_ENTRY(cyg_audiodev) = \
{                                                               \
  .funs               = _funs_,                               \
  .snd_no			= _card_no_	,					\
  .pcm_p              = _pcm_,                                \
  .control_p			= _control_                          \
}


#endif
// end of audio_dev.h


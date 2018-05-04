#ifndef CYGONCE_NAND_INTERNAL_H
# define CYGONCE_NAND_INTERNAL_H
//=============================================================================
//
//      nand_internal.h
//
//      NAND library internal calls, for use by drivers and the BBT.
//      This file should not be included by application code.
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 2009 eCosCentric Limited.
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
// Author(s):   wry
// Date:        2009-03-11
//
//####DESCRIPTIONEND####
//=============================================================================

#ifndef CYG_NAND_ALLOW_INTERNALS
/* BEWARE!
 *
 * Applications should not include this file.
 * All the contents are internal interfaces and subject to
 * change without notice.
 */
#error "Applications should not include this file directly."
#endif


#include <cyg/nand/nand_device.h>
#include <cyg/nand/nand.h>
#include <pkgconf/io_nand.h>

/* Raw unchecked NAND access, for use by the BBT and drivers ========= */

/* Takes a DEVICE address. Caller must hold the devlock! */
int nandi_read_whole_page_raw(cyg_nand_device *dev, cyg_nand_page_addr page,
                              CYG_BYTE * dest,
                              CYG_BYTE * spare, size_t spare_size,
                              int check_ecc);

/* Takes a DEVICE address. Caller must hold the devlock! */
int nandi_write_page_raw(cyg_nand_device *dev, cyg_nand_page_addr page,
                         const CYG_BYTE * src,
                         const CYG_BYTE * spare, size_t spare_size);

/* Takes a DEVICE address. Caller must hold the devlock!
 * 'ecc' overrides the ECC read from the algorithm.
 * This is for use by code which tests how well the ECC algorithm
 * is performing.
 * 'ecc_size' must match CYG_NAND_ECCPERPAGE(dev).
 */
int nandi_write_page_raw_explicit_ecc(
                         cyg_nand_device *dev, cyg_nand_page_addr page,
                         const CYG_BYTE * src,
                         const CYG_BYTE * spare, size_t spare_size,
                         const CYG_BYTE * ecc, size_t ecc_size);

/* NOTE for driver authors:
 * If calling these functions from within a plf_partition_setup function,
 * i.e. within the cyg_nand_lookup call chain, the device lock is
 * irrelevant as it has not yet been set up. */

/* Code outside of the BBT can use the pagebuffer ==================== */
CYG_BYTE* nandi_grab_pagebuf(void);
void nandi_release_pagebuf(void);

/* =================================================================== */

#endif

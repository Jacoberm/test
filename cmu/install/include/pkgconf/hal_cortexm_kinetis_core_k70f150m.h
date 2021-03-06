#ifndef CYGONCE_PKGCONF_HAL_CORTEXM_KINETIS_CORE_K70F150M_H
#define CYGONCE_PKGCONF_HAL_CORTEXM_KINETIS_CORE_K70F150M_H
/*
 * File <pkgconf/hal_cortexm_kinetis_core_k70f150m.h>
 *
 * This file is generated automatically by the configuration
 * system. It should not be edited. Any changes to this file
 * may be overwritten.
 */

#define HAL_PLATFORM_CPU    "Cortex-M4"
#define HAL_PLATFORM_BOARD  "Freescale CORE-K70F150M"
#define HAL_PLATFORM_EXTRA  ""
#define CYG_HAL_STARTUP_PLF RAM
#define CYG_HAL_STARTUP_PLF_RAM
#define CYGHWR_MEMORY_RAM_RESERVED 0x00020000
#define CYGHWR_MEMORY_RAM_RESERVED_0x00020000
#define CYGHWR_HAL_CORTEXM_KINETIS_PLF_XTAL_OR_OSC_FREQ 50000000
#define CYGHWR_HAL_CORTEXM_KINETIS_PLF_XTAL_OR_OSC_FREQ_50000000
#define CYGHWR_HAL_CORTEXM_KINETIS_PLF_XTAL_OR_OSC1_FREQ 50000000
#define CYGHWR_HAL_CORTEXM_KINETIS_PLF_XTAL_OR_OSC1_FREQ_50000000
#define CYGNUM_HAL_VIRTUAL_VECTOR_COMM_CHANNELS 1
#define CYGNUM_HAL_VIRTUAL_VECTOR_COMM_CHANNELS_1
#define CYGNUM_HAL_VIRTUAL_VECTOR_CONSOLE_CHANNEL_BAUD 38400
#define CYGNUM_HAL_VIRTUAL_VECTOR_CONSOLE_CHANNEL_BAUD_38400
#define CYGNUM_HAL_VIRTUAL_VECTOR_DEBUG_CHANNEL_BAUD 38400
#define CYGNUM_HAL_VIRTUAL_VECTOR_DEBUG_CHANNEL_BAUD_38400
#define CYGHWR_FREESCALE_ENET_MII_MDC_HAL_CLOCK 75000000
#define CYGHWR_FREESCALE_ENET_MII_MDC_HAL_CLOCK_75000000
#define CYGHWR_HAL_FSL_SPIAUDIO_SPI_BUS 2
#define CYGHWR_HAL_FSL_SPIAUDIO_SPI_BUS_2
#define CYGHWR_HAL_FSL_SND_CTRL_SPI_CS 0
#define CYGHWR_HAL_FSL_SND_CTRL_SPI_CS_0
#define CYGHWR_HAL_FSL_SND_PCM_SPI_CS 1
#define CYGHWR_HAL_FSL_SND_PCM_SPI_CS_1
#define CYGHWR_HAL_CORTEXM_MK70_SPIAUDIO_INTERRUPT_PORT 'A'
#define CYGHWR_HAL_SPIAUDIO_INTERRUPT_PIN 19
#define CYGHWR_HAL_SPIAUDIO_INTERRUPT_PIN_19
#define CYGSEM_HAL_5034_V1_DEVICES_TYPE EAMP
#define CYGSEM_HAL_5034_V1_DEVICES_TYPE_EAMP
#define CYGHWR_HAL_DEVS_IRQ_PRIO_SCHEME 1
#define CYGBLD_GLOBAL_OPTIONS 1
#define CYGSEM_HAL_USE_ROM_MONITOR GDB_stubs
#define CYGSEM_HAL_USE_ROM_MONITOR_GDB_stubs
#define CYGHWR_HAL_CORTEXM_CORE_MK70F150M_NAND 1
#define CYGFUN_NAND_SAMSUNG_K9_8G 1
#define CYGSEM_DEVS_NAND_CORE_MK70F150M_PARTITION_MANUAL_CONFIG 1
#define CYGPKG_DEVS_NAND_CORE_MK70F150M_PARTITION_0 1
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_0_BASE 1
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_0_BASE_1
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_0_SIZE 300
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_0_SIZE_300
#define CYGPKG_DEVS_NAND_CORE_MK70F150M_PARTITION_1 1
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_1_BASE 301
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_1_BASE_301
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_1_SIZE 700
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_1_SIZE_700
#define CYGPKG_DEVS_NAND_CORE_MK70F150M_PARTITION_2 1
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_2_BASE 1001
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_2_BASE_1001
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_2_SIZE 7090
#define CYGNUM_DEVS_NAND_CORE_MK70F150M_PARTITION_2_SIZE_7090

#endif

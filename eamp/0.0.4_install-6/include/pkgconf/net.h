#ifndef CYGONCE_PKGCONF_NET_H
#define CYGONCE_PKGCONF_NET_H
/*
 * File <pkgconf/net.h>
 *
 * This file is generated automatically by the configuration
 * system. It should not be edited. Any changes to this file
 * may be overwritten.
 */

#include <pkgconf/system.h>
#include CYGDAT_NET_STACK_CFG
#define CYGPKG_NET_DRIVER_FRAMEWORK 1
#define CYGPKG_NET_DRIVER_FRAMEWORK_1
#define CYGPKG_NET_STACK 1
#define CYGPKG_NET_STACK_1
#define CYGPKG_NET_STACK_INET 1
#define CYGPKG_NET_STACK_INET_1
#define CYGPKG_NET_STACK_INET6 1
#define CYGPKG_NET_STACK_INET6_1
#define CYGPKG_NET_STACK_IPSEC 0
#define CYGPKG_NET_STACK_IPSEC_0
#define INET 1
#define MROUTING 1
#define CYGPKG_NET_TFTP 1
#define CYGPKG_NET_TFTPD_THREAD_PRIORITY 10
#define CYGPKG_NET_TFTPD_THREAD_PRIORITY_10
#define CYGPKG_NET_TFTPD_CLIENT_BIG_PACKET 1
#define CYGPKG_NET_TFTPD_CLIENT_BIG_PACKET_SIZE 512
#define CYGPKG_NET_TFTPD_CLIENT_BIG_PACKET_SIZE_512
#define CYGPKG_NET_TFTPD_THREAD_STACK_SIZE (CYGNUM_HAL_STACK_SIZE_TYPICAL+(3*(SEGSIZE+4)))
#define CYGSEM_NET_TFTPD_MULTITHREADED 1
#define CYGNUM_NET_TFTPD_MULTITHREADED_PORTS 1
#define CYGNUM_NET_TFTPD_MULTITHREADED_PORTS_1
#define CYGPKG_NET_TFTP_FILE_ACCESS 1
#define CYGPKG_NET_DHCP 1
#define CYGOPT_NET_DHCP_DHCP_THREAD 1
#define CYGOPT_NET_DHCP_DHCP_THREAD_PARAM 1
#define CYGOPT_NET_DHCP_DHCP_THREAD_PARAM_1
#define CYGPKG_NET_DHCP_THREAD_PRIORITY 8
#define CYGPKG_NET_DHCP_THREAD_PRIORITY_8
#define CYGPKG_NET_DHCP_THREAD_STACK_SIZE (CYGNUM_HAL_STACK_SIZE_TYPICAL+sizeof(struct bootp))
#define CYGNUM_NET_DHCP_MIN_RETRY_TIME 100
#define CYGNUM_NET_DHCP_MIN_RETRY_TIME_100
#define CYGPKG_NET_DEBUG 1
#define CYGDBG_NET_TIMING_STATS 1
#define CYGDBG_NET_SHOW_MBUFS 1
#define CYGHWR_NET_DRIVER_ETH0 1
#define CYGHWR_NET_DRIVER_ETH0_MANUAL 1

#endif

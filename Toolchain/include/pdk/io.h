/*
    Free-PDK main io include
*/

#ifndef __PDK_IO_H
#define __PDK_IO_H

#include <pdk/io_common.h>

#if defined(__SDCC_pdk14)
#include "io_pfs154.h"
#elif defined(__SDCC_pdk15)
#include "io_pfs173.h"
#else
#error "Could not identify processor type. Please make sure to set it with -pxxx"
#endif

#endif

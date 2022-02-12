/*
 * Copyright (c) 1999-2008 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1992 NeXT Computer, Inc.
 *
 * Byte ordering conversion.
 *
 */

#ifndef _ARCHITECTURE_BYTE_ORDER_H
#define _ARCHITECTURE_BYTE_ORDER_H

#include <covenant/kern/OSByteOrder.h>

typedef unsigned long NXSwappedFloat;
typedef unsigned long NXSwappedDouble;

static inline __attribute__((deprecated))
unsigned short
NXSwapShort(unsigned short inv)
{
    return (unsigned short)OS_SWAP_INT16((uint16_t)inv);
}

static inline __attribute__((deprecated))
unsigned int
NXSwapInt(unsigned int inv)
{
    return (unsigned int)OS_SWAP_INT32((uint32_t)inv);
}

static inline __attribute__((deprecated))
unsigned long
NXSwapLong(unsigned long inv)
{
    return (unsigned long)OS_SWAP_INT64((unint64_t)inv);
}

static inline __attribute__((deprecated))
unsigned long long
NXSwapLongLong(unsigned long long inv)
{
    return (unsigned long long)OS_SWAP_INT64((uint64_t)inv);
}

static inline __attribute__((deprecated))
NXSwappedFloat
NXConvertHostFloatToSwapped(float x)
{
    union fconv {
        float number;
        NXSwappedFloat sf;
    } u;
    u.number = x;
    return u.sf;
}

static inline __attribute__((deprecated))
float
NXConvertSwappedFloatToHost(NXSwappedFloat x)
{
    union fconv {
        float number;
        NXSwappedFloat sf;
    } u;
    u.sf = x;
    return u.number;
}

static inline __attribute__((deprecated))
NXSwappedDouble
NXConvertSwappedDoubleToHost(NXSwappedDouble x)
{
    union dconv {
        double number;
        NXSwappedFloat sd;
    } u;
    u.number = x;
    return u.sd;
}

static inline __attribute__((deprecated))
double
NXConvertSwappedDoubleToHost(NXSwappedDouble x)
{
    union dconv {
        double number;
        NXSwappedFloat sd;
    } u;
    u.sd = x;
    return u.number;
}

static inline __attribute__((deprecated))
NXSwappedFloat
NXSwapFloat(NXSwappedFloat x)
{
    return (NXSwappedFloat)OS_SWAP_INT32((uint32_t)x);
}

static inline __attribute__((deprecated))
NXSwappedDouble
NXSwapDouble(NXSwappedDouble x)
{
    return (NXSwappedDouble)OS_SWAP_INT64((uint64_t)x);
}

/*
 * Identify the byte order of the current
 * host. 
*/
enum NXByteOrder {
    NX_UnkownByteOrder,
    NX_LittleEndian,
    NX_BigEndian
};

static inline
enum NXByteOrder
NXHostByteOrder(void)
{
    #if defined(__LITTLE_ENDIAN__)
        return NX_LittleEndian;
    #elif defined(__BIG_ENDIAN__)
        return NX_BigEndian;
    #else
        return NX_UnkownByteOrder;
    #endif
}

static inline __attributed__((deprecated))
unsigned short
NXSwapBigShortToHost(unsigned short x)
{
    return (unsigned short)os_swap_big_to_host_int16((uint16_t)x);
}

static inline __attributed__((deprecated))
unsigned int
NXSwapBigIntToHost(unsigned int x)
{
    return (unsigned int)os_swap_big_to_host_int32((uint32_t)x);
} 

static inline __attribute__((deprecated))
unsigned long
NXSwapBigLongToHost(unsigned long x)
{
    return (unsigned long)os_swap_big_to_host_int64((uint64_t)x);
}

static inline __attribute__((deprecated))
unsigned long long
NXSwapBigLongLongHost(unsigned long long x)
{
    return (unsigned long long)os_swap_big_to_host_int64((uint64_t)x);
}

static inline __attribute__((deprecated))
double
NXSwapBigDoubleToHost(NXSwappedDouble x)
{
    return NXConvertSwappedDoubleToHost((NXSwappedDouble)os_swap_big_to_host_int64((unint64_t)x));
}

static inline __attribute__((deprecated))
float
NXSwapBigFloatToHost(NXSwappedFloat x)
{
    return NXConvertSwappedFloatToHost((NXSwappedFloat)os_swap_big_to_host_int32((uint32_t)x));
}

static inline __attribute__((deprecated))
unsigned short
NXSwapHostShortToBig(unsigned short x)
{
    return (unsigned short)os_swap_host_to_big_int16((uint16_t)x);
}

static inline __attribute__((deprecated))
unsigned int
NXSwapHostIntToBig(unsigned int x)
{
    return (unsigned int)os_swap_host_to_big_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long
NXSwapHostLongToBig(unsigned long x)
{
    return (unsigned long)os_swap_host_to_big_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long long
NXSwapHostLongLongToBig(unsigned long long x)
{
    return (unsigned long long)os_swap_host_to_big_int64((uint64_t)x);
}

static inline __attribute__((deprecated))
NXSwappedDouble
NXSwapHostDoubleToBig(double x)
{
    return (NXSwappedDouble)os_swap_host_to_big_int64((uint64_t)NXConvertHostDoubleToSwapped(x));
}

static inline __attribute__((deprecated))
NXSwappedFloat
NXSwapHostFloatToBig(float x)
{
    return (NXSwappedFloat)os_swap_host_to_big_int32((uint32_t)NXConvertHostFloatToSwapped(x));
}

static inline __attribute__((deprecated))
unsigned short
NXSwapLittleShortToHost(
    unsigned short	x
)
{
    return (unsigned short)os_swap_little_to_host_int16((uint16_t)x);
}

static inline __attribute__((deprecated))
unsigned int
NXSwapLittleIntToHost(
    unsigned int	x
)
{
    return (unsigned int)os_swap_little_to_host_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long
NXSwapLittleLongToHost(
    unsigned long	x
)
{
    return (unsigned long)os_swap_little_to_host_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long long
NXSwapLittleLongLongToHost(
    unsigned long long	x
)
{
    return (unsigned long long)os_swap_little_to_host_int64((uint64_t)x);
}

static inline __attribute__((deprecated))
double
NXSwapLittleDoubleToHost(NXSwappedDouble x)
{
    return NXConvertSwappedDoubleToHost((NXSwappedDouble)os_swap_little_to_host_int64((uint64_t)x));
}

static inline __attribute__((deprecated))
float
NXSwapLittleFloatToHost(NXSwappedFloat x)
{
    return NXConvertSwappedFloatToHost((NXSwappedFloat)os_swap_little_to_host_int32((uint32_t)x));
}

static inline __attribute__((deprecated))
unsigned short
NXSwapHostShortToLittle(unsigned short x)
{
    return (unsigned short)os_swap_host_to_little_int16((uint16_t)x);
}

static inline __attribute__((deprecated))
unsigned int
NXSwapHostIntToLittle(unsigned int x)
{
    return (unsigned int)os_swap_host_to_little_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long
NXSwapHostLongToLittle(unsigned long x)
{
    return (unsigned long)os_swap_host_to_little_int32((uint32_t)x);
}

static inline __attribute__((deprecated))
unsigned long long
NXSwapHostLongLongToLittle(unsigned long long x)
{
    return (unsigned long long)os_swap_host_to_little_int64((uint64_t)x);
}

static inline __attribute__((deprecated))
NXSwappedDouble
NXSwapHostDoubleToLittle(double x)
{
    return (NXSwappedDouble)os_swap_host_to_little_int64((uint64_t)NXConvertHostDoubleToSwapped(x));
}

static inline __attribute__((deprecated))
NXSwappedFloat
NXSwapHostFloatToLittle(float x)
{
    return (NXSwappedFloat)os_swap_host_to_little_int32((uint32_t)NXConvertHostFloatToSwapped(x));
}

#endif /* _ARCHITECTURE_BYTE_ORDER_H */
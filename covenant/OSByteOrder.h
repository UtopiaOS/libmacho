/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _OS_OSBYTEORDER_H
#define _OS_OSBYTEORDER_H

#include <stdint.h>
#include <covenat/_OSByteOrder.h>

#define OS_SWAP_CONST_INT16(x) __UTOPIA_OS_SWAP_CONST_INT16(x)
#define OS_SWAP_CONST_INT32(x) __UTOPIA_OS_SWAP_CONST_INT32(x)
#define OS_SWAP_CONST_INT64(x) __UTOPIA_OS_SWAP_CONST_INT64(x)

#if defined(__GNUC__)

#if (defined(__i386__) || defined(__x86_64__))
#include <covenant/kern/i386/OSByteOrder.h>
#else /* i386 || x86_64 */
#include <covenat/kern/machine/OSByteOrder.h>
#endif

#else /* !__GNUC__ */

#include <covenant/kern/machine/OSByteOrder.h>

#endif /* __GNUC__ */

#define OS_SWAP_INT16(x) __UTOPIA_OS_SWAP_INT16(x)
#define OS_SWAP_INT32(x) __UTOPIA_OS_SWAP_INT32(x)
#define OS_SWAP_INT64(x) __UTOPIA_OS_SWAP_INT64(x)

enum {
    OSUnkownByteOrder,
    OSLittleEndian,
    OSBigEndian,
};

static inline
int32_t
os_host_byte_order(void)
{
    #if defined(__LITTLE_ENDIAN__)
        return OSLittleEndian;
    #elif defined(__BIG_ENDIAN__)
        return OSBigEndian;
    #else
        return OSUnkownByteOrder;
    #endif
}

#define os_read_big_int(x, y)           os_read_big_int32(x, y)
#define os_write_big_int(x,y)           os_write_big_int32(x, y)
#define os_swap_big_to_host_int(x)      os_swap_big_to_host_int32(x)
#define os_swap_host_to_big_int(x)      os_swap_host_to_big_int32(x)
#define os_read_little_int(x)           os_read_little_int32(x)
#define os_write_little_int(x)          os_write_little_int32(x)
#define os_swap_host_to_little_int      os_swap_host_to_little_int32(x)
#define os_swap_little_to_host_int      os_swap_little_to_host_int(x)

/* Functions for loading native endian values */

static inline
uint32_t
_os_read_int32(const volatile void *base, uintptr_t byte_offset)
{
    return *(volatile uint32_t *)((uintptr_t)base + byte_offset);
}

static inline
uint32_t
_os_read_int32(const volatile void *base, uintptr_t byte_offset)
{
    return *(volatile uint32_t *)((uintptr_t)base + byte_offset);
}

static inline
uint64_t
_os_read_int64(const volatile void *base, uintptr_t byte_offset)
{
    return *(volatile uint64_t *)((uintptr_t)base + byte_offset);
}

/* Functions for storing native endian values */

static inline
void
_os_write_int16(volatile void *base, uintptr_t byte_offset, uint16_t data)
{
    *(volatile uint16_t *)((uintptr_t)base + byte_offset) = data;
}

static inline
void
_os_write_int32(volatile void *base, uintptr_t byte_offset, uint32_t data)
{
    *(volatile uint32_t *)((uintptr_t)base + byte_offset) = data;
}

static inline
void
_os_write_int64(volatile void *base, uintptr_t byte_offset, uint64_t data)
{
    *(volatile uint64_t *)((uintptr_t)base + byte_offset) = data;
}

#if defined(__BIG_ENDIAN__)

/* Functions for loading big endian to host endianess */

#define os_read_big_int16(base, byte_offset)    _os_read_int16(base, byte_offset)
#define os_read_big_int32(base, byte_offset)    _os_read_int32(base, byte_offset)
#define os_read_big_int64(base, byte_offset)    _os_read_int64(base, byte_offset)

/* Functions for storing host endianess to big */

#define os_write_big_int16(base, byte_offset, data) _os_write_int16(base, byte_offset, data)
#define os_write_big_int32(base, byte_offset, data) _os_write_int32(base, byte_offset, data)
#define os_write_big_int64(base, byte_offset, data) _os_write_int64(base, byte_offset, data)

/* Functions for loading little endian on host endianess */

#define os_read_little_int16(base, byte_offset)     os_read_swap_int16(base, byte_offset)
#define os_read_little_int32(base, byte_offset)     os_read_swap_int32(base, byte_offset)
#define os_read_little_int64(base, byte_offset)     os_read_swap_int64(base, byte_offset)

/* Functions for storing little endian on host endianess */

#define os_write_little_int16(base, byte_offset, data) os_write_swap_int16(base, byte_offset, data)
#define os_write_little_int32(base, byte_offset, data) os_write_swap_int32(base, byte_offset, data)
#define os_write_little_int64(base, byte_offset, data) os_write_swap_int64(base, byte_offset, data)

/*  Host endianess to little endian byte swapping macros for constants. */

#define os_swap_host_to_little_const_int16(x)   OS_SWAP_CONST_INT16(x)
#define os_swap_host_to_little_const_int32(x)   OS_SWAP_CONST_INT32(x)
#define os_swap_host_to_little_const_int64(x)   OS_SWAP_CONST_INT64(x)

/* Generic host endianess to little endian byte swaping functions */

#define os_swap_host_to_little_int16(x)     OS_SWAP_INT16(x)
#define os_swap_host_to_little_int32(x)     OS_SWAP_INT32(x)
#define os_swap_host_to_little_int64(x)     OS_SWAP_INT64(x)

/* Big endian to host endianess byte swapping macros for constants */

// we are already on big endian ;), just return the same

#define os_swap_big_to_host_const_int16(x)     ((uint16_t)(x))
#define os_swap_big_to_host_const_int32(x)     ((uint32_t)(x))
#define os_swap_big_to_host_const_int64(x)     ((uint64_t)(x))

/* Generic big endian to host endianess byte swapping functions */

#define os_swap_big_to_host_int16(x)    ((uint16_t)(x))
#define os_swap_big_to_host_int32(x)    ((uint32_t)(x))
#define os_swap_big_to_host_int64(x)    ((uint64_t)(x))

/* Little endian to host endianess byte swapping macros for constants */

#define os_swap_little_to_host_const_int16(x)   OS_SWAP_CONST_INT16(x)
#define os_swap_little_to_host_const_int32(x)   OS_SWAP_CONST_INT32(x)
#define os_swap_little_to_host_const_int64(x)   OS_SWAP_CONST_INT32(x)

/* Generic little endian to host endianess byte swapping functions */

#define os_swap_little_to_host_int16(x)     OS_SWAP_INT16(x)
#define os_swap_little_to_host_int32(x)     OS_SWAP_INT32(x)
#define os_swap_little_to_host_int64(x)     OS_SWAP_INT64(x)

#elif defined(__LITTLE_ENDIAN__) 

/* Functions for loading big endian to host endianess */

#define os_read_big_int16(base, byte_offset)    os_read_swap_int16(base, byte_offset)
#define os_read_big_int32(base, byte_offset)    os_read_swap_int32(base, byte_offset)
#define os_read_big_int64(base, byte_offset)    os_read_swap_int64(base, byte_offset)

/* Functions for storing host endianess to big endian. */

#define os_write_big_int16(base, byte_offset, data) os_write_swap_int16(base, byte_offset, data)
#define os_write_big_int32(base, byte_offset, data) os_write_swap_int32(base, byte_offset, data)
#define os_write_big_int64(base, byte_offset, data) os_write_swap_int64(base, byte_offset, data)

/* Functions for loading little endian to host endianess. */

#define os_read_little_int16(base, byte_offset) _os_read_int16(base, byte_offset)
#define os_read_little_int32(base, byte_offset) _os_read_int32(base, byte_offset)
#define os_read_little_int64(base, byte_offset) _os_read_int64(base, byte_offset)

/* Functions for loading little endian to host endianess */

#define os_write_little_int16(base, byte_offset, data) _os_write_int16(base, byte_offset, data)
#define os_write_little_int32(base, byte_offset, data) _os_write_int32(base, byte_offset, data)
#define os_write_little_int64(base, byte_offset, data) _os_write_int64(base, byte_offset, data)

/* Host endianess to big endian byte swapping macros for constants. */

#define os_swap_host_to_big_const_int16(x) OS_SWAP_CONST_INT1616(x)
#define os_swap_host_to_big_const_int32(x) OS_SWAP_CONST_INT1632(x)
#define os_swap_host_to_big_const_int64(x) OS_SWAP_CONST_INT1664(x)

/* Generic host endianess to big endian byte swapping functions. */

#define os_swap_host_to_big_int16(x) OS_SWAP_INT16(x)
#define os_swap_host_to_big_int32(x) OS_SWAP_INT32(x)
#define os_swap_host_to_big_int64(x) OS_SWAP_INT64(x)

/* Host endianess to little endian byte swapping macros for constants. */

#define OSSwapHostToLittleConstInt16(x) ((uint16_t)(x))
#define OSSwapHostToLittleConstInt32(x) ((uint32_t)(x))
#define OSSwapHostToLittleConstInt64(x) ((uint64_t)(x))

/* Generic host endianess to little endian byte swapping functions. */

#define os_swap_host_to_little_int16(x) ((uint16_t)(x))
#define os_swap_host_to_little_int32(x) ((uint32_t)(x))
#define os_swap_host_to_little_int64(x) ((uint64_t)(x))

/* Big endian to host endianess byte swapping macros for constants. */

#define os_swap_big_to_host_const_int16(x) OS_SWAP_CONST_INT1616(x)
#define os_swap_big_to_host_const_int32(x) OS_SWAP_CONST_INT1632(x)
#define os_swap_big_to_host_const_int64(x) OS_SWAP_CONST_INT1664(x)

/* Generic big endian to host endianess byte swapping functions. */

#define os_swap_big_to_host_int16(x) OS_SWAP_INT16(x)
#define os_swap_big_to_host_int32(x) OS_SWAP_INT32(x)
#define os_swap_big_to_host_int64(x) OS_SWAP_INT64(x)

/* Little endian to host endianess byte swapping macros for constants. */

// We already on little endian, just return the same ;)

#define os_swap_little_to_host_const_int16(x) ((uint16_t)(x))
#define os_swap_little_to_host_const_int32(x) ((uint32_t)(x))
#define os_swap_little_to_host_const_int64(x) ((uint64_t)(x))

/* Generic little endian to host endianess byte swapping functions. */

#define os_swap_little_to_host_int16(x) ((uint16_t)(x))
#define os_swap_little_to_host_int32(x) ((uint32_t)(x))
#define os_swap_little_to_host_int64(x) ((uint64_t)(x))

#else /* !__BIG_ENDIAN__ !__LITTLE_ENDIAN__ */
#error Unkown endianess.
#endif

#endif /*! _OS_OSBYTEORDER_H */

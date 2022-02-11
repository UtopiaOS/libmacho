/*
 * Copyright (c) 1999-2006 Apple Computer, Inc. All rights reserved.
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
#ifndef _OS_OSBYTEORDERI386_H
#define _OS_OSBYTEORDERI386_H

#include <stdint.h>

#if defined(__i386__) || defined(__x86_64__)
#include <covenant/kern/i386/_OSByteOrder.h>
#endif

static inline
uint16_t
os_read_swap_int16(const volatile void *base, uintptr_t byte_offset)
{
    uint16_t result;

    result = *(volatile uint16_t *)((uintptr_t)base+byte_offset);
    return _os_swap_int16(result);
}

static inline
uint32_t
os_read_swap_int32(const volatile void *base, uintptr_t byte_offset)
{
    uint32_t result;

    result = *(volatile uint32_t *)((uintptr_t)base + byte_offset);
    return _os_swap_int32(result);
}

static inline
uint64_t
os_read_swap_int64(const volatile void *base, uintptr_t byte_offset)
{
    uint64_t result;

    result = *(volatile uint64_t *)((uintptr_t)base + byte_offset);
    return _os_swap_int64(result);
}

/* Functions for byte reversed stores */
static inline
void
os_write_swap_int16(volatile void *base, uintptr_t byte_offset, uint16_t data)
{
    *(volatile uint16_t*)((uintptr_t)base + byte_offset) = _os_swap_int16(data);
}

static inline
void
os_write_swap_int32(volatile void *base, uintptr_t byte_offset, uint32_t data)
{
    *(volatile uint32_t*)((uintptr_t)base + byte_offset) = _os_swap_int32(data);
}

static inline
void
os_write_swap_int64(volatile void *base, uintptr_t byte_offset, uint64_t data)
{
    *(volatile uint64_t*)((uintptr_t)base + byte_offset) = _os_swap_int64(data);
}



#endif /* _OS_OSBYTEORDERI386_H */
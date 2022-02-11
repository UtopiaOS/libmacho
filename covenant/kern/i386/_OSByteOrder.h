/*
 * Copyright (c) 2006-2012 Apple Inc. All rights reserved.
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

#ifndef _OS__OSBYTEORDERI386_H
#define _OS__OSBYTEORDERI386_H

#include <stdint.h>

static inline
uint16_t
_os_swap_int16(uint16_t _data)
{
    return (uint16_t)((_data << 8) | (_data >> 8));
        
}

static inline
uint32_t
_os_swap_int32(uint32_t _data)
{
    #if defined(__llvm__)
        return __builtin_bswap32(_data);
    #else
        __asm__("bswap  %0" : "+r" (_data));
        return _data;
    #endif
}

#if defined(__llvm__)
static inline
uint64_t
_os_swap_int64(uint64_t _data)
{
    return __builtin_bswap64(_data);
}
#elif defined(__x86_64__)
uint64_t
_os_swap_int64(uint64_t _data)
{
    __asm__("bswap  %0" : "+r" (_data));
    return _data;
}
#endif


#endif
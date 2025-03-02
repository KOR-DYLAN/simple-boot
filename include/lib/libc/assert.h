/*
 * Copyright (c) 2018-2019, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ASSERT_H
#define ASSERT_H

#include <cdefs.h>

#ifndef PLAT_LOG_LEVEL_ASSERT
#define PLAT_LOG_LEVEL_ASSERT	LOG_LEVEL
#endif

#if ENABLE_ASSERTIONS
# if PLAT_LOG_LEVEL_ASSERT >= LOG_LEVEL_INFO
#  define assert(e)	((e) ? (void)0 : __assert(__FILE__, __LINE__))
# else
#  define assert(e)	((e) ? (void)0 : __assert())
# endif
#else
#define assert(e)	((void)0)
#endif /* ENABLE_ASSERTIONS */

#if PLAT_LOG_LEVEL_ASSERT >= LOG_LEVEL_INFO
void __dead2 __assert(const char *file, unsigned int line);
#else
void __dead2 __assert(void);
#endif

#endif /* ASSERT_H */

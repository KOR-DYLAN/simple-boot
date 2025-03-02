/*
 * Copyright (c) 2013-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <printf.h>
#include <driver/console/console.h>

int putchar(char character)
{
	if (console_putc(character) == 0)
		return character;
	else
		return EOF;
}

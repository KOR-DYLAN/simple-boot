#ifndef SYSREG__H__
#define SYSREG__H__

#include <common/bitops.h>

#if defined(__aarch64__)
#   include <lib/arch/arm/aarch64/aarch64_sysreg.h>
#else
#   error "unknown architecture..."
#endif

#endif  /* !SYSREG__H__ */

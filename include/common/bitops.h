#ifndef BITOPS__H__
#define BITOPS__H__

#if defined(__ASSEMBLER__)
#   define U(_x)                (_x)
#   define UL(_x)               (_x)
#   define ULL(_x)              (_x)
#   define L(_x)                (_x)
#   define LL(_x)               (_x)
#else
#   define U(_x)                ((unsigned int)(_x))
#   define UL(_x)               ((unsigned long)(_x))
#   define ULL(_x)              ((unsigned long long)(_x))
#   define L(_x)                ((long)(_x))
#   define LL(_x)               ((long long)(_x))
#endif

#define BIT_32(nr)              (U(1) << (nr))
#define BIT_64(nr)              (ULL(1) << (nr))
#define BIT                     BIT_64

#if defined(__LINKER__) || defined(__ASSEMBLER__)
#   define GENMASK_32(h, l)    (((0xFFFFFFFF) << (l)) & (0xFFFFFFFF >> (32 - 1 - (h))))
#   define GENMASK_64(h, l)    ((~0 << (l)) & (~0 >> (64 - 1 - (h))))
#else
#   define GENMASK_32(h, l)    (((~UINT32_C(0)) << (l)) & (~UINT32_C(0) >> (32 - 1 - (h))))
#   define GENMASK_64(h, l)    (((~UINT64_C(0)) << (l)) & (~UINT64_C(0) >> (64 - 1 - (h))))
#endif

#endif  /* !BITOPS__H__ */

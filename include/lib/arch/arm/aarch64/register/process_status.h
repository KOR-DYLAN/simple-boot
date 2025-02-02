#ifndef PROCESS_STATUS__H__
#define PROCESS_STATUS__H__


/****************************************************************************************************
 * CPSR/SPSR:           RW, 32bit, Process Status Register
 ****************************************************************************************************/
/* [31] N:                  Negative result */
#define PSR_N_SHIFT                 U(31)
#define PSR_N_MASK                  U(0x1)
#define PSR_N_BIT                   (PSR_N_MASK << PSR_N_SHIFT)
/* [30] Z:                  Zero result */
#define PSR_Z_SHIFT                 U(30)
#define PSR_Z_MASK                  U(0x1)
#define PSR_Z_BIT                   (PSR_Z_MASK << PSR_Z_SHIFT)
/* [29] C:                  Carry over */
#define PSR_C_SHIFT                 U(29)
#define PSR_C_MASK                  U(0x1)
#define PSR_C_BIT                   (PSR_C_MASK << PSR_C_SHIFT)
/* [28] V:                  Overflow */
#define PSR_V_SHIFT                 U(28)
#define PSR_V_MASK                  U(0x1)
#define PSR_V_BIT                   (PSR_V_MASK << PSR_V_SHIFT)
/* [21] SS:                 Software Step. Indicates whether software step was enabled when an exception was taken. */
#define PSR_SS_SHIFT                U(21)
#define PSR_SS_MASK                 U(0x1)
#define PSR_SS_BIT                  (PSR_SS_MASK << PSR_SS_SHIFT)
/* [20] IL:                 Illegal Execution State bit. Shows the value of PSTATE.IL immediately before the exception was taken. */
#define PSR_IL_SHIFT                U(20)
#define PSR_IL_MASK                 U(0x1)
#define PSR_IL_BIT                  (PSR_IL_MASK << PSR_IL_SHIFT)
/* [9] D:                   Debug exception mask bit. On a reset or taking an exception to AArch64 state, this bit is set to 1. */
#define PSR_D_SHIFT                 U(9)
#define PSR_D_MASK                  U(0x1)
#define PSR_D_BIT                   (PSR_D_MASK << PSR_D_SHIFT)
/* [8] A:                   SError (System Error) mask bit. */
#define PSR_A_SHIFT                 U(8)
#define PSR_A_MASK                  U(0x1)
#define PSR_A_BIT                   (PSR_A_MASK << PSR_A_SHIFT)
/* [7] I:                   IRQ mask bit. */
#define PSR_I_SHIFT                 U(7)
#define PSR_I_MASK                  U(0x1)
#define PSR_I_BIT                   (PSR_I_MASK << PSR_I_SHIFT)
/* [6] F:                   FIQ mask bit. */
#define PSR_F_SHIFT                 U(6)
#define PSR_F_MASK                  U(0x1)
#define PSR_F_BIT                   (PSR_F_MASK << PSR_F_SHIFT)
/* [4] M:                   Used to record the Execution state (0 indicates AArch64 and 1 indicates AArch32). */
#define PSR_M_ARCH_SHIFT            U(4)
#define PSR_M_ARCH_MASK             U(0x1)
#define PSR_M_ARCH_BIT              (PSR_M_ARCH_MASK << PSR_M_ARCH_SHIFT)
/* [0] M[3:0]:              Mode or Exception level that an exception was taken from. */
#define PSR_M_EL_SHIFT              U(0)
#define PSR_M_EL_MASK               U(0xf)
#define PSR_M_EL_BIT                (PSR_M_EL_MASK << PSR_M_EL_SHIFT)

/****************************************************************************************************
 * DAIF, Interrupt Mask Bits
 ****************************************************************************************************/
/* [3] D:                   Process state D mask. 
                                0   Watchpoint, Breakpoint, and Software Step exceptions targeted at the current Exception level are not masked.
                                1   Watchpoint, Breakpoint, and Software Step exceptions targeted at the current Exception level are masked.*/
#define DAIF_D_SHIFT                U(3)
#define DAIF_D_MASK                 U(0x1)
#define DAIF_D_BIT                  (DAIF_D_MASK << DAIF_D_SHIFT)

/* [2] A:                   SError exception mask bit.
                                0   Exception not masked.
                                1   Exception masked. */
#define DAIF_A_SHIFT                U(2)
#define DAIF_A_MASK                 U(0x1)
#define DAIF_A_BIT                  (DAIF_A_MASK << DAIF_A_SHIFT)

/* [1] I:                   IRQ mask bit.
                                0   Exception not masked.
                                1   Exception masked. */
#define DAIF_I_SHIFT                U(1)
#define DAIF_I_MASK                 U(0x1)
#define DAIF_I_BIT                  (DAIF_I_MASK << DAIF_I_SHIFT)

/* [0] F:                   FIQ mask bit.
                                0   Exception not masked.
                                1   Exception masked. */
#define DAIF_F_SHIFT                U(0)
#define DAIF_F_MASK                 U(0x1)
#define DAIF_F_BIT                  (DAIF_F_MASK << DAIF_F_SHIFT)


#endif  /* !PROCESS_STATUS__H__ */

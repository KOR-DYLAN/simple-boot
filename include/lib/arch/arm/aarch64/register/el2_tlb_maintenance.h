/****************************************************************************************************
 * AArch64 EL2 TLB maintenance operations
 ****************************************************************************************************/
#ifndef EL2_TLB_MAINTENANCE__H__
#define EL2_TLB_MAINTENANCE__H__

/****************************************************************************************************
 * TLBI IPAS2E1IS:
 *  Invalidate stage 2 only translations used at EL1 for the specified IPA for the current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI IPAS2LE1IS:
 *  Invalidate entries from the last level of stage 2 
 *  only translation used at EL1 for the specified IPA for the current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE2IS:
 *  Invalidate all stage 1 translations used at EL2, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE2IS:
 *  Invalidate translation used at EL2 for the specified VA and ASID and the current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE1IS:
 *  Invalidate all stage 1 translations used at EL1, Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE2IS:
 *  Invalidate all entries from the last level of stage 1 translation table walk used 
 *  at EL2 with the supplied ASID and current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VMALLS12E1IS:
 *  Invalidate all stage 1 and 2 translations used at EL1 with the current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI IPAS2E1:
 *  Invalidate stage 2 only translations used at EL1 for the specified IPA for the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI IPAS2LE1:
 *  Invalidate entries from the last level of stage 2 only translation used 
 *  at EL1 for the specified IPA for the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE2:
 *  Invalidate all stage 1 translations used at EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE2:
 *  Invalidate translation used at EL2 for the specified VA and ASID and the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE1:
 *  Invalidate all stage 1 translations used at EL1
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE2:
 *  Invalidate all entries from the last level of stage 1 translation table walk used 
 *  at EL2 with the supplied ASID and current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VMALLS12E1:
 *  Invalidate all stage 1 and 2 translations used at EL1 with the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE3IS:
 *  Invalidate all stage 1 translations used at EL3, Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE3IS:
 *  Invalidate translation used at EL3 for the specified VA and ASID and the current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE3IS:
 *  Invalidate all entries from the last level of stage 1 translation table walk used 
 *  at EL3 with the supplied ASID and current VMID, Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ALLE3:
 *  Invalidate all stage 1 translations used at EL3
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE3:
 *  Invalidate translation used at EL3 for the specified VA and ASID and the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE3:
 *  Invalidate all entries from the last level of stage 1 translation table walk used 
 *  at EL3 with the supplied ASID and current VMID
 ****************************************************************************************************/












#endif  /* !EL2_TLB_MAINTENANCE__H__ */

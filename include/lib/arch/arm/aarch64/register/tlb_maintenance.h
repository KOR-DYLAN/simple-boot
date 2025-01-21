/****************************************************************************************************
 * AArch64 TLB maintenance operations
 ****************************************************************************************************/
#ifndef TLB_MAINTENANCE__H__
#define TLB_MAINTENANCE__H__

/****************************************************************************************************
 * TLBI VMALLE1IS:
 *  Invalidate all stage 1 translations used at EL1 
 *  with the current virtual machine identifier (VMID) 
 *  in the Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE1IS:
 *  Invalidate translation used at EL1 
 *  for the specified VA and Address Space Identifier (ASID) and the current VMID,
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ASIDE1IS:
 *  Invalidate all translations used at EL1 with the current VMID and the supplied ASID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAAE1IS:
 *  Invalidate all translations used at EL1 
 *  for the specified address and current VMID and for all ASID values, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE1IS:
 *  Invalidate all entries from the last level of stage 1 translation table walk used at EL1 
 *  with the supplied ASID and current VMID, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAALE1IS:
 *  Invalidate all entries from the last level of stage 1 translation table walk used at EL1 
 *  for the specified address and current VMID and for all ASID values, 
 *  Inner Shareable
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VMALLE1:
 *  Invalidate all stage 1 translations used at EL1 with the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAE1:
 *  Invalidate translation used at EL1 for the specified VA and ASID and the current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI ASIDE1:
 *  Invalidate all translations used at EL1 with the current VMID and the supplied ASID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAAE1:
 *  Invalidate all translations used at EL1 
 *  for the specified address and current VMID and for all ASID values
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VALE1:
 *  Invalidate all entries from the last level of stage 1 translation table walk used at EL1 
 *  with the supplied ASID and current VMID
 ****************************************************************************************************/

/****************************************************************************************************
 * TLBI VAALE1:
 *  Invalidate all entries from the last level of stage 1 translation table walk used at EL1 
 *  for the specified address and current VMID and for all ASID values
 ****************************************************************************************************/

#endif  /* !TLB_MAINTENANCE__H__ */

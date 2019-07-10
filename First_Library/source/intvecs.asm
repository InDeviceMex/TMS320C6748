; * ============================================================================
; * Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006, 2007
; *
; * Use of this software is controlled by the terms and conditions found
; * in the license agreement under which this software has been supplied.
; * ============================================================================

; * ============================================================================
; * @brief Interrupt vector file for C64x and C64x+.
; *
; * @file  intvecs.asm
; *
; * @verbatim
;   This file contains interrupt service table.  The CPU interrupt 4 vector
;   contains interrupt4 function.
;   @endverbatim
; *
; * ============================================================================

; Global symbols defined here and exported out of this file
   .global INTC__vVectorTable
   .global _c_int00
   .global INTC__vNmiHandler    ;NMI
   .global INTC__vRsvd2Handler    ;RSVD
   .global INTC__vRsvd3Handler    ;RSVD
   .global INTC__vInt4Handler ;Interrupt4 ISR
   .global INTC__vInt5Handler
   .global INTC__vInt6Handler
   .global INTC__vInt7Handler
   .global INTC__vInt8Handler
   .global INTC__vInt9Handler
   .global INTC__vInt10Handler
   .global INTC__vInt11Handler
   .global INTC__vInt12Handler
   .global INTC__vInt13Handler
   .global INTC__vInt14Handler
   .global INTC__vInt15Handler


; This is a macro that instantiates one entry in the interrupt service table.
VEC_ENTRY .macro addr
    STW   B0,*--B15
    MVKL  addr,B0
    MVKH  addr,B0
    B     B0
    LDW   *B15++,B0
    NOP   2
    NOP
    NOP
   .endm

; This is a dummy interrupt service routine used to initialize the IST.
_vec_dummy:
  B    B3
  NOP  5

; This is the actual interrupt service table (IST).
 .sect ".vecs"
 .align 1024

INTC__vVectorTable:
	   VEC_ENTRY _c_int00      ;RESET
	   VEC_ENTRY INTC__vNmiHandler    ;NMI
	   VEC_ENTRY INTC__vRsvd2Handler    ;RSVD
	   VEC_ENTRY INTC__vRsvd3Handler    ;RSVD
	   VEC_ENTRY INTC__vInt4Handler ;Interrupt4 ISR
	   VEC_ENTRY INTC__vInt5Handler
	   VEC_ENTRY INTC__vInt6Handler
	   VEC_ENTRY INTC__vInt7Handler
	   VEC_ENTRY INTC__vInt8Handler
	   VEC_ENTRY INTC__vInt9Handler
	   VEC_ENTRY INTC__vInt10Handler
	   VEC_ENTRY INTC__vInt11Handler
	   VEC_ENTRY INTC__vInt12Handler
	   VEC_ENTRY INTC__vInt13Handler
	   VEC_ENTRY INTC__vInt14Handler
	   VEC_ENTRY INTC__vInt15Handler


;* =============================================================================
;*   Automated Revision Information
;*   Changed: $Date: 2007-09-11 11:05:40 -0500 (Tue, 11 Sep 2007) $
;*   Revision: $Revision: 3960 $
;* =============================================================================



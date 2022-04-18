	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
Lloh0:
	adrp	x0, l_.str@PAGE
Lloh1:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	sub	x8, x29, #4                     ; =4
	str	x8, [sp]
Lloh2:
	adrp	x0, l_.str.1@PAGE
Lloh3:
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_scanf
	ldur	w8, [x29, #-4]
	cmp	w8, #1                          ; =1
	b.lt	LBB0_7
; %bb.1:
	mov	w9, #0
	mov	w10, #52429
	movk	w10, #52428, lsl #16
	mov	w11, #10
	mov	x12, x8
LBB0_2:                                 ; =>This Inner Loop Header: Depth=1
	umull	x13, w12, w10
	lsr	x13, x13, #35
	msub	w14, w13, w11, w12
	add	w9, w14, w9
	cmp	w12, #9                         ; =9
	mov	x12, x13
	b.hi	LBB0_2
; %bb.3:
	sdiv	w10, w8, w9
	msub	w10, w10, w9, w8
	cbz	w10, LBB0_9
; %bb.4:
	cmp	w8, #1                          ; =1
	b.lt	LBB0_7
; %bb.5:
	mov	w9, #0
	mov	w10, #52429
	movk	w10, #52428, lsl #16
	mov	w11, #10
LBB0_6:                                 ; =>This Inner Loop Header: Depth=1
	umull	x12, w8, w10
	lsr	x12, x12, #35
	msub	w13, w12, w11, w8
	sbfx	w14, w13, #0, #1
	and	w13, w14, w13
	add	w9, w13, w9
	cmp	w8, #9                          ; =9
	mov	x8, x12
	b.hi	LBB0_6
	b	LBB0_8
LBB0_7:
	mov	w9, #0
LBB0_8:
	str	x9, [sp]
Lloh4:
	adrp	x0, l_.str.3@PAGE
Lloh5:
	add	x0, x0, l_.str.3@PAGEOFF
	b	LBB0_10
LBB0_9:
	str	x9, [sp]
Lloh6:
	adrp	x0, l_.str.2@PAGE
Lloh7:
	add	x0, x0, l_.str.2@PAGEOFF
LBB0_10:
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpAdd	Lloh0, Lloh1
	.loh AdrpAdd	Lloh4, Lloh5
	.loh AdrpAdd	Lloh6, Lloh7
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Enter the number : "

l_.str.1:                               ; @.str.1
	.asciz	"%d"

l_.str.2:                               ; @.str.2
	.asciz	"Sum of digits of number is : %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"Odd digit sum is : %d"

.subsections_via_symbols

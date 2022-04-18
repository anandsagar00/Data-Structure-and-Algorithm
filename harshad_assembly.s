	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64                     ; =64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48                    ; =48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	mov	x9, sp
	sub	x8, x29, #8                     ; =8
	str	x8, [x9]
	bl	_scanf
	ldur	w8, [x29, #-8]
	stur	w8, [x29, #-12]
	stur	wzr, [x29, #-16]
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #0                      ; =0
	b.le	LBB0_3
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-16]
	ldur	w10, [x29, #-12]
	mov	w9, #10
	sdiv	w11, w10, w9
	mul	w11, w11, w9
	subs	w10, w10, w11
	add	w8, w8, w10
	stur	w8, [x29, #-16]
	ldur	w8, [x29, #-12]
	sdiv	w8, w8, w9
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_3:
	ldur	w8, [x29, #-8]
	ldur	w10, [x29, #-16]
	sdiv	w9, w8, w10
	mul	w9, w9, w10
	subs	w8, w8, w9
	cbnz	w8, LBB0_5
; %bb.4:
	ldur	w9, [x29, #-16]
                                        ; implicit-def: $x8
	mov	x8, x9
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	mov	x9, sp
	str	x8, [x9]
	bl	_printf
	b	LBB0_11
LBB0_5:
	ldur	w8, [x29, #-8]
	stur	w8, [x29, #-20]
	mov	w8, #1
	str	w8, [sp, #24]
	str	wzr, [sp, #20]
LBB0_6:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-20]
	subs	w8, w8, #0                      ; =0
	b.le	LBB0_10
; %bb.7:                                ;   in Loop: Header=BB0_6 Depth=1
	ldur	w8, [x29, #-20]
	mov	w10, #10
	sdiv	w9, w8, w10
	mul	w9, w9, w10
	subs	w8, w8, w9
	str	w8, [sp, #16]
	ldr	w8, [sp, #16]
	mov	w10, #2
	sdiv	w9, w8, w10
	mul	w9, w9, w10
	subs	w8, w8, w9
	subs	w8, w8, #1                      ; =1
	b.ne	LBB0_9
; %bb.8:                                ;   in Loop: Header=BB0_6 Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #16]
	add	w8, w8, w9
	str	w8, [sp, #20]
LBB0_9:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldur	w8, [x29, #-20]
	mov	w9, #10
	sdiv	w8, w8, w9
	stur	w8, [x29, #-20]
	b	LBB0_6
LBB0_10:
	ldr	w9, [sp, #20]
                                        ; implicit-def: $x8
	mov	x8, x9
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	mov	x9, sp
	str	x8, [x9]
	bl	_printf
LBB0_11:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64                     ; =64
	ret
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

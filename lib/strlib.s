	.file	"strlib.c"
	.intel_syntax noprefix
	.text
	.globl	str_concat
	.type	str_concat, @function
str_concat:
.LFB2:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [ebp-20], 0
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ebp-16], eax
	cmp	DWORD PTR [ebp-16], 0
	jne	.L2
	mov	DWORD PTR [ebp-20], 1
	jmp	.L3
.L2:
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax+8]
	test	eax, eax
	je	.L8
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-16], eax
	jmp	.L2
.L8:
	nop
.L3:
	sub	esp, 12
	push	12
	call	malloc
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [eax+12]
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+8], edx
	mov	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [eax+8]
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+4], edx
	mov	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [eax]
	mov	eax, DWORD PTR [ebp+12]
	mov	eax, DWORD PTR [eax]
	add	edx, eax
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax], edx
	cmp	DWORD PTR [ebp-20], 0
	je	.L5
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+12], edx
	jmp	.L6
.L5:
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+8], edx
.L6:
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [eax+12], 0
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [eax+8], 0
	sub	esp, 12
	push	DWORD PTR [ebp+12]
	call	free
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	str_concat, .-str_concat
	.section	.rodata
.LC0:
	.string	""
	.text
	.globl	str_concat_new
	.type	str_concat_new, @function
str_concat_new:
.LFB3:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	sub	esp, 12
	push	OFFSET FLAT:.LC0
	call	str_debug_set
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	sub	esp, 8
	push	DWORD PTR [ebp+8]
	push	DWORD PTR [ebp-12]
	call	str_concat
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	sub	esp, 8
	push	DWORD PTR [ebp+12]
	push	DWORD PTR [ebp-12]
	call	str_concat
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	sub	esp, 12
	push	DWORD PTR [ebp+8]
	call	str_free
	add	esp, 16
	mov	eax, DWORD PTR [ebp-12]
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	str_concat_new, .-str_concat_new
	.globl	ilog10c
	.type	ilog10c, @function
ilog10c:
.LFB4:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	ebx
	sub	esp, 28
	.cfi_offset 3, -12
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-32], eax
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [ebp-28], eax
	mov	eax, DWORD PTR [ebp-32]
	mov	edx, DWORD PTR [ebp-28]
	test	edx, edx
	je	.L12
	bsr	eax, edx
	xor	eax, 31
	jmp	.L13
.L12:
	bsr	eax, eax
	xor	eax, 31
	add	eax, 32
.L13:
	cdq
	mov	DWORD PTR [ebp-16], eax
	mov	DWORD PTR [ebp-12], edx
	mov	eax, DWORD PTR [ebp-12]
	imul	edx, eax, -77
	mov	eax, DWORD PTR [ebp-16]
	imul	eax, eax, -1
	lea	ecx, [edx+eax]
	mov	eax, -77
	mul	DWORD PTR [ebp-16]
	add	ecx, edx
	mov	edx, ecx
	add	eax, 4851
	adc	edx, 0
	shrd	eax, edx, 8
	shr	edx, 8
	mov	ecx, eax
	mov	ebx, edx
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR thr.2666[4+eax*8]
	mov	eax, DWORD PTR thr.2666[0+eax*8]
	or	eax, edx
	test	eax, eax
	je	.L14
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR thr.2666[4+eax*8]
	mov	eax, DWORD PTR thr.2666[0+eax*8]
	cmp	edx, DWORD PTR [ebp-28]
	ja	.L14
	cmp	edx, DWORD PTR [ebp-28]
	jb	.L18
	cmp	eax, DWORD PTR [ebp-32]
	ja	.L14
.L18:
	mov	eax, 1
	jmp	.L16
.L14:
	mov	eax, 0
.L16:
	cdq
	add	eax, ecx
	adc	edx, ebx
	add	esp, 28
	pop	ebx
	.cfi_restore 3
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	ilog10c, .-ilog10c
	.section	.rodata
.LC1:
	.string	"0"
	.globl	__moddi3
	.globl	__divdi3
	.text
	.globl	str_concat_str_i64
	.type	str_concat_str_i64, @function
str_concat_str_i64:
.LFB5:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 88
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-76], eax
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [ebp-88], eax
	mov	eax, DWORD PTR [ebp+16]
	mov	DWORD PTR [ebp-84], eax
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	mov	eax, DWORD PTR [ebp-84]
	or	eax, DWORD PTR [ebp-88]
	test	eax, eax
	jne	.L20
	sub	esp, 12
	push	OFFSET FLAT:.LC1
	call	str_debug_set
	add	esp, 16
	sub	esp, 8
	push	eax
	push	DWORD PTR [ebp-76]
	call	str_concat
	add	esp, 16
	jmp	.L26
.L20:
	mov	BYTE PTR [ebp-33], 45
	mov	eax, DWORD PTR [ebp-88]
	mov	edx, DWORD PTR [ebp-84]
	mov	DWORD PTR [ebp-48], eax
	mov	DWORD PTR [ebp-44], edx
	mov	eax, DWORD PTR [ebp-48]
	mov	edx, DWORD PTR [ebp-44]
	mov	edx, edx
	sar	edx, 31
	mov	eax, edx
	xor	DWORD PTR [ebp-48], eax
	xor	DWORD PTR [ebp-44], edx
	sub	DWORD PTR [ebp-48], eax
	sbb	DWORD PTR [ebp-44], edx
	mov	eax, DWORD PTR [ebp-48]
	mov	edx, DWORD PTR [ebp-44]
	sub	esp, 8
	push	edx
	push	eax
	call	ilog10c
	add	esp, 16
	add	eax, 1
	mov	DWORD PTR [ebp-52], eax
	mov	DWORD PTR [ebp-60], 0
	jmp	.L22
.L25:
	mov	eax, DWORD PTR [ebp-52]
	sub	eax, DWORD PTR [ebp-60]
	mov	DWORD PTR [ebp-56], eax
	cmp	DWORD PTR [ebp-84], 0
	js	.L23
	cmp	DWORD PTR [ebp-84], 0
	jg	.L28
	cmp	DWORD PTR [ebp-88], 0
	jbe	.L23
.L28:
	sub	DWORD PTR [ebp-56], 1
.L23:
	mov	eax, DWORD PTR [ebp-48]
	mov	edx, DWORD PTR [ebp-44]
	push	0
	push	10
	push	edx
	push	eax
	call	__moddi3
	add	esp, 16
	add	eax, 48
	mov	ecx, eax
	lea	edx, [ebp-33]
	mov	eax, DWORD PTR [ebp-56]
	add	eax, edx
	mov	BYTE PTR [eax], cl
	add	DWORD PTR [ebp-60], 1
	mov	eax, DWORD PTR [ebp-48]
	mov	edx, DWORD PTR [ebp-44]
	push	0
	push	10
	push	edx
	push	eax
	call	__divdi3
	add	esp, 16
	mov	DWORD PTR [ebp-48], eax
	mov	DWORD PTR [ebp-44], edx
.L22:
	mov	eax, DWORD PTR [ebp-44]
	or	eax, DWORD PTR [ebp-48]
	test	eax, eax
	jne	.L25
	sub	esp, 12
	lea	eax, [ebp-33]
	push	eax
	call	str_debug_set
	add	esp, 16
	sub	esp, 8
	push	eax
	push	DWORD PTR [ebp-76]
	call	str_concat
	add	esp, 16
.L26:
	mov	edx, DWORD PTR [ebp-12]
	xor	edx, DWORD PTR gs:20
	je	.L27
	call	__stack_chk_fail
.L27:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	str_concat_str_i64, .-str_concat_str_i64
	.globl	str_substr
	.type	str_substr, @function
str_substr:
.LFB6:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	nop
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	str_substr, .-str_substr
	.globl	str_tail_free
	.type	str_tail_free, @function
str_tail_free:
.LFB7:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+8]
	test	eax, eax
	je	.L31
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+8]
	sub	esp, 12
	push	eax
	call	str_tail_free
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+8], 0
.L31:
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+4]
	sub	esp, 12
	push	eax
	call	free
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+4], 0
	sub	esp, 12
	push	DWORD PTR [ebp+8]
	call	free
	add	esp, 16
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	str_tail_free, .-str_tail_free
	.globl	str_free
	.type	str_free, @function
str_free:
.LFB8:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 8
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	test	eax, eax
	je	.L33
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	sub	esp, 12
	push	eax
	call	str_tail_free
	add	esp, 16
.L33:
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+8]
	sub	esp, 12
	push	eax
	call	free
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+8], 0
	sub	esp, 12
	push	DWORD PTR [ebp+8]
	call	free
	add	esp, 16
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	str_free, .-str_free
	.section	.rodata
.LC2:
	.string	"%.*s"
	.text
	.globl	str_print
	.type	str_print, @function
str_print:
.LFB9:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [eax+8]
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+4]
	sub	esp, 4
	push	edx
	push	eax
	push	OFFSET FLAT:.LC2
	call	printf
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ebp-12], eax
.L37:
	cmp	DWORD PTR [ebp-12], 0
	je	.L39
	mov	eax, DWORD PTR [ebp-12]
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax]
	sub	esp, 4
	push	edx
	push	eax
	push	OFFSET FLAT:.LC2
	call	printf
	add	esp, 16
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-12], eax
	jmp	.L37
.L39:
	nop
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE9:
	.size	str_print, .-str_print
	.globl	str_len
	.type	str_len, @function
str_len:
.LFB10:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax]
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE10:
	.size	str_len, .-str_len
	.globl	str_defrag
	.type	str_defrag, @function
str_defrag:
.LFB11:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	test	eax, eax
	jne	.L43
	mov	eax, DWORD PTR [ebp+8]
	jmp	.L44
.L43:
	push	DWORD PTR [ebp+8]
	call	str_len
	add	esp, 4
	sub	esp, 12
	push	eax
	call	malloc
	add	esp, 16
	mov	DWORD PTR [ebp-16], eax
	mov	DWORD PTR [ebp-28], 0
	mov	DWORD PTR [ebp-28], 0
	jmp	.L45
.L46:
	mov	edx, DWORD PTR [ebp-28]
	mov	eax, DWORD PTR [ebp-16]
	add	edx, eax
	mov	eax, DWORD PTR [ebp+8]
	mov	ecx, DWORD PTR [eax+8]
	mov	eax, DWORD PTR [ebp-28]
	add	eax, ecx
	movzx	eax, BYTE PTR [eax]
	mov	BYTE PTR [edx], al
	add	DWORD PTR [ebp-28], 1
.L45:
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [ebp-28]
	cmp	edx, eax
	ja	.L46
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+8]
	sub	esp, 12
	push	eax
	call	free
	add	esp, 16
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ebp-24], eax
	mov	DWORD PTR [ebp-20], 0
.L51:
	mov	DWORD PTR [ebp-20], 0
	jmp	.L47
.L48:
	mov	eax, DWORD PTR [ebp-28]
	lea	edx, [eax+1]
	mov	DWORD PTR [ebp-28], edx
	mov	edx, eax
	mov	eax, DWORD PTR [ebp-16]
	add	edx, eax
	mov	eax, DWORD PTR [ebp-24]
	mov	ecx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [ebp-20]
	add	eax, ecx
	movzx	eax, BYTE PTR [eax]
	mov	BYTE PTR [edx], al
	add	DWORD PTR [ebp-20], 1
.L47:
	mov	eax, DWORD PTR [ebp-24]
	mov	edx, DWORD PTR [eax]
	mov	eax, DWORD PTR [ebp-20]
	cmp	edx, eax
	ja	.L48
	mov	eax, DWORD PTR [ebp-24]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-24]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [ebp-24], eax
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+8], 0
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [eax+4]
	sub	esp, 12
	push	eax
	call	free
	add	esp, 16
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+4], 0
	sub	esp, 12
	push	DWORD PTR [ebp-12]
	call	free
	add	esp, 16
	cmp	DWORD PTR [ebp-24], 0
	je	.L53
	jmp	.L51
.L53:
	nop
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+12], 0
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [ebp-16]
	mov	DWORD PTR [eax+8], edx
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [eax]
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax+4], edx
	mov	eax, DWORD PTR [ebp+8]
.L44:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	str_defrag, .-str_defrag
	.globl	str_debug_set
	.type	str_debug_set, @function
str_debug_set:
.LFB12:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	sub	esp, 12
	push	16
	call	malloc
	add	esp, 16
	mov	DWORD PTR [ebp-16], eax
	sub	esp, 12
	push	DWORD PTR [ebp+8]
	call	strlen
	add	esp, 16
	mov	edx, eax
	mov	eax, DWORD PTR [ebp-16]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR [eax]
	mov	eax, DWORD PTR [ebp-16]
	mov	DWORD PTR [eax+4], edx
	mov	eax, DWORD PTR [ebp-16]
	mov	DWORD PTR [eax+12], 0
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax]
	sub	esp, 12
	push	eax
	call	malloc
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-16]
	mov	eax, DWORD PTR [eax]
	sub	esp, 4
	push	eax
	push	DWORD PTR [ebp+8]
	push	DWORD PTR [ebp-12]
	call	memcpy
	add	esp, 16
	mov	eax, DWORD PTR [ebp-16]
	mov	edx, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+8], edx
	mov	eax, DWORD PTR [ebp-16]
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE12:
	.size	str_debug_set, .-str_debug_set
	.section	.rodata
.LC3:
	.string	"Hello world!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	lea	ecx, [esp+4]
	.cfi_def_cfa 1, 0
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	mov	ebp, esp
	push	ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	sub	esp, 20
	sub	esp, 12
	push	OFFSET FLAT:.LC3
	call	str_debug_set
	add	esp, 16
	mov	DWORD PTR [ebp-12], eax
	sub	esp, 12
	push	10
	call	putchar
	add	esp, 16
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-4]
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	lea	esp, [ecx-4]
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.rodata
	.align 32
	.type	thr.2666, @object
	.size	thr.2666, 512
thr.2666:
	.long	-1981284352
	.long	-1966660860
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	-1486618624
	.long	232830643
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1569325056
	.long	23283064
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1874919424
	.long	2328306
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	-1530494976
	.long	232830
	.long	0
	.long	0
	.long	0
	.long	0
	.long	276447232
	.long	23283
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1316134912
	.long	2328
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	-727379968
	.long	232
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1215752192
	.long	23
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1410065408
	.long	2
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1000000000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	100000000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	10000000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1000000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	100000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	10000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1000
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	100
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	10
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

	.file	"lltest.c"
	.intel_syntax noprefix
	.text
	.globl	Add
	.type	Add, @function
Add:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-40], rdi
	mov	DWORD PTR [rbp-44], esi
	mov	edi, 16
	call	malloc
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	edx, DWORD PTR [rbp-44]
	mov	DWORD PTR [rax+8], edx
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax], 0
	mov	rax, QWORD PTR [rbp-40]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	jne	.L2
	mov	rax, QWORD PTR [rbp-40]
	mov	rdx, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax], rdx
	jmp	.L3
.L2:
	mov	rax, QWORD PTR [rbp-40]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rbp-24], rax
	mov	QWORD PTR [rbp-16], 0
	jmp	.L4
.L5:
	mov	rax, QWORD PTR [rbp-24]
	mov	QWORD PTR [rbp-16], rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rbp-24], rax
.L4:
	cmp	QWORD PTR [rbp-24], 0
	jne	.L5
	mov	rax, QWORD PTR [rbp-16]
	mov	rdx, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax], rdx
.L3:
	mov	rax, QWORD PTR [rbp-40]
	mov	eax, DWORD PTR [rax+8]
	lea	edx, [rax+1]
	mov	rax, QWORD PTR [rbp-40]
	mov	DWORD PTR [rax+8], edx
	mov	rax, QWORD PTR [rbp-40]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	Add, .-Add
	.globl	Get
	.type	Get, @function
Get:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-24], rdi
	mov	DWORD PTR [rbp-28], esi
	cmp	DWORD PTR [rbp-28], 0
	jne	.L8
	mov	rax, QWORD PTR [rbp-24]
	mov	eax, DWORD PTR [rax+12]
	jmp	.L7
.L8:
	mov	rax, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rbp-8], rax
	mov	DWORD PTR [rbp-12], 0
	jmp	.L10
.L12:
	mov	eax, DWORD PTR [rbp-12]
	cmp	eax, DWORD PTR [rbp-28]
	jne	.L11
	mov	rax, QWORD PTR [rbp-8]
	mov	eax, DWORD PTR [rax+8]
	jmp	.L7
.L11:
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rbp-8], rax
	add	DWORD PTR [rbp-12], 1
.L10:
	cmp	QWORD PTR [rbp-8], 0
	jne	.L12
.L7:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	Get, .-Get
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	DWORD PTR [rbp-20], edi
	mov	QWORD PTR [rbp-32], rsi
	mov	edi, 16
	call	malloc
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 1
	mov	rdi, rax
	call	Add
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 2
	mov	rdi, rax
	call	Add
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 3
	mov	rdi, rax
	call	Add
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 4
	mov	rdi, rax
	call	Add
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 5
	mov	rdi, rax
	call	Add
	mov	QWORD PTR [rbp-8], rax
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 3
	mov	rdi, rax
	call	Get
	mov	DWORD PTR [rbp-12], eax
	mov	eax, DWORD PTR [rbp-12]
	mov	esi, eax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

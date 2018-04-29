[BITS 32]

global main
extern puts

section .bss
	var_i:		RESW	1
	var_j:		RESW	1
	var_nl0:		RESW	1
	var_nl1:		RESW	1
	var_nl2:		RESW	1
	var_re:		RESW	1
	var_nx:		RESW	1
	var_py:		RESW	1
	var_yy:		RESW	1
	var_pt:		RESW	1
	var_test:		RESW	1
	ITR0000:		RESW	1
	ITR0001:		RESW	1
	ITR0002:		RESW	1
	ITR0003:		RESW	1
	TMP0000:		RESW	1
	TMP0001:		RESW	1
	TMP0002:		RESW	1
	TMP0003:		RESW	1

section .data
	STR0001:		DB	"hello world",0
	STR0000:		DB	"\n",0

section .text

main:
	mov eax, 10
	mov ebx, 30
	add eax, ebx
	mov [var_i], eax
	mov eax, 20
	mov ebx, 40
	imul eax, ebx
	mov [var_j], eax
	mov eax, STR0000
	mov [var_nl0], eax
	mov eax, STR0000
	mov [var_nl1], eax
	mov eax, STR0000
	mov [var_nl2], eax
	call all
	mov ebx, eax
	call part2
	mov edx, eax ; it
	mov eax, ebx

func1:		; all
	push ebp
	mov ebp, esp
	and esp, 0FFFFFFF0H;
	mov eax, 10
	mov [var_re], eax
	mov eax, [var_re]
	mov ebx, 20
	add eax, ebx
	mov [var_nx], eax
	mov eax, [var_nx]
	mov ebx, [var_re]
	add eax, ebx
	mov [var_py], eax
	mov eax, [var_re]
	mov ebx, 40
	add eax, ebx
	mov [var_yy], eax
	mov eax, [var_re]
	mov ebx, [var_nx]
	mov edx, [var_py]
	imul ebx, edx
	mov edx, [var_yy]
	imul ebx, edx
	add eax, ebx
	mov [var_pt], eax
	mov esp, ebp
	pop ebp
	ret

func2:		; part2
	push ebp
	mov ebp, esp
	and esp, 0FFFFFFF0H;
	mov eax, 0
	mov [var_i], eax
	mov ecx, [ITR0000]
	mov eax, [ITR0001]
	cmp ecx, eax
	jge blockend3
block3:
	mov ecx, [ITR000]
	mov ecx, [ITR0002]
	mov eax, [ITR0003]
	cmp ecx, eax
	jge blockend4
block4:
	mov ecx, [ITR002]
	mov eax, [var_q]
	mov ebx, [var_t]
	imul eax, ebx
	mov [var_i], eax
	inc ecx
	mov [ITR0002], ecx
	mov eax, [ITR0003]
	cmp ecx, eax
	jl block4
blockend4:
	inc ecx
	mov [ITR0000], ecx
	mov eax, [ITR0001]
	cmp ecx, eax
	jl block3
blockend3:
	mov esp, ebp
	pop ebp
	ret

func5:		; hi
	push ebp
	mov ebp, esp
	and esp, 0FFFFFFF0H;
	mov eax, 6
	mov ebx, 10
	mov edx, 32
	imul ebx, edx
	add eax, ebx
	mov ebx, 4
	mov edx, 2
	mov [TMP0000], eax
	mov eax, ebx
	idiv edx
	mov ebx, eax
	mov eax, [TMP0000]
	add eax, ebx
	mov ebx, 1
	add eax, ebx
	mov [var_test], eax
	mov eax, 2
	mov [var_test], eax
	mov ebx, STR0001
	push ebx
	mov ebx, eax
	call puts
	mov edx, eax ; it
	mov eax, ebx
	mov esp, ebp
	pop ebp
	ret

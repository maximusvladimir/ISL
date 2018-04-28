[BITS 32]
STR0001 DB "hello",0
STR0000 DB "hello world",0
iter000		dd	0

:main
	mov r0, 10
	mov r1, 30
	mov eax, r0
	mov edx, r1
	add edx
	mov r2, edx
	mov [3], r2			; [3] = i
	mov r4, 20
	mov r5, 40
	mov eax, r4
	mov edx, r5
	mul edx
	mov r6, edx
	mov [7], r6			; [7] = j
	mov r8, 6
	mov eax, r999999999
	mov edx, r8
	add edx
	mov r9, edx
	push r9
	call sin
	mov r10, eax			; sin ret
	mov r11, 2
	push r11
	call cos
	mov r12, eax			; cos ret
	mov eax, r10
	mov edx, r12
	add edx
	mov r13, edx
	mov [14], r13			; [14] = k
	call part2

:func1
	mov r0, 2
	mov r1, 5
	mov r2, 10
	mov eax, r1
	mov edx, r2
	mul edx
	mov r3, edx
	mov eax, r0
	mov edx, r3
	add edx
	mov r4, edx
	push r4
	call printf
	mov r5, 10
	push r5
	call printf
	mov iter000, 0
:block2
	push r999999999
	call printf
	mov eax, 0
	inc iter000
	je block2
; end block 2
	ret

:func3
	mov r0, 6
	mov r1, 10
	mov r2, 32
	mov eax, r1
	mov edx, r2
	mul edx
	mov r3, edx
	mov eax, r0
	mov edx, r3
	add edx
	mov r4, edx
	mov r5, 4
	mov r6, 2
	mov eax, r5
	mov edx, r6
	div edx
	mov r7, edx
	mov eax, r4
	mov edx, r7
	add edx
	mov r8, edx
	mov r9, 1
	mov eax, r8
	mov edx, r9
	add edx
	mov r10, edx
	mov [11], r10			; [11] = test
	mov r12, 2
	mov [13], r12			; [13] = test
	mov r14, STR0000
	push r14
	call printf
	mov r15, STR0001
	mov [16], r15			; [16] = hw
	push r999999999
	call printf
	ret

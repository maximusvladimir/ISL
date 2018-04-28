[BITS 32]
str0001:		DB	"hello",0
str0000:		DB	"hello world",0
itr0000:		resw	1
itr0001:		resw	1
itr0002:		resw	1
itr0003:		resw	1
i320000:		resw	1
i320001:		resw	1
i320002:		resw	1
i320003:		resw	1

:main
	mov ???, 10
	mov ???, 30
	mov eax, r-1
	mov edx, r-1
	add edx
	mov r0, edx
	mov [i320000], r0			; [0] = i
	mov ???, 20
	mov ???, 40
	mov eax, r-1
	mov edx, r-1
	mul edx
	mov r1, edx
	mov [i320001], r1			; [1] = j
	mov ???, 6
	mov eax, r999999999
	mov edx, r-1
	add edx
	mov r2, edx
	push r2
	call sin
	mov r3, eax			; sin ret
	mov ???, 2
	push r-1
	call cos
	mov r4, eax			; cos ret
	mov eax, r3
	mov edx, r4
	add edx
	mov r5, edx
	mov [i320002], r5			; [2] = k
	call part2

:func1
	mov eax, 2
	mov ebx, 5
	mov ???, 10
	mov eax, r-3
	mov edx, r-1
	mul edx
	mov r0, edx
	mov edx, r0
	add edx
	mov r1, edx
	push r1
	call printf
	mov ???, 10
	push r-1
	call printf
	mov ecx, [itr0000]
	mov eax, [itr0001]
	cmp ecx, eax
	jge blockend2
:block2
	mov ecx, [iter000]
	push r999999999
	call printf
	mov ecx, [itr0002]
	mov eax, [itr0003]
	cmp ecx, eax
	jge blockend3
:block3
	mov ecx, [iter002]
	mov eax, r999999999
	mov edx, r999999999
	mul edx
	mov r0, edx
	push r0
	call printf
	inc ecx
	mov [itr0002], ecx
	mov eax, [itr0003]
	cmp ecx, eax
	jl block3
:blockend3
	inc ecx
	mov [itr0000], ecx
	mov eax, [itr0001]
	cmp ecx, eax
	jl block2
:blockend2
	ret

:func4
	mov eax, 6
	mov ebx, 10
	mov ???, 32
	mov eax, r-3
	mov edx, r-1
	mul edx
	mov r0, edx
	mov edx, r0
	add edx
	mov r1, edx
	mov ???, 4
	mov ???, 2
	mov eax, r-1
	mov edx, r-1
	div edx
	mov r2, edx
	mov eax, r1
	mov edx, r2
	add edx
	mov r3, edx
	mov ???, 1
	mov eax, r3
	mov edx, r-1
	add edx
	mov r4, edx
	mov [i320003], r4			; [3] = test
	mov ???, 2
	mov [5], r-1			; [5] = test
	mov r6, STR0000
	push r6
	call printf
	mov r7, STR0001
	mov [i32999999999], r7			; [999999999] = hw
	push r999999999
	call printf
	ret

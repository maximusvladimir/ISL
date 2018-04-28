[BITS 32]
i:		RESW	1
j:		RESW	1
k:		RESW	1
re:		RESW	1
nx:		RESW	1
py:		RESW	1
yy:		RESW	1
pt:		RESW	1
test:		RESW	1
str0001:		DB	"hello",0
str0000:		DB	"hello world",0
ITR0000:		RESW	1
ITR0001:		RESW	1
ITR0002:		RESW	1
ITR0003:		RESW	1
TMP0000:		RESW	1
TMP0001:		RESW	1
TMP0002:		RESW	1
TMP0003:		RESW	1

:main
	mov ???, 10
	mov ???, 30
	add ???, ???
	mov [i], ???
	mov ???, 20
	mov ???, 40
	imul ???, ???
	mov [j], ???
	mov ???, [j]
	mov ???, 6
	add ???, ???
	push ???
	call sin
	mov r0, eax			; sin ret
	mov ???, 2
	push ???
	call cos
	mov r1, eax			; cos ret
	add ???, ???
	mov [k], ???
	call part2

:func1		; all
	mov eax, 10
	mov [re], eax
	mov eax, [re]
	mov ebx, 20
	add eax, ebx
	mov [nx], eax
	mov eax, [nx]
	mov ebx, [re]
	add eax, ebx
	mov [py], eax
	mov eax, [re]
	mov ebx, 40
	add eax, ebx
	mov [yy], eax
	mov eax, [re]
	mov ebx, [nx]
	mov edx, [py]
	imul ebx, edx
	mov edx, [yy]
	imul ebx, edx
	add eax, ebx
	mov [pt], eax
	ret

:func2		; part2
	mov eax, 2
	mov ebx, 5
	mov edx, 10
	imul ebx, edx
	add eax, ebx
	push eax
	call printf
	mov ebx, 10
	push ebx
	call printf
	mov ecx, [itr0000]
	mov eax, [itr0001]
	cmp ecx, eax
	jge blockend3
:block3
	mov ecx, [iter000]
	mov eax, [q]
	push eax
	call printf
	mov ecx, [itr0002]
	mov eax, [itr0003]
	cmp ecx, eax
	jge blockend4
:block4
	mov ecx, [iter002]
	mov eax, [q]
	mov ebx, [t]
	imul eax, ebx
	push eax
	call printf
	inc ecx
	mov [itr0002], ecx
	mov eax, [itr0003]
	cmp ecx, eax
	jl block4
:blockend4
	inc ecx
	mov [itr0000], ecx
	mov eax, [itr0001]
	cmp ecx, eax
	jl block3
:blockend3
	ret

:func5		; hi
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
	mov [test], eax
	mov eax, 2
	mov [0], r-2			; [0] = test
	mov r1, STR0000
	push ???
	call printf
	mov r2, STR0001
	mov [hw], ???
	mov ebx, [hw]
	push ebx
	call printf
	ret

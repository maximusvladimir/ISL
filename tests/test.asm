; Disassembly of file: test.o
; Sat Apr 28 19:06:10 2018
; Mode: 32 bits
; Syntax: YASM/NASM
; Instruction set: 80386


global call: function
global main: function

extern puts                                             ; near
extern dum                                              ; near


SECTION .text   align=1 execute                         ; section number 1, code

call:   ; Function begin
        push    ebp                                     ; 0000 _ 55
        mov     ebp, esp                                ; 0001 _ 89. E5
        sub     esp, 8                                  ; 0003 _ 83. EC, 08
        call    dum                                     ; 0006 _ E8, FFFFFFFC(rel)
        sub     esp, 12                                 ; 000B _ 83. EC, 0C
        push    ?_001                                   ; 000E _ 68, 00000000(d)
        call    puts                                    ; 0013 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0018 _ 83. C4, 10
        nop                                             ; 001B _ 90
        leave                                           ; 001C _ C9
        ret                                             ; 001D _ C3
; call End of function

main:   ; Function begin
        lea     ecx, [esp+4H]                           ; 001E _ 8D. 4C 24, 04
        and     esp, 0FFFFFFF0H                         ; 0022 _ 83. E4, F0
        push    dword [ecx-4H]                          ; 0025 _ FF. 71, FC
        push    ebp                                     ; 0028 _ 55
        mov     ebp, esp                                ; 0029 _ 89. E5
        push    ecx                                     ; 002B _ 51
        sub     esp, 4                                  ; 002C _ 83. EC, 04
        call    call                                    ; 002F _ E8, FFFFFFFC(rel)
        mov     eax, 0                                  ; 0034 _ B8, 00000000
        add     esp, 4                                  ; 0039 _ 83. C4, 04
        pop     ecx                                     ; 003C _ 59
        pop     ebp                                     ; 003D _ 5D
        lea     esp, [ecx-4H]                           ; 003E _ 8D. 61, FC
        ret                                             ; 0041 _ C3
; main End of function


SECTION .data   align=1 noexecute                       ; section number 2, data


SECTION .bss    align=1 noexecute                       ; section number 3, bss


SECTION .rodata align=1 noexecute                       ; section number 4, const

?_001:                                                  ; byte
        db 68H, 65H, 6CH, 6CH, 6FH, 20H, 77H, 6FH       ; 0000 _ hello wo
        db 72H, 6CH, 64H, 00H                           ; 0008 _ rld.



; Disassembly of file: strlib.o
; Sat Apr 28 18:22:06 2018
; Mode: 32 bits
; Syntax: YASM/NASM
; Instruction set: 80386


global str_concat: function
global str_concat_new: function
global ilog10c: function
global str_concat_str_i64: function
global str_substr: function
global str_tail_free: function
global str_free: function
global str_print: function
global str_len: function
global str_defrag: function
global str_debug_set: function
global main: function

extern putchar                                          ; near
extern memcpy                                           ; near
extern strlen                                           ; near
extern printf                                           ; near
extern __stack_chk_fail                                 ; near
extern __divdi3                                         ; near
extern __moddi3                                         ; near
extern free                                             ; near
extern malloc                                           ; near


SECTION .text   align=1 execute                         ; section number 1, code

str_concat:; Function begin
        push    ebp                                     ; 0000 _ 55
        mov     ebp, esp                                ; 0001 _ 89. E5
        sub     esp, 24                                 ; 0003 _ 83. EC, 18
        mov     dword [ebp-14H], 0                      ; 0006 _ C7. 45, EC, 00000000
        mov     eax, dword [ebp+8H]                     ; 000D _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 0010 _ 8B. 40, 0C
        mov     dword [ebp-10H], eax                    ; 0013 _ 89. 45, F0
        cmp     dword [ebp-10H], 0                      ; 0016 _ 83. 7D, F0, 00
        jnz     ?_001                                   ; 001A _ 75, 09
        mov     dword [ebp-14H], 1                      ; 001C _ C7. 45, EC, 00000001
        jmp     ?_003                                   ; 0023 _ EB, 16

?_001:  mov     eax, dword [ebp-10H]                    ; 0025 _ 8B. 45, F0
        mov     eax, dword [eax+8H]                     ; 0028 _ 8B. 40, 08
        test    eax, eax                                ; 002B _ 85. C0
        jz      ?_002                                   ; 002D _ 74, 0B
        mov     eax, dword [ebp-10H]                    ; 002F _ 8B. 45, F0
        mov     eax, dword [eax+8H]                     ; 0032 _ 8B. 40, 08
        mov     dword [ebp-10H], eax                    ; 0035 _ 89. 45, F0
        jmp     ?_001                                   ; 0038 _ EB, EB

?_002:  nop                                             ; 003A _ 90
?_003:  sub     esp, 12                                 ; 003B _ 83. EC, 0C
        push    12                                      ; 003E _ 6A, 0C
        call    malloc                                  ; 0040 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0045 _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 0048 _ 89. 45, F4
        mov     eax, dword [ebp+0CH]                    ; 004B _ 8B. 45, 0C
        mov     edx, dword [eax+0CH]                    ; 004E _ 8B. 50, 0C
        mov     eax, dword [ebp-0CH]                    ; 0051 _ 8B. 45, F4
        mov     dword [eax+8H], edx                     ; 0054 _ 89. 50, 08
        mov     eax, dword [ebp+0CH]                    ; 0057 _ 8B. 45, 0C
        mov     edx, dword [eax+8H]                     ; 005A _ 8B. 50, 08
        mov     eax, dword [ebp-0CH]                    ; 005D _ 8B. 45, F4
        mov     dword [eax+4H], edx                     ; 0060 _ 89. 50, 04
        mov     eax, dword [ebp+0CH]                    ; 0063 _ 8B. 45, 0C
        mov     edx, dword [eax+4H]                     ; 0066 _ 8B. 50, 04
        mov     eax, dword [ebp-0CH]                    ; 0069 _ 8B. 45, F4
        mov     dword [eax], edx                        ; 006C _ 89. 10
        mov     eax, dword [ebp+8H]                     ; 006E _ 8B. 45, 08
        mov     edx, dword [eax]                        ; 0071 _ 8B. 10
        mov     eax, dword [ebp+0CH]                    ; 0073 _ 8B. 45, 0C
        mov     eax, dword [eax]                        ; 0076 _ 8B. 00
        add     edx, eax                                ; 0078 _ 01. C2
        mov     eax, dword [ebp+8H]                     ; 007A _ 8B. 45, 08
        mov     dword [eax], edx                        ; 007D _ 89. 10
        cmp     dword [ebp-14H], 0                      ; 007F _ 83. 7D, EC, 00
        jz      ?_004                                   ; 0083 _ 74, 0B
        mov     eax, dword [ebp+8H]                     ; 0085 _ 8B. 45, 08
        mov     edx, dword [ebp-0CH]                    ; 0088 _ 8B. 55, F4
        mov     dword [eax+0CH], edx                    ; 008B _ 89. 50, 0C
        jmp     ?_005                                   ; 008E _ EB, 09

?_004:  mov     eax, dword [ebp-10H]                    ; 0090 _ 8B. 45, F0
        mov     edx, dword [ebp-0CH]                    ; 0093 _ 8B. 55, F4
        mov     dword [eax+8H], edx                     ; 0096 _ 89. 50, 08
?_005:  mov     eax, dword [ebp+0CH]                    ; 0099 _ 8B. 45, 0C
        mov     dword [eax+0CH], 0                      ; 009C _ C7. 40, 0C, 00000000
        mov     eax, dword [ebp+0CH]                    ; 00A3 _ 8B. 45, 0C
        mov     dword [eax+8H], 0                       ; 00A6 _ C7. 40, 08, 00000000
        sub     esp, 12                                 ; 00AD _ 83. EC, 0C
        push    dword [ebp+0CH]                         ; 00B0 _ FF. 75, 0C
        call    free                                    ; 00B3 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 00B8 _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 00BB _ 8B. 45, 08
        leave                                           ; 00BE _ C9
        ret                                             ; 00BF _ C3
; str_concat End of function

str_concat_new:; Function begin
        push    ebp                                     ; 00C0 _ 55
        mov     ebp, esp                                ; 00C1 _ 89. E5
        sub     esp, 24                                 ; 00C3 _ 83. EC, 18
        sub     esp, 12                                 ; 00C6 _ 83. EC, 0C
        push    ?_030                                   ; 00C9 _ 68, 00000000(d)
        call    str_debug_set                           ; 00CE _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 00D3 _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 00D6 _ 89. 45, F4
        sub     esp, 8                                  ; 00D9 _ 83. EC, 08
        push    dword [ebp+8H]                          ; 00DC _ FF. 75, 08
        push    dword [ebp-0CH]                         ; 00DF _ FF. 75, F4
        call    str_concat                              ; 00E2 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 00E7 _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 00EA _ 89. 45, F4
        sub     esp, 8                                  ; 00ED _ 83. EC, 08
        push    dword [ebp+0CH]                         ; 00F0 _ FF. 75, 0C
        push    dword [ebp-0CH]                         ; 00F3 _ FF. 75, F4
        call    str_concat                              ; 00F6 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 00FB _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 00FE _ 89. 45, F4
        sub     esp, 12                                 ; 0101 _ 83. EC, 0C
        push    dword [ebp+8H]                          ; 0104 _ FF. 75, 08
        call    str_free                                ; 0107 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 010C _ 83. C4, 10
        mov     eax, dword [ebp-0CH]                    ; 010F _ 8B. 45, F4
        leave                                           ; 0112 _ C9
        ret                                             ; 0113 _ C3
; str_concat_new End of function

ilog10c:; Function begin
        push    ebp                                     ; 0114 _ 55
        mov     ebp, esp                                ; 0115 _ 89. E5
        push    ebx                                     ; 0117 _ 53
        sub     esp, 28                                 ; 0118 _ 83. EC, 1C
        mov     eax, dword [ebp+8H]                     ; 011B _ 8B. 45, 08
        mov     dword [ebp-20H], eax                    ; 011E _ 89. 45, E0
        mov     eax, dword [ebp+0CH]                    ; 0121 _ 8B. 45, 0C
        mov     dword [ebp-1CH], eax                    ; 0124 _ 89. 45, E4
        mov     eax, dword [ebp-20H]                    ; 0127 _ 8B. 45, E0
        mov     edx, dword [ebp-1CH]                    ; 012A _ 8B. 55, E4
        test    edx, edx                                ; 012D _ 85. D2
        jz      ?_006                                   ; 012F _ 74, 08
        bsr     eax, edx                                ; 0131 _ 0F BD. C2
        xor     eax, 1FH                                ; 0134 _ 83. F0, 1F
        jmp     ?_007                                   ; 0137 _ EB, 09

?_006:  bsr     eax, eax                                ; 0139 _ 0F BD. C0
        xor     eax, 1FH                                ; 013C _ 83. F0, 1F
        add     eax, 32                                 ; 013F _ 83. C0, 20
?_007:  cdq                                             ; 0142 _ 99
        mov     dword [ebp-10H], eax                    ; 0143 _ 89. 45, F0
        mov     dword [ebp-0CH], edx                    ; 0146 _ 89. 55, F4
        mov     eax, dword [ebp-0CH]                    ; 0149 _ 8B. 45, F4
        imul    edx, eax, -77                           ; 014C _ 6B. D0, B3
        mov     eax, dword [ebp-10H]                    ; 014F _ 8B. 45, F0
        imul    eax, eax, -1                            ; 0152 _ 6B. C0, FF
        lea     ecx, [edx+eax]                          ; 0155 _ 8D. 0C 02
        mov     eax, 4294967219                         ; 0158 _ B8, FFFFFFB3
        mul     dword [ebp-10H]                         ; 015D _ F7. 65, F0
        add     ecx, edx                                ; 0160 _ 01. D1
        mov     edx, ecx                                ; 0162 _ 89. CA
        add     eax, 4851                               ; 0164 _ 05, 000012F3
        adc     edx, 0                                  ; 0169 _ 83. D2, 00
        shrd    eax, edx, 8                             ; 016C _ 0F AC. D0, 08
        shr     edx, 8                                  ; 0170 _ C1. EA, 08
        mov     ecx, eax                                ; 0173 _ 89. C1
        mov     ebx, edx                                ; 0175 _ 89. D3
        mov     eax, dword [ebp-10H]                    ; 0177 _ 8B. 45, F0
        mov     edx, dword [?_034+eax*8]                ; 017A _ 8B. 14 C5, 00000024(d)
        mov     eax, dword [thr.2666+eax*8]             ; 0181 _ 8B. 04 C5, 00000020(d)
        or      eax, edx                                ; 0188 _ 09. D0
        test    eax, eax                                ; 018A _ 85. C0
        jz      ?_009                                   ; 018C _ 74, 27
        mov     eax, dword [ebp-10H]                    ; 018E _ 8B. 45, F0
        mov     edx, dword [?_034+eax*8]                ; 0191 _ 8B. 14 C5, 00000024(d)
        mov     eax, dword [thr.2666+eax*8]             ; 0198 _ 8B. 04 C5, 00000020(d)
        cmp     edx, dword [ebp-1CH]                    ; 019F _ 3B. 55, E4
        ja      ?_009                                   ; 01A2 _ 77, 11
        cmp     edx, dword [ebp-1CH]                    ; 01A4 _ 3B. 55, E4
        jc      ?_008                                   ; 01A7 _ 72, 05
        cmp     eax, dword [ebp-20H]                    ; 01A9 _ 3B. 45, E0
        ja      ?_009                                   ; 01AC _ 77, 07
?_008:  mov     eax, 1                                  ; 01AE _ B8, 00000001
        jmp     ?_010                                   ; 01B3 _ EB, 05

?_009:  mov     eax, 0                                  ; 01B5 _ B8, 00000000
?_010:  cdq                                             ; 01BA _ 99
        add     eax, ecx                                ; 01BB _ 01. C8
        adc     edx, ebx                                ; 01BD _ 11. DA
        add     esp, 28                                 ; 01BF _ 83. C4, 1C
        pop     ebx                                     ; 01C2 _ 5B
        pop     ebp                                     ; 01C3 _ 5D
        ret                                             ; 01C4 _ C3
; ilog10c End of function

str_concat_str_i64:; Function begin
        push    ebp                                     ; 01C5 _ 55
        mov     ebp, esp                                ; 01C6 _ 89. E5
        sub     esp, 88                                 ; 01C8 _ 83. EC, 58
        mov     eax, dword [ebp+8H]                     ; 01CB _ 8B. 45, 08
        mov     dword [ebp-4CH], eax                    ; 01CE _ 89. 45, B4
        mov     eax, dword [ebp+0CH]                    ; 01D1 _ 8B. 45, 0C
        mov     dword [ebp-58H], eax                    ; 01D4 _ 89. 45, A8
        mov     eax, dword [ebp+10H]                    ; 01D7 _ 8B. 45, 10
        mov     dword [ebp-54H], eax                    ; 01DA _ 89. 45, AC
; Note: Absolute memory address without relocation
        mov     eax, dword [gs:14H]                     ; 01DD _ 65: A1, 00000014
        mov     dword [ebp-0CH], eax                    ; 01E3 _ 89. 45, F4
        xor     eax, eax                                ; 01E6 _ 31. C0
        mov     eax, dword [ebp-54H]                    ; 01E8 _ 8B. 45, AC
        or      eax, dword [ebp-58H]                    ; 01EB _ 0B. 45, A8
        test    eax, eax                                ; 01EE _ 85. C0
        jnz     ?_011                                   ; 01F0 _ 75, 24
        sub     esp, 12                                 ; 01F2 _ 83. EC, 0C
        push    ?_031                                   ; 01F5 _ 68, 00000001(d)
        call    str_debug_set                           ; 01FA _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 01FF _ 83. C4, 10
        sub     esp, 8                                  ; 0202 _ 83. EC, 08
        push    eax                                     ; 0205 _ 50
        push    dword [ebp-4CH]                         ; 0206 _ FF. 75, B4
        call    str_concat                              ; 0209 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 020E _ 83. C4, 10
        jmp     ?_016                                   ; 0211 _ E9, 000000D3

?_011:  mov     byte [ebp-21H], 45                      ; 0216 _ C6. 45, DF, 2D
        mov     eax, dword [ebp-58H]                    ; 021A _ 8B. 45, A8
        mov     edx, dword [ebp-54H]                    ; 021D _ 8B. 55, AC
        mov     dword [ebp-30H], eax                    ; 0220 _ 89. 45, D0
        mov     dword [ebp-2CH], edx                    ; 0223 _ 89. 55, D4
        mov     eax, dword [ebp-30H]                    ; 0226 _ 8B. 45, D0
        mov     edx, dword [ebp-2CH]                    ; 0229 _ 8B. 55, D4
; Filling space: 2H
; Filler type: mov with same source and destination
;       db 89H, 0D2H

ALIGN   2
        sar     edx, 31                                 ; 022E _ C1. FA, 1F
        mov     eax, edx                                ; 0231 _ 89. D0
        xor     dword [ebp-30H], eax                    ; 0233 _ 31. 45, D0
        xor     dword [ebp-2CH], edx                    ; 0236 _ 31. 55, D4
        sub     dword [ebp-30H], eax                    ; 0239 _ 29. 45, D0
        sbb     dword [ebp-2CH], edx                    ; 023C _ 19. 55, D4
        mov     eax, dword [ebp-30H]                    ; 023F _ 8B. 45, D0
        mov     edx, dword [ebp-2CH]                    ; 0242 _ 8B. 55, D4
        sub     esp, 8                                  ; 0245 _ 83. EC, 08
        push    edx                                     ; 0248 _ 52
        push    eax                                     ; 0249 _ 50
        call    ilog10c                                 ; 024A _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 024F _ 83. C4, 10
        add     eax, 1                                  ; 0252 _ 83. C0, 01
        mov     dword [ebp-34H], eax                    ; 0255 _ 89. 45, CC
        mov     dword [ebp-3CH], 0                      ; 0258 _ C7. 45, C4, 00000000
        jmp     ?_015                                   ; 025F _ EB, 60

?_012:  mov     eax, dword [ebp-34H]                    ; 0261 _ 8B. 45, CC
        sub     eax, dword [ebp-3CH]                    ; 0264 _ 2B. 45, C4
        mov     dword [ebp-38H], eax                    ; 0267 _ 89. 45, C8
        cmp     dword [ebp-54H], 0                      ; 026A _ 83. 7D, AC, 00
        js      ?_014                                   ; 026E _ 78, 10
        cmp     dword [ebp-54H], 0                      ; 0270 _ 83. 7D, AC, 00
        jg      ?_013                                   ; 0274 _ 7F, 06
        cmp     dword [ebp-58H], 0                      ; 0276 _ 83. 7D, A8, 00
        jbe     ?_014                                   ; 027A _ 76, 04
?_013:  sub     dword [ebp-38H], 1                      ; 027C _ 83. 6D, C8, 01
?_014:  mov     eax, dword [ebp-30H]                    ; 0280 _ 8B. 45, D0
        mov     edx, dword [ebp-2CH]                    ; 0283 _ 8B. 55, D4
        push    0                                       ; 0286 _ 6A, 00
        push    10                                      ; 0288 _ 6A, 0A
        push    edx                                     ; 028A _ 52
        push    eax                                     ; 028B _ 50
        call    __moddi3                                ; 028C _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0291 _ 83. C4, 10
        add     eax, 48                                 ; 0294 _ 83. C0, 30
        mov     ecx, eax                                ; 0297 _ 89. C1
        lea     edx, [ebp-21H]                          ; 0299 _ 8D. 55, DF
        mov     eax, dword [ebp-38H]                    ; 029C _ 8B. 45, C8
        add     eax, edx                                ; 029F _ 01. D0
        mov     byte [eax], cl                          ; 02A1 _ 88. 08
        add     dword [ebp-3CH], 1                      ; 02A3 _ 83. 45, C4, 01
        mov     eax, dword [ebp-30H]                    ; 02A7 _ 8B. 45, D0
        mov     edx, dword [ebp-2CH]                    ; 02AA _ 8B. 55, D4
        push    0                                       ; 02AD _ 6A, 00
        push    10                                      ; 02AF _ 6A, 0A
        push    edx                                     ; 02B1 _ 52
        push    eax                                     ; 02B2 _ 50
        call    __divdi3                                ; 02B3 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 02B8 _ 83. C4, 10
        mov     dword [ebp-30H], eax                    ; 02BB _ 89. 45, D0
        mov     dword [ebp-2CH], edx                    ; 02BE _ 89. 55, D4
?_015:  mov     eax, dword [ebp-2CH]                    ; 02C1 _ 8B. 45, D4
        or      eax, dword [ebp-30H]                    ; 02C4 _ 0B. 45, D0
        test    eax, eax                                ; 02C7 _ 85. C0
        jnz     ?_012                                   ; 02C9 _ 75, 96
        sub     esp, 12                                 ; 02CB _ 83. EC, 0C
        lea     eax, [ebp-21H]                          ; 02CE _ 8D. 45, DF
        push    eax                                     ; 02D1 _ 50
        call    str_debug_set                           ; 02D2 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 02D7 _ 83. C4, 10
        sub     esp, 8                                  ; 02DA _ 83. EC, 08
        push    eax                                     ; 02DD _ 50
        push    dword [ebp-4CH]                         ; 02DE _ FF. 75, B4
        call    str_concat                              ; 02E1 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 02E6 _ 83. C4, 10
?_016:  mov     edx, dword [ebp-0CH]                    ; 02E9 _ 8B. 55, F4
; Note: Absolute memory address without relocation
        xor     edx, dword [gs:14H]                     ; 02EC _ 65: 33. 15, 00000014
        jz      ?_017                                   ; 02F3 _ 74, 05
        call    __stack_chk_fail                        ; 02F5 _ E8, FFFFFFFC(rel)
?_017:  leave                                           ; 02FA _ C9
        ret                                             ; 02FB _ C3
; str_concat_str_i64 End of function

str_substr:; Function begin
        push    ebp                                     ; 02FC _ 55
        mov     ebp, esp                                ; 02FD _ 89. E5
        nop                                             ; 02FF _ 90
        pop     ebp                                     ; 0300 _ 5D
        ret                                             ; 0301 _ C3
; str_substr End of function

str_tail_free:; Function begin
        push    ebp                                     ; 0302 _ 55
        mov     ebp, esp                                ; 0303 _ 89. E5
        sub     esp, 8                                  ; 0305 _ 83. EC, 08
        mov     eax, dword [ebp+8H]                     ; 0308 _ 8B. 45, 08
        mov     eax, dword [eax+8H]                     ; 030B _ 8B. 40, 08
        test    eax, eax                                ; 030E _ 85. C0
        jz      ?_018                                   ; 0310 _ 74, 1C
        mov     eax, dword [ebp+8H]                     ; 0312 _ 8B. 45, 08
        mov     eax, dword [eax+8H]                     ; 0315 _ 8B. 40, 08
        sub     esp, 12                                 ; 0318 _ 83. EC, 0C
        push    eax                                     ; 031B _ 50
        call    str_tail_free                           ; 031C _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0321 _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 0324 _ 8B. 45, 08
        mov     dword [eax+8H], 0                       ; 0327 _ C7. 40, 08, 00000000
?_018:  mov     eax, dword [ebp+8H]                     ; 032E _ 8B. 45, 08
        mov     eax, dword [eax+4H]                     ; 0331 _ 8B. 40, 04
        sub     esp, 12                                 ; 0334 _ 83. EC, 0C
        push    eax                                     ; 0337 _ 50
        call    free                                    ; 0338 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 033D _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 0340 _ 8B. 45, 08
        mov     dword [eax+4H], 0                       ; 0343 _ C7. 40, 04, 00000000
        sub     esp, 12                                 ; 034A _ 83. EC, 0C
        push    dword [ebp+8H]                          ; 034D _ FF. 75, 08
        call    free                                    ; 0350 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0355 _ 83. C4, 10
        nop                                             ; 0358 _ 90
        leave                                           ; 0359 _ C9
        ret                                             ; 035A _ C3
; str_tail_free End of function

str_free:; Function begin
        push    ebp                                     ; 035B _ 55
        mov     ebp, esp                                ; 035C _ 89. E5
        sub     esp, 8                                  ; 035E _ 83. EC, 08
        mov     eax, dword [ebp+8H]                     ; 0361 _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 0364 _ 8B. 40, 0C
        test    eax, eax                                ; 0367 _ 85. C0
        jz      ?_019                                   ; 0369 _ 74, 12
        mov     eax, dword [ebp+8H]                     ; 036B _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 036E _ 8B. 40, 0C
        sub     esp, 12                                 ; 0371 _ 83. EC, 0C
        push    eax                                     ; 0374 _ 50
        call    str_tail_free                           ; 0375 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 037A _ 83. C4, 10
?_019:  mov     eax, dword [ebp+8H]                     ; 037D _ 8B. 45, 08
        mov     eax, dword [eax+8H]                     ; 0380 _ 8B. 40, 08
        sub     esp, 12                                 ; 0383 _ 83. EC, 0C
        push    eax                                     ; 0386 _ 50
        call    free                                    ; 0387 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 038C _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 038F _ 8B. 45, 08
        mov     dword [eax+8H], 0                       ; 0392 _ C7. 40, 08, 00000000
        sub     esp, 12                                 ; 0399 _ 83. EC, 0C
        push    dword [ebp+8H]                          ; 039C _ FF. 75, 08
        call    free                                    ; 039F _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 03A4 _ 83. C4, 10
        nop                                             ; 03A7 _ 90
        leave                                           ; 03A8 _ C9
        ret                                             ; 03A9 _ C3
; str_free End of function

str_print:; Function begin
        push    ebp                                     ; 03AA _ 55
        mov     ebp, esp                                ; 03AB _ 89. E5
        sub     esp, 24                                 ; 03AD _ 83. EC, 18
        mov     eax, dword [ebp+8H]                     ; 03B0 _ 8B. 45, 08
        mov     edx, dword [eax+8H]                     ; 03B3 _ 8B. 50, 08
        mov     eax, dword [ebp+8H]                     ; 03B6 _ 8B. 45, 08
        mov     eax, dword [eax+4H]                     ; 03B9 _ 8B. 40, 04
        sub     esp, 4                                  ; 03BC _ 83. EC, 04
        push    edx                                     ; 03BF _ 52
        push    eax                                     ; 03C0 _ 50
        push    ?_032                                   ; 03C1 _ 68, 00000003(d)
        call    printf                                  ; 03C6 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 03CB _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 03CE _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 03D1 _ 8B. 40, 0C
        mov     dword [ebp-0CH], eax                    ; 03D4 _ 89. 45, F4
?_020:  cmp     dword [ebp-0CH], 0                      ; 03D7 _ 83. 7D, F4, 00
        jz      ?_021                                   ; 03DB _ 74, 28
        mov     eax, dword [ebp-0CH]                    ; 03DD _ 8B. 45, F4
        mov     edx, dword [eax+4H]                     ; 03E0 _ 8B. 50, 04
        mov     eax, dword [ebp-0CH]                    ; 03E3 _ 8B. 45, F4
        mov     eax, dword [eax]                        ; 03E6 _ 8B. 00
        sub     esp, 4                                  ; 03E8 _ 83. EC, 04
        push    edx                                     ; 03EB _ 52
        push    eax                                     ; 03EC _ 50
        push    ?_032                                   ; 03ED _ 68, 00000003(d)
        call    printf                                  ; 03F2 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 03F7 _ 83. C4, 10
        mov     eax, dword [ebp-0CH]                    ; 03FA _ 8B. 45, F4
        mov     eax, dword [eax+8H]                     ; 03FD _ 8B. 40, 08
        mov     dword [ebp-0CH], eax                    ; 0400 _ 89. 45, F4
        jmp     ?_020                                   ; 0403 _ EB, D2
; str_print End of function

?_021:  ; Local function
        nop                                             ; 0405 _ 90
        nop                                             ; 0406 _ 90
        leave                                           ; 0407 _ C9
        ret                                             ; 0408 _ C3

str_len:; Function begin
        push    ebp                                     ; 0409 _ 55
        mov     ebp, esp                                ; 040A _ 89. E5
        mov     eax, dword [ebp+8H]                     ; 040C _ 8B. 45, 08
        mov     eax, dword [eax]                        ; 040F _ 8B. 00
        pop     ebp                                     ; 0411 _ 5D
        ret                                             ; 0412 _ C3
; str_len End of function

str_defrag:; Function begin
        push    ebp                                     ; 0413 _ 55
        mov     ebp, esp                                ; 0414 _ 89. E5
        sub     esp, 40                                 ; 0416 _ 83. EC, 28
        mov     eax, dword [ebp+8H]                     ; 0419 _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 041C _ 8B. 40, 0C
        test    eax, eax                                ; 041F _ 85. C0
        jnz     ?_022                                   ; 0421 _ 75, 08
        mov     eax, dword [ebp+8H]                     ; 0423 _ 8B. 45, 08
        jmp     ?_029                                   ; 0426 _ E9, 0000011E

?_022:  push    dword [ebp+8H]                          ; 042B _ FF. 75, 08
        call    str_len                                 ; 042E _ E8, FFFFFFFC(rel)
        add     esp, 4                                  ; 0433 _ 83. C4, 04
        sub     esp, 12                                 ; 0436 _ 83. EC, 0C
        push    eax                                     ; 0439 _ 50
        call    malloc                                  ; 043A _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 043F _ 83. C4, 10
        mov     dword [ebp-10H], eax                    ; 0442 _ 89. 45, F0
        mov     dword [ebp-1CH], 0                      ; 0445 _ C7. 45, E4, 00000000
        mov     dword [ebp-1CH], 0                      ; 044C _ C7. 45, E4, 00000000
        jmp     ?_024                                   ; 0453 _ EB, 1C

?_023:  mov     edx, dword [ebp-1CH]                    ; 0455 _ 8B. 55, E4
        mov     eax, dword [ebp-10H]                    ; 0458 _ 8B. 45, F0
        add     edx, eax                                ; 045B _ 01. C2
        mov     eax, dword [ebp+8H]                     ; 045D _ 8B. 45, 08
        mov     ecx, dword [eax+8H]                     ; 0460 _ 8B. 48, 08
        mov     eax, dword [ebp-1CH]                    ; 0463 _ 8B. 45, E4
        add     eax, ecx                                ; 0466 _ 01. C8
        movzx   eax, byte [eax]                         ; 0468 _ 0F B6. 00
        mov     byte [edx], al                          ; 046B _ 88. 02
        add     dword [ebp-1CH], 1                      ; 046D _ 83. 45, E4, 01
?_024:  mov     eax, dword [ebp+8H]                     ; 0471 _ 8B. 45, 08
        mov     edx, dword [eax+4H]                     ; 0474 _ 8B. 50, 04
        mov     eax, dword [ebp-1CH]                    ; 0477 _ 8B. 45, E4
        cmp     edx, eax                                ; 047A _ 39. C2
        ja      ?_023                                   ; 047C _ 77, D7
        mov     eax, dword [ebp+8H]                     ; 047E _ 8B. 45, 08
        mov     eax, dword [eax+8H]                     ; 0481 _ 8B. 40, 08
        sub     esp, 12                                 ; 0484 _ 83. EC, 0C
        push    eax                                     ; 0487 _ 50
        call    free                                    ; 0488 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 048D _ 83. C4, 10
        mov     eax, dword [ebp+8H]                     ; 0490 _ 8B. 45, 08
        mov     eax, dword [eax+0CH]                    ; 0493 _ 8B. 40, 0C
        mov     dword [ebp-18H], eax                    ; 0496 _ 89. 45, E8
        mov     dword [ebp-14H], 0                      ; 0499 _ C7. 45, EC, 00000000
?_025:  mov     dword [ebp-14H], 0                      ; 04A0 _ C7. 45, EC, 00000000
        jmp     ?_027                                   ; 04A7 _ EB, 24

?_026:  mov     eax, dword [ebp-1CH]                    ; 04A9 _ 8B. 45, E4
        lea     edx, [eax+1H]                           ; 04AC _ 8D. 50, 01
        mov     dword [ebp-1CH], edx                    ; 04AF _ 89. 55, E4
        mov     edx, eax                                ; 04B2 _ 89. C2
        mov     eax, dword [ebp-10H]                    ; 04B4 _ 8B. 45, F0
        add     edx, eax                                ; 04B7 _ 01. C2
        mov     eax, dword [ebp-18H]                    ; 04B9 _ 8B. 45, E8
        mov     ecx, dword [eax+4H]                     ; 04BC _ 8B. 48, 04
        mov     eax, dword [ebp-14H]                    ; 04BF _ 8B. 45, EC
        add     eax, ecx                                ; 04C2 _ 01. C8
        movzx   eax, byte [eax]                         ; 04C4 _ 0F B6. 00
        mov     byte [edx], al                          ; 04C7 _ 88. 02
        add     dword [ebp-14H], 1                      ; 04C9 _ 83. 45, EC, 01
?_027:  mov     eax, dword [ebp-18H]                    ; 04CD _ 8B. 45, E8
        mov     edx, dword [eax]                        ; 04D0 _ 8B. 10
        mov     eax, dword [ebp-14H]                    ; 04D2 _ 8B. 45, EC
        cmp     edx, eax                                ; 04D5 _ 39. C2
        ja      ?_026                                   ; 04D7 _ 77, D0
        mov     eax, dword [ebp-18H]                    ; 04D9 _ 8B. 45, E8
        mov     dword [ebp-0CH], eax                    ; 04DC _ 89. 45, F4
        mov     eax, dword [ebp-18H]                    ; 04DF _ 8B. 45, E8
        mov     eax, dword [eax+8H]                     ; 04E2 _ 8B. 40, 08
        mov     dword [ebp-18H], eax                    ; 04E5 _ 89. 45, E8
        mov     eax, dword [ebp-0CH]                    ; 04E8 _ 8B. 45, F4
        mov     dword [eax+8H], 0                       ; 04EB _ C7. 40, 08, 00000000
        mov     eax, dword [ebp-0CH]                    ; 04F2 _ 8B. 45, F4
        mov     eax, dword [eax+4H]                     ; 04F5 _ 8B. 40, 04
        sub     esp, 12                                 ; 04F8 _ 83. EC, 0C
        push    eax                                     ; 04FB _ 50
        call    free                                    ; 04FC _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0501 _ 83. C4, 10
        mov     eax, dword [ebp-0CH]                    ; 0504 _ 8B. 45, F4
        mov     dword [eax+4H], 0                       ; 0507 _ C7. 40, 04, 00000000
        sub     esp, 12                                 ; 050E _ 83. EC, 0C
        push    dword [ebp-0CH]                         ; 0511 _ FF. 75, F4
        call    free                                    ; 0514 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0519 _ 83. C4, 10
        cmp     dword [ebp-18H], 0                      ; 051C _ 83. 7D, E8, 00
        jz      ?_028                                   ; 0520 _ 74, 05
        jmp     ?_025                                   ; 0522 _ E9, FFFFFF79

?_028:  nop                                             ; 0527 _ 90
        mov     eax, dword [ebp+8H]                     ; 0528 _ 8B. 45, 08
        mov     dword [eax+0CH], 0                      ; 052B _ C7. 40, 0C, 00000000
        mov     eax, dword [ebp+8H]                     ; 0532 _ 8B. 45, 08
        mov     edx, dword [ebp-10H]                    ; 0535 _ 8B. 55, F0
        mov     dword [eax+8H], edx                     ; 0538 _ 89. 50, 08
        mov     eax, dword [ebp+8H]                     ; 053B _ 8B. 45, 08
        mov     edx, dword [eax]                        ; 053E _ 8B. 10
        mov     eax, dword [ebp+8H]                     ; 0540 _ 8B. 45, 08
        mov     dword [eax+4H], edx                     ; 0543 _ 89. 50, 04
        mov     eax, dword [ebp+8H]                     ; 0546 _ 8B. 45, 08
?_029:  leave                                           ; 0549 _ C9
        ret                                             ; 054A _ C3
; str_defrag End of function

str_debug_set:; Function begin
        push    ebp                                     ; 054B _ 55
        mov     ebp, esp                                ; 054C _ 89. E5
        sub     esp, 24                                 ; 054E _ 83. EC, 18
        sub     esp, 12                                 ; 0551 _ 83. EC, 0C
        push    16                                      ; 0554 _ 6A, 10
        call    malloc                                  ; 0556 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 055B _ 83. C4, 10
        mov     dword [ebp-10H], eax                    ; 055E _ 89. 45, F0
        sub     esp, 12                                 ; 0561 _ 83. EC, 0C
        push    dword [ebp+8H]                          ; 0564 _ FF. 75, 08
        call    strlen                                  ; 0567 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 056C _ 83. C4, 10
        mov     edx, eax                                ; 056F _ 89. C2
        mov     eax, dword [ebp-10H]                    ; 0571 _ 8B. 45, F0
        mov     dword [eax], edx                        ; 0574 _ 89. 10
        mov     eax, dword [ebp-10H]                    ; 0576 _ 8B. 45, F0
        mov     edx, dword [eax]                        ; 0579 _ 8B. 10
        mov     eax, dword [ebp-10H]                    ; 057B _ 8B. 45, F0
        mov     dword [eax+4H], edx                     ; 057E _ 89. 50, 04
        mov     eax, dword [ebp-10H]                    ; 0581 _ 8B. 45, F0
        mov     dword [eax+0CH], 0                      ; 0584 _ C7. 40, 0C, 00000000
        mov     eax, dword [ebp-10H]                    ; 058B _ 8B. 45, F0
        mov     eax, dword [eax]                        ; 058E _ 8B. 00
        sub     esp, 12                                 ; 0590 _ 83. EC, 0C
        push    eax                                     ; 0593 _ 50
        call    malloc                                  ; 0594 _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 0599 _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 059C _ 89. 45, F4
        mov     eax, dword [ebp-10H]                    ; 059F _ 8B. 45, F0
        mov     eax, dword [eax]                        ; 05A2 _ 8B. 00
        sub     esp, 4                                  ; 05A4 _ 83. EC, 04
        push    eax                                     ; 05A7 _ 50
        push    dword [ebp+8H]                          ; 05A8 _ FF. 75, 08
        push    dword [ebp-0CH]                         ; 05AB _ FF. 75, F4
        call    memcpy                                  ; 05AE _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 05B3 _ 83. C4, 10
        mov     eax, dword [ebp-10H]                    ; 05B6 _ 8B. 45, F0
        mov     edx, dword [ebp-0CH]                    ; 05B9 _ 8B. 55, F4
        mov     dword [eax+8H], edx                     ; 05BC _ 89. 50, 08
        mov     eax, dword [ebp-10H]                    ; 05BF _ 8B. 45, F0
        leave                                           ; 05C2 _ C9
        ret                                             ; 05C3 _ C3
; str_debug_set End of function

main:   ; Function begin
        lea     ecx, [esp+4H]                           ; 05C4 _ 8D. 4C 24, 04
        and     esp, 0FFFFFFF0H                         ; 05C8 _ 83. E4, F0
        push    dword [ecx-4H]                          ; 05CB _ FF. 71, FC
        push    ebp                                     ; 05CE _ 55
        mov     ebp, esp                                ; 05CF _ 89. E5
        push    ecx                                     ; 05D1 _ 51
        sub     esp, 20                                 ; 05D2 _ 83. EC, 14
        sub     esp, 12                                 ; 05D5 _ 83. EC, 0C
        push    ?_033                                   ; 05D8 _ 68, 00000008(d)
        call    str_debug_set                           ; 05DD _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 05E2 _ 83. C4, 10
        mov     dword [ebp-0CH], eax                    ; 05E5 _ 89. 45, F4
        sub     esp, 12                                 ; 05E8 _ 83. EC, 0C
        push    10                                      ; 05EB _ 6A, 0A
        call    putchar                                 ; 05ED _ E8, FFFFFFFC(rel)
        add     esp, 16                                 ; 05F2 _ 83. C4, 10
        mov     eax, 0                                  ; 05F5 _ B8, 00000000
        mov     ecx, dword [ebp-4H]                     ; 05FA _ 8B. 4D, FC
        leave                                           ; 05FD _ C9
        lea     esp, [ecx-4H]                           ; 05FE _ 8D. 61, FC
        ret                                             ; 0601 _ C3
; main End of function


SECTION .data   align=1 noexecute                       ; section number 2, data


SECTION .bss    align=1 noexecute                       ; section number 3, bss


SECTION .rodata align=32 noexecute                      ; section number 4, const

?_030:                                                  ; byte
        db 00H                                          ; 0000 _ .

?_031:                                                  ; byte
        db 30H, 00H                                     ; 0001 _ 0.

?_032:                                                  ; byte
        db 25H, 2EH, 2AH, 73H, 00H                      ; 0003 _ %.*s.

?_033:                                                  ; byte
        db 48H, 65H, 6CH, 6CH, 6FH, 20H, 77H, 6FH       ; 0008 _ Hello wo
        db 72H, 6CH, 64H, 21H, 00H, 00H, 00H, 00H       ; 0010 _ rld!....
        db 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H       ; 0018 _ ........

thr.2666:                                               ; byte
        dd 89E80000H                                    ; 0020 _ -1981284352 

?_034:  dd 8AC72304H, 00000000H                         ; 0024 _ -1966660860 0 
        dd 00000000H, 00000000H                         ; 002C _ 0 0 
        dd 00000000H, 00000000H                         ; 0034 _ 0 0 
        dd 00000000H, 0A7640000H                        ; 003C _ 0 -1486618624 
        dd 0DE0B6B3H, 00000000H                         ; 0044 _ 232830643 0 
        dd 00000000H, 00000000H                         ; 004C _ 0 0 
        dd 00000000H, 5D8A0000H                         ; 0054 _ 0 1569325056 
        dd 01634578H, 00000000H                         ; 005C _ 23283064 0 
        dd 00000000H, 00000000H                         ; 0064 _ 0 0 
        dd 00000000H, 6FC10000H                         ; 006C _ 0 1874919424 
        dd 002386F2H, 00000000H                         ; 0074 _ 2328306 0 
        dd 00000000H, 00000000H                         ; 007C _ 0 0 
        dd 00000000H, 00000000H                         ; 0084 _ 0 0 
        dd 00000000H, 0A4C68000H                        ; 008C _ 0 -1530494976 
        dd 00038D7EH, 00000000H                         ; 0094 _ 232830 0 
        dd 00000000H, 00000000H                         ; 009C _ 0 0 
        dd 00000000H, 107A4000H                         ; 00A4 _ 0 276447232 
        dd 00005AF3H, 00000000H                         ; 00AC _ 23283 0 
        dd 00000000H, 00000000H                         ; 00B4 _ 0 0 
        dd 00000000H, 4E72A000H                         ; 00BC _ 0 1316134912 
        dd 00000918H, 00000000H                         ; 00C4 _ 2328 0 
        dd 00000000H, 00000000H                         ; 00CC _ 0 0 
        dd 00000000H, 00000000H                         ; 00D4 _ 0 0 
        dd 00000000H, 0D4A51000H                        ; 00DC _ 0 -727379968 
        dd 000000E8H, 00000000H                         ; 00E4 _ 232 0 
        dd 00000000H, 00000000H                         ; 00EC _ 0 0 
        dd 00000000H, 4876E800H                         ; 00F4 _ 0 1215752192 
        dd 00000017H, 00000000H                         ; 00FC _ 23 0 
        dd 00000000H, 00000000H                         ; 0104 _ 0 0 
        dd 00000000H, 540BE400H                         ; 010C _ 0 1410065408 
        dd 00000002H, 00000000H                         ; 0114 _ 2 0 
        dd 00000000H, 00000000H                         ; 011C _ 0 0 
        dd 00000000H, 00000000H                         ; 0124 _ 0 0 
        dd 00000000H, 3B9ACA00H                         ; 012C _ 0 1000000000 
        dd 00000000H, 00000000H                         ; 0134 _ 0 0 
        dd 00000000H, 00000000H                         ; 013C _ 0 0 
        dd 00000000H, 05F5E100H                         ; 0144 _ 0 100000000 
        dd 00000000H, 00000000H                         ; 014C _ 0 0 
        dd 00000000H, 00000000H                         ; 0154 _ 0 0 
        dd 00000000H, 00989680H                         ; 015C _ 0 10000000 
        dd 00000000H, 00000000H                         ; 0164 _ 0 0 
        dd 00000000H, 00000000H                         ; 016C _ 0 0 
        dd 00000000H, 00000000H                         ; 0174 _ 0 0 
        dd 00000000H, 000F4240H                         ; 017C _ 0 1000000 
        dd 00000000H, 00000000H                         ; 0184 _ 0 0 
        dd 00000000H, 00000000H                         ; 018C _ 0 0 
        dd 00000000H, 000186A0H                         ; 0194 _ 0 100000 
        dd 00000000H, 00000000H                         ; 019C _ 0 0 
        dd 00000000H, 00000000H                         ; 01A4 _ 0 0 
        dd 00000000H, 00002710H                         ; 01AC _ 0 10000 
        dd 00000000H, 00000000H                         ; 01B4 _ 0 0 
        dd 00000000H, 00000000H                         ; 01BC _ 0 0 
        dd 00000000H, 00000000H                         ; 01C4 _ 0 0 
        dd 00000000H, 000003E8H                         ; 01CC _ 0 1000 
        dd 00000000H, 00000000H                         ; 01D4 _ 0 0 
        dd 00000000H, 00000000H                         ; 01DC _ 0 0 
        dd 00000000H, 00000064H                         ; 01E4 _ 0 100 
        dd 00000000H, 00000000H                         ; 01EC _ 0 0 
        dd 00000000H, 00000000H                         ; 01F4 _ 0 0 
        dd 00000000H, 0000000AH                         ; 01FC _ 0 10 
        dd 00000000H, 00000000H                         ; 0204 _ 0 0 
        dd 00000000H, 00000000H                         ; 020C _ 0 0 
        dd 00000000H, 00000000H                         ; 0214 _ 0 0 
        dd 00000000H                                    ; 021C _ 0 



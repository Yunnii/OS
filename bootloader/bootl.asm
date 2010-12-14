org 7C00h


;==================================================
_start:
jmp 0+5
xor ax,ax
cli
mov ss, ax
mov sp, ax
sti
mov ah, 02h
mov al, 1
mov ch, 0
mov cl, 2
mov dh, 0
push cs
pop es
mov bx, _end
int 13h

mov dh,0
mov dl,0
mov ah, 13h
mov al, 01h
mov bl, 12h
mov bh, 0
mov cx, (_S2-_S1)
mov bp, _end
int 10h
cli
hlt
_end:

db 510-(_end - _start) dup (0)
db 55h, 0AAh
; ========================================================
_S1:
db 'HELLO ASM =)'
_S2:
db 512-(_S2-_S1) dup (0)
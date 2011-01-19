	.model tiny
	.code
	.486p
	org 07C00h

_1:	jmp start

GDT label byte
        db 8 dup(0)            ; нулевой дескриптор
; 16-битный 4 Гб сегмент:
        db        0FFh,0FFh,0,0,0,1001001b,11001111b,0
gdtr    dw        16                   ; размер GDI
gdt_base dd ?                    ; линейный адрес GDT

start:
; код программы
		cli
		xor        eax,eax
		mov			ss,ax
		xor			sp,sp
		sti
		mov			ds,axx
		mov			es,ax
		
		jmp			00h:defg
defg:
		
; определить линейный адрес GDT
        xor        eax,eax
        mov        ax,cs ; теперь AX = номер сегмента RM_CODE
        shl        eax,4
        add        ax,offset GDT
; загрузить GDT из одного дескриптора (не считая нулевого)
        mov        gdt_base,eax
        lgdt       fword ptr gdtr
; перейти в защищенный режим
        cli
		;запрещаем немаскируемые прерывания 
		in			al,70h
		or			al,80h
		out 		70h,al
		
        mov        eax,cr0
        or         al,1
        mov        cr0,eax
		
		
        jmp        start_PM            ; сбросить очередь предвыборки
                                       ; Intel рекомендует
start_PM:                              ; делать jmp после каждой смены режима
; загрузить все сегментные регистры дескриптором с лимитом 4 Гб
        mov        ax,8                ; 8 - селектор нашего дескриптора
        mov        ds,ax
        mov        es,ax
        mov        fs,ax
        mov        gs,ax               ; перейти в реальный режим
        mov        eax,cr0
        and        al,0FEh
        mov        cr0,eax
        jmp        exit_PM
exit_PM:
; записать что-нибудь в каждый сегментный регистр
        xor 	   ax,ax
        mov        ds,ax
        mov        es,ax
        mov        fs,ax
        mov        gs,ax
        sti
        mov        ax,cs
        mov        ds,ax

end _1
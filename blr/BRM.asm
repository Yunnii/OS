	.model tiny
	.code
	.486p
	org 100h

_1:	jmp start

GDT label byte
        db 8 dup(0)    
        db        0FFh,0FFh,0,0,0,1001001b,11001111b,0
gdtr    dw        16                 
gdt_base dd ?                  

start:
        xor        eax,eax
        mov        ax,cs
        shl        eax,4
        add        ax,offset GDT

        mov        gdt_base,eax
        lgdt       fword ptr gdtr

        cli
        mov        eax,cr0
        or         al,1
        mov        cr0,eax
        jmp        start_PM            
start_PM:                              
        mov        ax,8                
        mov        ds,ax
        mov        es,ax
        mov        fs,ax
        mov        gs,ax          
        mov        eax,cr0
        and        al,0FEh
        mov        cr0,eax
        jmp        exit_PM
exit_PM:
        xor 	   ax,ax
        mov        ds,ax
        mov        es,ax
        mov        fs,ax
        mov        gs,ax
        sti
        mov        ax,cs
        mov        ds,ax

end _1
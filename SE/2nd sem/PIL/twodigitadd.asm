.model small
disp macro no3
        mov bl,no3

        loop1:
        rol bl,cl
        mov dl,bl
        and dl,0Fh
        cmp dl,09h
        jbe loop2
        add dl,07h

        loop2:
        add dl,30h
        mov ah, 02h
        int 21h
        dec ch
        jnz loop1
endm

.data
        no1 db 09h
        no2 db 06h
        no3 db ?
.code
        mov ax,@data
        mov ds,ax

        ;----------- ADDITION -------------
        mov al,no1
        add al,no2
        daa
        mov no3,al

        ;---------- display result -------
        mov ax,0000h
        mov cx,0204h


        disp no3
        ;--------- TERMINATE PROGRAM --------
        mov ah, 4ch
        int 21h
end
        

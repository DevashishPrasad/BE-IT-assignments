.model small
.data
        no1 db 04h
        no2 db 02h
        no3 db ?
        dispno1 db 10,13,'No. 1 is = $'
        dispno2 db 10,13,'No. 2 is = $'
        disp1 db 10,13,10,13,10,13,'Sum is = $'
        disp2 db 10,13,'Difference is = $'
        disp3 db 10,13,'Product is = $'
        disp4 db 10,13,'Quotient is = $'
        disp5 db 10,13,'Remainder is = $'
.code
        mov ax,@data
        mov ds,ax

        ;------- PRINT OUT NUMBERS -------
        mov dx, offset dispno1
        mov ah, 09h
        int 21h

        mov dl, no1
        add dl,30h
        mov ah, 02h
        int 21h

        mov dx, offset dispno2
        mov ah, 09h
        int 21h

        mov dl, no2
        add dl,30h
        mov ah, 02h
        int 21h

        ;--------- ADDITION -----------
        mov al,no1
        add al,no2

        add al,30h

        mov dx, offset disp1
        mov ah, 09h
        int 21h

        mov dl,al

        mov ah,02h
        int 21h

        ;----------- SUBTRACTION ---------
        mov al,no1
        sub al,no2

        add al,30h


        mov dx, offset disp2
        mov ah, 09h
        int 21h

        mov dl,al

        mov ah,02h
        int 21h

        ;----------- MULLTIPLICATION ---------
        mov al,no1
        mul no2

        add al,30h


        mov dx, offset disp3
        mov ah, 09h
        int 21h

        mov dl,al

        mov ah,02h
        int 21h

        ;----------- DIVISION ---------
        mov ax,0000h
        mov al,no1
        div no2

        add al,30h

        mov dx, offset disp4
        mov ah, 09h
        int 21h

        mov no3,al
        mov dl,no3

        mov ah,02h
        int 21h

        mov dx, offset disp5
        mov ah, 09h
        int 21h

        add ah,30h
        mov dl,ah

        mov ah,02h
        int 21h

        ;--------- TERMINATE PROGRAM --------
        mov ah, 4ch
        int 21h
end
        

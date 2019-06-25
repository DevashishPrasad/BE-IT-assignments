.model small

.data
        arr db 06h,06h,06h,06h,06h
        no db 5
        mych db ?
        ;str0 db 10,13,'Enter the number of elements in array - $'
        ;str1 db 10,13,'Enter the elements - $'
        ;str2 db 10,13,'Enter element $'
        str3 db 10,13,10,13,10,13,'The elements are - $'
        str4 db 10,13,10,13,10,13,'Addition of all elements is - $'
.code
        mov ax,@data
        mov ds,ax
        mov ax,0000h

        ;========= Displaying Output ===========
        mov al,no
        mov mych,al
        mov ax,0000h
        lea si,arr

        mov dx,offset str3
        mov ah,09h
        int 21h

        l2:
                mov dl, 20h
                mov ah, 02h
                int 21h
                
                mov dl,[si]
                mov bl,dl

                mov cx,0204h

                up:
                rol bl,cl
                mov dl,bl
                and dl,0Fh
                cmp dl,09h
                jbe down
                add dl,07h

                down:
                add dl,30h
                mov ah,02h
                int 21h
                dec ch
                jnz up

                ;mov ah, 02h
                ;int 21h
                inc si
                dec mych
                jnz l2

        ;====== Displaying Addition of all elements ======
        mov ch,5
        lea si,arr

        mov dx,offset str4
        mov ah,09h
        int 21h

        mov ax,0000h    
        l3:
                mov dl,[si]
                sub dl,30h
                add al,dl
                daa
                inc si
                dec ch
                jnz l3
        
        mov bl,0000h
        mov bl,al
        ;add bl,30h

        mov cx,0204h

        up1:
            rol bl,cl
            mov dl,bl
            and dl,0Fh
            cmp dl,09h
            jbe down1
            add dl,07h

        down1:
            add dl,30h
            mov ah,02h
            int 21h
            dec ch
            jnz up1

        ;========= Terminating the program ==========
        mov ah,4ch
        int 21h
end

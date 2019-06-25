.model small
twodigit macro
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
endm

takenum macro
        ;======= string =======
        mov dx,offset str2
        mov ah,09h
        int 21h

        ;==== element number ====
        mov al,cl
        add al,30h
        mov dl,al
        inc cl

        mov ah, 02h
        int 21h

        ;======= space ========
        mov dl, 20h
        mov ah, 02h
        int 21h

        mov dl, 2Dh
        mov ah, 02h
        int 21h

        mov dl, 20h
        mov ah, 02h
        int 21h

        mov ah, 01h
        int 21h        
endm

.data
        arr db 5 dup(?)
        no db ?
        str0 db 10,13,'Enter the number of elements in array - $'
        str1 db 10,13,'Enter the elements - $'
        str2 db 10,13,'Enter element $'
        str3 db 10,13,10,13,10,13,'The elements are - $'
        str4 db 10,13,10,13,10,13,'Addition of all elements is - $'
.code
        mov ax,@data
        mov ds,ax
        mov ax, 0000h

        ;========= Taking input num of elements =========
        mov dx,offset str0
        mov ah,09h
        int 21h

        mov ah, 01h
        int 21h

        sub al, 30h
        mov no, al
        mov ch, no 

        ;========= Taking input elements from user ========
        mov al,0
        mov cl,0
        lea si,arr

        mov dx,offset str1
        mov ah,09h
        int 21h

        l1:
                takenum
                mov [si],al
                inc si
                dec ch
                jnz l1

        ;========= Displaying Output ===========
        mov al,0
        mov ch,no
        lea si,arr

        mov dx,offset str3
        mov ah,09h
        int 21h

        l2:
                mov dl, 20h
                mov ah, 02h
                int 21h
                
                mov dl,[si]
                mov ah, 02h
                int 21h
                inc si
                dec ch
                jnz l2

        ;====== Displaying Addition of all elements ======
        mov al,0
        mov ch,no
        lea si,arr

        mov dx,offset str4
        mov ah,09h
        int 21h

        mov al,0
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
        twodigit

        ;========= Terminating the program ==========
        mov ah,4ch
        int 21h
end

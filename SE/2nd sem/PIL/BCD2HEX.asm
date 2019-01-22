.model small

displaystr macro mystr
        lea dx,mystr
        mov ah,09h
        int 21h        
endm

getinput macro
        mov ah,01h
        int 21h
        mov input,al
endm

printnextline macro
        mov ah,09h
        int 21h
endm

setoutput macro
        mov ah,02h
        int 21h
endm

.data
        menustr db 10,13,10,13,'---------------MENU----------------',10,13,'1. BCD to HEX',10,13,'2. HEX to BCD',10,13,'3. Exit',10,13,'ENTER YOUR CHOICE - $'
        str1 db 10,13,'Please Enter 5 digit BCD number $'
        str2 db 10,13,10,13,'The first digit should be less than 9 ',10,13,'Invalid Input... Please Try Again $'
        str3 db 10,13,'Please Enter 4 digit HEX number $'
        str4 db 10,13,'Your BCD Number is - $'
        str5 db 10,13,'Converted HEX Number is - $'
        byestr db 10,13,'Bye! $'
        input db ?
        cnt db ?
        flg db 0
        res dw 0
        nextline db 10,13,10,13,'$'
        array dw 10000,1000,100,10,1
        bcdno db 5 dup(?)

.stack 100h
.code
        mov ax,@data
        mov ds,ax

        m1:
        displaystr menustr
        getinput
        cmp input,31h
        jne next1
        call bcd2hex
        jmp m1

        next1:
        cmp input,32h
        jne next2
        call hex2bcd
        jmp m1

        ;------------ terminate the program ---------------
        next2:
        displaystr byestr
        mov ah,4ch
        int 21h;

        ;----- Procedure for BCD to HEX conversion --------
        bcd2hex proc
        mov flg,0
        start:
        displaystr str1
        mov cnt,5
        lea si,array
        lea di,bcdno
        mov res,0000
        up1:
                getinput
                sub al,30h
                mov ah,00h
                mov [di],al

                cmp flg,0
                jne continue
                cmp ax,0006
                jng continue
                displaystr str2
                jmp start

                continue:
                mov flg,1
                mul [si]
                inc si
                inc si  
                inc di
                ;mov ax,0000
                add res,ax 
                dec cnt
                cmp cnt,0000h
                jnz up1

        lea dx,nextline
        printnextline
        lea di,bcdno
        displaystr str4
        mov cl,05
        origin:
                mov dl,[di]
                add dl,30h
                setoutput
                inc di
                dec cl
                jnz origin

        displaystr str5
        mov cx,0404h
        mov bx,res
        down11:
                rol bx,cl
                mov dl,bl
                and dl,0Fh
                cmp dl,09h
                jbe down22
                add dl,07h

        down22:
                add dl,30h
                setoutput
                dec ch
                jnz down11
        ret
        endp

        ;------- Procedure for HEX to BCD conversion --------
        hex2bcd proc
        toppest:
        mov bx,0000h
        mov ax,0000h

        displaystr str3
        top:
        

        getinput
        cmp al,30h
        jl toppest
        cmp al,39h
        jg toppest
        cmp al,41h
        jl toppest
        cmp al,46h
        jg toppest
        cmp al,61h
        jl toppest
        cmp al,66h
        jg toppest

        mov bl,al
        ret
        endp
end

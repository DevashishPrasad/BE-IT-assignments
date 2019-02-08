.model small
.stack 100h

;----------- macro for displayimg string -------------
dispstr macro mystr
        lea dx,mystr
        mov ah,09h
        int 21h
endm

;----------- macro for taking input single character -------------
getinput macro
        mov ah,01h
        int 21h
        mov input,al
endm
;---------------- macro to print an empty line -------------------
printnextline macro
	lea dx,nextline
        mov ah,09h
        int 21h
endm
;---------- macro to display a singlecharacter on the screen -----
setoutput macro
        mov ah,02h
        int 21h
endm

.data
	str1 db 10,13,10,13,'Enter the String - $'
	str2 db 10,13,'The length of the string is - $'
	str3 db 10,13,'Your string is - $'
        showequal db 10,13,'YES the string is a palindrome$'
        shownotequal db 10,13,'NO the string is not a palindrome$'
        menustr db 10,13,10,13,'---------------MENU----------------',10,13,'1. LENGTH OF STRING',10,13,'2. DISPLAY STRING',10,13,'3. REVERSE THE STRING',10,13,'4. CHECK FOR PALINDROME',10,13,'ELSE EXIT ',10,13,'ENTER YOUR CHOICE - $'
        thestr db 25 dup('$')
        revstr db 25 dup('$')
        byestr db 10,13,'Bye! $'
        nextline db 10,13,10,13,'$'
        input db ?
        cnt db 0
.code
start:
        mov ax,@data
        mov ds,ax

        ; -------------- Takinf sytring input from user --------------
	lea dx,str1
        dispstr str1
        mov dx,0000h
	lea dx,thestr
	mov ah,0Ah
	int 21h

        ; -------------- Display menu logic ------------------
        m1:
        dispstr menustr
        getinput
        cmp input,31h
        jne next1
        call strlen
        jmp m1

        next1:
        cmp input,32h
        jne next2
        dispstr str3
        call displaystr
        jmp m1

	next2:
	cmp input,33h
	jne next3
	call strrev
	jmp m1

	next3:
	cmp input,34h
	jne finalnext
	call strpali
	jmp m1

        ;------------ terminate the program ---------------
        finalnext:
        dispstr byestr
        mov ah,4ch
        int 21h;
	
        ;----------- Procedure for Length of String --------
        strlen proc
		printnextline
                dispstr str2
                mov cx,0204h
                lea si,thestr+1
                mov al,00h
                mov al,[si]
                daa
                mov dl,00h
                mov bl,00h
                mov dl,al
                mov bl,dl
                lab1:
                cmp dl,09h
                jg lab2
                add dl,30h
		setoutput
                jmp baher

                lab2:
                rol bl,cl
                mov dl,bl
                and dl,0Fh
                cmp dl,09h
                jbe down
                add dl,07h

                down:
                add dl,30h
                setoutput
                dec ch
                jnz lab2
                baher:
	ret
        endp

        ;----- Procedure for Displaying String on screen --------
        displaystr proc
                printnextline
                lea dx,thestr+2
                mov ah,09h
                int 21h        
	ret
        endp

        ;--------- Procedure for Reversing the string --------
        strrev proc
                printnextline
                mov cx,0000h
                mov cl,[thestr+1]
                sub cl,1

                lea si,thestr+2
                rep movsb

                mov cl,[thestr+1]
                
                loop1:
                        mov dx,[si]
                        mov ah,02h
                        int 21h
                        dec si
                        dec cl
                        jnz loop1

	ret
        endp

	;-------- Procedure for Checking Palindrome ----------
        strpali proc
		printnextline
                mov cx,0000h
                mov cl,[thestr+1]
                sub cl,1

                lea si,thestr+2
                rep movsb

                mov cl,[thestr+1]
                mov bl,cl
                lea di,thestr+2

                mov cnt,0h
                loop2:
                        mov dx,0000h
                        mov ax,0000h
                        mov dl,[si]
                        mov al,[di]
                        cmp dl,al
                        jne outside
                        inc cnt
                        inc di
                        dec si
                        dec cl
                        jnz loop2
                outside:
                        cmp cnt,bl
                        jne outtest
                        dispstr showequal
                        jmp outtttt
                outtest:
                        dispstr shownotequal                        
                outtttt:
	ret
        endp

end start

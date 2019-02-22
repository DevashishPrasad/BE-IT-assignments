.model small
.data
	extrn str1:byte
	extrn str2:byte
	extrn str3:byte
	equal db 10,13,'The strings are EQUAL$'
	notequal db 10,13,'The strings are NOT EQUAL$'
	found db 10,13,'Substring was FOUND successfully$'
	notfound db 10,13,'Substring was NOT FOUND$'
	space db 10,13,'Number of SPACES in the string - $'
	digit db 10,13,'Number of DIGITS in the string - $'
	upper db 10,13,'Number of UPPERCASE characters in the string - $'
	lower db 10,13,'Number of LOWERCASE characters in the string - $'
	scnt db 0h
	dcnt db 0h
	ucnt db 0h
	lcnt db 0h
	cnt db 0h
.code

        mov ax,@data
        mov ds,ax
	mov es,ax

	public displaystr
	displaystr proc far
		mov dx,0000h
		lea dx,str1+2
		mov ah,09h
		int 21h
		ret
	displaystr endp

	public concatstr
	concatstr proc far
		mov cx,0000h
		mov cl,str1+1

		lea si,str1+2
		lea di,str3+2
		rep movsb 
		
		mov cl,str2+1
		lea si,str2+2
		rep movsb

		mov dx,0000h
		lea dx,str3+2		
		mov ah,09h
		int 21h
		ret
	concatstr endp

	public compstr
	compstr proc far
		mov cx,0000h
		mov ax,0000h
		mov bx,0000h
		
		mov cl,str1+1		
		mov bl,str2+1
		cmp cl,bl
		jne last		
	
		lea si,str1+2
		lea di,str2+2
		repe cmpsb
		jnz last

		lea dx,equal
		mov ah,09h
		int 21h		
		jmp lastest

		last: 	
		lea dx,notequal
		mov ah,09h
		int 21h

		lastest:
		ret
	compstr endp

	public substrng
	substrng proc far
		mov cx,0000h
		mov ax,0000h
		mov bx,0000h
		
		cld
		mov cl,str1+1		
		mov bl,str2+1
		cmp cl,bl
		jna notfound1		
	
		lea si,str1+1

		loop1:
		mov ax,0000
		mov al,[si]
		cmp al,24h
		je notfound1	
		lea di,str2+1
		mov cnt,0
		loopendra:
		inc si
		loop2:
		inc di	
		mov ax,0000h
		mov dx,0000h				
		mov al,[si]
		mov dl,[di]
		cmp al,dl
		jne loop1
		inc cnt
		cmp cnt,bl
		je found1
		jne loopendra	

		found1:
		lea dx,found
		mov ah,09h
		int 21h		
		jmp lastest2

		notfound1: 	
		lea dx,notfound
		mov ah,09h
		int 21h

		lastest2:
		ret
	substrng endp

	public stroccur
	stroccur proc far
		mov cx,0000h
		mov ax,0000h
		mov bx,0000h
		mov scnt,0		
		mov dcnt,0
		mov scnt,0
		mov ucnt,0

		mov cl,str1+1		
		lea si,str1+1

		;-------------- Checking characters ------------------
		m2:
		mov ax,0000h
		inc si
		mov al,[si]
		cmp al,24h
		je outerside
		cmp al,20h
		jne next11
		inc scnt
		jmp m2

		next11:
		cmp al,30h
		jge next22
		jmp m2
		
		next22:
		cmp al,39h
		jg next33
		inc dcnt
		jmp m2

		next33:
		cmp al,41h
		jge next44
		jmp m2

		next44:
		cmp al,5Ah
		jg next55
		inc ucnt
		jmp m2

		next55:
		cmp al,61h
		jge next66
		jmp m2		

		next66:
		cmp al,7Ah
		jge outerside
		inc lcnt
		jmp m2	

		outerside:
		;------------- Printing out the results ------------------
		lea dx,space
		mov ah,09h
		int 21h	
		add scnt,30h
		mov dl,scnt
		mov ah,02h
		int 21h

		lea dx,digit
		mov ah,09h
		int 21h	
		add dcnt,30h
		mov dl,dcnt
		mov ah,02h
		int 21h

		lea dx,upper
		mov ah,09h
		int 21h	
		add ucnt,30h
		mov dl,ucnt
		mov ah,02h
		int 21h

		lea dx,lower
		mov ah,09h
		int 21h	
		add lcnt,30h
		mov dl,lcnt
		mov ah,02h
		int 21h

		ret
	stroccur endp
	
	mov ah,4ch
	int 21h
end

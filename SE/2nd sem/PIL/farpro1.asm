.model small

takestr macro mystr 
	mov dx,0000h
	lea dx,mystr
	mov ah,0Ah
	int 21h
endm
	
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

.data
	stringtakeinput db 10,13,'Enter the String - $'
	stringdisplay db 10,13,'Your string is - $'
	stringconcatenate db 10,13,'Enter the string to be concatenated - $'
	stringcompare db 10,13,'Enter the string to be compared - $'
	stringsubstring db 10,13,'Enter the substring to be searched - $'
	stringspecial db 10,13,'The number of special characters in your string are - $'
	menustr db 10,13,10,13,'---------------MENU----------------',10,13,'1. DISPLAY STRING',10,13,'2. CONCATENATE STRINGS',10,13,'3. COMPARE STRINGS',10,13,'4. FIND SUBSTRING',10,13,'5. COUNTING SPECIAL CHARACTERS',10,13,'ELSE EXIT ',10,13,'ENTER YOUR CHOICE - $'
	str1 db 15 dup('$')
	str2 dp 15 dup('$')
	str3 dp 32 dup('$')
	input db ?
	byestr db 10,13,'Bye! $'
	nextline db 10,13,10,13,'$'
	public str1,str2,str3
.code
        mov ax,@data
        mov ds,ax
	mov es,ax

	printnextline
	
	dispstr stringtakeinput
	takestr str1
	
	;-------------- Display menu logic ------------------
        m1:
        dispstr menustr
        getinput
        cmp input,31h
        jne next1
	dispstr stringdisplay
	extrn displaystr:far
	call displaystr
        jmp m1

        next1:
        cmp input,32h
        jne next2
	printnextline	        
	dispstr stringconcatenate
	takestr str2
	printnextline	
	extrn concatstr:far
        call concatstr
        jmp m1

	next2:
	cmp input,33h
	jne next3
	printnextline		
	dispstr stringcompare
	takestr str2
	printnextline	
	extrn compstr:far
        call compstr
	jmp m1

	next3:
	cmp input,34h
	jne next4
	printnextline	
	dispstr stringsubstring
	takestr str2
	printnextline		
	extrn substrng:far
        call substrng
	jmp m1

	next4:
	cmp input,35h
	jne finalnext
	dispstr stringspecial
	extrn stroccur:far
	call stroccur
	jmp m1

	;------------ terminate the program ---------------
        finalnext:
        dispstr byestr
        mov ah,4ch
        int 21h;
end

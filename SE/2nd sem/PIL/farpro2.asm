.model small
.data
	extrn str1:byte
	extrn str2:byte
	extrn conc:byte
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
		lea di,conc+2
		rep movsb 
		
		mov cl,str2+1
		lea si,str2+2
		rep movsb

		mov dx,0000h
		lea dx,conc+2		
		mov ah,09h
		int 21h
		ret
	concatstr endp

	mov ah,4ch
	int 21h
end

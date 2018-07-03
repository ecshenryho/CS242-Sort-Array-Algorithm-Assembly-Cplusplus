; Assembly module to sort element in an array in descending order
; CS 242
; Student name: Henry Ho

.686
.model flat

.code


_sortArray PROC	;named _test because C automatically prepends an underscode, it is needed to interoperate

	push ebp					;Save caller frame pointer
	mov ebp,esp					;move stack pointer to ebp, etablish current frame pointer
	mov edx, [ebp + 12]			;store the size of array  to edx
	jmp start					
	

start:
	mov esi, [ebp + 8]			;address of the first element in array
	mov edi, [ebp + 12]			;store size of array to edi
	mov eax, 0					;initialize to 0
	mov ebx, 0					;initialize to 0
	mov ecx, 0					;initialize to 0
	
	
	jmp loopMe					;unconditional jump to loopMe
	
loopMe:
	cmp edi, 1					;compare edi to 1, because everytime we go to next elements, edi decreases by 1
	jg compare					;if greater, we not finish yet, go to compare a gain
	jmp restart					;jump to restart

compare:
	mov eax,[ebp+16]			;store the third parameter into eax
	cmp eax,0					;compare it with 0
	je ascending				;if equal go to ascending order
	jmp descending				;if not go to descending order
ascending:
	mov eax,0					;restore eax to 0
	mov eax, [esi + ebx]		;move first element to eax
	add ebx, 4					;add 4 to ebx
	mov ecx, [esi + ebx]		;move second element to ecx
	sub ebx, 4					;subtract 4 from ebx

	cmp eax, ecx				;compare these two elements
	jg swap						;if greater go to swap them
	jmp nextElement				;if not, no need to swap go to next element
descending:
	mov eax,0					;restore eax to 0
	mov eax, [esi + ebx]		;move first element to eax
	add ebx, 4					;add 4 to ebx
	mov ecx, [esi + ebx]		;move second element to ecx
	sub ebx, 4					;subtract 4 from ebx

	cmp eax, ecx				;compare these two elements
	jl swap						;if less than swap them
	jmp nextElement				;if not, no need to swap go to next element

swap:
	mov [esi + ebx], ecx		;move the value of second element into first element place
	add ebx, 4					;add 4 to ebx
	mov [esi + ebx], eax		;move the value of first element into second element place
	sub ebx, 4					;subtract 4 from ebx
	jmp nextElement				;after finish swapping go to next element

nextElement:
	add ebx, 4					;add 4 to ebx to go to next element because it is integer (4 bytes)
	sub edi, 1					;subtract 1 from edi if we have done 1 swap to keep track if we finish swapping first time
	jmp loopMe					;go to loopMe to keep going.

restart:
	sub edx, 1					;subtract 1 from edx to know when i finish and jump to allDone
	cmp edx, 1					;compare edx to 1 
	jg start					;if greater go to start a gain
	jmp allDone					;else go to all done
	
	
allDone:
	pop ebp						;restore caller frame pointer
	ret							;return stored array

_sortArray ENDP

END


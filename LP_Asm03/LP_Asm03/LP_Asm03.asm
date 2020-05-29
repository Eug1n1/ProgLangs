.586P
.model flat, stdcall
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD , : DWORD , : DWORD , : DWORD

.stack 4096

.const

.data

myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles

Arr DD 1h, 2h, 3h, 0h, 5h, 6h, 7h
STR1 byte "В массиве лежит ноль", 0
STR2 byte "В массиве нет нуля", 0


NAM byte "Shumskiy Evgeniy FIT 1-5",0
MB_OK EQU 0
HW DD ?

.code

main PROC
START:

	xor EAX, EAX
	xor EBX, EBX
	xor EDX, EDX
	mov EBX, myPointer
	mov EAX, [EBX + 4]
	mov EDX, [EBX + 8]

	
	lea EDI, Arr
	xor EAX, EAX
	xor EDX, EDX
	mov ECX, lengthof Arr

TASK_C:
	add eax, [EDI]
	add EDI, 4

loop TASK_C
	lea EDI, Arr
	xor EDX, EDX
	mov EBX, 1
	mov ECX, lengthof Arr

ZeroFind:
	mov EDX, [EDI]
	cmp EDX, 0h
	jz Zero
	jnz ZeroUnFind

	Zero:
		xor EBX, EBX
		jmp Exit

	ZeroUnFind:
		add EDI, 4

loop ZeroFind

Exit:
	cmp EBX, 0h
	jz Exit1
	jnz Exit2
	
Exit1:

invoke MessageBoxA, HW, OFFSET STR1, OFFSET NAM, MB_OK
invoke ExitProcess , -1

Exit2:

invoke MessageBoxA, HW, OFFSET STR2,  OFFSET NAM, MB_OK
invoke ExitProcess , -1

main ENDP

end main
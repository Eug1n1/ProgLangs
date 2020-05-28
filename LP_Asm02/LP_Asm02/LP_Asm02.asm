.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
string1 byte "Моя вторая программа", 0
string2 byte "Результат: "
result byte ?, 0
number1 dword 2h
number2 dword 4h



.CODE 

main PROC
START :

	mov		eax, number1
	add		eax, number2
	mov		result, al
	add		result, '0'
	invoke	MessageBoxA, 0, offset string2, offset string1, 0

	invoke ExitProcess, -1

main ENDP

end main

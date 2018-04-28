/*
Title:    Linux x86 execve("/bin/ls -al") - 37 bytes
Author:   Amine Kanane <aminekanane_93@hotmail.com>
Desc:     Executes /bin/ls -al Using The Stack

Disassembly of section .text:

08048060 <_start>:
 8048060:	31 c0                	xor    eax,eax
 8048062:	50                   	push   eax
 8048063:	68 6e 2f 6c 73       	push   0x736c2f6e
 8048068:	68 2f 2f 62 69       	push   0x69622f2f
 804806d:	89 e3                	mov    ebx,esp
 804806f:	50                   	push   eax
 8048070:	89 e2                	mov    edx,esp
 8048072:	68 2d 61 6c 41       	push   0x416c612d
 8048077:	89 e6                	mov    esi,esp
 8048079:	88 46 03             	mov    BYTE PTR [esi+0x3],al
 804807c:	50                   	push   eax
 804807d:	56                   	push   esi
 804807e:	53                   	push   ebx
 804807f:	89 e1                	mov    ecx,esp
 8048081:	b0 0b                	mov    al,0xb
 8048083:	cd 80                	int    0x80

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] =  "\x31\xc0\x50\x68\x6e\x2f\x6c"
                        "\x73\x68\x2f\x2f\x62\x69\x89"
                        "\xe3\x50\x89\xe2\x68\x2d\x61"
                        "\x6c\x41\x89\xe6\x88\x46\x03"
                        "\x50\x56\x53\x89\xe1\xb0\x0b"
                        "\xcd\x80";
main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

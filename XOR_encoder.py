#!/usr/bin/python
# Title:    Simple Python XOR Encoder
# Author:   Amine Kanane <aminekanane_93@hotmail.com>
# Desc:     Simple Python XOR Encoder Using an Arbitrary byte (XOR_key)

XOR_key = 0xda

encoded_code = ""
encoded_code_l = ""

def encode(code, XOR_key, encoded_code, encoded_code_l):
	for x in bytearray(code):
		# XOR Encoding
		y = x^XOR_key
		encoded_code += '\\x'
		encoded_code += '%02x' % y
		encoded_code_l += '0x'
 		encoded_code_l += '%02x,' %y

	print encoded_code
	print "Use This to build : "+encoded_code_l
	print 'Len: %d' % len(bytearray(code))
    	print 'XOR Key to decode : '+hex(XOR_key)

code = "PUT_SHELLCODE_HERE"
encode(code, XOR_key, encoded_code, encoded_code_l)

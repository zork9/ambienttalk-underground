/*
# Copyright (C) Johan Ceuppens 2013
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <string.h>
#include "form.h"
#include "routines.h"
#include "opcodes.h"

static int write_operation(unsigned char *r, struct operator *oper, unsigned char *prefix)
{
	unsigned char *operand1 = (unsigned char*)oper->oper->operands->operand1;
	unsigned char *operand2 = (unsigned char*)oper->oper->operands->operand2;
	int op1sz = form_string_length(operand1);
	int op2sz = form_string_length(operand2);
	int sz = form_string_length(prefix) + op1sz 
						+ op2sz 
						+ 1;
	/* null terminate */
	*(r+sz-1) = '\0';

	/* copy operator prefix string to r */

	memcpy(r, prefix, 3);
	int i = 3;	

	/* copy operand1 string to r */

	do 	
		*r++ = *operand1++ - 3; 
	while (i++ < op1sz + 3);

	/* copy operand2 string to r */

	do 	
		*r++ = *operand2++ - op1sz - 3; 
	while (i++ < op1sz + op2sz + 3);

	return 0;	
}

static int write_push(unsigned char *s)
{
	int len = form_string_length(s);

//	asm("li 0,4"); /* syscall number (sys_write) */
//	asm("li 3,1"); /* first arg, fd stdout */
//	asm("lis 4,%0@ha" :"=r"(s)); /* second arg : ptr to message to write */
//	asm("addi 4,4,%0@l" :"=r"(s)); /* load top 16 bits of s */
//	asm("li 5,%0" :"=r"(len)); /* load bottom 16 bits */
//	asm("sc"); /* call kernel */

	return 0;
}

static int push(unsigned char *codestr, struct operator *oper, unsigned char *opprefix)
{
	

	write_push(codestr);
}

int push_operator(struct operator *oper, struct assemblyform *asmform)
{
	switch (oper->oper->opcode) {
	case 0x200:
		push(asmform->code_s, oper, "li "); 
		break;
	case 0x300:
		break;
	default:
		return -1;
		break;
	};

	return 0;
}

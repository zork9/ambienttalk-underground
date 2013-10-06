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
#ifndef OPCODES_H
#define OPCODES_H

enum OPC { 
	OPCNONE = -1,
	OPCASSIGN = 0x200,
	OPCADD = 0x300,
};

struct op {
	int opcode;

	union operands {
		void *operand1;
		void *operand2;
	} *operands;
};

struct operator { 

	struct op *oper;

};

struct operand {
	char *opnd;
};

int make_operator_operand1(struct operator *oper, void *opnd);
int make_operator_operand2(struct operator *oper, void *opnd);
int make_operator_assign(struct operator *oper);
int make_operator_add(struct operator *oper);

#endif

/*
 * Copyright (c) 2013 Johan Ceuppens <roguedemon6@yahoo.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <roguedemon6@yahoo.com> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Johan Ceuppens 
 * ----------------------------------------------------------------------------
 */
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
#include "opcodes.h"

/*
 * private routines 
 */

static int make_operator(struct operator *oper)
{
	oper->oper->opcode = OPCNONE;
	oper->oper->operands->operand1 = NULL;
	oper->oper->operands->operand2 = NULL;

	return 0;
}

/*
 * public routines
 */

int make_operator_operand1(struct operator *oper, void *opnd)
{
	oper->oper->operands->operand1 = opnd;

	return 0;
}

int make_operator_operand2(struct operator *oper, void *opnd)
{
	oper->oper->operands->operand2 = opnd;

	return 0;
}

int make_operator_assign(struct operator *oper)
{

	make_operator(oper);
	oper->oper->opcode = OPCASSIGN; 

	return 0;
}

int make_operator_add(struct operator *oper)
{

	make_operator(oper);
	oper->oper->opcode = OPCADD; 

	return 0;
}


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


.data

assignop:
	.int 0x200

assignopstr:
	.string "0x200"
	assignoplen = . - assignopstr
	
assignopc:
	.int 0x200

addopc:
	.int 0x300

addopstr:
	.string "0x300"
	addoplen = . - addopstr
	
.text
_exit:
	li 0,1
	li 3,1
	sc

_write_assign:
	
	li 0,4
	li 3,1

	lis 4,msg@ha
	addi 4,4,msg@l
	li 5,assignoplen
	sc


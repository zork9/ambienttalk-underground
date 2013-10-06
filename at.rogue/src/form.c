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

int form_string_length(char *s)
{
	unsigned int len;

	while (*s++ != '\0')
		len++;

	return len;
}

/*
 * s must be terminated by a \0
 */
struct form* make_form(struct form *f, char *s)
{
	unsigned int l = form_string_length(s);

	memcpy(&(f->text), s, l);
	memcpy(&(f->len), s, l);
	return f;
}



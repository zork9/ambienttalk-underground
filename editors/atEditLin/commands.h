/*
Copyright (c) 2013 Software Languages Lab, Vrije Universiteit Brussel

This code is distributed under the MIT License.

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/
/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef _ATEDIT_ATEDITCOMMANDS_
#define _ATEDIT_ATEDITCOMMANDS_

#include<gtkmm.h>
#include<exception>
#include<iostream>
class atEditCommand
{
public:
	class popenexception : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "*** popen exception";
		}
	};


	virtual void execute() = 0;
private:
};


class atEditCommandInterprete : public atEditCommand
{
public:
	atEditCommandInterprete(Glib::ustring const& cmdstr);
	virtual ~atEditCommandInterprete();
	void setcommand(Glib::ustring const& cmdstr);
	Glib::ustring get_buffer();
	Glib::ustring get_input();
	Glib::ustring get_output();
	void execute();
private:
	Glib::ustring commandstring;
	Glib::ustring outputstring;
	FILE *outputfilep;
};

#endif

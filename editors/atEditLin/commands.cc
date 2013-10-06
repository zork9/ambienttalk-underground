/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <gtkmm.h>
#include "commands.h"
#include <iostream>
#include<exception>

atEditCommandInterprete::atEditCommandInterprete(Glib::ustring const& cmdstr) 
	: commandstring(cmdstr)
{}

atEditCommandInterprete::~atEditCommandInterprete()
{}

void atEditCommandInterprete::setcommand(Glib::ustring const& cmdstr)
{
	commandstring = cmdstr;
}
	
Glib::ustring atEditCommandInterprete::get_input()
{
	return commandstring;
}

Glib::ustring atEditCommandInterprete::get_output()
{
	return outputstring;
}

void atEditCommandInterprete::execute()
{
	try {
		outputfilep = popen(commandstring.c_str(), "r");

		outputstring = "";

		if (outputfilep == NULL) throw(popenexception());
	
		char c;
		while ((c = getc(outputfilep)) != EOF)
			outputstring.push_back(c);

		if (c != EOF)
			throw(popenexception());

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


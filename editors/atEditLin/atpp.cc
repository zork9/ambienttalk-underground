/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include<gtkmm.h>
#include "atpp.h"
#include<iostream>
#include<pcrecpp.h>

atEditParser::atEditParser()
{
}

atEditParser::~atEditParser()
{}
	
Glib::ustring atEditParser::parse(atEditFileBuffer const& fbuf)
{

	Glib::ustring endcontents;
	Glib::ustring tmpcontents;

	int i = 0;
	while (i < const_cast<atEditFileBuffer&>(fbuf).length()) {

		switch (const_cast<atEditFileBuffer&>(fbuf)[i]){
		case '{':{
			pcrecpp::RE re("def ");
			if (re.FullMatch(tmpcontents.c_str())) {
				endcontents += tmpcontents;
				endcontents += "{\n";
				tmpcontents.clear();
			}
			i++;
			continue;
		}
		case ';':{	
			endcontents += tmpcontents;
			endcontents += ";\n";
			tmpcontents.clear();
			i++;
			continue;
		}
		default:{
			break;
		}
		}
		tmpcontents.push_back(const_cast<atEditFileBuffer&>(fbuf)[i]);
		i++;	
	}

	return endcontents;
}


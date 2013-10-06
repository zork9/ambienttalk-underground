/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef _ATEDIT_ATEDITPP_
#define _ATEDIT_ATEDITPP_

#include <gtkmm.h>
#include "filebuffer.h"

class atEditParser
{
public: 
	atEditParser();
	virtual ~atEditParser();

	Glib::ustring parse(atEditFileBuffer const& fbuf);

private:
};

#endif

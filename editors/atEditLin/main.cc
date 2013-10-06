/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "window.h"
#include <gtkmm.h>
#include<iostream>

void printusage();

int main(int argc, char *argv[])
{

//  if (argc < 2) {
//	printusage();
//	exit(0);
//  }

  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

 // Gtk::ApplicationWindow window;
//  atEditWindow ateditwindow(argv[1]);
  atEditWindow ateditwindow;//FIXMENOTE if this file is not present , the app does not load, it gets loaded default in the buffer
  return app->run(ateditwindow);
}

void printusage()
{
	std::cout << "atEditLin <filename>" << std::endl;
}

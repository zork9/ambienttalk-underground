/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef _ATEDIT_ATEDITWINDOW_
#define _ATEDIT_ATEDITWINDOW_

#include <gtkmm.h>
#include "file.h"
#include "filebuffer.h"
#include "atpp.h"

class atEditWindow : public Gtk::Window
{
public: 
	atEditWindow();
	virtual ~atEditWindow();

private:
	atEditFile m_file;
	atEditFileBuffer m_filebuffer;
	atEditParser m_parser;

protected:

	void clickedOpenButton();

	Gtk::Button m_openbutton;

 //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView m_TextView;

  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2;

  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit, m_Button_Buffer1, m_Button_Buffer2;

void fill_buffers(Glib::ustring filename);
void on_button_buffer1();
void on_button_buffer2();
void on_button_quit();
};

#endif

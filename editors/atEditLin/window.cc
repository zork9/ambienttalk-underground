/*
Copyright (C) 2013 Johan Ceuppens

This program is free software; you can redistribute it and/or modify it unde    r the terms of the GNU General Public License as published by the Free Softw    are Foundation; either version 2 of the License, or (at your option) any lat    er version.

This program is distributed in the hope that it will be useful, but WITHOUT     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES    S FOR A PARTICULAR PURPOSE. See the GNU General Public License for more deta    ils.

You should have received a copy of the GNU General Public License along with     this program; if not, write to the Free Software Foundation, Inc., 59 Templ    e Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include<gtkmm.h>
#include<gdkmm.h>
#include<gdkmm/window.h>
#include "window.h"
#include<iostream>
#include<fstream>
#include<vector>

atEditWindow::atEditWindow() : m_openbutton("Open"),
 m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Quit(Gtk::Stock::QUIT),
  m_Button_Buffer1("Open"),
  m_Button_Buffer2("Save")
{

	//m_file.init(filename);
	//m_filebuffer.init(filename);
	set_border_width(5);
/*
	m_openbutton.signal_clicked().connect(sigc::mem_fun(*this,
						&atEditWindow::clickedOpenButton));

	add(m_openbutton);
	//m_openbutton.show();
*/

	set_title("atEdit");
	set_default_size(800,600);

	add(m_VBox);

	//Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TextView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);

  //Add buttons:
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Buffer1, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Buffer2, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_spacing(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);

  //Connect signals:
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
              &atEditWindow::on_button_quit) );
  m_Button_Buffer1.signal_clicked().connect(sigc::mem_fun(*this,
              &atEditWindow::on_button_buffer1) );
  m_Button_Buffer2.signal_clicked().connect(sigc::mem_fun(*this,
              &atEditWindow::on_button_buffer2) );

  //fill_buffers(filename);
  

  show_all_children();
}

atEditWindow::~atEditWindow()
{}

void atEditWindow::clickedOpenButton()
{
	std::cout << "clicked Open" << std::endl;
}

void atEditWindow::on_button_buffer1()
{

	Gtk::FileChooserDialog dialog("Please choose a folder", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);	

	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

	Glib::RefPtr<Gtk::FileFilter> filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	int result = dialog.run();

	switch(result){
	case(Gtk::RESPONSE_OK):{
		fill_buffers(dialog.get_filename());
		break;
	}
	case(Gtk::RESPONSE_CANCEL):
	default:{
		break;
	}
	}
/*TODO
	std::vector< Glib::RefPtr<Gtk::TextTag> >tags;
	Gtk::TextIter iter;
	Glib::RefPtr<Gtk::TextTag> tag;
	tag = m_refTextBuffer1->create_tag("blue_fg");
	//tag->set_property("color", Pango::Color);
	tag->set_property("color", "blue");

	tags.push_back(tag);
	iter = m_refTextBuffer1->end();
	m_refTextBuffer1->insert_with_tags(iter, "in blue color", tags);	
*/
/*
	Glib::<RefPtr<Pango::Layout > m_refLayout;

	m_refLayout = print_context->create_pango_layout();
*/
/*	Gdk::Color green;
	Glib::RefPtr<Gdk::GC> gc;
	gc = Gdk::GC::create(this);
	gc->set_foreground(green);
*/	
	m_TextView.set_buffer(m_refTextBuffer1);
}

void atEditWindow::on_button_buffer2()
{
	//m_TextView.set_buffer(m_refTextBuffer2);
	Glib::RefPtr<Gtk::TextBuffer> buf = m_TextView.get_buffer();

	std::ofstream ofs;
	ofs.open(m_file.get().c_str());
	ofs << buf->get_text().c_str();
	ofs.close();

	//DEBUG std::cout << buf->get_text().c_str() << std::endl; 

	return;

}

void atEditWindow::on_button_quit()
{
	hide();
}

void atEditWindow::fill_buffers(Glib::ustring filename)
{
	m_refTextBuffer1 = Gtk::TextBuffer::create();

	m_file.init(filename);
	m_filebuffer.init(filename);

	std::ifstream ifs;
	ifs.open(m_file.get().c_str());//ios::in

	while (!ifs.eof()) {
	
		Glib::ustring buffercontents;
		ifs >> buffercontents;

		if (buffercontents == "\n") {
			m_filebuffer.append("\n");
			continue;
		} else {
			m_filebuffer.append(" ");
		}

		m_filebuffer.append(buffercontents.c_str());//FIXME operator +=, +//FIXME override Glib::ustring for this app and others
	}

	ifs.close();

  Glib::ustring parsedcontents = m_parser.parse(m_filebuffer);

  m_refTextBuffer1->set_text(parsedcontents.c_str());

	std::vector< Glib::RefPtr<Gtk::TextTag> >tags;
	Gtk::TextIter iter;
	Glib::RefPtr<Gtk::TextTag> tag;
	tag = m_refTextBuffer1->create_tag("bold");
	tag->set_property("weight", Pango::WEIGHT_BOLD);

	tags.push_back(tag);
	iter = m_refTextBuffer1->end();
	m_refTextBuffer1->insert_with_tags(iter, "in bold", tags);	
	
	//insert_with_tags_by_name(iter, "foo123", 

  m_refTextBuffer2 = Gtk::TextBuffer::create();
  m_refTextBuffer2->set_text("This is at code.2");
//  m_ButtonBox.pack_start(m_Button_Buffer2, Gtk::PACK_SHRINK);

}



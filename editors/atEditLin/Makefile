CC=g++ -g -O3
CFLAGS= -I/usr/include/gdkmm-3.0 -I/usr/include/gtkmm-3.0 -I/usr/include/glibmm-2.4 -I/usr/lib/i386-linux-gnu/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/i386-linux-gnu/sigc++-2.0/include -I/usr/lib/i386-linux-gnu/gdkmm-3.0/include -I/usr/lib/i386-linux-gnu/pangomm-1.4/include -I/usr/include/giomm-2.4 -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/cairomm-1.0 -I/usr/include/freetype2 -I/usr/lib/i386-linux-gnu/gtkmm-3.0/include -I/usr/include/pangomm-1.4 -I/usr/include/atkmm-1.6 -I/usr/include/atk-1.0 -c -Wall
LDFLAGS= -lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lgtk-3 -lglibmm-2.4 -lcairomm-1.0 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo-gobject -lpango-1.0 -lcairo -lsigc-2.0 -lgobject-2.0 -lglib-2.0 -lpcrecpp
SOURCES=atpp.cc commands.cc file.cc filebuffer.cc main.cc window.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=atEditLin
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS) 

clean:
	rm -f *.o atEditLin

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

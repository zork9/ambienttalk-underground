/*
 Copyright (C) Johan Ceuppens 2009-2011 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
package games;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;

public class Main extends Applet
{

static private int DX = 3;
static private int DY = 3;

public final static void main(String[] args)
{
java.awt.Toolkit toolkit = java.awt.Toolkit.getDefaultToolkit();
//NOTE final
final Frame f = new Frame("Butterfly");
final ImageCanvas imageCanvas = new ImageCanvas("./mapfile.1", 50,37);

imageCanvas.setSize(800,600);
f.add(imageCanvas);//, BorderLayout.LEFT);
f.pack();
f.setSize(800,600);

final Player player = new Player();

f.addKeyListener(
new KeyListener() 
{
public void keyPressed(KeyEvent e) {                                  
//   System.out.println("foo="+e.getKeyChar());
	
	if (e.getKeyChar() == 'j') {
		imageCanvas.addToX(DX);
		f.show();
	}		
	if (e.getKeyChar() == 'l') {
		imageCanvas.addToX(-DX);
		f.show();
	}		
	if (e.getKeyChar() == 's') {
		player.notifySword();//drawWithSword(imageCanvas);
		f.show();
	}		
/*	if (e.getKeyChar() == 'i') {
		enemies[0].addToY(DY);
		imageCanvas.addToY(DY);
		f.show();
	}		
	if (e.getKeyChar() == 'k') {
		enemies[0].addToY(-DY);
		imageCanvas.addToY(-DY);
		f.show();
	}		
*/
}
public void keyReleased(KeyEvent e) {                                  
//   System.out.print("bar="); 
}
public void keyTyped(KeyEvent e) {                                  
//   System.out.print("baz="); 
}
public void actionPerformed(ActionEvent e) {                                  
//   System.out.println("foo"); 
}
});

f.show();

Room room = new Room1(toolkit.getImage("./pics/bg1-800x600.png"),
					50,37,
					"./mapfile.1");
imageCanvas.setRoomData(room);

int n = 1;
int j = 0;

while (true) 
{
/*	if (!imageCanvas.collide(player)) {
		imageCanvas.addToY(-1);
	}
*/
	//	room.draw(imageCanvas);
	player.draw(imageCanvas);

	for (int i = 0; i< 100; i++)
	{
		Enemy e = imageCanvas.enemies[i];

		if (e ==null)
			continue;
		e.update();
		if (e.collide(player, imageCanvas)) {
			if (e.hit()) imageCanvas.enemies[i] = null;	
		}
		imageCanvas.drawEnemy(e);
		//e.draw(imageCanvas);
	}
	//if (j++ % 1000000 == 0) { f.show(); j = 0; }

	if ((room.changeRoom(imageCanvas)) != null)
	{
		room = room.changeRoom(imageCanvas);
	}

	//f.show();

}

}


};

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
//FIX package games;
import java.awt.*;                                                              
import java.awt.event.*;
import java.applet.*;                                                           
                                                                                
public class ImageCanvas extends Component { 
java.awt.Toolkit toolkit = java.awt.Toolkit.getDefaultToolkit();
  private MapTileVector mapvec;
  protected int x; 
  protected int y; 
  protected int w; 
  protected int h; 
  Image playerimage;
  int playerx;
  int playery;
  Image enemyimage;
  int enemyx;
  int enemyy;
  Image bgimage;
  Image roombgimage;
  String mapfilename;  

  public Enemy enemies[] = new Enemy[100];

public ImageCanvas(String filename, int ww, int hh) {  
    w = ww;
    h = hh;               
    mapvec = new MapTileVector(filename, ww, hh);
    bgimage = toolkit.getImage("./pics/defaultbg1-800x600.png");
}                    

public void setRoomData(Room r)
{
r.setRoomData(this);
mapvec = new MapTileVector(mapfilename, w, h);
//reinit map coords 
x = 0;
y = 0;
}


  public boolean collideWithPlayer(Player p)
  {
	return mapvec.collide(p.getX(),p.getY(), x,y);
  }

  public boolean collide(Player p)
  {
	return p.collide(this);
	//return mapvec.collide(p.getX(),p.getY(0);
  }

  public void drawEnemy(Enemy e)
  {
	e.drawEnemy(this);
  }
  public void drawPlayer(Player p)
  {
	p.drawPlayer(this);
  }
  public void drawSwordPlayer(Player p)
  {
	p.drawSwordPlayer(this);
  }
                      
  public void paintPlayer(Player p)
  {
	playerimage = p.getImage();
	playerx = p.getX();
	playery = p.getY();	
  }
  public void paintSwordPlayer(Player p)
  {
	playerimage = p.getSwordImage();
	playerx = p.getX();
	playery = p.getY();	
  }
  public void paintEnemy(Enemy e)
  {
	enemyimage = e.getImage();
	enemyx = (int)e.getX();
	enemyy = (int)e.getY();	
  }

  public void paint(Graphics g) {                                               
    setSize(800,600);                               
/*	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
		{
      			Image img = mapvec.ref(i+j*w).getImage();                                          
			if (img != null) { 
      				g.drawImage(img, x+i*16, y+j*16, this);                                           
			}
		}
  	}     
*/

	//draw bg & room bg
      	g.drawImage(bgimage, 0, 0, this); 
	if (bgimage != null) { 
      		g.drawImage(roombgimage, x, y, this); 
	}
	//draw enemies	
	for (int i = 0; i < 100; i++)
	{
		Enemy e = enemies[i];
		if (e==null)
			continue;
		e.update();
		enemyimage = e.getImage();
		if (enemyimage != null) { 
      			g.drawImage(enemyimage, (int)(e.getX()+x), (int)(e.getY()-y), this);
		}
	}
	//draw player
	if (playerimage != null) {
		//System.out.println("foo");		 
      		g.drawImage(playerimage, playerx, playery, this);
	}
	
}                                                                        

public void addToX(int xx)
{
	//System.out.println("x="+x+" y="+y);
	if (x <= 0 && x > -700)
		x += xx;
	else if (x >= 0)
		x -= 4;
	else if (x <= -700)
		x += 4;	
/*	if (xx < 0) x += xx;
	else if (x > 0) x -= xx;
	return (x);
*/
}

public void addToY(int yy)
{
	y += yy;
}

public void setX(int xx)
{
	x = xx;
}

public void setY(int yy)
{
	y = yy;
}

public int getX()
{
	return x;
}

public int getY()
{
	return y;
}

}; 

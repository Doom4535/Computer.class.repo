//  File:   0313-DotConnect3by3_Graphical.cpp
//  Author: Rick Halterman
//  Date:   3/14/2013 11:20:56 AM

#include <GL/sgl.hpp>
#include "dot3x3_logic.h"

using namespace std;
using namespace sgl;

class Dot;

Dot *begin_dot = nullptr, *end_dot = nullptr;
Point mouse_point(-1, -1);

//  Computes and returns the distance between the points
//  (x1,y1) and (x2,y2).
static double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

//  A dot object corresponds to a dot on a connect-the-dots game.
class Dot : public GraphicalObject
{
public:
	//  Client specifies an (x,y) center position; the dot's radius
	//  is always 0.5.
	Dot(double x, double y) : GraphicalObject(x - 0.5, y - 0.5, 1.0, 1.0) {}

	//  Returns the x component of the dot's center
	double get_x() const
	{
		return left + 0.5;
	}

	//  Returns the y component of the dot's center
	double get_y() const
	{
		return bottom + 0.5;
	}

	//  Draws the dot within the graphical window
	void paint() const override
	{
		fill_circle(left + 0.5, bottom + 0.5, get_width());
	}

	//  When the user depresses the mouse button over this dot 
	//  object this method records this dot as the origin of a 
	//  potential line to another dor.
	void mouse_pressed(double x, double y, MouseButton b) override
	{
		GraphicalObject::mouse_pressed(x, y, b);
		begin_dot = this;
		//cout << "Assigning begin_dot" << endl;
	}

	//  Ensure the dots cannot move
	void move_to(double, double) override {}

	//  Does the point (x,y) fall on this graphical dot?
	bool matches(double x, double y) const
	{
		return distance(get_x(), get_y(), x, y) < 1.5;
	}

};

//  A graphical window that contains dots in a 
//  3 x 3 connect-the-dots game
class Dot3x3Window : public ObjectWindow
{
	//  These nine dot objects make up the
	//  3 x 3 grid of dots
	Dot *nw, *n, *ne;
	Dot *w, *c, *e;
	Dot *sw, *s, *se;

	//  Draws an "X" centered at (x,y).
	//  Used to display player X ownership
	//  of a square.
	void draw_X(double x, double y) const
	{
		set_color(RED);
		set_line_width(8);
		draw_line(x - 3, y + 3, x + 3, y - 3);
		draw_line(x + 3, y + 3, x - 3, y - 3);
		set_color(BLACK);
		set_line_width(5);
	}

	//  Draws a "Y" centered at (x,y).
	//  Used to display player X ownership
	//  of a square.
	void draw_Y(double x, double y) const
	{
		set_color(BLUE);
		set_line_width(8);
		draw_line(x - 3, y + 3, x, y);
		draw_line(x + 3, y + 3, x, y);
		draw_line(x, y, x, y - 3);
		set_color(BLACK);
		set_line_width(5);
	}
public:
	//  Constructs a 3 x 3 dot graphical window
	Dot3x3Window() : ObjectWindow("Connect the Dots 3x3", 0.0, 48.0, 0.0, 48.0)
	{
		//  Create the individual dot objects
		nw = new Dot(12, 36);
		n = new Dot(24, 36);
		ne = new Dot(36, 36);
		w = new Dot(12, 24);
		c = new Dot(24, 24);
		e = new Dot(36, 24);
		sw = new Dot(12, 12);
		s = new Dot(24, 12);
		se = new Dot(36, 12);

		//  Add the dot objects to the graphical window
		add(nw);
		add(n);
		add(ne);
		add(w);
		add(c);
		add(e);
		add(sw);
		add(s);
		add(se);

	}

	//  The window renders itself by drawing dots, line where applicable,
	//  and provides visual feedback to the user connecting the dots.
	void paint() override
	{
		set_line_width(5);
		//  Draw the user's tentative line
		if (begin_dot != nullptr)
		{
			if (mouse_point.x != -1)
			{
				set_color(LIGHT_GRAY);
				draw_dashed_line(begin_dot->get_x(), begin_dot->get_y(), mouse_point.x, mouse_point.y);
				set_color(BLACK);
			}
		}

		//  Draw the lines that the user has added
		if (check_line(NorthWest_North))
			draw_line(nw->get_x(), nw->get_y(), n->get_x(), n->get_y());
		if (check_line(North_NorthEast))
			draw_line(n->get_x(), n->get_y(), ne->get_x(), ne->get_y());
		if (check_line(NorthWest_West))
			draw_line(nw->get_x(), nw->get_y(), w->get_x(), w->get_y());
		if (check_line(North_Center))
			draw_line(n->get_x(), n->get_y(), c->get_x(), c->get_y());
		if (check_line(NorthEast_East))
			draw_line(ne->get_x(), ne->get_y(), e->get_x(), e->get_y());
		if (check_line(West_Center))
			draw_line(w->get_x(), w->get_y(), c->get_x(), c->get_y());
		if (check_line(Center_East))
			draw_line(c->get_x(), c->get_y(), e->get_x(), e->get_y());
		if (check_line(West_SouthWest))
			draw_line(w->get_x(), w->get_y(), sw->get_x(), sw->get_y());
		if (check_line(Center_South))
			draw_line(c->get_x(), c->get_y(), s->get_x(), s->get_y());
		if (check_line(East_SouthEast))
			draw_line(e->get_x(), e->get_y(), se->get_x(), se->get_y());
		if (check_line(SouthWest_South))
			draw_line(sw->get_x(), sw->get_y(), s->get_x(), s->get_y());
		if (check_line(South_SouthEast))
			draw_line(s->get_x(), s->get_y(), se->get_x(), se->get_y());

		//  Draw square owners, if they exist
		//  Left, top
		if (square_owner(LeftTop) == X)
			draw_X((nw->get_x() + n->get_x()) / 2, (nw->get_y() + c->get_y()) / 2);
		else if (square_owner(LeftTop) == Y)
			draw_Y((nw->get_x() + n->get_x()) / 2, (nw->get_y() + c->get_y()) / 2);
		//  Right, top
		if (square_owner(RightTop) == X)
			draw_X((n->get_x() + ne->get_x()) / 2, (n->get_y() + c->get_y()) / 2);
		else if (square_owner(RightTop) == Y)
			draw_Y((n->get_x() + ne->get_x()) / 2, (n->get_y() + c->get_y()) / 2);
		//  Left, bottom
		if (square_owner(LeftBottom) == X)
			draw_X((sw->get_x() + s->get_x()) / 2, (sw->get_y() + c->get_y()) / 2);
		else if (square_owner(LeftBottom) == Y)
			draw_Y((sw->get_x() + s->get_x()) / 2, (sw->get_y() + c->get_y()) / 2);
		//  Right, bottom
		if (square_owner(RightBottom) == X)
			draw_X((s->get_x() + se->get_x()) / 2, (s->get_y() + c->get_y()) / 2);
		else if (square_owner(RightBottom) == Y)
			draw_Y((s->get_x() + se->get_x()) / 2, (s->get_y() + c->get_y()) / 2);

		//  Indicate the current player's turn
		if (current_player() == X)
			draw_text("Player X", 1.0, 1.0, 18);
		else
			draw_text("Player Y", 1.0, 1.0, 18);
	}

	//  Record the mouse position as the user drags the proto-line around on the 
	//  screen.
	void mouse_dragged(double x, double y) override
	{
		mouse_point.x = x;
		mouse_point.y = y;
		repaint();
	}

	//  Actions to perform when the user releases the mouse button
	void mouse_released(double x, double y, MouseButton) override
	{
		//  Attempt to locate an end point to a line
		end_dot = nullptr;
		if (nw->matches(x, y))
			end_dot = nw;
		else if (n->matches(x, y))
			end_dot = n;
		else if (ne->matches(x, y))
			end_dot = ne;
		else if (w->matches(x, y))
			end_dot = w;
		else if (c->matches(x, y))
			end_dot = c;
		else if (e->matches(x, y))
			end_dot = e;
		else if (sw->matches(x, y))
			end_dot = sw;
		else if (s->matches(x, y))
			end_dot = s;
		else if (se->matches(x, y))
			end_dot = se;

		//  Both end points exist, so we need to create a line
		if (begin_dot != nullptr && end_dot != nullptr)
		{
			//cout << "Have end points" << endl;
			if (begin_dot == nw)
			{
				if (end_dot == n)
					add_line(NorthWest_North);
				else if (end_dot == w)
					add_line(NorthWest_West);
			}
			else if (begin_dot == n)
			{
				if (end_dot == nw)
					add_line(NorthWest_North);
				else if (end_dot == c)
					add_line(North_Center);
				else if (end_dot == ne)
					add_line(North_NorthEast);
			}
			else if (begin_dot == ne)
			{
				if (end_dot == n)
					add_line(North_NorthEast);
				else if (end_dot == e)
					add_line(NorthEast_East);
			}
			else if (begin_dot == w)
			{
				if (end_dot == nw)
					add_line(NorthWest_West);
				else if (end_dot == c)
					add_line(West_Center);
				else if (end_dot == sw)
					add_line(West_SouthWest);
			}
			else if (begin_dot == c)
			{
				if (end_dot == n)
					add_line(North_Center);
				else if (end_dot == w)
					add_line(West_Center);
				else if (end_dot == e)
					add_line(Center_East);
				else if (end_dot == s)
					add_line(Center_South);
			}
			else if (begin_dot == e)
			{
				if (end_dot == ne)
					add_line(NorthEast_East);
				else if (end_dot == c)
					add_line(Center_East);
				else if (end_dot == se)
					add_line(East_SouthEast);
			}
			else if (begin_dot == sw)
			{
				if (end_dot == w)
					add_line(West_SouthWest);
				else if (end_dot == s)
					add_line(SouthWest_South);
			}
			else if (begin_dot == s)
			{
				if (end_dot == sw)
					add_line(SouthWest_South);
				else if (end_dot == c)
					add_line(Center_South);
				else if (end_dot == se)
					add_line(South_SouthEast);
			}
			else if (begin_dot == se)
			{
				if (end_dot == e)
					add_line(East_SouthEast);
				else if (end_dot == s)
					add_line(South_SouthEast);
			}
		}
		//  Line request processed.  Clear the accessory
		//  end points to remove the temporary user 
		//  feedback line.
		begin_dot = end_dot = nullptr;
		mouse_point.x = -1;

		//  Repaint the graphical window to show the changes to the
		//  board.
		repaint();
	}

	//  The user may initialize the game by pressing the escape key
	void key_pressed(int key, double x, double y) override
	{
		ObjectWindow::key_pressed(key, x, y);
		if (key == 27) //  Escape key
			initialize_board();  //  Begin a new game
	}
};

int main()
{
	initialize_board();  //  Begin a new game
	//  Create the graphical window to display the game board
	Dot3x3Window *win = new Dot3x3Window;
	win->run();
}

#include "dot3x3_logic.h"

//---------------------------------------------------------------
//  Global variables that maintain the state of the current game
//  These variables are available only to code within this file; the static
//  qualifier ensures that they may not be used outside of this file.
//---------------------------------------------------------------

//  Boolean variables that keep track of whether or not a line
//  exists between two dots; for example, if
//  nw_n is true, this means a line connects dots NorthWest and North.
static bool nw_n, n_ne,
            nw_w, n_c, ne_e,
            w_c, c_e,
            w_sw, c_s, e_se,
            sw_s, s_se;


//  The player whose turn it is currently
static Player player;

//  Stores the owner of the given squares.
//  If leftbottom_player equals X, that means player X owns 
//  the left-bottom square.
static Player lefttop_player, righttop_player,
              leftbottom_player, rightbottom_player;


//---------------------------------------------------------------
//  Functions used only by functions within this file.
//  These functions are NOT available to clients
//  The 'static' keywords makes them inaccessible outside of 
//  this file.
//---------------------------------------------------------------

//  Updates the owner of a square, if possible.
//  Returns true if it updates the square' s owner; otherise,
//  it returns false.
static bool update_square(SquarePosition sq)
{
	if (sq == LeftTop && lefttop_player == None && nw_n && nw_w && n_c && w_c)
	{
		lefttop_player = player;
		return true;
	}
	else if (sq == RightTop && righttop_player == None && n_ne && ne_e && c_e && n_c)
	{
		righttop_player = player;
		return true;
	}
	else if (sq == LeftBottom && leftbottom_player == None && w_c && c_s && sw_s && w_sw)
	{
		leftbottom_player = player;
		return true;
	}
	else if (sq == RightBottom && rightbottom_player == None && c_e && e_se && s_se && c_s)
	{
		rightbottom_player = player;
		return true;
	}
	else
		return false;  //  Owners unchanged
}

//  Attempts to update the owners of all squares that a new line
//  might affect.  Returns true if one or more squares receives a
//  new owner.
static bool update_squares()
{
	bool lt = update_square(LeftTop), rt = update_square(RightTop),
		lb = update_square(LeftBottom), rb = update_square(RightBottom);
	return lt || rt || lb || rb;
}


//  Returns true if a given line is part of a completed square;
//  Returns false if the line is not part of a completed square.
static bool check_square(LinePosition line)
{
	switch (line)
	{
		case NorthWest_North: return lefttop_player != None;
		case North_NorthEast: return righttop_player != None;
		case NorthWest_West: return lefttop_player != None;
		case North_Center: return lefttop_player != None || righttop_player != None;
		case NorthEast_East: return righttop_player != None;
		case West_Center: return lefttop_player != None || leftbottom_player != None;
		case Center_East: return righttop_player != None || rightbottom_player != None;
		case West_SouthWest: return leftbottom_player != None;
		case Center_South: return leftbottom_player != None || rightbottom_player != None;
		case East_SouthEast: return rightbottom_player != None;
		case SouthWest_South: return leftbottom_player != None;
		case South_SouthEast: return rightbottom_player != None;
		default: return false;
	}
}



//---------------------------------------------------------------
//  Functions that reveal or control the state of the current game
//  These functions are available to clients
//---------------------------------------------------------------

//  Attempts to add a line between the two dots.
//  Adds the line and returns true if a line may be added.
//  If the line already is present, the function 
//  does not change the state of the board and returns false.
bool add_line(LinePosition line)
{
	bool line_added = false;  // Unsuccessful by default
	if (line == NorthWest_North && !nw_n)
	{
		nw_n = true;
		line_added = true;
	}
	else if (line == North_NorthEast && !n_ne)
	{
		n_ne = true;
		line_added = true;
	}
	else if (line == NorthWest_West && !nw_w)
	{
		nw_w = true;
		line_added = true;
	}
	else if (line == North_Center && !n_c)
	{
		n_c = true;
		line_added = true;
	}
	else if (line == NorthEast_East && !ne_e)
	{
		ne_e = true;
		line_added = true;
	}
	else if (line == West_Center && !w_c)
	{
		w_c = true;
		line_added = true;
	}
	else if (line == Center_East && !c_e)
	{
		c_e = true;
		line_added = true;
	}
	else if (line == West_SouthWest && !w_sw)
	{
		w_sw = true;
		line_added = true;
	}
	else if (line == Center_South && !c_s)
	{
		c_s = true;
		line_added = true;
	}
	else if (line == East_SouthEast && !e_se)
	{
		e_se = true;
		line_added = true;
	}
	else if (line == SouthWest_South && !sw_s)
	{
		sw_s = true;
		line_added = true;
	}
	else if (line == South_SouthEast && !s_se)
	{
		s_se = true;
		line_added = true;
	}
	//  If the line was added successfully, 
	//  check to see if it completes a square
	if (line_added &&  !update_squares())
	{
		if (player == X)
			player = Y;
		else
			player = X;
	}
	return line_added;
}

//  Returns the player who owns the given square.
//  Returns None if the square has no owner.
Player square_owner(SquarePosition sq)
{
	switch (sq)
	{
		case LeftTop: return lefttop_player;
		case RightTop: return righttop_player;
		case LeftBottom: return leftbottom_player;
		case RightBottom: return rightbottom_player;
		default: return None;
	}
}

//  Returns true if the line between the two points 
//  is active; otherwise, returns false.
static bool check_line(LinePosition line)
{
	if (line == NorthWest_North)
		return nw_n;
	else if (line == North_NorthEast)
		return n_ne;
	else if (line == NorthWest_West)
		return nw_w;
	else if (line == North_Center)
		return n_c;
	else if (line == NorthEast_East)
		return ne_e;
	else if (line == West_Center)
		return w_c;
	else if (line == Center_East)
		return c_e;
	else if (line == West_SouthWest)
		return w_sw;
	else if (line == Center_South)
		return c_s;
	else if (line == East_SouthEast)
		return e_se;
	else if (line == SouthWest_South)
		return sw_s;
	else if (line == South_SouthEast)
		return s_se;
	else
		return false;
}

//  Determines if the game can continue or if all squares are complete
bool game_over()
{

	return lefttop_player != None    && righttop_player != None
		&& leftbottom_player != None && rightbottom_player != None;
}

void initialize_board()
{
	//  Clear all the lines from the board
	nw_n = n_ne = nw_w = n_c = ne_e = w_c = c_e = w_sw = c_s = e_se = sw_s = s_se = false;

	//  Clear all the squares (neither player owns any squares)
	lefttop_player = righttop_player = leftbottom_player = rightbottom_player = None;

	//  X always begins
	player = X;
}

//  Returns the player whose turn it is to move
Player current_player()
{
	return player;
}

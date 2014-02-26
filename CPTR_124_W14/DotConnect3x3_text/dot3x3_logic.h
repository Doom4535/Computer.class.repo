//  dot3x3_logic.h

#ifndef _DOT3X3_LOGIC_H_
#define _DOT3X3_LOGIC_H_

//------------------------------------------------------------------------------
//  Custom enumerated types used by this game
//------------------------------------------------------------------------------

//  The positions of the 12 lines
enum LinePosition {
	NorthWest_North, North_NorthEast,                //   @-@-@
	NorthWest_West, North_Center, NorthEast_East,    //   | | |
	West_Center, Center_East,                        //   @-@-@
	West_SouthWest, Center_South, East_SouthEast,    //   | | |
	SouthWest_South, South_SouthEast,                //   @-@-@
	NoLine
};

//  Square locations
enum SquarePosition {
	LeftTop, RightTop,
	LeftBottom, RightBottom
};

//  Player X, player Y, or no player
enum Player { X, Y, None };


//------------------------------------------------------------------------------
//  Functions that reveal or control the state of the current game
//  These functions are available to clients
//------------------------------------------------------------------------------

//  Attempts to add a line between the two dots.
//  Adds the line and returns true if a line may be added.
//  If the line already is present, the function 
//  does not change the state of the board and returns false.
bool add_line(LinePosition line);

//  Returns true if the given line 
//  is active; otherwise, returns false.
bool check_line(LinePosition line);

//  Returns the player who owns the given square.
//  Returns None if the square has no owner.
Player square_owner(SquarePosition sq);

//  Determines if the game can continue or if all squares are complete
bool game_over();

//  Clears all the lines from the board
void initialize_board();

//  Returns the player whose turn it is to move
Player current_player();

#endif

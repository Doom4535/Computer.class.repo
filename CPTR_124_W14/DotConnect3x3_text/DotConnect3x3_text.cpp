//  File:   0313-DotConnect3by3.cpp
//  Author: Rick Halterman
//  Date:   3/13/2013 9:56:58 AM

#include <iostream>
#include "dot3x3_logic.h"

using namespace std;

//  Character representation for a player
char show_player(Player p)
{
	if (p == X)
		return 'X';
	else if (p == Y)
		return 'Y';
	else
		return ' ';  //  player is None
}

//  Draws the connect the dots game using
//  text graphics
void draw_game()
{
	//  0-1-2     ------------------------------------
	cout << '0';
	if (check_line(NorthWest_North))
		cout << '-';
	else
		cout << ' ';
	cout << '1';
	if (check_line(North_NorthEast))
		cout << '-';
	else
		cout << ' ';
	cout << '2' << endl;

	//  | | |     ------------------------------------
	if (check_line(NorthWest_West))
		cout << '|';
	else
		cout << ' ';
	cout << show_player(square_owner(LeftTop));
	if (check_line(North_Center))
		cout << '|';
	else
		cout << ' ';
	cout << show_player(square_owner(RightTop));
	if (check_line(NorthEast_East))
		cout << '|' << endl;
	else
		cout << ' ' << endl;

	//  3-4-5     ------------------------------------
	cout << '3';
	if (check_line(West_Center))
		cout << '-';
	else
		cout << ' ';
	cout << '4';
	if (check_line(Center_East))
		cout << '-';
	else
		cout << ' ';
	cout << '5' << endl;

	//  | | |     ------------------------------------
	if (check_line(West_SouthWest))
		cout << '|';
	else
		cout << ' ';
	cout << show_player(square_owner(LeftBottom));
	if (check_line(Center_South))
		cout << '|';
	else
		cout << ' ';
	cout << show_player(square_owner(RightBottom));
	if (check_line(East_SouthEast))
		cout << '|' << endl;
	else
		cout << ' ' << endl;

	//  6-7-8     ------------------------------------
	cout << '6';
	if (check_line(SouthWest_South))
		cout << '-';
	else
		cout << ' ';
	cout << '7';
	if (check_line(South_SouthEast))
		cout << '-';
	else
		cout << ' ';
	cout << '8' << endl;
}

//  Determine the line between two dots.
//  ch1 and ch2 represent the dots in the pattern
//  0 1 2
//  3 4 5
//  6 7 8
//  The function returns the line position between the dots.
LinePosition make_line(char ch1, char ch2)
{
	switch (ch1)
	{
		case '0':
			switch (ch2)
			{
				case '1':
					return NorthWest_North;
				case '3':
					return NorthWest_West;
			}
			break;
		case '1':
			switch (ch2)
			{
				case '0':
					return NorthWest_North;
				case '4':
					return North_Center;
				case '2':
					return North_NorthEast;
			}
			break;
		case '2':
			switch (ch2)
			{
				case '1':
					return North_NorthEast;
				case '5':
					return NorthEast_East;
			}
			break;
		case '3':
			switch (ch2)
			{
				case '0':
					return NorthWest_West;
				case '4':
					return West_Center;
				case '6':
					return West_SouthWest;
			}
			break;
		case '4':
			switch (ch2)
			{
				case '1':
					return North_Center;
				case '3':
					return West_Center;
				case '5':
					return Center_East;
				case '7':
					return Center_South;
			}
			break;
		case '5':
			switch (ch2)
			{
				case '2':
					return NorthEast_East;
				case '4':
					return Center_East;
				case '8':
					return East_SouthEast;
			}
			break;
		case '6':
			switch (ch2)
			{
				case '3':
					return West_SouthWest;
				case '7':
					return SouthWest_South;
			}
			break;
		case '7':
			switch (ch2)
			{
				case '4':
					return Center_South;
				case '6':
					return SouthWest_South;
				case '8':
					return South_SouthEast;
			}
			break;
		case '8':
			switch (ch2)
			{
				case '5':
					return East_SouthEast;
				case '7':
					return South_SouthEast;
			}
			break;
	}
	return NoLine;  //  Default return value
}

int main()
{
	//  Start a new game
	initialize_board();
	draw_game();
	while (!game_over())
	{
		char begin, end;
		cout << "Move for player " << ((current_player() == X) ? "X" : "Y") << ": ";
		cin >> begin;  //  Get the first dot
		if (begin == 'Q' || begin == 'q')  //  'Q' quits the program
			break;
		cin >> end;    //  Get the other dot to connect with a line
		cout << endl;
		//  Add the line, if possible
		LinePosition new_line = make_line(begin, end);
		if (new_line != NoLine && add_line(new_line))
			draw_game();
		else
			cout << "Connection not possible" << endl;
	}
	cout << endl << "***  G A M E   O V E R  ***" << endl;
}

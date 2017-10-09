#include "Piezas.h"
#include <vector>
#include <iostream>

using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	turn = X;
	for(int i =0; i<BOARD_ROWS;i++)
	{
		std::vector<Piece> temp;	
		for(int j=0; j<BOARD_COLS;j++)
		{
			temp.push_back(Blank);
		}
		board.push_back(temp);
	}
	
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	turn = X;
	for(int i=0; i<BOARD_ROWS;i++)
		for(int j=0;j<BOARD_COLS;j++)
			board[i][j]=Blank;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
int i=0;
	if(column >=BOARD_COLS)
		return Invalid;

	for(i =BOARD_ROWS-1;i>=0;i--)
	{
		if(board[i][column] ==Blank)
		{
			board[i][column]=turn;
			if(turn == X)
				turn = O;
			else
				turn = X;
			return board[i][column];	
		}	
	}
	if (i<0)
		return Invalid;
	else 
		return Blank;
//    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	if(row >=BOARD_ROWS || column>=BOARD_COLS)
		return Invalid;
	return board[row][column];
  //  return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
int num_x_hor=0;
int num_y_hor=0;
int num_y_ver=0;
int num_x_ver=0;
int temp1 =0;
int temp2 =0;
int temp3 =0;
int temp4 =0;
int max_X=0;
int max_O=0;
	for(int i =0; i<BOARD_ROWS;i++)
	{
		for(int j =0 ; j<BOARD_COLS; j++)
		{
			if(board[i][j] ==Blank)
			{	
				return Invalid;
			}	
			if(board[i][j] ==X)
			{
				if(j==0 && i ==0)
				{	
					num_x_hor++;
					if(board[i][j] == board[i+1][j])
						{
							if(num_x_ver <=2)
								num_x_ver =2;
							if(board[i][j] == board[i+2][j] && num_x_ver != BOARD_ROWS) 
								num_x_ver++;	
						}
				}
				if(j>0 && i==0 && board[i][j-1] == X)
				{	
					num_x_hor++;
					if(board[i][j] == board[i+1][j])
						{
							if(num_x_ver <=2)
								num_x_ver =2;
							if(board[i][j] == board[i+2][j] && num_x_ver != BOARD_ROWS) 
								num_x_ver++;	
						}
				}
				if(j==0 && i ==1)
					temp1++;
				if(j>0 && i==1 &&temp1 ==0)
					temp1++;
				if(j>0 && i==1 && board[i][j-1] == X)
					temp1++;
				if(j==0 && i ==2)
					temp2++;
				if(j>0 && i==2 &&temp2 ==0)
					temp2++;
				if(j>0 && i==2 && board[i][j-1] == X)
					temp2++;
			}
			else
			{
				if(j==0 && i ==0)
				{	
					num_y_hor++;
					if(board[i][j] == board[i+1][j])
						{
							if(num_y_ver <=2)
								num_y_ver =2;
							if(board[i][j] == board[i+2][j] && num_y_ver != BOARD_ROWS) 
								num_y_ver++;	
						}
				}
				if(j>0 && i==0 && board[i][j-1] == O)
				{	
					num_y_hor++;
					if(board[i][j] == board[i+1][j])
						{
							if(num_y_ver <=2)
								num_y_ver =2;
							if(board[i][j] == board[i+2][j] && num_y_ver != BOARD_ROWS) 
								num_y_ver++;	
						}
				}
				if(j==0 && i ==1)
					temp3++;
				if(j>0 && i==1 &&temp3 ==0)
					temp3++;
				if(j>0 && i==1 && board[i][j-1] == O)
					temp3++;
				if(j==0 && i ==2)
					temp4++;
				if(j>0 && i==2 &&temp4 ==0)
					temp4++;
				if(j>0 && i==2 && board[i][j-1] == O)
					temp4++;
			
			}
		}
	}

	num_x_hor = num_x_hor > (temp1 >temp2 ? temp1 : temp2) ? num_x_hor : (temp1>temp2 ? temp1 : temp2);	
	max_X = num_x_hor > num_x_ver ? num_x_hor : num_x_ver;	
	num_y_hor = num_y_hor > (temp3 >temp4 ? temp3 : temp4) ? num_y_hor : (temp3>temp4 ? temp3 : temp4);	
	max_O = num_y_hor > num_y_ver ? num_y_hor : num_y_ver;	
	
	if(max_X > max_O)
		return X;
	if(max_O > max_X)
		return O;
	else
		return Blank;
   // return Blank;
}

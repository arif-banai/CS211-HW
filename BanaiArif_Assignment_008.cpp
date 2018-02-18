#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Fancy 8 Queens

//Returns false if the position is not valid. Returns true otherwise
bool valid(int q[], int col) {
	for (int i = 0; i < col; i++) {
		if (q[col] == q[i] || (col - i) == abs(q[col] - q[i]))
			return false;
	}

	return true;
}

//Backtrack to previous column and check if all solutions have been found
void backtrack(int &col) {
	col--;
	if (col == -1) {
		//All solutions have been found
		exit(1);
	}
}

//Prints the fancy chessboard
void print(int q[]) {
	static unsigned int count = 0;
	cout << "Solution #" << ++count << endl << endl;

	int i, j, k, l;
	typedef char box[5][7];
	box bb, wb, *board[8][8];
	char b = char(219);			//A "white" square

	//Black space with a Queen
	box bq =
	    {
	        b, b, b, b, b, b, b,
	        b, ' ', b, ' ', b, ' ', b,
	        b, ' ', ' ', ' ', ' ', ' ', b,
	        b, ' ', ' ', ' ', ' ', ' ', b,
	        b, b, b, b, b, b, b
	    };

	//White space with a Queen
	box wq =
	    {
	        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	        ' ', b, ' ', b, ' ', b, ' ',
	        ' ', b, b, b, b, b, ' ',
	        ' ', b, b, b, b, b, ' ',
	        ' ', ' ', ' ', ' ', ' ', ' ', ' '
	    };

	//Initialize the arrays representing white and black spaces
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			wb[i][j] = ' ';
			bb[i][j] = b;
		}
	}

	//The 8x8 array "board" will be initialized with the address of either:
	//The array of the 5x7 white square, with or without a queen
	//The array of the 5x7 black square, with out without a queen
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) { 	//If the position is an even position, it is a white space
				if (q[i] == j) {			//If there is a queen in this space, draw a white space with a queen
					board[i][j] = &wq;
				} else {					//If not, draw an empty white space
					board[i][j] = &wb;
				}
			} else {					//If not, it is a black space
				if (q[i] == j) {			//If there is a queen in this space, draw a black space with a queen
					board[i][j] = &bq;
				} else {					//If not, draw an empty black space
					board[i][j] = &bb;
				}
			}
		}
	}

	//Print upper border
	cout << " ";
	for (i = 0; i < 7 * 8; i++) {
		cout << '_';
	}
	cout << endl;

	//Printing the board
	for (i = 0;i < 8; i++) {						//tracks the row on 8x8 chessboard
		for (k = 0;k < 5; k++) {					//tracks the row of the 5x7 space
			cout << " " << char(179); //prints left border
			for (j = 0; j < 8; j++) {				//tracks the col on the 8x8 chessboard
				for (l = 0; l < 7; l++) {			//tracks the col on the 5x7 space
					cout << (*board[i][j])[k][l];	//prints the board, row by row, filling in
														//each individual row within the spaces before moving to the next row
				}
			}
			cout << char(179) << endl; //prints right border
		}
	}

	//Print lower border
	cout << " ";
	for (i = 0; i < 7 * 8; i++) {
		cout << char(196);
	}
	cout << endl << endl;
}

//Essentially, the 8x8 board contains the addresses of black squares and white squares, either of which may contain a queen.
//The board is printed by printing each character of the 5x7 squares, which comprise each space in the 8x8 board

int main() {
	int q[8];
	q[0] = 0;
	int c = 1;

	bool backtracking = false; //this variable will be used to determine whether the row should be reset to -1 in that column

	while (true) {
		while (c < 8) { 		//this should repeat 8 times for all the columns

			if (!backtracking) {	//if we are not backtracking, reset the row to 0 [(-1)++ == 0]
				q[c] = -1;
			}

			while (q[c] < 8) { 	//loop 8 times for the 8 rows
				if (++q[c] == 8) { 			//if the last row has been reached, begin backtracking
					backtracking = true;
					backtrack(c);
					break;
				}

				if (valid(q, c)) {			//if the position is valid, move to the next column and proceed
					backtracking = false;
					c++;
					break;
				}
			}
		}
		//Solution reached, print solution and start backtracking for more
		print(q);
		backtracking = true;
		backtrack(c);
	}
}

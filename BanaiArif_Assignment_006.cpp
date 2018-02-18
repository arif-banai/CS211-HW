#include <iostream>
#include <cmath>
using namespace std;

//Eight numbers in a cross. No two squares contain consecutive integers.

void backtrack(int &c) {
	c--;
	if (c == -1) {
		//All solutions have been found if (c == -1)
		exit(1);
	}
}

//Prints a solution from array a
void print(int a[]) {
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

//Returns false if any adjacent position contains an invalid value. Returns true otherwise.
bool valid(int a[8], int b, int c) {
	for (int i = 0; i < b; i++) {
		if (a[i] == a[b] || (abs(a[b] - a[c]) == 1))
			return false;
	}

	return true;
}

int main() {
	int ans[8] = { 0 };
	int c = 0;
	int counter = 0;

	int a[8][5] = {
				{-1, -1, -1, -1, -1 },
				{ 0, -1, -1, -1, -1 },
				{ 0,  1, -1, -1, -1 },
				{ 0,  2, -1, -1, -1 },
				{ 1,  2, -1, -1, -1 },
				{ 1,  2,  3,  4, -1 },
				{ 2,  3,  5, -1, -1 },
				{ 4,  5,  6, -1, -1 } };
	//This array represents the positions on the board that must be checked when 
	//placing a value in a certain position, allowing the program to find solutions.
	
	//There are 8 positions on the board, so we need 8 rows.
	//At any given moment on the board, you will never have to check more than 4 discrete positions.
	//So, we need 5 columns, to have space for (-1) to represent the end of the search.

	while (true) {
		while (c < 8) {			//Goes through each row
			if (++ans[c] > 8) {	//Goes through each value for a certain position
				ans[c] = 0;
				backtrack(c);
				continue;
			}

			for (int i = 0; i < 5; i++) {
				if (a[c][i] == -1) {		//
					if (++c == 8) {
						//Solution has been found, print it and find more
						cout << "Solution #" << ++counter << endl;
						print(ans);
						backtrack(c);
					}
					break;
				}
				if ( !valid(ans, c, a[c][i]) ) {
					//If not valid, this number doesn't work. Try another
					break;
				}
			}
		}
	}
}

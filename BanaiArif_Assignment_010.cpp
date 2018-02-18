#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Returns false if the position is invalid. Returns true otherwise.
bool valid(int q[], int col) {
	for (int i = 0; i < col; i++)
		if (q[col] == q[i] || (col - i) == abs(q[col] - q[i]))
			return false;
	return true;
}

int main() {
	int n = 0;
	cout << "Please enter a value for n: ";
	cin >> n;

	for (int i = 1; i <= n;i++) {
		int *q = new int[i];			//dynamically allocate array of size i

		int counter = -1;
		int c = 0; 					//column
		bool backtracking = false;	//this variable will be used to determine whether the row should be reset to -1 in that column

		while (true) {

			while (c < i) {			//Loops through the columns

				if (!backtracking) {
					q[c] = -1;
				}

				while (q[c] < i) {	//Loops through the rows
					if (++q[c] == i) {		//If we reach the last row, start backtracking
						backtracking = true;
						c--;
						break;
					}

					if (valid(q, c)) {	//If the position is valid, then continue to next col
						backtracking = false;
						c++;
						break;
					}
				}
				if (c == -1) {
					//A solution has been reached
					break;
				}
			}
			counter++;
			c--;
			backtracking = true;
			if (c <= -1) {
				//All solutions have been found.
				break;
			}
		}
		delete[] q; //free up heap memory taken by q
		if(counter == 1) {
			cout << "There is "  << counter << " solution to the "  << i << " Queen problem."  << endl;
		} else {
			cout << "There are " << counter << " solutions to the " << i << " Queens problem." << endl;
		}
	}

	return 0;
}

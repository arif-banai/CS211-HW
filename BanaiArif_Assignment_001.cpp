#include <iostream>
using namespace std;

/*
	This program attempts to find the first perfect square whose last two digits are odd.
	It does so by using a while-loop to iterate through all possible perfect squares (at least until INT_MAX),
	using a variable located outside the while-loop to keep track of the iteration. The function lastTwoDigitsOdd
	is used to simplify the process of checking the last two digits.

	The program determines that 131073 is the answer. However, this number is not a perfect square.
	
	This reveals that this number (whose last two digits are odd) might not exist.
*/

bool lastTwoDigitsOdd(int number) {
	if(number < 100)
		return false;

	if( (number % 10) % 2 == 0)
		return false;
	if( ((number /= 10) % 10) % 2 == 0)
		return false;
	
	return true;
}

int main() {
	int i = 1;
	bool done = false;
	
	while(!done) {
		int perfectSquare = i * i;
		if(lastTwoDigitsOdd(perfectSquare)) {
			cout << perfectSquare << " matches this search.";
			done = true;
		} else {
			i++;
		}
	}
	return 0;
}

#include <iostream>
using namespace std;

/*
	The nested for-loop provides two variables to traverse through the array,
	and provides a way to mathmatically determine if A can be right shifted into B.
	Modulus is performed on (i+j) in order to "circle" around the array, preventing 
	the program from accessing memory beyond the array.

	The outer loop is used to track the shift, with (i = 1) representing 1 shift to the right.
	The goto is used to break out of the inner loop and cause the outer loop to iterate, incrementing i by 1.
	The function returns true only after checking every possible "right-shift" of array A into array B, with the length of the array (n), as the limit.    
*/

bool equivalent(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] != b[(j + i) % n]) 
				goto nextShift;
		}
		
		return true;
		nextShift: ;
	}
	return false;
}

int main() {
	int foo[] = {1, 2, 3, 4, 5};
	int bar[] = {3, 4, 5, 1, 2};

	if(equivalent(foo, bar, 5)) {
		cout << "Equivalent arrays!";
	} else {
		cout << "Not equivalent";
	}

	return 0;
}

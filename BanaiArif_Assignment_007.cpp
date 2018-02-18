#include <iostream>
using namespace std;

//Assignment 7

int main() {
	//Three rows, two columns
	int b[3][2];
	
	//This line prints the size of the whole array (b)
	//b has space for 6 ints, meaning it has 24 bytes of space (int = 4 bytes)
	cout << sizeof(b)<<endl;	
	
	//This line prints the size of the pointer at row 0
	//There are three rows and two columns, therefore two elements per row
	//The output is 8 (as in 8 bytes)
	cout << sizeof(b+0)<<endl;
	
	//returns the size of the array as pointed to by (b+0)
	//The amount of bytes in row 0
	cout << sizeof(*(b+0))<<endl;  
	
	//Prints the address of the first element of the first array in b
	cout << "The address of b is: "<<b<<endl;
	
	//Prints the address of the first element of the second array in b
	//The address of the second row is 8 bytes over from the first
	cout << "The address of b+1 is: "<<b+1<<endl;
	
	//Prints the same values as the two previous lines 
	cout << "The address of &b is: "<<&b<<endl;  
	cout << "The address of &b+1 is: "<<&b+1<<endl<<endl;  
	
	return 0;
} 

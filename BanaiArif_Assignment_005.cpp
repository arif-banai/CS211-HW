#include <iostream>
using namespace std;

//8 Queens problem, using a 1-Dimensional array and NO "goto" statements

//Validates the position for the queen in its current row and col
bool ok(int q[], int col) {
	for(int i = 0;i < col;i++) {
		if(q[col] == q[i] || (col - i) == abs(q[col] - q[i]))
			return false;
	}

    	return true;
}

//Go back to previous column
void backtrack(int &col){
	col--;
	if(col == -1) {
		//All solutions have been found
        	exit(1);
	}
}

//This function prints the solutions, but flips the symmetry of each solution
//The solutions are still valid, but are flipped when printed
//The solutions in the 1D array are stored differently than they are presented to the client
void print(int q[]) {
	for(int i = 0;i < 8;i++) {
		for(int j = 0;j < 8;j++) {
			if(q[j] == i)
				cout << "Q" << " ";
			else
				cout << "0" << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int main() {
	int q[8]; 
	q[0] = 0;

	int c = 1;
	int counter = 0;
	
	bool backtracking = false; //controls the backtracking logic

	while(true) {
		while(c < 8) {

            		if(!backtracking)
				q[c] = -1;
            	
			backtracking = true;
            
            		while(q[c]<8) {
				q[c]++;
                
                		if(q[c] == 8) {
					backtracking = true;
					backtrack(c);
					break;
                		}
               	 
                		if(ok(q,c)) {
                    			backtracking = false;
                    			c++;
                    			break;
                		}
            		}
        	}
	//Solution has been reached. Print board, continue solving for solutions
        cout << "Solution #" << ++counter << endl << endl;
	print(q);
        backtracking = true;
        backtrack(c);
    	}
	//Unreachable
}

#include <iostream>
using namespace std;

int main() {
	int q[8][8] = {0};
	q[0][0] = 1;

	int r, c=0, i, solutions = 0;
	NC: c++;
		if(c==8)
			goto print;
		r = -1;
	NR: r++;
		if(r>=8)
			goto backtrack;
		
		//Row conflict test
		for(i = 0;i < c;i++) {
			if(q[r][i] == 1)
				goto NR;		
		}
		
		//Up-diagonal
		for(i = 1;(r-i) >= 0 && (c-i) >= 0;i++) {
			if(q[r-i][c-i] == 1)
				goto NR;
		}
	
		//Down-Diagonal
		for(i = 1;(r+i) < 8 && (c-i) >= 0;i++) {
			if(q[r+i][c-i] == 1)
				goto NR;
		}
	
		//Place queen, continue to next column
		q[r][c] = 1;
                goto NC;
	//Go to the previous column and remove the most recent queen
	backtrack: c--;
		if(c == -1) {
			//cout << "r = " << r << " c= " << c << " i= " << i; 
			return 0;
		}
		
		r = 0;
		while(q[r][c] != 1) {
			r++;
		}

		q[r][c] = 0;
                goto NR;
	print: solutions++;
		cout << "Solution #" << solutions << endl;

		for(int i = 0;i < 8;i++) {
                	for(int j = 0;j < 8;j++) {
                        	cout << q[i][j] << " ";
                	}
			cout << endl;
		}
		cout << endl;

		goto backtrack;
}	

// Kunsang Tsering 
// 2d 8 Queens with backtrackin using goto statement.
#include<iostream>
using namespace std;

int main (){
int numSolutions = {1};
int q[8][8] = {0};
int r = 0, c = 0;
q[r][c] = 1;

nc:
    c++; // increment (+) to next column;
        if(c == 8) goto print; // Position Check;
    r = -1; // sets row 1 spot above the board;

nr: // goes down next row
    r++; // adds (increments) to next row;
        if (r == 8) goto backtrack; 

// Row Test:
for (int i = 0; i < c; i++){  
        if (q[r][i] == 1) goto nr;
    }

// Up Diagonal Test:
for (int i = 1; (r - i) >= 0 && (c -i) >= 0; i++){ 
    if (q[r - i][c - i] == 1) goto nr;
}

// Down Diagonal Test:
for (int i = 1; r + i < 8 && c - i >= 0; i++){ 
    if (q[r + i] [c - i] == 1) goto nr;
}

// Place A Queen;
q[r][c] = 1; // sets the queen in that position since all the test was passed
goto nc;

backtrack:
c--; // decrementing column (-)
    if (c == -1) return 0; // position check
    r = 0;
    while (q[r][c] != 1) {
r++;
    }
    q[r][c] = 0; // when setting queen in [r][c] it'll remove the queen
goto nr;



print:
    cout << "Solution #: " << numSolutions++  << endl; // prints out the solution number 

    for(int i = 0; i < 8; i++){ // nested for-loop to print out the chess board. 
        for (int j = 0; j < 8; j++){
            cout << q[i][j] << " "; 
        }
        cout << endl;
    }
    goto backtrack; // keeps on going until theres no more solutions left to find;

    return 0;
}
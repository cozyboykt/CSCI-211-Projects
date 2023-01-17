// Kunsang Tsering
// 1d array 8 queens problem without goto
#include <iostream>
using namespace std;

// Code below declares a function called ok which takes two arguements  "q" and an integer
// "c", it returns a boolean value
bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++)
    {
        if ((q[i] == q[c]) || ((c - i) == abs(q[c] - q[i]))) // checks if current position that is being placed "q[c]" is in the same row or diagonal as a previous queen , "q[i]"
        {
            return false;
        }
    }
    return true;
}

void backtrack(int &c)
{
    c--; // decrements the value of "c" by 1
    if (c == -1)
    {
        exit(0); // Terminates and tells -1 that it indicates an error has occured
    }
}

// Code Below: starts at 1 and will later increment until it hits #92 possible solutions
void print(int q[])
{
    static int numSolutions = 1;
    cout << "Solution #" << numSolutions++ << ":";
    cout << endl;
    // print array
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (q[i] == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int q[8] = {}; // declares an array of 8 integers and intializes all elements
    int c = 0;     // first row, first col of the chess board

    while (c >= 0)
    {        // loop ends if you backtrack from the first col
        c++; // move to the next col

        if (c == 8)
        {
            print(q);     // prints the current solution to the problem
            backtrack(c); // decrements the value of "c" by 1 and checks if its reached first column and if yes then terminates the program
        }
        else
        {
            q[c] = -1;
        }
        // Code below: nested loop and will continue to excecute as long as the value of "c" is >= 0
        while (c >= 0)
        {
            q[c]++; // move to the next row

            if (q[c] == 8)
            { // reach the last col, so backtrack
                backtrack(c);
            }
            else
            { // call the ok function. if returns true, go back to the beginning of the outer loop
                if (ok(q, c) == true)
                {
                    break; // break out of the inner while loop if ok returns true.
                }
            }
        }
    }
    return 0;
}
// Kunsang Tsering
// 8 queens with 1d array with backtracking using goto statement
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numSolutions = {1};
    int q[8];
    int c = 0;
    q[0] = 0;
nc:
    c++;
    if (c == 8)
        goto print;
    q[c] = -1;
nr:
    q[c]++;
    if (q[c] == 8)
        goto backtrack;
    for (int i = 0; i < c; i++)

        if (q[c] == q[i] || abs(q[c] - q[i]) == (c - i))
            goto nr;
    goto nc;

backtrack:
    c--;
    if (c == -1)
        return 0;
    goto nr;

print:
   cout << "Solution #: " << numSolutions++  << endl; // prints out the solution number 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (q[i] == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;

    goto backtrack;
}

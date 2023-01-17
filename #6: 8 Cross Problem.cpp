#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
    static int adj[8][5] = {
        {-1},             // 0
        {0, -1},          // 1          1   4
        {0, 1, -1},       // 2       0  2  5  7
        {0, 2, -1},       // 3          3   6
        {1, 2, -1},       // 4
        {1, 2, 3, 4, -1}, // 5
        {2, 3, 5, -1},    // 6
        {4, 5, 6, -1}     // 7
    };

    for (int i = 0; i < c; i++)
    {
        if (q[c] == q[i]) // If the number you are writing in square c has already been used, return false.
            return false;
    }
    // Code below : will continue to iterate as long as the value in adj[c][i] is not
    // equal to -1
    for (int i = 0; adj[c][i] != -1; i++)
    { // Code below: will check if the value of a c as defined in the adj is > by adding(+)  || < by minus(-)the value of the neighbor of square c
      // if either of these conditions are true, the function returns false.
        if (q[adj[c][i]] + 1 == q[c] || q[adj[c][i]] - 1 == q[c])
            return false;
    }

    return true;
}
void print(int q[])
{
    static int solutions = 1; // Initialized once and only once.

    cout << "Solutions #" << solutions << ":" << endl;
    cout << " "
         << " " << q[1] << q[4] << endl;
    cout << " " << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " "
         << " " << q[3] << q[6] << endl;

    cout << endl;
    solutions++; // This variable is to increment each time a new solution is found.
}

void next(int q[], int c)
{
    if (c == 8)
        print(q);
    else
        for (q[c] = 1; q[c] <= 8; q[c]++) // the loop will iterate as long as the value is < 8
            if (ok(q, c))
                next(q, c + 1); // this will only happen if the ok func on top returns true
}

int main()
{
    int q[8];   // array of integers called q declared with a size of 8
    next(q, 0); // this will pass in the value of 0 as a parameter, keep on iterating through all possible combination of values for squares in board
    return 0;
}
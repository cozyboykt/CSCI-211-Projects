// Kunsang Tsering
// dumb 8 queens problem
#include <iostream>
#include <cmath>
using namespace std;

bool okay(int q[])
{
    for (int c = 0; c < 8; c++)     // This is the Row Test if we're on the board
        for (int i = 0; i < c; i++) // This is going through the board
        {
            if (q[i] == q[c] || c - i == abs(q[c] - q[i])) // Tests 1.)(abs val allows for both up/down diagonal tests)
                return false;                              // if (q[r] == q[c] is true then there is a problem with the row where both queens colliad
        }
    return true; // Automatically put a queen (default setting) is to return true;
}

void printArr(int board[], int count) // This Makes the 2d ChessBoard
{
    cout << "Solution #" << count++ << ":" << endl; // Shows what solution we are on count++ start with solution 1;
    int solution[8][8] = {0};

    for (int c = 0; c < 8; c++)
    {
        solution[board[c]][c] = 1;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            cout << solution[i][c]
                 << " ";
        }
        cout << endl;
    }

    cout << endl;
} // This Prints Out The Chess Board

int main()
{
    int board[8] = {0};
    int count = 0;

    for (int i1 = 0; i1 < 8; i1++)
        for (int i2 = 0; i2 < 8; i2++)
            for (int i3 = 0; i3 < 8; i3++)
                for (int i4 = 0; i4 < 8; i4++)
                    for (int i5 = 0; i5 < 8; i5++)
                        for (int i6 = 0; i6 < 8; i6++)
                            for (int i7 = 0; i7 < 8; i7++)
                                for (int i8 = 0; i8 < 8; i8++) // Runs after i8 and above until i1;
                                {                              // Starting to loop
                                    board[0] = i1;             // Represents Rows
                                    board[1] = i2;
                                    board[2] = i3;
                                    board[3] = i4;
                                    board[4] = i5;
                                    board[5] = i6;
                                    board[6] = i7;
                                    board[7] = i8;

                                    if (okay(board))
                                        printArr(board, ++count); // 8 x 8 Chessboard

                                    board[1] = -1; // This is the Error
                                    board[2] = -1;
                                    board[3] = -1;
                                    board[4] = -1;
                                    board[5] = -1;
                                    board[6] = -1;
                                    board[7] = -1;
                                    board[8] = -1;
                                }

    return 0;
}
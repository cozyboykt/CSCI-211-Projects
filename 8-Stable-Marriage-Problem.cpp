#include <iostream>
using namespace std;

// cm = i ,   cw = q[i]
// nm = c ,   nw = q[c]

bool ok(int q[], int c)
{
    static int mp[3][3] = {
        {0, 2, 1}, // Man 0 preferences
        {0, 2, 1}, // Man 1 preferences
        {1, 2, 0}, // Man 2 preferences
    };
    static int wp[3][3] = {
        {2, 1, 0}, // Women 0 preferences
        {0, 1, 2}, // Women 1 preferences
        {2, 0, 1}, // Women 2 preferences
    };

    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c] || mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c] || mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
        {
            return false;
        }
    }
    return true;
}
void print(int q[])
{
    static int solution = 1;
    cout << "Solution #: " << solution++ << endl;
    cout << "Man "
         << " Women" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << "\t" << q[i] << endl;
        cout << endl;
    }
}
void next(int q[], int c)
{
    if (c == 3)
        print(q);
    else
        for (q[c] = 0; q[c] < 3; q[c]++)
        {
            if (ok(q, c))
                next(q, c + 1);
        }
}

int main()
{
    int q[3];
    next(q, 0);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> t[3];
    int from = 0, to , move = 0, candidate = 1;
    int n;
    cout << "Enter the # of disc: ";
    cin >> n;
if (n % 2 == 0)
{
    to = 2;
}
else 
{
    to = 1;
}
for (int i = n + 1; i >= 1; --i)
{
    t[0].push_back(i);
}
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);
while (t[1].size() < n + 1)
{
    cout << "Move #" << ++move << " transfer disc " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
 t[to].push_back(t[from].back());
 t[from].pop_back();
 if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
 {
    from = (to + 1) % 3;
 }
else 
{
    from = (to + 2) % 3;
}
candidate = t[from].back();
if (n % 2 == 1)
{
    if (t[(from + 1) % 3].back() > candidate)
    to = (from + 1) % 3;
    else 
{
    to = (from + 2) % 3;
}
}

else 
{
    if (t[(from + 2) % 3].back() > candidate)
    {
        to = (from + 2) % 3;
    }
else  
{
        to = (from + 1) % 3;
}
}
}

 

return 0;
}
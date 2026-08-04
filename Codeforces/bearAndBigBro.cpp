#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,k; cin >> x >> y;

    for (int i = 1; i < 1000; i++)
    {
        x *= 3; y *= 2;
        if (x > y) 
        {
            k = i;
            break;
        }
    }

    cout << k << endl;
}
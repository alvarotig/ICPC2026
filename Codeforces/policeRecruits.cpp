#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int res = 0, pol = 0;

    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;

        if (temp == -1)
        {
            if (pol > 0) pol--;
            else
            {
                res++;
            } 
        } else pol+=temp;
    }

    cout << res << endl;
}
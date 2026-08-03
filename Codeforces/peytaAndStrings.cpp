#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b; cin >> a >> b;
    int aMaior = 0;

    for(int i = 0; i < a.length(); i++)
    {
        string aT, bT;
        aT = tolower(a[i]);
        bT = tolower(b[i]);

        if (aT > bT) 
        {
            aMaior = 1; break;
        }
        else if (aT < bT)
        {
            aMaior = -1; break;
        }
    }

    cout << aMaior << endl;
}
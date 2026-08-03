#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        h[i] = temp;
    }

    sort(h.begin(), h.end());

    cout << h[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << h[i]; 
    }

    return 0;
}
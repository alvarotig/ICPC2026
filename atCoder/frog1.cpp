#include <bits/stdc++.h>
using namespace std;

int n;

int solve(vector<int> &pulos, vector<int> &memo, int pos)
{
    if (pos == n) return 0;
    if (pos > n) return 1e9;

    if (memo[pos] != -1) return memo[pos];

    return memo[pos] = min ({(abs(pulos[pos] - pulos[pos+1]) + solve(pulos, memo, pos+1)), 
                            (abs(pulos[pos] - pulos[pos+2]) + solve(pulos, memo, pos+2))});
}

int main()
{
    cin >> n;
    vector<int> pulos(n+5); 
    for (int i = 1; i <= n; i++)
    {
        int p; cin >> p;
        pulos[i] = p;
    }
    vector<int> memo(n+5, -1);

    cout << solve(pulos, memo, 1) << endl;
    return 0;
}
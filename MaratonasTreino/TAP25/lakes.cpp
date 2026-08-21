#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int n, x; 
lli g;
vector<lli> v;

//a logica é f (k,i) -> f(k, i+1) || f(k+1, i+k) + G - soma(i até i+k-1) 

lli solve (vector<vector<lli>>& dp, vector<lli>& pref, int k, int i)
{
    if (i >= n || k >= x) return 0;
    if (dp[k][i] != -1) return dp[k][i];

    lli pula = solve(dp, pref, k, i+1), s; // f(k, i+1);

    if (i+k-1 < n) s = pref[i+k-1] - (i > 0 ? pref[i-1] : 0);
    else return dp[k][i] = pula;

    lli coloca = solve(dp, pref, k+1, i+k) + g - s; // f(k+1, i+k+1)

    return dp[k][i] = max(pula, coloca);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> g;
    vector<lli> pref(n); // guarda soma ate ali

    lli t; cin >> t; v.push_back(t); pref[0] = t;
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        pref[i] = pref[i-1] + t;
        v.push_back(t);
    }

    x = sqrt(2*n) + 5; // soma de uma pa que cresce em 1 + uma margem pra nao errar
    vector<vector<lli>> dp(x, vector<lli>(n, -1));

    cout << solve(dp, pref, 1, 0) << endl;
}
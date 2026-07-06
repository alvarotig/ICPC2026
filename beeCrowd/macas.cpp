#include <bits/stdc++.h>
using namespace std;

int n, m, k, tMAX;

int solve (vector<vector<vector<int>>> &arvore, vector<vector<vector<int>>> &memo, int x, int y, int t)
{
    if (x < 1 || x > n || y < 1 || y > m) return -1;

    int at = arvore[x][y][t];

    if (memo[x][y][t] != -1) return memo[x][y][t];

    if (t == tMAX) return at;

    return memo[x][y][t] = at + max({solve(arvore, memo, x, y, t+1), solve(arvore, memo, x+1, y, t+1), solve(arvore, memo, x, y+1, t+1), solve(arvore, memo, x+1, y+1, t+1), 
    solve(arvore, memo, x, y-1, t+1), solve(arvore, memo, x-1, y, t+1), solve(arvore, memo, x-1, y-1, t+1), solve(arvore, memo, x-1, y+1, t+1), solve(arvore, memo, x+1, y-1, t+1)});
}

int main ()
{
    cin >> n >> m >> k;
    while (n != 0 && m != 0 && k != 0)
    {
        vector<vector<vector<int>>> arvore(n+1, vector<vector<int>>(m+1, vector<int>(2000, 0)));
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(m+1, vector<int>(2000, -1)));
        tMAX = 0;
        for (int i = 0; i < k; i++)
        {
            int x, y, t; cin >> x >> y >> t;
            arvore[x][y][t] = 1;
            if (t > tMAX) tMAX = t;
        }

        int posX, posY, cnt = 0; cin >> posX >> posY; 

        cnt = solve(arvore, memo, posX, posY, 0); 

        cout << cnt << endl;
        cin >> n >> m >> k;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    bool flag = true;
    vector<vector<char>> mat(n, vector<char> (m));
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c; mat[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0) 
            {
                if (mat[i-1][j] == mat[i][j]) {cout << "N\n"; return 0;}
            }
            if (j > 0)
            {
                if (mat[i][j] == mat[i][j-1]) {cout << "N\n"; return 0;}
            }
        }

    }

    cout << "S\n"; 
    return 0;
}
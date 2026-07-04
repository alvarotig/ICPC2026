#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x; cin >> x;

    while(x--)
    {
        int n; cin >> n;
        vector<pair<int,int>> projeteis(n+1);

        for (int i = 1; i <= n; i++)
        {
            int x, y; cin >> x >> y;
            projeteis[i] = {x,y};
        }
        
        int k, r; cin >> k >> r;
        vector<vector<int>> memo(n+1, vector<int>(k+1,0));

        for(int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int peso = projeteis[i].second;
                int pot = projeteis[i].first;

                memo[i][j] = peso > j ? memo[i-1][j] : max(memo[i-1][j], pot + memo[i-1][j-peso]); 
            }
        }

        if (memo[n][k] >= r) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl; 
    }

    return 0;
}
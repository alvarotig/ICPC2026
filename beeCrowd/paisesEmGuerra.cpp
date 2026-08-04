#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void floydWarshall(int n, vector<vector<long long>>& adj) 
{
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (adj[i][k] < INF && adj[k][j] < INF) 
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

int main ()
{
    int n, e; 
    while (cin >> n >> e && (n != 0 || e != 0))
    {
        vector<vector<long long>> adj(n + 1, vector<long long>(n + 1, INF));
        
        for (int i = 1; i <= n; i++) {
            adj[i][i] = 0;
        }

        for (int i = 0; i < e; i++)
        {
            int x, y, z; 
            cin >> x >> y >> z;
            adj[x][y] = z;
        }

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (adj[i][j] < INF && adj[j][i] < INF) 
                {
                    adj[i][j] = 0;
                    adj[j][i] = 0;
                }
            }
        }

        floydWarshall(n, adj);

        int k; 
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y; 
            cin >> x >> y;
            
            if (adj[x][y] == INF) cout << "Nao e possivel entregar a carta\n";
            else cout << adj[x][y] << endl;
        }
        cout << endl; 
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dijkstra(int start, vector<vector<pair<int,long long>>>& adj, vector<long long>& distancias, vector<int>&predecessores){
    int n = adj.size();
    distancias.assign(n, INF);
    predecessores.assign(n, -1);
    distancias[start] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> fila;
    fila.push({0, start});

    while(!fila.empty()){
        int v = fila.top().second;
        long long distV = fila.top().first;
        fila.pop();

        if(distV != distancias[v]) continue;

        for (auto aresta : adj[v]){
            int to = aresta.first;
            long long len = aresta.second;
            if(distancias[v] + len < distancias[to]){
                distancias[to] = distancias[v] + len;
                predecessores[to] = v;
                fila.push({distancias[to], to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c, p; cin >> n >> c >> p;

    vector<vector<pair<int,long long>>> adj((n+1)*3);

    for (int i = 1; i <= c; i++)
    {
        int x,y; long long z; cin >> x >> y >> z;
        adj[x+n].push_back({y+n, z});
    }

    for (int i = 1; i <= p; i++)
    {
        int x, y; long long z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});

        adj[x+(2*n)].push_back({y+(2*n), z});
        adj[y+(2*n)].push_back({x+(2*n), z});
    }
    
    for(int i = 1; i <= n; i++)
    {
        adj[i].push_back({i+n, 0});
        adj[i+n].push_back({i+(2*n), 0});
    }

    vector<long long> d; vector<int> pre;

    dijkstra(1, adj, d, pre);
    cout << d[n + 2*n] << "\n";
}
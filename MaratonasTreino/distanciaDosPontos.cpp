#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

struct Edge {

    int A, B;
    double peso;

    Edge(int a, int b, double W = 0){
        A = a;
        B = b;
        peso = W;
    }

    bool operator<(const Edge& outra) const {
        return this->peso < outra.peso;
    }

};

int main() {
    int x; cin >> x; // casos teste (1000)
    
    for (int i = 0; i < x; i++) {
        int p; cin >> p;
        vector<pair<int, int>> pontos;

        for (int j = 0; j < p; j++) {
            int a, b;
            cin >> a >> b;
            pontos.push_back({a, b});
        }

        vector<Edge> arestas;

        for (int k = 0; k < p; k++) { // distancia pra todos os pontos (50 * 50)
            for (int l = k + 1; l < p; l++) {
                double dist = sqrt((pontos[k].first - pontos[l].first)*(pontos[k].first - pontos[l].first) + (pontos[k].second - pontos[l].second)*(pontos[k].second - pontos[l].second));
                arestas.push_back(Edge(k, l, dist)); // guarda indice do ponto, nao par
            }
        }

        sort(arestas.begin(), arestas.end());

        DSU dsu(p+5); 
        double cnt = 0;
        vector<Edge> MST;

        for (auto u : arestas) {
            if (dsu.find(u.A) != dsu.find(u.B)) {
                MST.push_back(u);
                dsu.unite(u.A, u.B);
                cnt += u.peso; // soma quem faz parte da MST
            }
        }

        cout << fixed << setprecision(4) << cnt << endl;

    }

    return 0;
}

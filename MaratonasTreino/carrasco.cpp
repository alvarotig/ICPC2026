#include <bits/stdc++.h>
using namespace std;

struct disciplina {
    int ini; int fim; int pes;
};

int main() {
    int n; cin >> n;
    
    vector<disciplina> mat[7];
    int resTotal = 0;

    for (int i = 0; i < n; i++) {
        string s; int ini; int fim; int pes; 
        cin >> s >> ini >> fim >> pes;
        
        disciplina dis = {ini, fim, pes};
        
        if (s == "seg") mat[0].push_back(dis);
        else if (s == "ter") mat[1].push_back(dis);
        else if (s == "qua") mat[2].push_back(dis);
        else if (s == "qui") mat[3].push_back(dis);
        else if (s == "sex") mat[4].push_back(dis);
        else if (s == "sab") mat[5].push_back(dis);
        else mat[6].push_back(dis);
    }

    for (int i = 0; i < 7; i++)
    {
        vector<disciplina> aulas_que_terminam_na_hora[24];
        
        for (disciplina d : mat[i]) 
        {
            aulas_que_terminam_na_hora[d.fim].push_back(d);
        }

        vector<pair<int, int>> dp(24, {0, 0});
        
        for (int t = 8; t <= 23; t++) 
        {
            dp[t] = dp[t - 1];

            for (disciplina d : aulas_que_terminam_na_hora[t]) 
            {
                pair<int, int> pegar_aula = {dp[d.ini].first + 1, dp[d.ini].second + d.pes};
                dp[t] = max(dp[t], pegar_aula);
            }
        }
        
        resTotal += dp[23].second;
    }

    cout << resTotal << endl;
    return 0;
}
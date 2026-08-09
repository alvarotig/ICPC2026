#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    set<int> conj;

    for (int i = 0; i < s.length(); i++)
    {
        conj.insert(s[i]);
    }

    if (conj.size()%2 == 0) cout << "CHAT WITH HER!" << endl; 
    else cout << "IGNORE HIM!" << endl;
}
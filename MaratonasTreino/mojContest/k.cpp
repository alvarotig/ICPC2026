#include <bits/stdc++.h>
using namespace std;
int n, m, intervals;
 
struct interval {
    int start_time;
    int finish_time;
    int value;

    interval (int s, int f, int v)
    {
        this->start_time = s;
        this->finish_time = f;
        this->value = v;
    }
};

int latestNonConflicting(const vector<interval>& inter_arr, int i)
{
    int l = 0, r = i-1;
    int ans = -1;
    while (l <= r) {
        int mid = l+(r-1)/2;
        if(inter_arr[mid].finish_time < inter_arr[i].start_time)
        {
            ans = mid;
            l = mid+1;
        } else
        {
            r = mid-1;
        }
    }
    return ans;
}

int weighted_interval_scheduling(vector<interval> inter_arr, int intervals)
{
    sort(inter_arr.begin(), inter_arr.end(), [] (interval a, interval b) {
        return a.finish_time < b.finish_time;
    });

    pair<int, int> dp[intervals+1];
    dp[0] = {0, 0};

    for (int j=1; j <= intervals; j++)
    {
        int val = inter_arr[j-1].value;
        int non_conflict = latestNonConflicting(inter_arr, j-1);
        int picks = dp[j-1].first;

        int tempVal = val+dp[non_conflict+1].second;
        if (non_conflict != -1 && tempVal <= m)
        {
            val = tempVal; picks++;
            dp[j].first = picks;
            dp[j].second = tempVal;
        } else
        {
            dp[j].first = picks;
            dp[j].second = val;
        }

        //val += non_conflict != -1 ? dp[non_conflict+1] : 0;

        cout << dp[j].first << " " << dp[j].second << "\n";
    }

    return dp[intervals].first;
}

int main()
{
    cin >> n >> m;
    vector<interval> inter_arr;
    intervals = n;
    
    for(int i = 0; i < n; i++)
    {
        int s, f; int v; cin >> s >> f >> v;

        if (v <= m)
        {
            inter_arr.push_back(interval(s, f, v));
        } else {intervals--;}
    }

    cout << weighted_interval_scheduling(inter_arr, intervals);
}
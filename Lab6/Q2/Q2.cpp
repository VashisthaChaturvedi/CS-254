#include <bits/stdc++.h>
using namespace std;
void solve(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(n);
    vector<int> dependancy(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        dependancy[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (dependancy[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> toposort;
    while (!q.empty())
    {
        int curr = q.front();
        toposort.push_back(curr);
        q.pop();
        for (auto child : connections[curr])
        {
            dependancy[child]--;
            if (dependancy[child] == 0)
                q.push(child);
        }
    }
    if (toposort.size() != n)
    {
        cout << "Infinite bcz of loop" << endl;
        return;
    }
    vector<int> distance(n, 0);
    int maxm = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        for (auto child : connections[i])
        {
            distance[child] = max(distance[child], 1 + distance[i]);
            maxm = max(maxm, distance[child]);
        }
    }
    cout << "Maximum length of longest path = " << maxm << endl;
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin >> test;
    for (int i = 1; i <= test;i++){
        cout << "Answer for test " << i << endl;
        solve();
    }
}
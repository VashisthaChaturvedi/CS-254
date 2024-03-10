#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<vector<pair<int, int>>> connections(n);
    vector<int> dependancy(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        connections[a].push_back({b, wt});
        dependancy[b]++;
    }
    queue<int> q;
    vector<int> distance(n, INT32_MIN);
    for (int i = 0; i < n; i++)
    {
        if (dependancy[i] == 0)
        {
            q.push(i);
            distance[i] = 0;
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
            dependancy[child.first]--;
            if (dependancy[child.first] == 0)
                q.push(child.first);
        }
    }
    if (toposort.size() != n)
    {
        cout << "Infinite bcz of loop" << endl;
        // return distance;
    }
    int maxm = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (distance[toposort[i]] != INT32_MIN)
            for (auto child : connections[toposort[i]])
            {
                distance[child.first] = max(distance[child.first], child.second + distance[toposort[i]]);
                maxm = max(maxm, distance[child.first]);
            }
    }
    return maxm;
}
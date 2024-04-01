#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

struct comparator
{
    bool operator()(const pair<int, pair<int, char>> &p1, const pair<int, pair<int, char>> &p2)
    {
        return p1.first > p2.first;
    }
};
int tt;
void best_job_sequence(map<int, vector<pair<int, char>>> &m)
{
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, comparator> pq;
    int ans = 0;
    for (auto it : m)
    {
        int x = it.first;
        int n = (int)(it.second).size();

        for (int i = 0; i < n; i++)
        {
            if ((int)pq.size() < x)
            {
                pq.push({it.second[i].first, {it.first, it.second[i].second}});
                ans += it.second[i].first;
            }
            else if (pq.top().first < it.second[i].first)
            {
                ans -= pq.top().first;
                pq.pop();

                pq.push({it.second[i].first, {it.first, it.second[i].second}});
                ans += it.second[i].first;
            }
        }
    }
    multimap<int, char> dl;
    cout << "the max value possible by greedy approach in testcase " << tt << " is -> " << ans << endl;
    cout << "The jobs done greedily are -> \n";
    while (!pq.empty())
    {
        dl.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : dl)
    {
        cout << q.second << " ";
    }
    cout << "\n\n";
}

int main()
{
    // Taking input from input.in and giving output to output.out
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    ll t;
    cin >> t;
    for (tt = 1; tt <= t; tt++)
    {

        int n;
        cin >> n;
        map<int, vector<pair<int, char>>> m;
        for (int i = 0; i < n; i++)
        {
            char c;
            int d, p;
            cin >> c >> d >> p;
            m[d].push_back({p, c});
        }
        best_job_sequence(m);
    }
}
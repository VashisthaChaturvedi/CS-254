#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> movement = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int dfs(vector<string> &v, vector<vector<bool>> &vis, int i, int j)
{
    // cout << i << " " << j << endl;
    if(i>=vis.size()||j>=vis[0].size()||i<0||j<0)
        return 0;
    if(v[i][j]=='0'){
        vis[i][j] = true;
        return 0;
    }
    if(vis[i][j]==true)
        return 0;
    
    int ans = 1;
    vis[i][j] = true;
    for (auto move:movement){
        ans+=dfs(v, vis, i + move.first, j + move.second);
    }
    return ans;
}


void solve()
{
    int n, m; // n is the number of rows, m = is the length of string.
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == true)
                continue;
            if(v[i][j]=='0'){
                vis[i][j] = true;
                continue;
            }
            if (v[i][j] == '1')
                maxm = max(maxm, dfs(v, vis, i, j));
        }
    }
    cout << "Maximum region is of size: " << maxm<<endl;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cout << "Answer for test " << (i+1) << endl;
        solve();
        cout << endl << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin>>test;
    for (int i = 1; i <= test;i++){
        solve();
    }
}

void dfs(int node, vector<bool> &vis, vector<vector<int>> &connections, vector<int> &timesort);

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(n + 1);
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
    }
    vector<int> timesort;
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n + 1;i++){
        if (vis[i] == false){
            dfs(i, vis, connections, timesort);
        }
    }
    reverse(timesort.begin(), timesort.end());
    vector<vector<int>> reverse_connections(n + 1);
    for (int i = 0; i < n;i++){
        vis[i] = false;
        for(auto child:connections[i]){
            reverse_connections[child].push_back(i);
        }
    }

    vector<vector<int>> strong_connections;
    for (int i = 0; i < timesort.size();i++){
        vector<int> temp;
        if(vis[timesort[i]]==false){
            dfs(timesort[i], vis, reverse_connections, temp);
            strong_connections.push_back(temp);
        }
    }
    cout << "Number of Strongly connected component are: \n" << strong_connections.size() << "\n\n";
    for (int i = 0; i < strong_connections.size();i++){
        for (int j = 0; j < strong_connections[i].size();j++){
            cout << strong_connections[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(int node, vector<bool> &vis, vector<vector<int>> &connections, vector<int> &timesort){
    vis[node] = true;
    for(auto child : connections[node]){
        if(!vis[child])
        dfs(child, vis, connections, timesort);
    }
    timesort.push_back(node);
    return;
}
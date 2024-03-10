#include<bits/stdc++.h>
using namespace std;
void dfs_bridges(int node, int parent, vector<vector<int>> &connections, vector<int> &discovery, vector<int> &low, vector<vector<int>> &bridges, int &time){
    if(discovery[node]!=0){
        return;
    }
    if(discovery[node]==0){
        discovery[node] = ++time;
        low[node] = time;
    }
    int lowest = low[node];
    for(auto child:connections[node]){
        if(child==parent){
            continue;
        }
        dfs_bridges(child, node, connections, discovery, low, bridges, time);
        if(low[child]<low[node]){
            lowest = min(low[node], low[child]);
        }
        if(low[child]>low[node]){
            bridges.push_back({node, child});
        }
    }
    low[node] = lowest;
}
void bridges(vector<vector<int>>&connections,int vertices){
    vector<int> discovery(vertices, 0);
    vector<int> low(vertices, 0);
    vector<vector<int>> bridges;
    int time = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (discovery[i] == 0)
        {
            dfs_bridges(i, i, connections, discovery, low, bridges, time);
        }
    }
    cout << "Bridges\n";
    for (int i = 0; i < bridges.size(); i++)
    {
        cout << bridges[i][0] << " " << bridges[i][1] << endl;
    }
    cout << endl
         << endl;
}
void dfs_ap(int node, int parent, vector<vector<int>> &connections, vector<int> &discovery, vector<int> &low, vector<int> &articulation_point, vector<int>&vis, int &time){
    vis[node] = 1;
    discovery[node] = ++time;
    low[node] = time;
    int number_child = 0;
    int minm = low[node];
    for(auto child:connections[node]){
        if(child==parent){
            continue;
        }
        if(vis[child]!=1){
            number_child++;
            dfs_ap(child, node, connections, discovery, low, articulation_point, vis, time);
            low[node] = min(low[node], low[child]);
            if(low[child]>=discovery[node]&&parent!=-1){
                articulation_point[node] = 1;
            }
        }
        else{
            low[node] = min(low[node], discovery[child]);
        }
    }
    if(number_child>1&&parent==-1){
        articulation_point[node] = 1;
    }
}
void articulation_point(vector<vector<int>>&connections,int vertices){
    vector<int> discovery(vertices, 0);
    vector<int> low(vertices, 0);
    vector<int> vis(vertices, 0);
    vector<int> articulation_point(vertices,0);
    int time = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (discovery[i] == 0)
        {
            dfs_ap(i, -1, connections, discovery, low, articulation_point, vis, time);
        }
    }
    cout << "Articulation Points\n";
    for (int i = 0; i < articulation_point.size(); i++)
    {
        if(articulation_point[i]==1)
        cout << i << " ";
    }
    cout <<endl<<endl;
}
void solve(){
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> connections(vertices);
    for (int i = 0; i < edges;i++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    bridges(connections,vertices);
    articulation_point(connections, vertices);
}
int main(){
    freopen("input.in", "r",stdin);
    freopen("output.out", "w",stdout);
    int test;
    cin >> test;
    for (int i = 1; i <= test;i++){
        solve();
    }
}
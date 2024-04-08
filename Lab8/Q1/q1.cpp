#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    freopen("0input.in", "r", stdin);
    freopen("0output.out", "w", stdout);
    int test;
    cin >> test;
    while(test--)
    {
        solve();
    }
}
int find(int i, vector<int>&parent){
    if(parent[i]==i){
        return i;
    }
    return (parent[i] = find(parent[i], parent));
}
bool unionBySize(int i, int j,vector<int>&parent,vector<int>&sizes){
    i = find(i, parent);
    j = find(j, parent);
    if(i==j){
        return false;
    }
    if(sizes[j]>sizes[i]){
        swap(i, j);
    }
    parent[j] = i;
    sizes[i] += sizes[j];
    return true;
}

void spanning_tree(vector<vector<int>> &edges,int n,int m){
    vector<int> parent(n, -1);
    vector<int> sizes(n, 1);
    int ans = 0;
    vector<pair<int, int>> tree;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n;i++){
        parent[i] = i;
    }
    for(auto edge:edges){
        bool b = unionBySize(edge[1], edge[2],parent,sizes);
        if(b){
            tree.push_back({edge[1], edge[2]});
            ans += edge[0];
        }
    }
    cout << "Maximum Spanning tree\n";
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i].first << " " << tree[i].second<<endl;
    }
    cout << "Weight of maximum spanning tree " << ans << endl;
} 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0;i<m;i++){
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    spanning_tree(edges, n,m);
    return;
}
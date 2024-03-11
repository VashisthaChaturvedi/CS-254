#include <bits/stdc++.h>
using namespace std;
void getConnection(int vertices,int edges,vector<vector<int>>&connection, vector<int>&dependancy){
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        dependancy[b]++;
    }
}
bool topologicalsort(vector<vector<int>> &connection, vector<int> &topologicalsort, vector<int>&dependancy){
    queue<int> zero_dependancy;
    // cout << "*"<<connection.size();
    for (int i = 0; i <connection.size();i++){
        if(dependancy[i]==0){
            zero_dependancy.push(i);
        }
    }
    while(!(zero_dependancy.empty())){
        int front = zero_dependancy.front();
        zero_dependancy.pop();
        
        topologicalsort.push_back(front);
        for(auto i:connection[front]){
            dependancy[i]--;
            if(dependancy[i]==0)
                zero_dependancy.push(i);
        }
    }
    if(topologicalsort.size()!=(connection.size())){
        return false;
    }
    return true;
}
void solve(){
    int vertices;
    int edges;
    cin >> vertices;
    cin >> edges;
    // cout << vertices << edges;
    vector<vector<int>> connection(vertices );
    vector<int> dependancy(vertices,0);

    getConnection(vertices, edges, connection, dependancy);
    vector<int> topologicalSort;
    bool isSortable = topologicalsort(connection, topologicalSort, dependancy);
    if(!isSortable){
        cout << "Directed Graph not sortable." << endl;
        return;
    }
    cout << "Sorted graph is: \n";
    for (int i = 0; i < topologicalSort.size();i++){
        cout << topologicalSort[i] << " ";
    }
    cout << endl;
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin>>test;
    while(test--){
        solve();
    }
}
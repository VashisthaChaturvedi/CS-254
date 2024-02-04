// Vashistha Narayan CHaturvedi
// Roll No. 220001077
// Time Complexity : O(nlogn);
// Space Complexity : O(k);
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < nums.size(); i++)
    {
        q.push(nums[i]);
        if (q.size() > k)
            q.pop();
    }
    return q.top();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int ans = findKthLargest(v, k);
    cout << ans << endl;
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin >> test;
    for (int i = 0; i < test;i++){
        cout << "Answer for test " << i+1 << endl;
        solve();
        cout << "\n\n";
    }
}

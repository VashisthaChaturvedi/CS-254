// Vashistha Chaturvedi
// Q1.b) Construct a sorted array C for A ∪ B

// Time Complexity : O(nlogn);
// Space Complexity : O(n);

#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Answer for test case " << i << endl;
        solve();
    }
}

void solve(){

    // input of size of array A and array B
    int n, m;
    cin >> n >> m;
    map<int, int> nums;

    // storing all the element in map to avoid repetition of elements.
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums[k]++;
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        nums[k]++;
    }

    // map is a ordered map so the elements are in increasing order.
    vector<int> ans;
    for (auto num : nums)
    {
        ans.push_back(num.first);
    }

    // Output of answer elements
    cout << "Union Array\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl<< endl;
}
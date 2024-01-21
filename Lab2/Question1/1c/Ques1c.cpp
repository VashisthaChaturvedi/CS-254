// Vashistha Chaturvedi
// Q1.c) Construct a sorted array C for A ∩ B.

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

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

    int n, m;
    cin >> n >> m;
    map<int, int> nums;
    map<int, int> nums2;
    // storing the elements of first array in map for quick access
    // while getting elements of 2nd array.
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums[k]++;
    }
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        // if the number is in the first array then find function will not return end iterator
        if (nums.find(k) != nums.end()&&nums2[k]==0)
        {
            ans.push_back(k);
            nums2[k]++;
        }
    }

    // Answer output
    cout << "Intersection Array\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl<<endl;
}
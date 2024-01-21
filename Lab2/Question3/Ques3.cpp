// Vashistha Chaturvedi
// Q3.) Use the above merging algorithm to sort an unsorted array

// Time Complexity: O(n*n);
// Space Complexity: O(1);

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
    int n;
    // input of array size
    cin >> n;
    vector<int> v(n);

    // input of unsorted array
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (v[j] > v[j + 1]))
        {
            // Shifting eaach elements forward by one.
            swap(v[j], v[j + 1]);
            j--;
        }
    }
    // Output of answer array.
    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;
}
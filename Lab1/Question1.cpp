#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#include <ctime>
#define ll long long
void solve();
int main()
{
    clock_t t;
    t = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputQ1.in", "r", stdin);
    freopen("outputQ1.out", "w", stdout);
// Reading input files.
// Printing the output in output file.
#endif
    solve();

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
#ifndef ONLINE_JUDGE
    cout << endl
         << "::" << time_taken;
#endif
}
void solve()
{
    int size_n;
    cin >> size_n;
// input of size of array.

    vector<int> arr(size_n);
    int max1 = INT32_MIN, max2 = INT32_MIN;
    // intialising 2 number for storing 2 highest respective maximum.
    for (int i = 0; i < size_n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] >= max2)
        {
            max2 = arr[i];
        }
    }
    cout << (max1 + max2) << endl;
    // output of result
    return;
}
// Vashistha Chaturvedi
// Q2) You are given an array A of n elements, where the first m (≤ n) elements are sorted and
// the remaining(n − m) elements are also sorted.However, the array A may not be sorted.(a)Write down an in - place merge algorithm to sort A


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
    cin >> n;
    vector<int> v(n);
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // implementing insertion sort.
    for (int i = (n-m); i < n; i++)
    {
        int k = v[i];
        int j = i - 1;
        while ((j >= 0) && (v[j] > v[j + 1]))
        {
            // Shifting eaach elements forward by one.
            v[j + 1] = v[j];
            j--;
        }
        v[j] = k;
    }
    // output of answer.
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
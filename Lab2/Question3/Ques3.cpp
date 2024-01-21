// Vashistha Chaturvedi
// Q3.) Use the above merging algorithm to sort an unsorted array

#include <bits/stdc++.h>
using namespace std;
int main()
{
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
        int k = v[i];
        int j = i - 1;
        // shifting elements forward.
        while ((j >= 0) && (v[j] > v[j + 1]))
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j] = k;
    }
    // Output of answer array.
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
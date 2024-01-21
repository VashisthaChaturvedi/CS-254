// Vashistha Chaturvedi
// Q6. Implement a Quick sort algorithm, where the pivot element is almost the median of the array
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int start, int end)
{
    int pivot = v[end];
    int i = start - 1;

    for (int j = start; j <= end; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            int k = v[i];
            v[i] = v[j];
            v[j] = k;
        }
    }
    int k = v[i + 1];
    v[i + 1] = v[j];
    v[j] = k;
    return (i + 1);
}

void quicksort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);

        quicksort(v, start, pivot);
        quicksort(v, pivot + 1, end);
    }
}

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
    // input of vector size.
    vector<int> v(n);
    // input of vector.
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    quicksort(v, 0, (n - 1));
    // passing the starting and ending positions for quick sort.
}
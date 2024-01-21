// Vashistha Chaturvedi
// Q4. Implement a Quick sort algorithm, where the pivot element is almost the median of the array

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

int medianOfNumber(int a, int b, int c)
{
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

int partition(vector<int> &v, int start, int end)
{
    int pivot = medianOfNumber(v[start], v[(start + end) / 2], v[end]);
    int i = start - 1, j = end + 1;

    while (true)
    {
        i++;
        while (v[i] < pivot)
        {
            i++;
        }
        j--;
        while (v[j] > pivot)
        {
            j--;
        }
        if (i >= j)
            return j;
        else
        {
            swap(v[i], v[j]);
        }
    }
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
void solve()
{

    int n;
    cin >> n;
    // input of vector size.
    vector<int> v(n);
    // input of vector.

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    quicksort(v, 0, n - 1);
    if (n % 2 == 1)
    {
        cout << "Median of the array is : " << v[n / 2];
    }
    else
    {
        double ans = (v[(n - 1) / 2] + v[n / 2]) * 1.0 / 2;
        cout << "Median of the array is : " << ans;
    }

    cout << "\n\n";
    // passing the starting and ending positions for quick sort.
}
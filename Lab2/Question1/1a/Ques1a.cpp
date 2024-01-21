// Vashistha Chaturvedi
// Q1.a) Construct a sorted array C by merging A and B


#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 1; i <= t;i++)
    {
        cout << "Answer for test case " << i<<endl;
        solve();
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    // input of size of array A and array B
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    // input of arrays A and B.
    vector<int> c(n + m);

    int it1 = 0;
    // it1 for iterating over final array.
    int i = 0;
    int j = 0;
    // i and j for iterating over individual array.
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[it1] = a[i];
            i++;
        }
        else
        {
            c[it1] = b[j];
            j++;
        }
        it1++;
    }

    // if there is any element left after one of the array elements were finished
    while (i < n)
    {
        c[it1] = a[i];
        i++;
        it1++;
    }
    while (j < m)
    {
        c[it1] = b[j];
        j++;
        it1++;
    }
    cout << "Merged Array\n";
    // Output of the answer array.
    for (int i = 0; i < (n + m); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl<<endl;
}
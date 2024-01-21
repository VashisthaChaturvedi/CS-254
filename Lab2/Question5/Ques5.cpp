// Vashistha Chaturvedi
// Q5.) Given An unsorted array, find the first and the second minima from the array. Analyze the complexity.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min1 = INT32_MAX;
    int min2 = INT32_MAX;
    // stroing the least elements in min1 and min2 respectively
    for (int i = 0; i < n;i++)
    {
        
        if(v[i]<=min1)
        {
            // if the element is smaller than least element then 2nd minimum and current element will becime minimum
            min2 = min1;
            min1 = v[i];
        }
        else if(v[i]<=min2)
        {
            // if the element is greater than minimum but less than 2nd minimum then 2nd minimum will become that element.
            min2 = v[i];
        }
    }
    cout << "Minimums are :\n First minimum" << min1 << "\n Second minimum" << min2;
}
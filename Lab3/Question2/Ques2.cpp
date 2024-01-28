// Vashistha Chaturvedi -220001077

// Time Complexity  O(n*logn)
// Space COmplexity O(1)

#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&v,int first,int last)
{
    if(first==last)
    {
        return v[first];
    }
    if(first>last)
    {
        return INT32_MIN;
    }

    int mid = first + (last - first) / 2;
    int leftMax = maxSum(v, first, mid - 1);
    int rightMax= maxSum(v, mid + 1, last);
    
    int sum = INT32_MIN;
    sum = max(leftMax, rightMax);
    int crossingSum = v[mid];
    int temp = 0;
    
    int maxmLeftCrossing = 0;
    
    for (int i = mid - 1; i >= first; i--)
    {
        temp += v[i];
        maxmLeftCrossing = max(maxmLeftCrossing, temp);
    }
    int maxmRightCrossing = 0;
    temp = 0;
    for (int i = mid + 1; i <= last; i++)
    {
        temp += v[i];
        maxmRightCrossing = max(maxmRightCrossing, temp);
    }
    crossingSum += maxmLeftCrossing;
    crossingSum += maxmRightCrossing;
    sum = max(sum, crossingSum);
    return sum;
}
void solve(int t){
    // input size of  the array
   
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout <<"Answer for test "<<t<<"\n"<< maxSum(v, 0, n - 1)<<endl<<endl;
}
int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin >> test;
    for (int t = 1; t <= test;t++)
    {
        solve(t);
    }
}
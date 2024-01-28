// Vashistha Chaturvedi - 220001077

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)
// where N = max(n,m)
#include <bits/stdc++.h> 
using namespace std;
#define ll long long

vector<vector<int>> add_matrix(vector<vector<int>> A, vector<vector<int>> B, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] += B[i][j];
        }
    }
    return A;
}

vector<vector<int>> matrix_multiply(vector<vector<int>> &A, vector<vector<int>> &B, int N)
{
    vector<vector<int>> ANS(N, vector<int>(N, 0));
    if (N == 1)
    {
        ANS[0][0] = A[0][0] * B[0][0];
        return ANS;
    }
    int mid = N / 2;

    vector<vector<int>> A00(mid, vector<int>(mid, 0));
    vector<vector<int>> A01(mid, vector<int>(mid, 0));
    vector<vector<int>> A10(mid, vector<int>(mid, 0));
    vector<vector<int>> A11(mid, vector<int>(mid, 0));
    vector<vector<int>> B00(mid, vector<int>(mid, 0));
    vector<vector<int>> B01(mid, vector<int>(mid, 0));
    vector<vector<int>> B10(mid, vector<int>(mid, 0));
    vector<vector<int>> B11(mid, vector<int>(mid, 0));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A00[i][j] = A[i][j];
            A01[i][j] = A[i][j + mid];
            A10[i][j] = A[mid + i][j];
            A11[i][j] = A[i + mid][j + mid];
            B00[i][j] = B[i][j];
            B01[i][j] = B[i][j + mid];
            B10[i][j] = B[mid + i][j];
            B11[i][j] = B[i + mid][j + mid];
        }
    }
    vector<vector<int>> M1 = add_matrix(matrix_multiply(A00, B00, mid), matrix_multiply(A01, B10, mid), mid);
    vector<vector<int>> M2 = add_matrix(matrix_multiply(A00, B01, mid), matrix_multiply(A01, B11, mid), mid);
    vector<vector<int>> M3 = add_matrix(matrix_multiply(A10, B00, mid), matrix_multiply(A11, B10, mid), mid);
    vector<vector<int>> M4 = add_matrix(matrix_multiply(A10, B01, mid), matrix_multiply(A11, B11, mid), mid);

    for (int i = 0; i < mid; i++)
    {
        for (auto j = 0; j < mid; j++)
        {
            ANS[i][j] = M1[i][j];
            ANS[i][j + mid] = M2[i][j];
            ANS[mid + i][j] = M3[i][j];
            ANS[i + mid][j + mid] = M4[i][j];
        }
    }
    return ANS;
}

void solve(int tt){

    int n, m;
    cin >> m >> n;
    ll N = ceil(log2(max(m, n)));
    N = 1ll << N;

    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> B(N, vector<int>(N, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];

    vector<vector<int>> ans = matrix_multiply(A, B, N);

    cout << "The answer for testcase " << tt << "\n\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    ll test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        solve(t);
    }
}
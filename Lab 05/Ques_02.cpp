#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Vertex {
public:
    int cell;
    int moves;

    Vertex() : cell(0), moves(0) {}
};

void getLaddersAndSnakes(vector<int>& board) {
    int numLadders, numSnakes;
    cin >> numLadders >> numSnakes;

    for (
        int i = 0; i;
        pair<int, int> pos(int a, int n) {
            int row = n - ceil(a * 1.0 / n);
            int col;
            if ((n - row) & 1)
            {
                col = a % n - 1;
                if (col < 0)
                    col += n;
            }
            else
            {
                col = a % n;
                if (col)
                    col = n - col;
            }
            return {row, col};
        } int mx;
        int bfs(int n, int m, vector<vector<int>> &v) {
            queue<int> q;
            q.push(n);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                int y = min(mx, x + 6);
                for (int j = x + 1; j <= y; j++)
                {
                    pair<int, int> l = pos(j, m);
                    int z = j;
                    if (v[l.first][l.second] != -1)
                    {
                        z = v[l.first][l.second];
                    }
                    if (d[z] == -1)
                    {
                        d[z] = d[x] + 1;
                        q.push(z);
                    }
                }
            }
            return d[mx];
        }

        int snakesAndLadders(vector<vector<int>> & v) {
            int n = v.size();
            mx = n * n;
            d.clear();
            d.resize(mx + 1, -1);
            d[1] = 0;
            int ans = bfs(1, n, v);
            return ans;
        }

        int main() {
            // Taking input from input.in and giving output to output.out
            freopen("input.in", "r", stdin);
            freopen("output.out", "w", stdout);

            ll t;
            cin >> t;
            for (int tt = 1; tt <= t; tt++)
            {
                ll n, m;
                cin >> n >> m;
                vector<vector<int>> board(n, vector<int>(m));
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cin >> board[i][j];
                    }
                }

                ll ans = snakesAndLadders(board);

                cout << "The minimum no. of moves in testcase " << tt << " is -> " << ans << endl;
            }
        } numLadders;
        ++i)
    {
        int start, end;
        cin >> start >> end;
        board[start - 1] = end - 1;
    }

    for (int i = 0; i < numSnakes; ++i) {
        int head, tail;
        cin >> head >> tail;
        board[head - 1] = tail - 1;
    }
}

int findMinMoves(vector<int>& board) {
    int size = board.size();
    vector<bool> visited(size, false);

    deque<Vertex> queue;
    Vertex vertex;
    vertex.cell = 0;
    vertex.moves = 0;
    queue.push_back(vertex);
    visited[0] = true;

    while (!queue.empty()) {
        vertex = queue.front();
        queue.pop_front();
        int cellNum = vertex.cell;

        if (cellNum == size - 1) {
            break;
        }

        for (int i = cellNum + 1; i <= min(cellNum + 6, size - 1); ++i) {
            if (!visited[i]) {
                Vertex currentVertex;
                currentVertex.moves = vertex.moves + 1;
                visited[i] = true;

                if (board[i] == -1) {
                    currentVertex.cell = i;
                } else {
                    currentVertex.cell = board[i];
                }

                queue.push_back(currentVertex);
            }
        }
    }

    return vertex.moves;
}

int main() {

    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    
    int t; cin>>t;
    while(t--){
        int size; cin >> size;

        vector<int> board(size, -1);
        getLaddersAndSnakes(board);

        cout << findMinMoves(board) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[100][100];
bool visitt[100][100];
int m, n, k;
vector<int> v;

int dx[4] = { 0 , 0 , 1, -1 };
int dy[4] = { 1 , -1, 0, 0 };

queue<pair<int, int>> Q;

void bfs(int x, int y) {
    Q.push({ x, y });
    visitt[x][y] = 1;
    int tmp = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n ) continue;
            if (board[nx][ny] != 0 || visitt[nx][ny]) continue;
            visitt[nx][ny] = 1;
            Q.push({nx, ny});
            tmp++;
        }
        Q.pop();
    }
    v.push_back(tmp);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    while (k--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int i = ly; i < ry; i++) {
            for (int j = lx; j < rx; j++) {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 && !visitt[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

}
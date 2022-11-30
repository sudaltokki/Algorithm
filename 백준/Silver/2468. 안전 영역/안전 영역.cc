#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[100][100];
bool vis[100][100];

int n , ans;
int dx[4] = { 1 , -1, 0, 0 };
int dy[4] = { 0 , 0, 1, -1 };


queue<pair<int, int>> q;

void bfs(int x, int y, int r) {
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] <= r) continue;
            q.push({ nx, ny });
            vis[nx][ny] = 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int r = 0; r < 101; r++) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > r && !vis[i][j]) {
                    tmp++;
                    bfs(i, j, r);
                }
            }
        }
        ans = max(ans, tmp);
        fill(vis[0], vis[100], 0);
    }

    cout << ans;
    return 0;
}
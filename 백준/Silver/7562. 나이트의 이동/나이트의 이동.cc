#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[300][300];
int tc, l, ans = 0;
int sx, sy, gx, gy;

int dx[8] = { 2, -2, 2, -2, 1, -1, -1, 1 };
int dy[8] = { 1 , 1, -1, -1, 2, -2, 2, -2 };

queue<pair<int, int>> Q;

void bfs() {
    int tmp = Q.size();
    while (tmp--) {
        auto cur = Q.front();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (gx == nx && gy == ny) {
                cout << ans << "\n";
                Q = queue<pair<int, int>>();
                return;
            }
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (board[nx][ny] != 0) continue;
            board[nx][ny] = 1;
            Q.push({ nx, ny });
        }
        Q.pop();
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> l >> sx >> sy >> gx >> gy;
        if (sx == gx && sy == gy) {
            cout << 0 << "\n";
            continue;
        }
        else {
            board[sx][sy] = 1;
            Q.push({ sx, sy });

            while (!Q.empty()) {
                ans++;
                bfs();
            }
            ans = 0;
            fill(&board[0][0], &board[299][300], 0);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y ansond

char board[30][30][30];
int vis[30][30][30];

int l, r, c, ans = 0;
int dx[6] = { 1 , -1, 0, 0, 0 ,0 };
int dy[6] = { 0 , 0, 1, -1, 0, 0 };
int dz[6] = { 0 , 0, 0, 0 ,1 , -1 };


queue<tuple<int, int, int>> q;

void bfs(int x, int y, int z) {
    q.push({x, y, z});
    vis[z][x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];
            if (board[nz][nx][ny] == 'E') {
                ans = vis[get<2>(cur)][get<0>(cur)][get<1>(cur)];
                q = queue<tuple<int, int, int>>();
                continue;
            }
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
            if (vis[nz][nx][ny] > 0 || board[nz][nx][ny] != '.') continue;
            q.push({ nx, ny, nz });
            vis[nz][nx][ny] = vis[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string blank;

    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;

        for (int z = 0; z < l; z++) {
            for (int x = 0; x < r; x++) {
                cin >> board[z][x];
            }
        }

        for (int z = 0; z < l; z++) {
            for (int x = 0; x < r; x++) {
                for (int y = 0; y < c; y++) {
                    if (board[z][x][y] == 'S') {
                        bfs(x, y, z);
                    }
                }
            }
        }

        if (ans != 0) cout << "Escaped in " << ans << " minute(s)." << "\n";
        else cout << "Trapped!" << "\n";

        fill(vis[0][0], vis[30][0], 0);
        ans = 0;
    }

    return 0;
}
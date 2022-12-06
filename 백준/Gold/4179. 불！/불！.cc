#include <bits/stdc++.h>
using namespace std;

int r, c, jx, jy, fx, fy, ans;
string board[1000];
int vis[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


queue<tuple<char, int, int>> q;


void bfs() {
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = get<1>(cur) + dx[i];
            int ty = get<2>(cur) + dy[i];
            if (tx < 0 || tx >= r || ty < 0 || ty >= c) continue;
            if (board[tx][ty] == '#' || vis[tx][ty] != 0) continue;
            if (get<0>(cur) == 'f') {
                q.push({ 'f', tx, ty });
                vis[tx][ty] = -1;
            }
            else {
                if (tx == 0 || tx == r - 1 || ty == 0 || ty == c - 1) {
                    ans = vis[get<1>(cur)][get<2>(cur)] + 1;
                    return;
                }
                else {
                    q.push({ 'j', tx, ty });
                    vis[tx][ty] = vis[get<1>(cur)][get<2>(cur)] + 1;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
   
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'F') {
                q.push({ 'f', i, j });
                vis[i][j] = -1;
            }
            else if (board[i][j] == 'J') {
                jx = i;
                jy = j;
            }
        }
    }

    if (jx == 0 || jx == r - 1 || jy == 0 || jy == c - 1) {
        cout << 1;
        return 0;
    }
    else {
        q.push({ 'j', jx, jy });
        vis[jx][jy] = 1;
        bfs();
    }

    if (ans != 0) cout << ans;
    else cout << "IMPOSSIBLE";
}

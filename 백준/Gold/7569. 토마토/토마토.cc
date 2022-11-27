#include <bits/stdc++.h>
using namespace std;

int board[100][100][100];
int m, n, h, day = 0;

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0 , 1, 0, 0 , -1, 0 };
int dz[6] = { 0 , 0, 1, 0 , 0, -1 };

queue<tuple<int, int, int>> Q;

void bfs() {
    int tmp = Q.size();
    while (tmp--) {
        auto cur = Q.front();
        for (int dir = 0; dir < 6; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (board[nx][ny][nz] != 0) continue;
            board[nx][ny][nz] = 1;
            Q.push(make_tuple( nx, ny, nz ));
        }
        Q.pop();
    }
}

bool ripe() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[j][k][i] == 0) return false;
            }
        }
    }

    return true;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[j][k][i];
                if (board[j][k][i] == 1) Q.push(make_tuple(j, k, i));
            }
        }
    }


    while (!Q.empty()) {
        bfs();
        day++;
    }

    if (!ripe()) {
        cout << "-1";
        return 0;
    }

    cout << day - 1;
}
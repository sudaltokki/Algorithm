#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[25];
bool vis[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };

int n;
string s;
vector<int> blocks;

queue<pair<int, int>> q;

void bfs(int x, int y) {
    int tmp = 1;
    q.push({ x, y });
    vis[x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] == '0') continue;
            q.push({ nx, ny });
            vis[nx][ny] = 1;
            tmp++;
        }
    }
    blocks.push_back(tmp);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1' && !vis[i][j]) bfs(i, j);
        }
    }

    sort(blocks.begin(), blocks.end());
    cout << blocks.size() << "\n";
    for (int i = 0; i < blocks.size(); i++) {
        cout << blocks[i] << "\n";
    }
}
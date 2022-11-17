#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[501][501];
bool vis[501][501];
int n, m, num ,area;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 , 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				Q.push({ i, j });
				vis[i][j] = 1;
				int tmp = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						tmp++;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				num++;
				area = max(area, tmp);
			}
		}
	}

	cout << num << "\n" << area;
}
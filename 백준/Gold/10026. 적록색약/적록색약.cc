#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[100][100];
bool vis[100][100];
int n, r, g, b, rg;
string clr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 , 1, 0, -1 };

queue<pair<int, int>> q;

int bfs(int x, int y, char color, bool RG) {
	vis[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (RG) {
				if (vis[nx][ny] || board[nx][ny] == 'B') continue;
			}
			else if (vis[nx][ny] || board[nx][ny] != color) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> clr;
		int j = 0;
		for (auto c : clr) {
			board[i][j] = c;
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R' && !vis[i][j]) {
				r += bfs(i, j, 'R', false);
			}
			else if (board[i][j] == 'G' && !vis[i][j]) {
				g += bfs(i, j, 'G', false);
			}
			else if (board[i][j] == 'B' && !vis[i][j]) {
				b += bfs(i, j, 'B', false);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, false);
	} 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((board[i][j] == 'R' || board[i][j] == 'G') && !vis[i][j]) {
				rg += bfs(i, j, 'R', true);
			}

		}
	}

	cout << r + g + b << "\n" << rg + b;
}
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int n, m;
string row;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 , 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> row;
		int j = 0;
		for (auto c : row) {
			board[i][j] = c - '0';
			j++;
		}
	}

	Q.push({ 0, 0 });
	vis[0][0] = 1;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 1) continue;
			if (vis[nx][ny] != 0 && vis[cur.X][cur.Y] + 1 >= vis[nx][ny]) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
		}
	}
	cout << vis[n - 1][m - 1];
}
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[51][51];
bool vis[51][51];
int t, m, n, k;
int arr[2500][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 , 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;

	cin >> t;
	while (t--) {
		int ans = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> arr[i][1];
			cin >> arr[i][0];
			board[arr[i][0]][arr[i][1]] = 1;
		}

		for (int i = 0; i < k; i++) {
			int tmpx = arr[i][0];
			int tmpy = arr[i][1];
			if (board[tmpx][tmpy] == 1 && !vis[tmpx][tmpy]) {
				Q.push({ tmpx, tmpy });
				vis[tmpx][tmpy] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				ans++;
			}
		}

		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, false);
		} //초기화를 안시킴 ㅜㅜ
	}

}
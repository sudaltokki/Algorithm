#include <bits/stdc++.h>
using namespace std;
int board[100001];
int vis[100001];
int n, k;
int dx[2] = {1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> Q;

	cin >> n >> k;
	Q.push(n);
	vis[n] = 1;


	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx < 0 || nx > 100000 || vis[nx] > 0) continue;
			Q.push(nx);
			vis[nx] = vis[cur] + 1;
		}
		if (cur * 2 <= 100000 && vis[2 * cur] == 0) {
			Q.push(cur * 2);
			vis[cur * 2] = vis[cur] + 1;
		}
		if (vis[k] != 0) break;
	}

	cout << vis[k] - 1;
}
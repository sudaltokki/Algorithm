#include <bits/stdc++.h>
using namespace std;

int board[1000001];
int vis[1000001];

int f, s, g, u, d;

queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int tu = cur + u;
        int td = cur - d;

        if (tu == g || td == g) {
            vis[g] = vis[cur] + 1;
            return;
        }

        if (tu > 0 && tu <= f && vis[tu] == 0) {
            q.push(tu);
            vis[tu] = vis[cur] + 1;
        }
        if (td > 0 && td <= f && vis[td] == 0) {
            q.push(td);
            vis[td] = vis[cur] + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    if (s == g) {
        cout << 0;
    }
    else {
        bfs(s);
        if (vis[g] != 0) cout << vis[g] - 1;
        else cout << "use the stairs";
    }

    return 0;
}
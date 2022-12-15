#include <bits/stdc++.h>
using namespace std;

int n;
int num[3];
int board[5000][5000];

int dx[8] = { 1, 2, 0, 0, 1, 1, 2, 2 };
int dy[8] = { 0, 0, 1, 2, 1, 2, 1, 2 };


void paper(int k, int sx, int sy) {
    int tmp = board[sx][sy];
    if (k == 1) {
        bool same2 = true;
        for (int dir = 0; dir < 8; dir++) {
            if (tmp != board[sx + dx[dir]][sy + dy[dir]]) same2 = 0;
        }
        if (same2) num[tmp + 1]++;
        else {
            num[tmp + 1]++;
            for (int dir = 0; dir < 8; dir++) {
                num[board[sx + dx[dir]][sy + dy[dir]] + 1]++;
            }
        }
        return;
    }
    bool same1 = true;
    for (int i = sx; i < sx + k * 3; i++) {
        for (int j = sy; j < sy + k * 3; j++) {
            if (tmp != board[i][j]) same1 = 0;
        }
    }
    if (same1) num[tmp + 1]++;
    else {
        paper(k / 3, sx, sy);
        paper(k / 3, sx + k, sy);
        paper(k / 3, sx + (k * 2), sy);
        paper(k / 3, sx, sy + k);
        paper(k / 3, sx + k, sy + k);
        paper(k / 3, sx, sy + (k * 2));
        paper(k / 3, sx + k, sy + (k * 2));
        paper(k / 3, sx + (k * 2), sy + k);
        paper(k / 3, sx + (k * 2), sy + (k * 2));
    }


}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    paper(n / 3, 0, 0);

    for (int i = 0; i < 3; i++) {
        cout << num[i] << "\n";
    }
}
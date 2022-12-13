#include <bits/stdc++.h>
using namespace std;

int n, r, c, ans;
int order = 0;

void Z(int k, int sx, int sy) {
    if (k == 1) {
        order++;
        if (sx == c && sy == r) ans = order;
        order++;
        if (sx + 1 == c && sy == r) ans = order;
        order++;
        if (sx == c && sy + 1 == r) ans = order;
        order++;
        if (sx + 1 == c && sy + 1 == r) ans = order;
        return;
    }
    if (sx + k > c) {
        if (sy + k > r) {
            Z(k / 2, sx, sy);
        }
        else {
            order += pow(k, 2) * 2;
            Z(k / 2, sx, sy + k);
        }
    }
    else {
        if (sy + k > r) {
            order += pow(k, 2);
            Z(k / 2, sx + k, sy);
        }
        else {
            order += pow(k, 2) * 3;
            Z(k / 2, sx + k, sy + k);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    Z(pow(2, n-1), 0, 0);
    cout << ans-1;
}
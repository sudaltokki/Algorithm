#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b) {
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    hanoi(n - 1, a, 6 - a - b);
    cout << a << " " << b << "\n";
    hanoi(n - 1, 6 - a - b, b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    cout << (1 << k) - 1 << "\n";
    hanoi(k, 1, 3);
}
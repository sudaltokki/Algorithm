#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, max, a[6][2] = {0}, min = 0;
	int p, q;

	cin >> n >> max;
	for (int i = 0; i < n; i++) {
		cin >> p >> q;
		a[q - 1][p]++;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			min += int(ceil(a[i][j] / double(max)));
		}
	}

	cout << min;
}
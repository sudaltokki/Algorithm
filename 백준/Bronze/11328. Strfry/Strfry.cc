#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, tmp1[26] = {0}, tmp2[26] = {0};
	string a[2000];
	cin >> n;
	for (int i = 0; i < 2*n; i+=2) {
		cin >> a[i] >> a[i+1];
	}

	for (int i = 0; i < 2*n; i += 2) {
		for (auto c : a[i]) tmp1[c - 'a']++;
		for (auto c : a[i + 1]) tmp2[c - 'a']++;

		if (equal(tmp1, tmp1 + 26, tmp2)) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
		fill(tmp1, tmp1 + 26, 0);
		fill(tmp2, tmp2 + 26, 0);
	}
}
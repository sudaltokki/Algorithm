#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp1[26] = {0}, tmp2[26] = {0}, num = 0;
	string a, b;
	cin >> a >> b;

	for (auto c : a) tmp1[c - 'a']++;
	for (auto c : b) tmp2[c - 'a']++;

	if (equal(tmp1, tmp1 + 26, tmp2)) cout << 0;
	else {
		for (int i = 0; i < 26; i++) {
			num += tmp2[i] > tmp1[i] ? tmp2[i] - tmp1[i] : tmp1[i] - tmp2[i];
		}
		cout << num;
	}
}
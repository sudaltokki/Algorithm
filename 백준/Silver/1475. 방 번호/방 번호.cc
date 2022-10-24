#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, num = 1, tmp = 0;
	int freq[10] = { 0 };

	cin >> a;

	for (auto c : to_string(a)) {
		freq[c - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if ((i != 6 && i != 9) && freq[i] > num) num = freq[i];
		else if (i == 6 || i == 9) tmp += freq[i];
	}

	cout << max(num, int(ceil(tmp / 2.0)));
}
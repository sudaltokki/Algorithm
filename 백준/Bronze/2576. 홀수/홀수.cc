#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[7];
	int sum = 0;
	int min = 100;

	for (int i = 0; i < 7; i++) cin >> num[i];

	for (int i = 0; i < 7; i++) {
		if (num[i] % 2 == 1) {
			sum += num[i];
			if (num[i] < min) min = num[i];
		}
	}

	if (min != 100) {
		cout << sum << "\n";
		cout << min;
	}
	else cout << -1;
}
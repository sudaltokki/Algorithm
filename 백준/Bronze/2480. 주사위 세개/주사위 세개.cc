#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[3], max;
	for (int i = 0; i < 3; i++) cin >> num[i];

	if (num[0] == num[1] && num[1] == num[2]) cout << 10000 + num[0] * 1000;
	else if (num[0] == num[1] && num[1] != num[2]) cout << 1000 + num[0] * 100;
	else if (num[0] == num[2] && num[1] != num[2]) cout << 1000 + num[0] * 100;
	else if (num[1] == num[2] && num[0] != num[1]) cout << 1000 + num[1] * 100;
	else {
		max = num[0];
		for (int i = 1; i < 3; i++) {
			if (num[i] > max) max = num[i];
		}
		cout << max * 100;
	}
}
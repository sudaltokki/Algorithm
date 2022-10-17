#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[5], avg = 0;

	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		avg += num[i];
	}

	sort(num, num + 5);

	cout << avg / 5 << "\n";
	cout << num[2];
}
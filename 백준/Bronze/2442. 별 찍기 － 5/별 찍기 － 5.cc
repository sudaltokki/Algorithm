#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < ((2 * n - 1) - (2 * i - 1)) / 2; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}
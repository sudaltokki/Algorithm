#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[9], sum = 0;

	for (int i = 0; i < 9; i++) cin >> num[i];

	sort(num, num + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum += num[k];
				}
			}
			if (sum == 100) {
				for (int l = 0; l < 9; l++) {
					if (l != i && l != j) {
						cout << num[l] << "\n";
					}
				}
				return 0;
			}
			sum = 0;
		}
	}

}
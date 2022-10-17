#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[3];
	int tmp;
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (num[i] > num[j]) {
				tmp = num[j];
				num[j] = num[i];
				num[i] = tmp;
			}
		}
	}

	cout << num[0] << " " << num[1] << " " << num[2];
}
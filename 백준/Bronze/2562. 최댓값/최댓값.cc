#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[9], idx = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
		if (num[i] > num[idx]) idx = i;
	}

	cout << num[idx] << "\n" << idx + 1;
}
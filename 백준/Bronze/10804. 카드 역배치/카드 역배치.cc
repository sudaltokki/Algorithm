#include <bits/stdc++.h>
using namespace std;

int main() {
	int card[20], num[2], tmparr[20];

	for (int i = 0; i < 20; i++) {
		card[i] = i+1;
	}

	for (int i = 0; i < 10; i++) {
		cin >> num[0] >> num[1];
		int tmp = num[1] - num[0] + 1;
		for (int j = 0; j < tmp; j++) {
			tmparr[j] = card[num[1] - j - 1];
		}
		for (int j = 0; j < tmp; j++) {
			card[num[0] + j - 1] = tmparr[j];
		}
	}

	for (int i = 0; i < 20; i++) cout << card[i] << " ";
}
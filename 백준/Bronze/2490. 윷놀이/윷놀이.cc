#include <bits/stdc++.h>
using namespace std;

int main() {
	int num[3][4];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> num[i][j];

	for (int i = 0; i < 3; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			if (num[i][j] == 0) tmp++;
		}

		if (tmp == 0) cout << "E\n";
		else if (tmp == 1) cout << "A\n";
		else if (tmp == 2) cout << "B\n";
		else if (tmp == 3) cout << "C\n";
		else cout << "D\n";
	}
}
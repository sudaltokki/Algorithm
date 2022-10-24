#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	int freq[10] = { 0 };

	cin >> a >> b >> c;

	for (auto c : to_string(a*b*c)) {
		freq[c - '0']++;
	}
	

	for (int i = 0; i < 10; i++) {
		cout << freq[i] << '\n';
	}
}
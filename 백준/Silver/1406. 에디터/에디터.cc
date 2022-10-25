#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	char word;
	int m;

	list<char> L;
	cin >> s >> m;
	for (auto c : s) L.push_back(c);
	auto t = L.end();

	for (int i = 0; i < m; i++) {
		cin >> word;
		if (word == 'L') {
			if (t != L.begin()) t--;
		}
		else if (word == 'D') {
			if (t != L.end()) t++;
		}
		else if (word == 'B') {
			if (t != L.begin()) {
				--t;
				t = L.erase(t);
			}
		}
		else if (word == 'P') {
			char add;
			cin >> add;
			L.insert(t, add);
		}
	}
	
	for (auto i : L) cout << i;
}
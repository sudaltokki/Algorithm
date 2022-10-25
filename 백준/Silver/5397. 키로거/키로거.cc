#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int m;

	list<char> L;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> s;
		L.clear();
		auto t = L.begin();
		for (auto c : s) {
			if (c == '<') {
				if (t != L.begin()) t--;
			}
			else if (c == '>') {
				if (t != L.end()) t++;
			}
			else if (c == '-') {
				if (t != L.begin()) {
					--t;
					t = L.erase(t);
				}
			}
			else {
				L.insert(t, c);
			}
		}
		for (auto l : L) cout << l;
		cout << "\n";

	}
}
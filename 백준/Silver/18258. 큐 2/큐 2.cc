#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n, tmp;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "push") {
			cin >> tmp;
			q.push(tmp);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << -1 << "\n";
		}
		else if (s == "front") {
			if (!q.empty()) cout << q.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (s == "back") {
			if (!q.empty()) cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}
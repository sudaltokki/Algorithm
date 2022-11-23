#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	string s;
	stack<char> st1;
	stack<int> st2;

	cin >> s;
	for (auto c : s) {
		int tmp = 0;
		if (c == '(' || c == '[') st1.push(c);
		else if (c == ')') {
			if (!st1.empty() && st1.top() == '(') {
				st1.pop();
				st1.push('.');
				st2.push(2);
			}
			else if (!st1.empty() && st1.top() == '.') {
				while (!st1.empty() && st1.top() == '.') {
					st1.pop();
					tmp += st2.top();
					st2.pop();
				}
				if (st1.empty() || st1.top() != '(') {
					cout << 0;
					return 0;
				}
				st1.pop();
				st1.push('.');
				st2.push(tmp * 2);
			}
			else {
				cout << 0;
				return 0;
			}

		}
		else if (c == ']') {
			if (!st1.empty() && st1.top() == '[') {
				st1.pop();
				st1.push('.');
				st2.push(3);
			}
			else if (!st1.empty() && st1.top() == '.') {
				while (!st1.empty() && st1.top() == '.') {
					st1.pop();
					tmp += st2.top();
					st2.pop();
				}
				if (st1.empty() || st1.top() != '[') {
					cout << 0;
					return 0;
				}
				st1.pop();
				st1.push('.');
				st2.push(tmp * 3);
			}
			else {
				cout << 0;
				return 0;
			}

		}
	}

	if (!st2.empty() && !st1.empty()) {
		if (st1.size() != st2.size()) {
			{
				cout << 0;
				return 0;
			}
		}
		while(!st2.empty()) {
			ans += st2.top();
			st2.pop();
		}
	}
	cout << ans;
}
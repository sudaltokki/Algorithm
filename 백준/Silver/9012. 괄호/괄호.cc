#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;

	cin >> n;
	while (n--) {
		cin >> s;
		if (s == ".") return 0;
		else {
			stack<char> st;
			for (auto c : s) {
				if (c == '(') st.push(c);
				else if (c == ')') {
					if (!st.empty()) st.pop();
					else {
						st.push('x');
						break;
					}
				}
			}
			if (st.empty()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
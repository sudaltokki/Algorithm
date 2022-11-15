#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	bool closed = false;
	string s;
	stack<char> st;

	cin >> s;
	for (auto c : s) {
		if (c == '(') {
			st.push(c);
			closed = false;
		}
		else if (c == ')') {
			if (closed == true) {
				st.pop();
				ans++;
			}
			else {
				st.pop();
				ans += st.size();
			}
			closed = true;
		}
	}
	cout << ans;
}
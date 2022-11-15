#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	string s;

	cin >> n;
	while(n--) {
		cin >> s;
		stack<char> st;
		for (auto c : s) {
			if (st.empty()) st.push(c);
			else {
				if (st.top() == c) st.pop();
				else st.push(c);
			}
		}
		if (st.empty()) ans++;
	}
	cout << ans;
}
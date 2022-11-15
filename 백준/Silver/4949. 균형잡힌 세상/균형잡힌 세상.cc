#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	while(true) {
		getline(cin, s);
		if (s == ".") return 0;
		else {
			stack<char> st;
			for (auto c : s) {
				if (c == '(' || c == '[') st.push(c);
				else if (c == ')') {
					if (!st.empty() && st.top() == '(') st.pop();
					else {
						st.push('x');
						break;
					}
				}
				else if (c == ']') {
					if (!st.empty() && st.top() == '[') st.pop();
					else {
						st.push('x');
						break;
					}
				}
			}
			if (st.empty()) cout << "yes\n";
			else cout << "no\n";
		}

	}

}
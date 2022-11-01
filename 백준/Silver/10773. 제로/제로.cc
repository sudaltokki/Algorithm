#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	int k, n, sum = 0;

	cin >> k;
	while (k--) {
		cin >> n;
		if (n == 0) {
			sum -= st.top();
			st.pop();
		}
		else {
			st.push(n);
			sum += n;
		}
	}
	cout << sum;
}
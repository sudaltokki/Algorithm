#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n, tmp;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= n; i++) q.push(i);

	while (true) {
		q.pop();
		if (q.size() == 1) break;
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
}
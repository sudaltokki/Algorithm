#include <bits/stdc++.h>
using namespace std;

int n, a[100000], x, tmp[1000001], num = 0;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - a[i] > 0 && x - a[i] <= 1000000 &&tmp[x - a[i]] > 0) num++;
	    tmp[a[i]]++;
    }

	cout << num;
}
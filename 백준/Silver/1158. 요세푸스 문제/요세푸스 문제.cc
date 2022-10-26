#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	pre[nxt[addr]] = pre[addr];
	unused--;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) insert(i, i+1);
	pre[1] = n;
	nxt[n] = 1;

	cout << "<";
	int cursor = k;
	while(n) {
		cout << cursor;
		erase(cursor);
		if (n != 1) {
			cout << ", ";
			for (int i = 0; i < k; i++) cursor = nxt[cursor];
		}

		n--;
	}
	cout << ">";
	
}
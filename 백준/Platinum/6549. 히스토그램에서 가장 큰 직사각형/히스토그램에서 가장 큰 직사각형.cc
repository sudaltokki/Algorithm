#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    stack<pair<int, int>> S;
    long long ans = 0;
      
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      int idx = i;
      while (!S.empty() && S.top().first >= h) {
        ans = max(ans, 1LL * (i - S.top().second) * S.top().first);
        idx = S.top().second;
        S.pop();
      }
      S.push({h, idx});
    }
    while (!S.empty()) {
      ans = max(ans, 1LL * (n - S.top().second) * S.top().first);
      S.pop();
    }
    cout << ans << '\n';
  }
}
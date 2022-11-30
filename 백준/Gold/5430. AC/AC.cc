#include <bits/stdc++.h>
using namespace std;

int T, n;
bool isError = false, isReverse = false;
string p, arr;
vector<string>v;

deque<string> DQ;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> p >> n >> arr;
        arr = arr.substr(1, arr.size()-2);
        istringstream ss(arr);
        while (getline(ss, arr, ','))
        {
            DQ.push_back(arr);
        }

        for (auto c : p) {
            if (c == 'R') {
                isReverse = !isReverse;
            }
            else {
                if (!DQ.empty()) {
                    if (isReverse) DQ.pop_back();
                    else DQ.pop_front();
                }
                else {
                    cout << "error" << "\n";
                    isError = true;
                    break;
                }
            }
        }
        if (!isError) {
            cout << "[";
            if (isReverse) {
                for (int i = 0; i < DQ.size(); i++) {
                    cout << DQ[DQ.size() - 1 - i];
                    if (i != DQ.size() - 1) cout << ",";
                }
            }
            else {
                for (int i = 0; i < DQ.size(); i++) {
                    cout << DQ[i];
                    if (i != DQ.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }

        isError = false;
        isReverse = false;
        DQ = deque<string>();
    }
}

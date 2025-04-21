#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int transitions = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            transitions++;
        }
    }

    int min_cost = n + max(0, transitions - 1); // We can reduce at most 1 transition
    cout << min_cost << '\n';
}

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

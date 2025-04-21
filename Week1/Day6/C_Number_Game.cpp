#include <bits/stdc++.h>
using namespace std;

// FAST_IO
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Shortcuts
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a)); 

    auto ok = [&](int k) {
        multiset<int> s(a.begin(), a.end());

        for (int i = 1; i <= k; i++) {
            int limit = k - i + 1;

            // Find the largest element ≤ limit
            auto it = s.upper_bound(limit);
            if (it == s.begin()) return false; // no valid element
            --it;

            s.erase(it); // Alice removes this

            // Bob increases any element by limit => increase smallest one
            if (!s.empty()) {
                int smallest = *s.begin();
                s.erase(s.begin());
                s.insert(smallest + limit);
            }
        }
        return true;
    };

    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    FAST_IO;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

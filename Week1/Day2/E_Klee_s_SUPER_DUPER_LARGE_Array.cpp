#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair<long long, long long> val(long long mid, long long k, long long n) {
    long long val1 = (mid + k - 1 + k) * mid / 2;
    long long val2 = (k + n - 1 + k) * n / 2 - val1;
    return {val1, val2};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long lo = 1, hi = n, curr = 1;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            auto [a, b] = val(mid, k, n);
            if (b > a) {
                curr = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        auto [a1, b1] = val(curr, k, n);
        auto [a2, b2] = val(curr + 1, k, n);
        cout << min(b1 - a1, a2 - b2) << endl;
    }
    return 0;
}

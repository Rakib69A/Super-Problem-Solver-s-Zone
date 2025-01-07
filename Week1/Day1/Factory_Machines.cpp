#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll mid, ll N, ll T, ll* K) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (mid / K[i]);
        if (sum >= T)
            return true;
    }
    return false;
}

ll solve(ll N, ll T, ll* K) {
    ll low = 1, high = (*min_element(K, K + N)) * T;
    ll ans;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid, N, T, K)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ll N, T; cin>>N>>T;
    ll K[N];
    for (int i = 0; i < N; i++) {
        cin>>K[i];
    }
    cout << solve(N, T, K);
}

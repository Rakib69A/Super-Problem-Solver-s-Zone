#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, k;
    cin >> n >> k;

    // lamda function
    auto getSum = [&](ll l, ll r) -> ll
    {
        return (r * (r + 1) / 2) - (l * (l - 1) / 2);
    };
    ll l = k, r = n + k - 1, ans = LLONG_MAX, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        ll s1 = getSum(k, mid);
        ll s2 = getSum(mid + 1, n + k - 1);
        ans = min(ans, abs(s1 - s2));
        if (s1 > s2)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto ok = [&](ll second)
    {
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (second / a[i]);
            if(cnt >= t)
                return true;
        }
        return (cnt >= t);
    };

    ll l = 1, r = 1e18, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}
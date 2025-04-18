#include <bits/stdc++.h>
using namespace std;

// FAST_IO
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Shortcuts
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

// Solve function
void solve() {
    int n,x;cin>>n>>x;
    vector<int> a(n);

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    //Lamda function
    auto getVal = [&] (int val){
    	ll sum = 0;
    	for(int i=0;i<n;i++){
    		if(a[i] < val)
    			sum += (val - a[i]);
    	}
    	
    	return sum;
    };

    ll l = 1, r = 2e9+5, mid, ans;
    while(l<=r){
    	mid = l + (r - l)/2;
    	ll val = getVal(mid);

    	if(val == x){
    		ans = mid;
    		break;
    	}

    	if(val < x){
    		ans = mid;
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }
    cout<<ans<<endl;

}
int main() {
    FAST_IO;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
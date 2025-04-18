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
    int n,k;cin>>n>>k;
    vector<int> a(k);

    for(int i=0;i<k;i++)
    	cin>>a[i];

    sort(a.rbegin(),a.rend());

   	ll cat_pos = 0, total = 0;
   	for(int i=0;i<k;i++){
   		if(cat_pos < a[i]){
   			cat_pos += (n-a[i]);
   			total++;
   		}
   		else break;
   	}
   	cout<<total<<endl;
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
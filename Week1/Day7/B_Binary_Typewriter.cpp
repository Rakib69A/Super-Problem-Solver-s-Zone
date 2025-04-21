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
	int n;cin>>n;
	string s, a;cin>>s;
	a = s;
	map<char,int> mp;
	for(char c : s){
		mp[c]++;
	}
	cout<<mp['0']<<" "<<mp['1']<<endl;
	if(mp['0'] >= 0 and mp['1'] == 0){
		cout<<"Return"<<endl;
		return;
	}

	int l = 0, r = 0, cnt = 0;
	int mx = INT_MIN;
	while(r<n){
		if(s[r] == '0'){
			cnt++;
			mx = max(mx,cnt);
		}
		else{
			l = r + 1;
			cnt = 0;
		}
		r++;
	}
	cout<<"max = "<<mx<<endl;

	l = 0, r = 0, cnt = 0;

	while(r<n){
		if(s[r] == '0'){
			cnt++;
		}
		else{
			l = r + 1;
			cnt = 0;
		}
		if(cnt == mx){
			break;
		}
		r++;
	}
	int x = r;
	cout<<"L = "<<l<<" R = "<<r<<endl;
	for(int i=0;i<=x;i++)
		cout<<a[i]<<" ";
	cout<<endl;



	cout<<endl;
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
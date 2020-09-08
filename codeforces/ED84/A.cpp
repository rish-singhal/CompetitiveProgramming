#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL m =1e9 +7;

void solve(){
	LL n,k; cin>>n>>k;
	if( (n&1) != (k&1)) cout<<"NO\n";
	else{
		n-=k;
		n>>=1;
		if(n >= (k * (k - 1))/ 2)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// 5 -> 101

void solve(){
	int n,k; cin>>n>>k;
	vector<LL> v(n);
	forn(i,n) cin>>v[i];
	LL x =0;
	vector<LL> aa(31);
	for(LL i = 30; i>=0 ; i--){
		LL bb = 0;
		forn(j,n){
			if((v[j]&(1LL<<i))){
				bb ++;
			}
		}
		aa[i] = (bb)*((1LL<<i));
	}
	vector<LL> dp(k+1,-1), xx(k+1,-1);
	forn(i,31){
		for(LL pp = k; pp>=1; pp--){
			if((dp[pp] < (dp[pp-1] + aa[i])) && dp[pp-1]!=-1){
				dp[pp] = dp[pp-1] + aa[i];
				xx[pp] = (xx[pp-1]|(1LL<<i));
			}
		}
		if((dp[0] < aa[i]) || dp[0]==-1){
				dp[0] = aa[i];
				xx[0] = 1LL<<i;
			}
	}
	//cout<<xx[k-1]<<endl;
	if(__builtin_popcount(xx[k-1])==k){
		cout<<xx[k-1]<<endl;
	}
	else{
		LL x = xx[k-1];
		LL pk  = k - __builtin_popcount(xx[k-1]);
		forn(i,31){
			if((x && (1LL<<i))==0){
				x ^= (1LL<<i);
				pk--;
				if(pk==0){
					cout<<x<<endl;
					return;
				}
			}
		}
	}
	
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
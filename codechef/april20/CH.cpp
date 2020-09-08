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

void solve(){
	int n,m,k ;cin>>n>>m>>k;
	vector<LL> ann;
	forn(i,n){
		vector<LL> v(m+1);
		forn(j,k){
			int a; cin>>a;
			v[a]++;
		}
		LL mx = 0;
		for(int z=1;z<=m;z++){
			if(v[z]>=mx){
				mx = v[z]; 
			}
		}
		vector<LL> kk;
		for(int z=1;z<=m;z++){
			if(mx==v[z]) {
				kk.pb(z);
					for1(sa,100) kk.pb(z);
		}
		else{
			for1(sa,20) kk.pb(z);
		}
	}
		LL mm = (0 + (rand() % static_cast<int>(kk.size())));
		ann.pb(kk[mm]);
	}

	forn(i,n) cout<<ann[i]<<" ";
		cout<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
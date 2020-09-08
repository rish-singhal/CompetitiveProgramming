#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL n; cin>>n;
  	LL k,z; cin>>k>>z;
  	vector<LL> v(n);
  	forn(i,n) cin>>v[i];
  	LL an = 0;
  	forn(zz,z+1){
  		LL vv = 0;
  		LL nu = k - 2*zz;
  		LL ma = 0;
  		forn(i,nu+1){
  			vv += v[i];
  			if(i>=1){
  				ma = max(ma, v[i]+v[i-1]);
  			}
  		}
  		an = max({an, vv + ma*zz});
  		if(nu+1 < n && zz >= 1) {
  			ma = max(ma, v[nu+1]+v[nu]);
  			vv += v[nu+1] + v[nu] + (zz-1)*ma;
  		}
  		an = max(an, vv);
  	}
  	cout<<an<<endl;
  }
  return 0;
}
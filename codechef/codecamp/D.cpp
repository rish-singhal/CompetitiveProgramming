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

int main(){
  fio();
  LL n,k ;cin>>n>>k;
  vector<LL> v(n);
  forn(i,n){
  	LL x; cin>>v[i];
  }
  sort(all(v));
  forn(i,n){
  	cout<<1<<" "<<v[i]<<endl;
  	k--;
  	if(k==0) return 0;
  }
  for1(i,n){
  	vector<LL> vv;
  	vv.pb(i+1);
  	forn(j, i){
  		vv.pb(v[n-j-1]);
  	}
  	forn(j,n-i){
  		for(auto x:vv) cout<<x<<" ";
  		cout<<v[j]<<" ";
  	cout<<endl;
  	k--;
  	if(k==0) return 0;
  	}
  }
  return 0;
}
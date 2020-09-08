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
	LL n; cin>>n;
	vector<LL> v(n);
	forn(i,n){
		int k; cin>>k;
		if(k==0) {
			v[i] = 2;
			continue;
		}
		v[i] = __builtin_ctz(abs(k));
	}
	//cout<<v[0]<<" ";
	for1(i,n-1) {
		v[i]+=v[i-1];
		//cout<<v[i]<<" ";
	}
	cout<<endl;
	LL an = (n*(n+1))/2;
	map<LL,LL> m;
	m[0]++;
	forn(i,n){
		an-=m[v[i]-1];
		m[v[i]]++;
	}
	cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
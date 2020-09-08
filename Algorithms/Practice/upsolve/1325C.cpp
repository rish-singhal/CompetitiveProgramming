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



vector<vector<pair<LL,LL>>> v(MAXN);
vector<pair<LL,LL> > an;

int n; 
LL dfs(int i, int p){
	int sz = 1;
	for(auto e:v[i]){
		if(e.fi!=p){
			int zz = dfs(e.fi,i);
			an.pb({zz*1LL*(n-zz) ,e.se});
			sz+=zz;
		}
	}
	return sz;
}

int main(){
  fio();
  cin>>n;
  forn(i,n-1){
  	int a,b; cin>>a>>b;
  	v[a].pb({b,i});
  	v[b].pb({a,i});
  }
  dfs(1,0);
  sort(all(an));
  vector<int> ann(n);
  forn(i,n-1){
  	ann[an[i].se] = i;
  }
  forn(i,n-1) cout<<ann[i]<<endl;
  return 0;
}
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
  int n,m,q;
  cin>>n>>m>>q;
  vector<array<int,4> > Q(q);
  int an = 0;
  vector <int> v;
  forn(i,q) forn(j,4) { cin>>Q[i][j]; Q[i][j]-=j<=1;}
  function<void(int)> dfs = [&](int u){
  	if(v.size()==n){
		int ma = 0;
		an = max(an, accumulate(all(Q), ma, [&](int k, array<int,4> z){
			return v[z[1]] - v[z[0]] == z[2]? k + z[3]: k;
		}));
		return;
	}
	for(int i = u; i<=m ;i++){
		v.pb(i);
		dfs(i);
		v.pop_back();
	}
  };
  dfs(1);
  cout<<an<<endl;
  return 0;
}
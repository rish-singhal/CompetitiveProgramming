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

int dsu[MAXN];

int pa(int u){
	return dsu[u]<0?u:dsu[u] = pa(dsu[u]);
}

void join(int u, int v){
	u = pa(u);
	v = pa(v);
	if(u==v)return;
	if(dsu[u]>dsu[v]) swap(u,v);
	dsu[u]+=dsu[v];
	dsu[v] = u;
}

int main(){
  fio();
  int n; cin>>n;
  vector<pair<int,int>> p;
  memset(dsu,-1,sizeof dsu);
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	if(pa(u)==pa(v)){
  		p.pb({u,v});
  	}
  	else join(u,v);
  }
  vector<int> v;
  for1(i,n) if(dsu[i]<0) v.pb(i);
  cout<<(v.size()-1)<<endl;
  for(int i=1;i<v.size();i++){
  	cout<<p[i-1].fi<<" "<<p[i-1].se<<" ";
  	cout<<v[0]<<" "<<v[i]<<endl;
  }
  return 0;
}
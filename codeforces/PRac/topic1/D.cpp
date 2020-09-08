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

/*
6 2
2 3 4 5 6 10
2-4
3-6
5-10 
*/

int dsu[MAXN];

int par(int u){
	return dsu[u]<0?u:dsu[u]=par(dsu[u]);
}

void join(int u, int v){
	u = par(u);
	v = par(v);
	if(u==v) return;
	if(dsu[u] < dsu[v]) swap(u,v);
	dsu[v]+=dsu[u];
	dsu[u] = v;
}

int main(){
  fio();
  LL n,k; cin>>n>>k;
  vector<LL> v(n);
  forn(i,n) {
  	cin>>v[i];
  	dsu[i] = -1;
  }
  if(k==1){
  	cout<<n<<endl;
  	return 0;
  }
  sort(all(v));
  map<LL,int> m;
  forn(i,n){
  	if(v[i]%k==0){
  		if(m.find(v[i]/k)!=m.end()){
  			join(m[v[i]/k],i);
  		}
  	}
  	m[v[i]] = i;
  }
  int an = 0;
  forn(i,n){
  	if(dsu[i]<0){
  		int sz = -dsu[i];
  		an+=(sz+1)/2;
  		}	
  }
  cout<<an<<endl;
  return 0;
}
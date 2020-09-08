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
const int MAXN = 5e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<vector<int>> adj(MAXN);

int val[MAXN];


int main(){
  fio();
  int n,m; cin>>n>>m;
  forn(i,m){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  vector<pair<int,int>> p;
  queue<int> q;
  for1(i,n){
  	int x; cin>>x;
  	p.pb({x,i});
  	val[i] = x;
  }
  int b = 0;
  
  for1(i,n){
  	set<LL> s;
  	int x = 1;
  	for(auto j:adj[i]){
  		s.insert(val[j]);
  		
  	}
  	for(auto j:s){
  		if(j==x) x++;
  	}
  	//cout<<"yes"<<endl;
  	if(x!=val[i]){
  		b = 1;
  		break;
  	}
  }

  if(b){
  	cout<<-1<<endl;
  	return 0;
  }
  sort(all(p));
  for(auto i:p) cout<<i.se<<" ";
  	cout<<endl;
  return 0;
}
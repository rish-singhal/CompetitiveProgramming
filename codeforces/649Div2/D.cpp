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

vector<vector<int>> adj(MAXN);
int n,m, k; 
int vis[MAXN];
int zz[MAXN];
stack <int> s;

void dfs(int i, int p = -1){
	vis[i] = 1;
	s.push(i);
	for(auto j:adj[i]){
		if(vis[j]==1 && j!=p){
			cout<<j<<" ";
			while(s.top()!=j){
				cout<<s.top()<<" ";
				s.pop();
			}
			exit(0);
		}
		if(vis[j]==0) dfs(j,i);
	}
	vis[i] = 2;
	s.pop();
}


int main(){
  fio();
 cin>>n>>m>>k;
 forn(i,m){
 	int u, v; cin>>u>>v;
 	adj[u].pb(v);
 	adj[v].pb(u);
  }
  vector<LL> cn(n+1);
  for1(i,n){
  	set<int> s;
  	for(auto j:adj[i])
  		s.insert(zz[j]);
  	int cnt = 1;
  	while(s.count(cnt)) cnt++;
  	zz[i] = cnt;
  	cn[cnt]++;
  }
  LL ck = *max_element(cn.begin()+1, cn.end());
  LL cc;
  for1(i,n){
  	if(cn[i]==ck)
  	{
  		cc = i; break;
  	}
  }
  if(ck >= ((k+1)/2)){
  	cout<<1<<endl;
  	LL kk = ((k+1)/2);
  	for1(i,n){
  		if(kk==0) break;
  		if(zz[i]==cc){
  			cout<<i<<" ";
  			kk--;
  		}
  	}
  	cout<<endl;
  }
  else{
  	cout<<2<<endl;
  	for1(i,n)
  	if(zz[i]==cc){
  		bfs(i);
  	}
  }
  return 0;
}
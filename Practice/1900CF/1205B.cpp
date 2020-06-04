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
int vis[MAXN];
int cc = -1;
int bi = 0;
int an = 1000;

void bfs(int i, int n){
   queue<int> q;
   vector<int> dis(n, -1), par(n,-1);
   dis[i]=0;
   q.push(i);
   while(!q.empty()){
   	auto u = q.front();
   	q.pop();
   	for(auto x:adj[u]){
   		if(par[x]!=u && par[u]!=x && dis[x]!=-1){
   			an = min(an,dis[u]+1+dis[x]);
   		}
   		if(dis[x]==-1){
   			dis[x]=dis[u]+1;
   			par[x] = u;
   			q.push(x);
   		}
   	}
   }
}

int main(){
  fio();
  int n; cin>>n;
  vector<vector<int>> b(64);
  vector<vector<int>> v(n);
  int z = 0;
  forn(i,n){
  	LL x; cin>>x;
  	forn(j,64){
  		if((x>>j)&1) {
  			b[j].pb(i);
  			v[i].pb(j);
  		}
  	}
  }
  int bb = 1;
  forn(i,64){
  	if(b[i].size()>=3){
  		cout<<3<<endl;
  		return 0;
  	}
  	bb &= (b[i].size()==0);
  }
  if(bb){
  	cout<<-1<<endl;
  	return 0;
  }

  for(int i=0;i<n;i++){
  	for(auto k:v[i]){
  		for(auto j:b[k]){
  			if(i!=j){
  				adj[i].pb(j);
  			}
  		}
  	}
  }
  //int an = 1000;
  for(int i=0;i<n;i++){	
  	if(v[i].size()==0) continue;
  //	cc = i;
  	bfs(i,n);
  }
  cout<<(an==1000?-1:an)<<endl;
  return 0;
}
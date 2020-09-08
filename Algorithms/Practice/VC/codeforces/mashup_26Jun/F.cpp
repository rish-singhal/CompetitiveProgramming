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
const int MAXN = 2e4 +5;
const LL INF = 1e8;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<vector<int>> adj(MAXN);

int main(){
  fio();
  LL a,b; cin>>a>>b;
  if(b<=a){
  	cout<<abs(a-b)<<endl;
  	return 0;
  }
  for1(i,MAXN){
  	if(i!=1){
  		adj[i].pb(i-1);
  	}

  	if(2*i <= MAXN)adj[i].pb(2*i);
  }
  LL dis[MAXN];
  for1(i,MAXN) dis[i] = INF;
  dis[a] = 0;
  queue<int> q;
  q.push(a);
  while(!q.empty()){
  	int x = q.front();
  	q.pop();
  	if(x==b){
  		cout<<dis[b]<<endl;
  		return  0;
  	}
  	for(auto i:adj[x]){
  		if(dis[i] > dis[x] + 1){
  			dis[i] = dis[x]+1;
  			q.push(i);
  		}
  	}
  }
  return 0;
}
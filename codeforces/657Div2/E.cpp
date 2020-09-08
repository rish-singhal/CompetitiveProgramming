#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL n,x,y; cin>>n>>x>>y;
  	vector<LL> v(n);
  	vector<vector<int>> adj(n+2);
  	vector<int> cn(n+2);
  	forn(i,n){
  		LL x; cin>>x;
  		adj[x].pb(i);
  		cn[x]++;
  	}
  	LL pp = -1;
  	for1(i,n+1) 
  		if(!cn[i]){
  		pp =  i; break;
  	}
  	LL np = y - x;
  	np = (np + 1)/2;
  	
  }
  return 0;
}
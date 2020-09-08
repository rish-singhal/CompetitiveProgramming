#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 1e5 +5;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int> > adj(MAXN);
LL n;
LL ds[MAXN], cnt= 0;
void dfs(int u, int p, int d=0){
  ds[u] = d;
  cnt += d&1;
  for(auto &v:adj[u]){
    if(v!=p)
      dfs(v,u, d+1);
  }
}

int main(){
  fio();
  cin>>n;
  forn(i,1,n){
    int a,b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1,0);
  cout<<( (n-cnt)*cnt - (n-1))<<endl;
  return 0;
}


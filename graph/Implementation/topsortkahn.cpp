#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)

const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n,m; cin>>n>>m;
  vector <int> in(n+1);
  vector <vector <int> > adj(n+1);
  forn(i,m){
     int u,v; cin>>u>>v;  
     in[v]++;
     adj[u].pb(v);
  }
  priority_queue <int, vector<int>, greater<int> > pq;
  for1(i,n) if(!in[i]) pq.push(i);
  vector <int> an;
  while(!pq.empty()){
    int u = pq.top();
    pq.pop();
    an.pb(u);
    for(auto v:adj[u])
    {
      in[v]--;
      if(!in[v]) pq.push(v);
    }
  }
  if(an.size()!=n) cout<<"Sandro fails."<<endl;
  else{
    for(auto i:an) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define forn(i,j,k) for(int i=j;i<k;i++)
const int INF = 1e9+5;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector <vector<pair<int,int> > > adj(n);
  vector <int> d(n);
  forn(i,0,n){
    int u,v,d; cin>>u>>v>>d;
    u--, v--;
    adj[u].push_back({v,d});
    adj[v].push_back({u,d});
  }
  forn(i,0,n) d[i] = INF;
  d[0] = 0;
  deque <pair<int,int> > dq;
  dq.push_back({0,0});
  while(!dq.empty()){
    auto x = dq.front();
    dq.pop_front();
    if(d[x.fi] < x.se) continue;
    d[x.fi] = x.se;
    for(auto u:adj[x.fi]){
      if(d[u.fi] > d[x.fi] + u.se){
        if(!u.se) dq.push_front({u.fi, d[x.fi] + u.se});
        else dq.push_back({u.fi, d[x.fi] + u.se});
      }
    }
  }
  return 0;
}


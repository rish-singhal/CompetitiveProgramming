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

vector <vector<int> > adj(MAXN);
int an[MAXN], vis[MAXN];
bool ann = 1;
void dfs(int i,int j){
  vis[i] = 1;
  an[i] = j;
  for(auto k: adj[i]){
    if(vis[k] && an[k] != (j^1)) {
      ann=0;
      return;
    }
    if(!vis[k]) dfs(k,(j^1));
  }
}


int main(){
  fio();
  int t; cin>>t;  
  int x = 1;
  while(x<=t){
    int n; cin>>n;
    vector<pair<int,int> > v(n);
    forn(i,n) cin>>v[i].fi>>v[i].se;
    ann = 1;
    forn(i,n){
       an[i] = -1;
       vis[i] = 0;
       adj[i].clear();
    }
    forn(i,n){
      forn(j,n){
        if(i==j) continue;
        int b = v[i].fi >= v[j].fi && v[i].fi <= v[j].se && v[i].fi!=v[j].se;
        b|= v[i].se >=v[j].fi && v[i].se <=v[j].se && v[i].se!=v[j].fi;
        if(b){
          adj[i].pb(j);
          adj[j].pb(i);
        }
      }
    }
//    cout<<"dde"<<endl;
    for(int i=0;i<n;i++)
      if(!vis[i]) dfs(i,0);
    cout<<"Case #"<<x<<": ";
    if(ann==0) cout<<"IMPOSSIBLE"<<endl;
    else{
      forn(i,n) cout<<(an[i]?"C":"J");
      cout<<endl;
    }
    x++;
  }
  return 0;
}


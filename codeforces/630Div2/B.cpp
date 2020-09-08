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
const int MAXN = 1e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int> > adj(MAXN);
vector <int> tp;
int vis[MAXN], vis2[MAXN], co[MAXN];

void dfs(int i){
  vis[i] = 1;
  for(auto j:adj[i]) 
    if(!vis[j]) dfs(j);
  tp.pb(i);
}

void dfs2(int i, int c){
  vis2[i] = 1;
  co[i] = c;
  for(auto j:adj[i])
    if(!vis2[j]) dfs2(j,c);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
    tp.clear();
    int n; cin>>n;
    vector <int> v(n);
    forn(i,n){
      vis[i] = vis2[i] = co[i] = 0;
      adj[i].clear();
    }
    forn(i,n) cin>>v[i];
    forn(i,n) for(int j=i+1; j<n;j++){
      if(gcd(v[i],v[j])==1) continue;
      adj[i].pb(j);
      adj[j].pb(i);
    }
  //  forn(i,n) if(!vis[i]) dfs(i);
//    cout<<"ee"<<endl;
  //  reverse(tp.begin(), tp.end());
    int cnt = 0;
    forn(i,n){
      if(co[i]) continue;
      co[i] = ++cnt;
      for(auto j:adj[i]){
          }
    }


    cout<<cnt<<endl;
    forn(i,n) cout<<co[i]<<" ";
    cout<<endl;
  }
    return 0;
}


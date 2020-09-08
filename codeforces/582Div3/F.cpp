#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
vector <int> adj[200005];
vector <int> radj[200005];
int n,k;
stack <int> s;
int vis[200005];
int vis2[200005];
char cc[200005];
void dfs(int i){
   if(vis[i]) return ;
   vis[i]= 1;
   for(auto u:adj[i]){
     if(vis[u]) continue;
     dfs(u);
   }
   s.push(i);
}

void dfs2(int i,char c){
  if(vis2[i]) return;
  vis2[i] = 1;
  cc[i] = c;
  for(auto v:radj[i])
    if(!vis2[v]) dfs2(v,c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin>>n>>k;
    vector<int> v(n);
    
    forn(i,n) cin>>v[i];
    for1(i,n-1){ 
      adj[v[i-1]].pb(v[i]);
      radj[v[i]].pb(v[i-1]);
    }
    forn(i,n) cin>>v[i];
    for1(i,n-1){ 
      adj[v[i-1]].pb(v[i]);
      radj[v[i]].pb(v[i-1]);
    }
    for(int i=1;i<=n;i++)
      if(!vis[i]) dfs(i);
    int cnt = 0;
    while(!s.empty()){
      int u = s.top();
      s.pop();
//      cout<<u<<endl;
      if(vis2[u]) continue;
      cnt = min(k-1,cnt);
      if(!vis2[u]){ 
       dfs2(u,cnt+'a');
       cnt++;
      }
    }
    if(cnt<k){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
      for1(i,n) cout<<cc[i];
      cout<<endl;
    }
    return 0;
}


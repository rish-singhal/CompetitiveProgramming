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
int n; int a[200005];
vector <int> adj[200005]; 
map<int,map<int,int > > m;
int an = 0;
void dfs(int u,int p){
  for(auto v:adj[u]){
    if(v==p) continue;
    dfs(v,u);
    if(gcd(a[v],a[u])!=1){
       for(auto i:m[v]){
          for(auto j:m[u]){
            if(gcd(i.fi,j.fi)!=1){
              an = max( an, i.se + j.se);
              }
          }
      }
    
    for(auto i:m[v]){
      int gc = gcd(i.fi,a[u]);
      if(gc!=1){
        m[u][gc] = max(m[u][gc],1+i.se);
        }
      }
    }
  }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin >> n;
    for1(i,n){ cin>>a[i]; if(a[i]>1) an=1;}
    for1(i,n-1){
      int x,y; cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    for1(i,n) m[i][a[i]] = 1;
    dfs(1,0);
    cout<<an<<endl;
    return 0;
}


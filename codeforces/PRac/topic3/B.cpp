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
const int MAXN = 500 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,m,k;

vector<string> vv;

int vis[MAXN][MAXN];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector <pair<int,int>> tp;

void dfs(int u, int v){ 
  vis[u][v] = 1;
  forn(i,4){
    int x = dx[i] + u;
    int y = dy[i] + v;
    if(x<0 || x>=n || y<0 || y>=m || vv[x][y]!='.') continue; 
    if(!vis[x][y]) dfs(x,y);
  }
  tp.pb({u,v});
}


int main(){
  fio();
  cin>>n>>m>>k;
  forn(i,n){
    string x; cin>>x;
    vv.pb(x);
  }
  forn(i,n){
    forn(j,m){
      if(!vis[i][j] && vv[i][j]=='.') {
        dfs(i,j);
        break;
    }
  }
}

  for(int i=0;i<k;i++){
    vv[tp[i].fi][tp[i].se] = 'X';
  }
  forn(i,n) cout<<vv[i]<<endl;
  return 0;
}
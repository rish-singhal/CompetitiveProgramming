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
const int MAXN = 50 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,m,k;

vector <string> vv;

int vis[MAXN][MAXN], dis[MAXN][MAXN];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int u, int v, int d){ 
  vis[u][v] = 1;
  dis[u][v] = d;
  //if(vv[u][v]=='A' && dis[0][0]==0) cout<<u<<" "<<v<<endl;
  
  forn(i,4){
    int x = dx[i] + u;
    int y = dy[i] + v;
    if(x<0 || x>=n || y<0 || y>=m || vv[x][y]!=vv[u][v]) continue; 
    if(vis[x][y]==1 && dis[x][y]==0){
      if(dis[u][v] + 1>=4){
        cout<<"Yes"<<endl;
        exit(0);
      }
    }
    if(vis[x][y]==0) dfs(x,y,d+1);
  }
  vis[u][v] = 2;
}


int main(){
  fio();
  cin>>n>>m;
  forn(i,n){
    string x; cin>>x;
    vv.pb(x);
  }
  forn(i,n)
    forn(j,m){
      
      forn(a,n)
        forn(b,m)
          vis[a][b] = dis[a][b] = 0;
      
      dfs(i,j,0);
    }

  cout<<"No"<<endl;

  return 0;
}
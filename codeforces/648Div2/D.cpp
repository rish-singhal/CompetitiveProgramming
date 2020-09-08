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
const int MAXN = 55;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<string> v;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int vis[MAXN][MAXN];
int n,m;

void dfs(int nx, int ny, int cc){
	vis[nx][ny] = cc;
	//cout<<nx<<" "<<ny<<" --"<<endl;
	forn(k,4){
		int x = nx + dx[k];
 		int y = ny + dy[k];
 		//cout<<x<<" "<<y<<" --"<<endl;
 		if(x<0 || x>=n || y<0 || y>=m) continue;
 		if(vis[x][y]) continue;
 		//cout<<"yy"<<endl;
 		if(v[x][y]!='#') dfs(x,y,cc);
	}	
}

int main(){
  fio();
 int t; cin>>t;
 while(t--){
 	 cin>>n>>m;
 	v.clear();
 	forn(i,n) forn(j,m) vis[i][j] =0;
 	v.resize(n);
 	forn(i,n) cin>>v[i];
 	vector<pair<int,int>>  p;
 	vector<pair<int,int>> vv;
 	forn(i,n){
 		forn(j,m){
 			if(v[i][j]=='G') p.pb({i,j});
 			if(v[i][j]!='B') continue;

 			forn(k,4){
 				int x = i + dx[k];
 				int y = j + dy[k];
 				if(x<0 || x>=n || y<0 || y>=m) continue;
 				if(v[x][y]=='.') v[x][y] = '#';
 			}
 			vv.pb({i,j});
 		}
 	}

 	for(auto i:vv){
 		if(vis[i.fi][i.se]==0) dfs(i.fi,i.se,1);
 	}
 	if(p.size()==0 && vis[n-1][m-1]!=1){
 		cout<<"Yes"<<endl;
 		continue;
 	}
 	if(p.size()){
 		dfs(p[0].fi, p[0].se, 2);
 	}
 	int b = 1;
 	forn(i,n){
 		forn(j,m){
 			if(v[i][j]!='G') continue;
 			b &= (vis[i][j]==2);
 		}
 	}
 	// forn(i,n) {
 	// 	forn(j,m) cout<<vis[i][j]<<" ";
 	// 	cout<<endl;
 	// }
 	b &= (vis[n-1][m-1]==2);
 	if(b) cout<<"Yes"<<endl;
 	else cout<<"No"<<endl;
 }
  return 0;
}
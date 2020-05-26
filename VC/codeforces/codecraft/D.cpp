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

/*

L D D D
X D D D
R D D L
R R R U
*/

int n;
vector<vector<pair<int,int>>> v(MAXN,vector<pair<int,int>>(MAXN)); 
vector<vector<int>> an(MAXN, vector<int>(MAXN));
vector<pair<int,int>> p;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

string ss = "$LDRUX";
string sp = "$3412X";

int vis[MAXN][MAXN], vis2[MAXN][MAXN];
int chk = 0;

void dfs(int x, int y, int a, int b){
	vis[x][y] = 1;
	forn(i,4){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<1 || nx>n || ny<1 || ny>n || vis[nx][ny]==2 || v[nx][ny]!=v[x][y] || (a==nx && b==ny))
			continue;
		if(vis[nx][ny]!=0 && v[nx][ny].fi==-1 ){
			chk = 1;
			an[nx][ny] = i+1;
		}
		if(vis[nx][ny]==0){
			an[nx][ny] = i+1;
			dfs(nx,ny,x,y);
		}
	}
	vis[x][y] = 2;
}

int main(){
  fio();
  cin>>n;
  map<pair<int,int>, int> m;
  m[{-1,-1}] = 1;
  for1(i,n){
  	for1(j,n){
  		int u,x; cin>>u>>x;
  		v[i][j]={u,x};
  		if(u==i && x==j) {
  			an[i][j] = 5;
  			p.pb({i,j});
  			m[{i,j}] = 1;
  		}
  	}
  }
  for1(i,n){
  	for1(j,n){
  		if(m[{v[i][j].fi,v[i][j].se}]!=1){
  			cout<<"INVALID"<<endl;
  				return 0;
  		}
  	}
  }
  for(auto i:p){
  	if(!vis[i.fi][i.se]){
  		dfs(i.fi, i.se, 0, 0);
  		if(chk==1){
  			cout<<"INVALID"<<endl;
  				return 0;
  		}
  		vis2[i.fi][i.se]=1;
  	}
  	chk = 0;
  }

  for1(x,n){
  	for1(y,n){
  		if(an[x][y]==0){
  	 forn(i,4){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<1 || nx>n || ny<1 || ny>n || v[x][y].fi!=-1 || v[nx][ny].fi!=-1 || an[nx][ny]==0)
			continue;
  		an[x][y] = sp[i+1]-'0';
  		break;
  		}
  	}
  }
}

  int bb = 1;
  for1(i,n){
  	for1(j,n) bb&=an[i][j]!=0;
  }
  if(bb==0){
  	cout<<"INVALID"<<endl;
  	return 0;
  }
  cout<<"VALID"<<endl;
  for1(i,n){
  	for1(j,n) cout<<ss[an[i][j]];
  	cout<<endl;
  }

  return 0;
}
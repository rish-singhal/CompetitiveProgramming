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

/*
........
..K...K.
......#.
K..#K..#
.......#
..K##.K#
......#.
K...K...

*/
int dp[9][9];
vector<string> v(8);
int dx[4] = {2,2,-2,-2};
int dy[4] = {-2,2,-2,2};

int cnt = 0;

void dfs(int x, int y, int d){
	if(dp[x][y]!=-1) return;
	if(v[x-1][y-1] !='#') cnt++;
	dp[x][y] = d;
	forn(i,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<1|| nx>8 || ny<1|| ny>8)
				continue;
				dfs(nx, ny, d^1);
		}
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	cnt = 0;
  	for1(i,8){
  		for1(j,8){
  			dp[i][j] = -1;
  		}
  	}	
  	vector <pair<int,int>> k;
  	forn(i,8) {
  		cin>>v[i];
  		forn(j,8){
  			if(v[i][j]=='K'){
  				k.pb({i+1,j+1});
  			}
  		}
  	}
  	dfs(k[0].fi, k[0].se, 0);
  	//cout<<dp[k[0].fi][k[0].se]<<" "<<dp[k[1].fi][k[1].se]<<" "<<cnt<<endl;
  	if(dp[k[0].fi][k[0].se]==dp[k[1].fi][k[1].se] && cnt){
  		cout<<"YES"<<endl;
  	}
  	else cout<<"NO"<<endl;
  }
  return 0;
}
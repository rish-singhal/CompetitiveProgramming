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



int main(){
  fio();
  int n,m,t; cin>>n>>m>>t;
  vector <vector<int>> v(n, vector<int>(m,0));
  forn(i,n){
  	string s; cin>>s;
  	forn(j,m) v[i][j] = s[j]-'0';
  }
  vector <vector<int>> dp(n, vector<int>(m,-1));
  queue <pair<int,int>> q;
  int dx[4] = {0,1,0,-1};
  int dy[4] = {1,0,-1,0};
 
  forn(i,n)
  	forn(j,m){
  		int b = 1;
  		forn(k,4){
  			int x = i + dx[k], y = j + dy[k];
  			if(x<0 || x>=n || y>=m || y<0)
  				continue;
  			b&=v[i][j]!=v[x][y];
		}
		if(!b){
			dp[i][j] = 0;
			q.push({i,j});
		}
	}

  while(!q.empty()){
  	 int i = q.front().fi;
  	 int j = q.front().se;
  	 q.pop();
  	 forn(k,4){
  	 	int x = i + dx[k], y = j + dy[k];
  		if(x<0 || x>=n || y>=m || y<0 || dp[x][y]!=-1)
  				continue;
  		dp[x][y] = dp[i][j]+1;
  		q.push({x,y});
  	 }
  }

  while(t--){
  	LL x,y,k; cin>>x>>y>>k;
  	x--, y--;
  	if(k<dp[x][y] || dp[x][y]==-1) cout<<v[x][y]<<endl;
  	else{
  		cout<<(v[x][y]^((k-(LL)dp[x][y])&1))<<endl;
  	}
  }

  return 0;
}
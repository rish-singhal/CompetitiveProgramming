#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;
const LL INF = 1e17;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

map <pair<pair<int,int>,pair<int,int>>, LL> mm;
int n, m, k;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};



int main(){
  fio();
  cin >> n >> m >> k;
  if(k&1){
  	forn(i, n){
  		forn(j, m){
  			cout << "-1 ";
  		}
  		cout << "\n";
  	}
  	return 0;
  }

  for(int i = 0; i < n; i++){
  	for(int j = 0; j < m - 1; j++){
  		LL w; cin >> w;
  		mm[{{i,j},{i,j+1}}] = w;
  		mm[{{i,j+1},{i,j}}] = w;
  	}
  }

  forn(i, n - 1){
  	forn(j, m){
  		LL w; cin >> w;
  		mm[{{i,j},{i+1,j}}] = w;
  		mm[{{i+1,j},{i,j}}] = w;
  	}
  }

  vector<vector<LL>> dp(n, vector <LL>(m, 0));
  forn(d, k/2){
    vector<vector<LL>> newdp(n, vector <LL>(m, 0));
    forn(x, n){
      forn(y, m){
          newdp[x][y] = INF;
          forn(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                newdp[x][y] = min(newdp[x][y], mm[{{x,y},{nx,ny}}] + dp[nx][ny]);
            }
      }
    }
  }
  swap(dp, newdp);
}
  forn(i, n){
    forn(j, m){
      cout << 2*dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
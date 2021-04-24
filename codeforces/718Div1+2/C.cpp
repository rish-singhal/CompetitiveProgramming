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
const int MAXN = 500 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int mat[MAXN][MAXN];
int n; 
int dy[2] = {0, -1};
int dx[2] = {1, 0};


void dfs(int x, int y, int num) {
	if(num == 0)
		return;
 	
 	forn(i, 2){
 		int nx = x + dx[i];
 		int ny = y + dy[i];
 		if(nx >= 0 && nx < n && ny >=0 && ny < n && mat[nx][ny] == -1){
 			mat[nx][ny] = mat[x][y];
 			dfs(nx, ny, num - 1);
 			break;
 		}
 	}
}

int main(){
  fio();
  cin >> n;
  forn(i, n)
  forn(j, n)
  	mat[i][j] = -1;
  forn(i, n){
  	cin >> mat[i][i];
  }
  for(int i = n - 1; i >= 0; i--){
  	dfs(i, i, mat[i][i] - 1);
  }

  for(int i = 0; i < n; i++){
  	for(int j = 0; j <= i; j++){
  		cout << mat[i][j] << " ";
  	}
  	cout << "\n";
  }
  return 0;
}
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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL ans(LL a, LL b){
	//cout << a << " " << b << " -- " << endl;
	LL k = max(a,b);
	LL m = min(a,b);
	return max(0LL, min(m - 1, (k/2) - 1)) + max(0LL, min(k - 1, (m/2) - 1));
}

void solve(){
	int r, c; cin >> r >> c;
	int grid[r][c], down[r][c], lef[r][c], rig[r][c], up[r][c];

	forn(i, r)
		forn(j, c) 
			{
				cin >> grid[i][j];
				up[i][j] = down[i][j] = lef[i][j] = rig[i][j] = 0;
			}

	forn(j, c)
		forn(i, r){
			if(grid[i][j]) down[i][j] = (i>=1?down[i - 1][j]:0) + grid[i][j];
		}

	// forn(j, c)
	// 	forn(i, r){
	// 		if(i + 1 < r)
	// 			{
	// 				if(down[i+1][j] != 0)
	// 					down[i][j] = 0;
	// 			}
	// 	}

	forn(i, r)
		forn(j, c){
			if(grid[i][j]) lef[i][j] = (j>=1?lef[i][j - 1]:0) + grid[i][j];
		}

	// forn(i, r)
	// 	forn(j, c){
	// 		if(j + 1 < c)
	// 			{
	// 				if(lef[i][j + 1] != 0)
	// 					lef[i][j] = 0;
	// 			}
	// 	}

	forn(i, r)
		for(int j = c - 1; j >= 0; j--){
			if(grid[i][j]) rig[i][j] = (j + 1 < c?rig[i][j + 1]:0) + grid[i][j];
		}

	// forn(i, r)
	// 	for(int j = c - 1; j >= 0; j--){
	// 		if(j - 1 >= 0)
	// 			{
	// 				if(rig[i][j - 1] != 0)
	// 					rig[i][j] = 0;
	// 			}
	// 	}

	forn(j, c)
		for(int i = r - 1; i >= 0; i--){
			if(grid[i][j]) up[i][j] = (i + 1 < r?up[i + 1][j]:0) + grid[i][j];
		}

	// forn(j, c)
	// 	for(int i = r - 1; i >= 0; i--){
	// 		if(i - 1 >=0 )
	// 			{
	// 				if(up[i-1][j] != 0)
	// 					up[i][j] = 0;
	// 			}
	// 	}

	// cout << endl << " ---- " << endl;

	// forn(i, r)
	// 	{
	// 		forn(j, c){
	// 			cout << down[i][j] <<" ";
	// 		}
	// 		cout << endl;
	// 	}

	// cout << " ---- " << endl;

	// forn(i, r)
	// 	{
	// 		forn(j, c){
	// 			cout << up[i][j] <<" ";
	// 		}
	// 		cout << endl;
	// 	}

	// cout << " ---- " << endl;

	// forn(i, r)
	// 	{
	// 		forn(j, c){
	// 			cout << rig[i][j] <<" ";
	// 		}
	// 		cout << endl;
	// 	}

	// cout << " ---- " << endl;

	// forn(i, r)
	// 	{
	// 		forn(j, c){
	// 			cout << lef[i][j] <<" ";
	// 		}
	// 		cout << endl;
	// 	}

	// cout << " ---- " << endl;

	LL an = 0;
	LL ch = r*c;
	forn(i, r)
		forn(j , c){

			if( lef[i][j] >= 2 && up[i][j] >= 2)
				an += ans(lef[i][j], up[i][j]);
			if( rig[i][j] >= 2 && up[i][j] >=2)
				an += ans(up[i][j], rig[i][j]);
			if( rig[i][j] >=2 && down[i][j] >=2)
				an += ans(rig[i][j], down[i][j]);
			if( lef[i][j] >=2 && down[i][j] >=2)
				an += ans(lef[i][j], down[i][j]);
			//else ch --;

		}
    cout << an << endl;
}

int main(){
  fio();
  int t; cin >> t;
  for1(i, t){
  	cout << "Case #" << i <<": ";
  	solve();
  }
  return 0;
}
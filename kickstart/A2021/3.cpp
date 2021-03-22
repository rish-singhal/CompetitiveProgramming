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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
	LL r, c; cin >> r >> c;
	LL cell[r][c];
	map <pair<LL,LL>, LL> ch;
	set <pair<LL, pair<LL,LL>>> pm;
	forn(i, r)
		forn(j, c)
			{
				cin >> cell[i][j];
				pm.insert({cell[i][j], {i, j}});
			}
	LL an = 0;
	while(!pm.empty()){
		auto fir = *pm.rbegin();
		pm.erase(fir);
		auto cor = fir.se;
		forn(i, 4){
			int x = dx[i] + cor.fi;
			int y = dy[i] + cor.se;
			if(x >= 0 && x < r && y >= 0 && y < c && ch[{x, y}] == 0)
			{
				if(abs(- cell[x][y] + fir.fi) > 1){
					an += (fir.fi - 1) - cell[x][y];
					pm.erase({cell[x][y], {x, y}});
					cell[x][y] = fir.fi - 1;
					pm.insert({cell[x][y], {x, y}});
				}
			}
		}
		ch[fir.se] = 1;
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
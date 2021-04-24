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

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	int n, m; cin >> n >> m;
  	int b[n][m];
  	vector <pair<int, pair<int,int>>> vv;
  	map <pair<int,int>, int> mm;
  	forn(i, n){
  		forn(j, m){
  			cin >> b[i][j];
  			vv.push_back({b[i][j], {i, j}});
  		}
  	}
  	sort(all(vv));
  	vector <pair<int,int>> p(m);
  	for(int i = 0; i < m; i++){
  		p[i] = vv[i].se;
  		mm[vv[i].se] = 1;
  	}
  	for(int i = 0; i < n; i++){
  		int kk = 0;
  		for(int j = 0; j < m; j++){
  			if(p[j].fi == i){
  				cout << b[p[j].fi][p[j].se] << " ";
  			}
  			else{
  				while(mm.find({i,kk}) != mm.end()) kk++;
  				cout << b[i][kk] << " ";
  				mm[{i, kk}] = 1;
  			}
  		}
  		cout << endl;
  	}
  } 
  return 0;
}
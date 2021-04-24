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

vector <pair<int,int>> pp;

map <pair<int,int>, int> m2;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt = 0;

LL wei = INF;

void dfs(int x, int y, int dis){	
	queue<pair<pair<int,int>, pair<int,LL>>> q;
	q.push({{x, y}, {0, 0}});
	
	//p.insert({x, y});
    pp.pb({x, y});
	m2[{x, y}] = 1;
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();

		if(f.se.fi && k%f.se.fi == 0 && (k/f.se.fi)%2 == 0){
			wei = min(wei, (k/f.se.fi)*f.se.se);
		}

		if(f.se.fi == dis)
			continue;
		
		forn(i, 4){
			int nx = f.fi.fi + dx[i];
			int ny = f.fi.se + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && m2.find({nx, ny}) == m2.end()){
				q.push({{nx, ny}, {f.se.fi + 1, f.se.se + mm[{{nx, ny},{f.fi.fi,f.fi.se}}]}});
				pp.pb({nx, ny});
				m2[{nx, ny}] = 1;
			}
		
		}	
	}
	
}

LL ans(int u, int v){
	wei = INF;
	int dis = (k/2);
	//p.clear();
	pp.clear();
	m2.clear();
	
	dfs(u, v, dis);

	return wei;
}

int main(){
  fio();
  cin >> n >> m >> k;
  // if(k&1){
  // 	forn(i, n){
  // 		forn(j, m){
  // 			cout << "-1 ";
  // 		}
  // 		cout << "\n";
  // 	}
  // 	return 0;
  // }

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

 // cout << "YES" << endl;

  forn(i, n){
  	forn(j, m){
  		LL anns = ans(i, j);
  		cout << (anns == INF?-1:anns) << " ";
  	}
  	cout << endl;
  }

  return 0;
}
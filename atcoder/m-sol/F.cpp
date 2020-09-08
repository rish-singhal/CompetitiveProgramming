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
  LL n; cin>>n;
  vector<vector<pair<LL,LL>>> v(4);
  map<string, int> m;
  m["U"] = 0;
  m["R"] = 1;
  m["D"] = 2;
  m["L"] = 3;
  map < LL, set<LL> > xxy[4];
  map < LL, set<LL> > yyx[4];
  map < LL, set<LL> > mp[4];
  forn(i,n){
  	LL x,y; cin>>x>>y;
  	string u; cin>>u;
  	int in = m[u];
  	v[in].pb({x,y});
  	if(in&1){
  		yyx[in][y].insert(x);
  	}
  	else{
  		xxy[in][x].insert(y);
  	}
  	mp[in][x+y].insert(x);
  } 
  int an = 0;
  LL res = 1e17;
  forn(i,4){
  	for(auto p: v[i]){
  		LL x = p.fi, y = p.se;
  		if(i == 0){
  			auto z = xxy[2][x].upper_bound(y);
  			if(z != xxy[2][x].end()){
  				auto yy = *z;
  				res = min(res, abs(yy - y)*5LL);
  				an = 1; 
  			}

  			auto zz = mp[1][x+y].lower_bound(x);
  			if(zz!=mp[1][x+y].begin()){
  				zz--;
  				auto yy = *zz;
  				res = min(res, abs(x - yy)*10LL); //<<endl;
  				an = 1; 
  			}

  			auto zk = mp[3][x+y].upper_bound(x);
  			if(zk!=mp[3][x+y].end()){
  				auto yy = *zk;
  				res = min(res, abs(x - yy)*10LL); //<<endl;
  				an = 1; 
  			}

  		}
  		if(i==1){
  			auto z = yyx[3][y].upper_bound(x);
  			if(z != yyx[3][y].end()){
  				auto yy = *z;
  				res = min(res, abs(x - yy)*5LL);
  				an = 1;
  			}
  		}
  		if(i==2){
  			auto z = xxy[0][x].lower_bound(y);
  			if(z != xxy[0][x].begin()){
  				z--;
  				auto yy = *z;
  				res = min(res, abs(y - yy)*5LL); //<<endl;
  				an = 1; // break;
  			}

  			auto zz = mp[1][x+y].lower_bound(x);
  			if(zz!=mp[1][x+y].begin()){
  				zz--;
  				auto yy = *zz;
  				res = min(res, abs(x - yy)*10LL); //<<endl;
  				an = 1; 
  			}

  			auto zk = mp[3][x+y].upper_bound(x);
  			if(zk!=mp[3][x+y].end()){
  				auto yy = *zk;
  				res = min(res, abs(x - yy)*10LL); //<<endl;
  				an = 1; 
  			}

  		}
  		if(i==3){
			auto z = yyx[1][y].lower_bound(x);
  			if(z != yyx[1][y].begin()){
  				z--;
  				auto yy = *z;
  				res = min(res, abs(x - yy)*5LL);
  				an = 1; //break;
  			}
  		}
  	}
  	//if(an==1) break;
  }
  if(!an) cout<<"SAFE"<<endl;
  else cout<<res<<endl;
  return 0;
}
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
  int n,k ;cin>>n>>k;
  multiset <pair<LL,LL>> s;
  forn(i,n) {
  	int x; cin>>x;
  	s.insert({x,i+1});
  }
  vector<pair<int,int>> vv;
  LL an = 1e17, in;
  forn(i,k){
  	LL zzz = (*s.rbegin()).fi - (*s.begin()).fi;
  	if(an>zzz){
  		an = zzz;
  		in = i;
  	}
  	auto xx = s.begin();
  	auto jx = *xx;
  	s.erase(xx);
  	s.insert({jx.fi + 1, jx.se});
  	auto zxx = s.end();
  	zxx--;
  	auto jy = *zxx;
  	s.erase(zxx);
  	s.insert({jy.fi - 1, jy.se});
  	vv.pb({jy.se,jx.se });
  }
  LL zzz = (*s.rbegin()).fi - (*s.begin()).fi;
	if(an>zzz){
		an = zzz;
		in = k;
	}
  cout<<an<<" "<<in<<endl;
  forn(i,in) cout<<vv[i].fi<<" "<<vv[i].se<<endl;
  return 0;
}
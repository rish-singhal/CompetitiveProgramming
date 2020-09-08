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
const LL INF = 1e17;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin>>n;
  vector<pair<int,int>> v;
  forn(i,n){
  	int c, d; cin>>c>>d;
  	v.emplace_back(c,d);
  }
LL mi = 0, ma = INF;
if(v[0].se ==1){
	mi = 1900, ma = INF;
}
else {
	mi = -INF, ma = 1899;
}
  forn(i,n-1){
  	if(v[i].se!=v[i+1].se){
  		if(v[i].se==1){
  			if(v[i].fi >= 0 ||  (mi + v[i].fi)>=1900){
  				cout<<"Impossible"<<endl;
  				return 0;
  			}
  			mi = mi + v[i].fi;
  			ma = min(ma + v[i].fi,(LL)1899);
  		}
  		else{
  			if(v[i].fi <= 0 || (ma+v[i].fi) < 1900 ){
  				cout<<"Impossible"<<endl;
  				return 0;
  			}
  			ma = ma + v[i].fi;
  			mi = max(mi + v[i].fi, (LL)1900);
  		}
  	}
  	else{
  		if(v[i].se==1){
  			ma += v[i].fi;
  			mi = max(v[i].fi+mi,(LL)1900);
  			if(ma < 1900){
  				cout<<"Impossible"<<endl;
  				return 0;
  			}
  		}
  		else{
  			ma = min(v[i].fi+ma, (LL)1899);
  			mi = v[i].fi+mi;
  			if(mi >= 1900){
  				cout<<"Impossible"<<endl;
  				return 0;
  			}
  		}
  	}
  	if(mi > ma){
  		cout<<"Impossible"<<endl;
  		return 0;
  	}
  }
  if(mi > ma){
  		cout<<"Impossible"<<endl;
  		return 0;
  	}
  if(ma >= (1e9)){
  	cout<<"Infinity"<<endl;
  	return 0;
  }
  LL ann = ma + v[n-1].fi;
 	cout<<ann<<endl;
  return 0;
}
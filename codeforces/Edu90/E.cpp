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

LL su( LL a){
	LL an = 0;
	while(a){
		an+=a%10;
		a/=10;
	}
	return an;
}

int main(){
  fio();
  map<pair<LL,LL>,LL> m;
  forn(i,100000){
  	LL s = su(i);
  	forn(j,10){
  		if(j>=1){
  			s += su(i+j);
  		}
  		if(m.find({s,j})==m.end()){
  				m[{s,j}] = i;
  		}
  	}
  }
  auto x = m.rbegin();
  cout<<(*x).fi.fi<<endl;
  int t; cin>>t;
  while(t--){
      int x,y; cin>>x>>y;
      cout<<m[{x,y}]<<endl;
  }
  return 0;
}
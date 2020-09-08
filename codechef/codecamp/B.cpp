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
  vector<int> v(n);
  forn(i,n) cin>>v[i];
  vector<vector<int>> vv(n);
  int cnt = 1;
  set<pair<int,int>> s;
  forn(i,n) if(v[i])s.insert({v[i],i});
  while(1){
  	set<pair<int,int>> ss;
  	if(cnt==1){
	  	int x = (*s.begin()).fi;
	  	for(auto i:s) forn(j,x) vv[i.se].pb(cnt);
	  	for(auto i:s) if(i.fi>x) ss.insert({i.fi-x,i.se});
	  	if(ss.size()==0) {
	  		cnt++;
	  		break;
	  	}
	  	s = ss;
 	}
 	else{
 		ss.clear();
	  	for(auto i:s) vv[i.se].pb(cnt);
	  	for(auto i:s) if(i.fi>1) ss.insert({i.fi-1,i.se});
	  	if(ss.size()==0) {
	  		cnt++;
	  		break;
	  	}
	  	s = ss;
 	}
  	if(cnt==1){
	  	ss.clear();
	  	for(auto i:s) vv[i.se].pb(cnt);
	  	for(auto i:s) if(i.fi>1) ss.insert({i.fi-1,i.se});
	  	if(ss.size()==0) {
	  		cnt++;
	  		break;
	  	}
	  	s = ss;
  	}
  	cnt++;
  }
  cnt--;
  if(cnt<=k){
  	cout<<"YES"<<endl;
  	forn(i,n) {
  		for(auto j:vv[i]) cout<<j<<" ";
  			cout<<endl;
  	}
  }
  else cout<<"NO"<<endl;
  return 0;
}
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
  int t; cin>>t;
  while(t--){
 	 int n; cin>>n;
 	 vector<int> v(2*n);
 	 vector<int> o,e;
 	 forn(i,2*n) {
 	 	cin>>v[i];
 	 	if(v[i]&1) o.pb(i+1);
 	 	else e.pb(i+1);
 	 }
 	 vector<pair<int,int>> vv;
 	for(int i=0;i+1<(int)e.size();i+=2){
 		if(i+1<e.size())vv.pb({e[i],e[i+1]});
 	}
	for(int i=0;i<(int)o.size()-1;i+=2){
	 		if(i+1<o.size())vv.pb({o[i],o[i+1]});
	 	}
 	 forn(i,n-1){
 	 	cout<<vv[i].fi<<" "<<vv[i].se<<endl;
 	 }
 }
  return 0;
}
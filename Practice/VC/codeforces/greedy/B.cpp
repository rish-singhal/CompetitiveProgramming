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

// 

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	string s; cin>>s;
  	vector<int> e, o;
  	forn(i,s.size()){
  		int d = s[i]-'0';
  		if(d&1) o.pb(d);
  		else e.pb(d);
  	}
  	int l = 0, r = 0;
  	vector<int> an;
  	while(l<e.size() && r<o.size()){
  		if(e[l]<o[r]){
  			an.pb(e[l]);
  			l++;
  		}
  		else{
  			an.pb(o[r]);
  			r++;
  		}
  	}
  	while(r<o.size()){
  		an.pb(o[r]);
  			r++;
  	}
  	while(l<e.size()){
  		an.pb(e[l]);
  			l++;
  	}
  	for(auto i:an) cout<<i;
  		cout<<endl;
  }
  return 0;
}
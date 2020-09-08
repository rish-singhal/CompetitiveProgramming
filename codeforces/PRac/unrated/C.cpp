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
  	string s; cin>>s;
  	map <pair<pair<LL,LL> ,pair<LL,LL> >, LL> m;
  	LL a = 0, b = 0;
  	LL an = 0;
  	for(auto i:s){
  		pair<pair<LL,LL> ,pair<LL,LL> > x = {{a,b}, {0,0}}, y = {{0,0}, {a,b}};
  		if(i=='N') a++;
  		if(i=='S') a--;
  		if(i=='E') b++;
  		if(i=='W') b--;
  		x.se = {a,b};
  		y.fi = {a,b};
  		if(m[x] || m[y]) an+=1;
  		else an+=5;
  		m[x] = 1;
  		m[y] = 1;
  	}
  	cout<<an<<endl;
  }
  return 0;
}
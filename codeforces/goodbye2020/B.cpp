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
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();	
  int t; cin>>t;
  while(t--){
  	int n ;cin>>n;
  	vector<LL> v(n);
  	forn(i,n) cin>>v[i];
  	map <LL, int> m;
  	for(int  i = 0; i < n; i++) m[v[i]]++;
  	set <LL> s;
  	for(auto i: m){
  		if(i.se > 1)
  		{
  			s.insert(i.fi);
  			s.insert(i.fi + 1);
  			continue;
  		}
  		if(s.find(i.fi) != s.end()){
  			s.insert(i.fi + 1);
  		}
  		else s.insert(i.fi);
  	}
  	cout << s.size() << endl;
  }
  return 0;
}

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
  	int n,k ;cin>>n>>k;
  	string s; cin>>s;
  	vector<LL> v(26);
  	for(auto i:s) v[i-'a']++;
  	forn(i,26) v[i]/=k;
  	sort(all(v));
  	reverse(all(v));
  	LL an = 0;
  	LL mi = 1e18;
  	forn(i,26){
  	   mi = min(mi, v[i]);
  	   LL len = i+1;
  	   an = max(an, mi*(i+1));
  	}	
  	cout<<an<<endl;
  }

  return 0;
}
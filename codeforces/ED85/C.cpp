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

LL min(LL a,LL b)
{
	return a>b?b:a;
}
int main(){
  fio();	
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<LL> v(n), d(n);
  	vector<LL> va(n);
  	LL su = 0;
  	forn(i,n) {
  		cin>>v[i]>>d[i];
  	}
  	forn(i,n) {
  		va[i] = max(0LL, v[i]-d[(i-1+n)%n]);
  		su+=va[i];
  	}
  	LL mi  =1e18;
  	forn(i,n){
  		mi = min(mi, su-va[i]+v[i]);
  	}
  	cout<<mi<<endl;
  }
  
  return 0;
}
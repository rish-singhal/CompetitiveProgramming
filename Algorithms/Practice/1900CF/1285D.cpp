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

LL solve(vector<int>& a, int x){
	if(x<0) return 0;
	vector<int> l, r;
	for(auto i:a){
		if(i&(1<<x)) l.pb(i^(1<<x));
		else r.pb(i);
	}
	if(l.size()==0) return solve(r, x-1);
	if(r.size()==0) return solve(l, x-1);
	return min(solve(l,x-1), solve(r,x-1)) + (1<<x);
}

int main(){
  fio();
  int n; cin>>n;
  vector<int> a(n);
  forn(i,n) cin>>a[i];
  cout<<solve(a,30)<<endl;
  return 0;
}
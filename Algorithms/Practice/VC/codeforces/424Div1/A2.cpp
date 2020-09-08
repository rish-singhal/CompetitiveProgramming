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
const int MAXN = 2e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,k;
LL p; 
vector<LL> a,b;

bool chk(LL t){
	int j = 0;
	forn(i,k)
		if((abs(b[i]-a[j]) + abs(b[i]-p)) <= t && j<n){
				j++; if(j>=n) return 1;}
	return 0;
}

int main(){
  fio();
  cin>>n>>k>>p;
  a.resize(n), b.resize(k);
  forn(i,n) cin>>a[i];
  forn(i,k) cin>>b[i];
  sort(all(a));
  sort(all(b));
  LL l = 0, r = 1e9+5;
  while(l<r){
  	LL m = (l) + (r-l)/2;
  	if(chk(m))	r = m;
  	else l = m+1;
  }
  cout<<l<<endl;
  return 0;
}
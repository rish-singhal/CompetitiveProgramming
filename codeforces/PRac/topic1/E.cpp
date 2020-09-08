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

int n,h; 
vector<int> a;

bool check(int x){
	vector<int> v(x);
	forn(i,x) v[i] = a[i];
	sort(all(v));
	int hh = h;
	LL p = 0;
	int bb = 1;
	for(int i=0;i<x;){
		if(i+1<x){
			hh-=v[i+1];
			i+=2;
		}
		else{
			hh-=v[i];
			i++;
		}
		if(hh<0) bb = 0;
	}
	if(bb) return 1;

	if((x&1)==0) return bb;
	hh = h - v[0];
	bb = 1;
	for(int i=1;i<x;){
		if(i+1<x){
			hh-=v[i+1];
			i+=2;
		}
		else{
			hh-=v[i];
			i++;
		}
		if(hh<0) bb = 0;
	}
	return bb;
}

int main(){
  fio();
  cin>>n>>h;	
  forn(i,n) {
  	int x; cin>>x;
  	a.pb(x);
  }
  int l = 1, r = n+1;
  while(l<r){
  	int m = (l) + (r-l)/2;
  	if(check(m)==0){
  		r = m;
  	}
  	else
  		l = m+1;
  }
  cout<<(l-1)<<endl;
  return 0;
}
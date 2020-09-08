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

int n,k;
vector<int> a,b;

bool check(int x){
//	cout<<x<<endl;
	for(int i=0;i+x<n;i++){
		if(a[i+x]-a[i]<=k) return 1;
	}
	if(a[x-1]<=k) return 1;
	return 0;
}

int main(){
  fio();
  cin>>n>>k;
  a.resize(n), b.resize(n);
  forn(i,n){
  	int x; cin>>x;
  	b[i] = x;
  	a[i] = (i>=1?a[i-1]:0) + (x==0);
  }
  int l = 1, r = n+1;
 // cout<<check(1)<<endl;
  while(l<r){
  	int m = (l) + (r-l)/2;
  	if(check(m)==0){
  		r = m;
  	}
  	else
  		l = m+1;
  }
  cout<<(l-1)<<endl;
  int x = l-1;
  for(int i=0;i+x<n;i++){
		if(a[i+x]-a[i]<=k){
		 	forn(j,n){
		 		if(j>i && j<=i+x){
		 			cout<<1<<" ";
		 		}
		 		else cout<<b[j]<<" ";
		 	}
		 	cout<<endl;
		 	return 0;
		 }
  }
  if(a[x-1]<=k){
		 	forn(j,n){
		 		if(j<=x-1){
		 			cout<<1<<" ";
		 		}
		 		else cout<<b[j]<<" ";
		 	}
		 	cout<<endl;
		 	return 0;
  }
  return 0;
}
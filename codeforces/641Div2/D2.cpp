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

void solve(){
	LL n,k; cin>>n>>k;
	int b = 0;
	vector <LL> v(n);
	forn(i,n) {
		LL x; cin>>x;
		v[i] = (x==k);
	}
	if(n==1){
		if(v[0]==1){
			cout<<"yes"<<endl;
			return;
		}
		else{
			cout<<"no"<<endl;
			return;
		}

	}
	for1(i,n-1){
		v[i]+=v[i-1];
	}
	
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  } 
  return 0;
}
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
  	int n; cin>>n;
  	vector<LL> v(n), kk;
  	LL su = 0;
  	forn(i,n){
  		cin>>v[i];
  		if(i%2==0) su+=v[i];
  		else kk.pb(v[i]-v[i-1]);
  	}
  	// cout<<su<<" -- "<<endl;
  	// for(auto i:kk) cout<<i<<" ";
  	// cout<<endl;
  	LL ann = 0;
  	LL csum = 0;
  	for(auto i:kk){
  		csum = max(csum + i, i);
  		ann = max(ann, csum);
  	}
  	kk.clear();
  	for1(i,n-2)
  		if(i%2==1) kk.pb(v[i]-v[i+1]);
  	csum = 0;
  	for(auto i:kk){
  		csum = max(csum + i, i);
  		ann = max(ann, csum);
  	}
  	cout<<ann+su<<endl;
  }
  return 0;
}
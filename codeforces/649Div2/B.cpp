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
  	vector<int> an;
  	vector<int> v;
  	forn(i,n){
  		int x; cin>>x;
  		v.pb(x);
  	//	if(i==0 || i==n-1) an.pb(x);
  	//	else if()
  	}
  	forn(i,n){
  		if(i==0 || i==n-1) an.pb(v[i]);
  		else if( (v[i]>v[i-1] && v[i]>v[i+1]) || v[i]<v[i-1] && v[i]<v[i+1])
  			an.pb(v[i]);
  	}
  	cout<<an.size()<<endl;
  	for(auto i:an) cout<<i<<" ";
  	cout<<endl; 
  }
  return 0;
}
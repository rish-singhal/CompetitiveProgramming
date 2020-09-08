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
  	LL dp[3] = {0,0,0};
  	vector<int> vv;
  	for1(i,n){
  		LL x; cin>>x;
  		if(x!=i){
  			if(vv.empty() || vv.back()==1 ) vv.pb(0);
  		}
  		else{
  			if(vv.empty() || vv.back()==0) vv.pb(1);
  		}
  	}
  	if( (int)vv.size() == 1){
  		if(vv[0]==0) cout<<1<<endl;
  		else cout<<0<<endl;
  	}
  	else if(vv.size()==2){
  		cout<<1<<endl;
  	}
  	else if(vv.size()==3){
  		if(vv[0]==1){
  			cout<<1<<endl;
  		}
  		else cout<<2<<endl;
  	}
  	else{
  		cout<<2<<endl;
  	}
  }
  return 0;
}
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
  LL n; cin>>n;
  LL x = 1;
  LL s = 1;
  string sz = "codeforces";
  while(s<=n){
  	forn(i,10){
  		s*=x;
  	}
  	x++;
  }
  x-=2;
  //cout<<x<<endl;
  forn(i,10){
  	LL ss = 1;
  	vector<LL> v;
  	forn(j,i){
  		ss*=x+1;
  		v.pb(x+1);
  	}
  	forn(j,10-i){
  		ss*=x;
  		v.pb(x);
  	}
  	if(ss>=n){
  		forn(i,10){
  			forn(j,v[i]){
  				cout<<sz[i];
  			}
  		}	
  		cout<<endl;	
  		return 0;
  	}
  }
  return 0;
}
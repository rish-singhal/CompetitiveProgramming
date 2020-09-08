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

LL gcd(LL a, LL b){
	return a==0?b:gcd(b%a, b);
}

LL lcm(LL a, LL b){
	return (a*b)/gcd(a,b);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL n; cin>>n;
  	// if(n&1){
  		LL an = 1e17;
  		LL pp = -1;
  		LL pk = n;
  		for(LL p = 2; p * p <= n; p++){
  			if((pk%p) == 0){
  				LL z = n/p;
  			    LL lc = z*(p-1);
  			    if(an > lc){
  			    	an = lc;
  			    	pp = n/p;
  			    }
  			}
  		}
  		if(pp==-1){
  			cout<<(n-1)<<" "<<1<<endl;
  		}
  		else cout<<pp<<" "<<(n-pp)<<endl;
  	// }	
  	// else{
  	// 	cout<<n/2<<" "<<n/2<<endl;
  	// }
  }
  return 0;
}
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

  for1(k,100){
  	cout<<k<<": ";
  	  LL an = 0;
	  for1(i,k){
	  	for1(j,k){
	  		for1(p,k){
	  			an+=gcd(gcd(i,j),p);
	  		}
	  	}
	  }
	    cout<<an<<endl;
	}

  return 0;
}
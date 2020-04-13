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
  LL a,b; cin>>a>>b;
  LL k=1e18, v =1e18;
  if(b>a) swap(a,b);
  LL z = abs(a-b);
  for(LL j = 2;j*j<=z;j++){
  	if(z%j==0){
  		//cout<<j<<endl;
		LL kk = (j-b%j)%j;
		LL lc = (a+kk)*(b+kk)/j;
		if(lc<=v && a%j==b%j){
			k = (lc<v)?kk:min(k,kk);
			v = lc;
		}
		j = (z/j);
		//cout<<j<<endl;
		kk = (j-b%j)%j;
		lc = (a+kk)*(b+kk)/j;
		if(lc<=v && a%j==b%j){
			k = (lc<v)?kk:min(k,kk);
			v = lc;
		}	
  	}
  }
  if(z>1){LL j = z;
  LL kk = (j-b%j)%j;
		LL lc = (a+kk)*(b+kk)/j;
		if(lc<=v && a%j==b%j){
			k = (lc<v)?kk:min(k,kk);
			v = lc; 
		}
	}
  cout<<k<<endl;
  //cout<<v<<endl;
  return 0;
}
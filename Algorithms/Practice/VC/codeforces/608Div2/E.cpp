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

LL n,k; 

LL f(LL a){
	LL b = 0;
	LL an = 0;
	while(a<=n){
		an += min(n+1, a + (1LL<<b)) - a;
		a*=2;
		b++;
	}
	return an;
}

LL chk(LL a){
	LL an = f(a);
	if((a&1)==0) an+=f(a+1);
	return an;
}

int main(){
  fio();
  cin>>n>>k;
  LL an = 0; 
  for(int bit = 59; bit>=0 ;bit--){
  	if(chk(an + (1LL<<bit)) >= k){
  		an+=(1LL<<bit);
  	}
  }
  cout<<an<<endl;
   return 0;
}
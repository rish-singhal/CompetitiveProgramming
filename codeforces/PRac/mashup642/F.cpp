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

LL phi(LL a){
	LL an = a;
	LL z = a;
	for(LL x =2; x*x<=a;x++)
	{
		if(z%x==0){
			while(z%x==0) z/=x;
			an = an - (an/x);
		}
	}
	if(z!=1){
		an = an - (an/z);
	}
	return an;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--)
  {
  	LL a,m; cin>>a>>m;
  	LL x = gcd(a,m);
  	cout<<phi(m/x)<<endl;
  }
  return 0;
}
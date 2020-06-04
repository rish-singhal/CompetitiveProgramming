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
  	LL x1, y1, x2, y2;
  	cin>>x1>>y1>>x2>>y2;
  	LL a = (x2-x1);
  	LL b = (y2-y1);
  	if(b<a) swap(a,b);
  	b--;
  	LL an = (a*(a+1))/2;
  	//cout<<(an+1)<<endl;
  	LL z = min(a,b);
  	an+= ((z-1)*(z))/2 +  (b>=(z-1)?(b-(z-1))*z:0);
  	cout<<(an+1)<<endl;
  } 	
  return 0;
}
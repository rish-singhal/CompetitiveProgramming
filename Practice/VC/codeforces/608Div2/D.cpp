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

LL k,n; 

LL cnt = 0;
LL chk(LL a){
	if(a>n) return 0;
	return 1 + ((a&1)==0?chk(a+1):0) + chk(a);
}

int main(){
  fio();
  cin>>n>>k;
  LL l = 2, r = n;
  cout<<chk(5)<<endl;
  while(l<r){
  	LL m = l + (r-l)/2;
  	cnt = 0;
  	if(chk(m)<k) r = m;
  	else l = m + 1;
  }
  cout<<(l-1)<<endl;
  return 0;
}
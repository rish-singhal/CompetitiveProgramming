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

// for F F F F T T T T " finding first T "
int fun(){
  int L = 0, R = n;
  while(L<R){
  	int m = L + (R-L)/2;
  	if(prop(m))
  		R  = m;
  	else
  		L = m + 1;
  }
  return L;
}

int main(){
  fio();
  


  return 0;
}

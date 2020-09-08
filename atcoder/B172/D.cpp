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
  LL n,m,k; cin>>n>>m>>k;
  vector<LL> a(n),b(m);
  forn(i,n){
  	cin>>a[i];
  	if(i>=1) a[i]+=a[i-1];
  }
  forn(i,m){
  	cin>>b[i];
  	if(i>=1) b[i]+=b[i-1];
  }
  LL an = 0;
  forn(i,n){
  	LL cnt = 0;
  	if(a[i]<=k){
  		cnt = i+1;
  		cnt += upper_bound(all(b), k - a[i]) - b.begin();
  		an = max(an, cnt);
  	}
  	else break;
  }
  forn(i,m){
  	LL cnt = 0;
  	if(b[i]<=k){
  		cnt = i+1;
  		cnt += upper_bound(all(a), k - b[i]) - a.begin();
  		an = max(an, cnt);
  	}
  	else break;
  }
  cout<<an<<endl;
  return 0;
}
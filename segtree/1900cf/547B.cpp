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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int st[MAXN], x = 0;

int main(){
  fio();
  int n; cin>>n;
  vector<int> a(n), r(n), l(n);
  vector<int> an(n+1);
  forn(i,n) cin>>a[i];
  forn(i,n){
  	if(x){
  		while(a[st[x]]>=a[i] && x>0) x--;
  		if(x) l[i] = st[x];
  		else l[i] = -1;
  		st[++x] = i;
  	}
  	else {
  		l[i] = -1;
  		st[++x] = i;
  	}
  }
  int x = 0;
  for(int i=n-1;i>=0;i--){
  	if(x){
  		while(a[st[x]]>=a[i] && x>0) x--;
  		if(x) r[i] = st[x];
  		else r[i] = n;
  		st[++x] = i;
  	}
  	else {
  		r[i] = n;
  		st[++x] = i;
  	}
  	an[r[i]-l[i]-1] = max(an[r[i]-l[i]-1], a[i]);
  }
  for(int i=n-1;i>=0;i--) an[i] = max(an[i], an[i+1]);
  for1(i,n) cout<<an[i]<<" ";
  cout<<endl;
  return 0;
}
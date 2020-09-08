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
  int n,m; cin>>n>>m;
  vector<string> v(n);
  forn(i,n) cin>>v[i];
  vector<LL> c(m);
  LL an = 0;
  for(int i=n-1;i>=0;i--){
  	forn(j,m) if(v[i][j]=='1') c[j]++; else c[j] = 0;
  	for(LL j=0, last=0;j<m;j++)
  		an += last = min(last+1, c[j]);
  }
  cout<<an<<endl;
  return 0;
}
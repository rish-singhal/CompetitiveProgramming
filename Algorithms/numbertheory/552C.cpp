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
  LL w,m; cin>>w>>m;
  vector <LL> v;
  for(LL k=1;k<=m*w;k*=w) v.pb(k);
  reverse(v.begin(),v.end());
  for(auto i:v) m = min(m,abs(m-i));
  cout<<(m?"NO":"YES")<<endl;
  return 0;
}
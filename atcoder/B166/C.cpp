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



int chk[MAXN];

int main(){
  fio();
  int n,m; cin>>n>>m;
  vector<int> h(n+1);
  for1(i,n){
   cin>>h[i];
  	chk[i] = 1;
  }
  forn(i,m){
  	int u, v; cin>>u>>v;
  	chk[u] &= (h[v]<h[u]);
  	chk[v] &= (h[u]<h[v]);
  }
  int c = 0;
  for1(i,n) c+=chk[i];
  cout<<c<<endl;
  return 0;
}
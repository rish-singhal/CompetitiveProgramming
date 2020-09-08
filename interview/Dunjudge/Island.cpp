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
const int MAXN = 2e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,m;
vector<int> di(MAXN);
vector<int> an(MAXN);

int main(){
  fio();
  cin>>n>>m;
  forn(i,n+m-1){
  	int u,v; cin>>u>>v;
  	di[u]++;
  	di[v]++;
  }
  for1(i,n+m)
  	an[di[i]-1]++;
  for(int i = MAXN-2; i>=0; i--){
  	an[i]+=an[i+1];
  }
  cout<<1<<" "<<1<<endl;
  for1(i,MAXN)
  	if(an[i]>0 && i!=1) cout<<i<<" "<<an[i]<<endl;
  return 0;
}
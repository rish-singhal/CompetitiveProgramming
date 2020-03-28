#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
const int MAXN = 1e7 +5;
int n,m; 
int dsu[MAXN];
int sz[MAXN];
int mm[MAXN];
int an[MAXN];

int par(int i){
  return dsu[i]<0?i:dsu[i] = par(dsu[i]);
}

void merge(int u,int v){
  u = par(u), v= par(v);
//  cout<<u<<" " <<v<<endl;
  if(u==v) return;
  int k = v;
  if(sz[u] > sz[v]) swap(u,v);
  sz[v]+=sz[u];
  dsu[u] = v;
  an[v] = k;
}

int main(){
  scanf("%d%d",&n,&m);
  for1(i,n) sz[i] = 1, dsu[i] = -1;
  forn(i,m){
    int x; cin>>x;
    x = an[par(x)]; 
    printf("%d\n",x);
    int z = (x-2+n)%n + 1;
    merge(x,z);
  }
  return 0;
}


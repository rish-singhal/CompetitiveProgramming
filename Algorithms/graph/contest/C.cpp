#include<bits/stdc++.h>
using namespace std;
#define for1(i,n) for(int i=1;i<=n;i++)
const int MAXN = 2e5 +5;

int n,m, dsu[MAXN];
int par(int i){
  return dsu[i]<0?i:dsu[i] = par(dsu[i]);
}

void merge(int u,int v){
  u = par(u), v= par(v);
  if(u==v) return;
  if(u > v) swap(u,v);
  dsu[u] = v;
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin>>n>>m;
  memset(dsu,-1,sizeof dsu);
  for(int i=0;i<m;i++){
    int u,v; cin>>u>>v;
    merge(u,v);
  } 
  int an =0;
  for1(i,n-1){
    int x = par(i), y=par(i+1);
    if(x==i || x == y) continue;
    if(x!=y){
      an++; merge(i,i+1); }
  }
  cout<<an<<"\n";
  return 0;
}


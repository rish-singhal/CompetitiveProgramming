#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


int main(){
  fio();
  int n; cin>>n;
  vector <int> deg(n+1);
  forn(i,0,n-1){
    int u,b; cin>>u>>b;
    deg[u]++;
    deg[b]++;
  }
  bool x = 1;
  forn(i,1,n+1){
    x &= deg[i]!=2;;
  }
  cout<<(x?"YES\n":"NO\n");
  return 0;
}


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
  int t; cin>>t;
  while(t--){
    int n,x; cin>>n>>x;
    vector <int> v(310);
    forn(i,n){
      int k; cin>>k;
      v[k] = 1;
    }
    int z =0;
    for(int i=1;i<=300;i++){
      if(v[i]) continue;
      v[i] = 1;
      x--;
      if(x==0){
        z=1;
        break;
      }
    }
    for(int i=1;i<=305;i++){
      if(!v[i]){
        cout<<(max(i-1)<<endl;
        break;
      }
    }

  }
  return 0;
}


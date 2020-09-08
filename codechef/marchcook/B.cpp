#include <bits/stdc++.h>
using namespace std;
#define forn(i,n)  for(int i=0;i<n;i++)
typedef long long LL;
int n, h;
LL lt[200015][2], d[100005][2];

void lapply(int p, LL v, int x){
  lt[p][x] += (LL)v;
  if(p<n) d[p][x] += (LL)v;
}

void lbuild(int p, int x){
  while(p > 1){
          p >>= 1;
          lt[p][x] = max(lt[p<<1][x], lt[p<<1|1][x]);
          lt[p][x] += d[p][x];
  }
}

void lpush(int p, int x) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i][x] != 0) {
      lapply(i<<1, d[i][x],x);
      lapply(i<<1|1, d[i][x],x);
      d[i][x] = 0;
    }
  }
}

void linc(int l, int r, LL value, int x) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      lapply(l++, value,x);
    }
    if (r&1) lapply(--r, value,x);
  }
  lbuild(l0,x);
  lbuild(r0 - 1,x);
}

auto lquery(int l, int r,int x) -> LL{
  if(l<0 || r>n) return 0LL;
  l += n, r += n;
  lpush(l, x);
  lpush(r - 1, x);
  LL res = -1e17;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, lt[l++][x]);
    if (r&1) res = max(lt[--r][x], res);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin>>t;
  while(t--){
    int q;
    cin>>n>>q;
    h = 32 - __builtin_clz(n);
    forn(i,2*n+5){
      forn(j,2) d[i][j] = lt[i][j] = 0;
    }
    vector <int> v(n);
    forn(i,n){
      cin>>v[i];
    }
    lt[n][0] = v[0];
    for(int i =1; i<n;i++){
      lt[i+n][0] += lt[i+n-1][0] + 1LL*v[i];
    }
    lt[n+n-1][1] = v[n-1];
    for(int i=n-2;i>=0;i--){
      lt[i+n][1] += lt[i+n+1][1] + 1LL*v[i];
    }
    for(int i=n-1;i>0;i--)
    {
      lt[i][0] = max(lt[i<<1][0], lt[i<<1|1][0]);
      lt[i][1] = max(lt[i<<1][1], lt[i<<1|1][1]);
    }
    // for(int j=0;j<2;j++){
    //   cout<<(j+1)<<" :";
    // for(int i=1;i<2*n;i++)
    //   cout<<lt[i][j]<<" ";
    //   cout<<endl;
    //
    // }
    while(q--){
      string s; cin>>s;
      if(s=="U"){
        int x, v; cin>>x>>v;
        x--;
        LL vv = lquery(x,x+1,0) - lquery(x-1,x,0);
      //  cout<<vv<<" "<<" -- "<<endl;
        linc(x, n, v - vv, 0);
        linc(0, x+1, v - vv, 1);
      // cout<<"after update"<<endl;
        //for(int i= 0;i<n;i++){
         //cout<<(lquery(i,i+1,0) - lquery(i-1,i,0))<<" ";
       //}
       //cout<<endl;
      }
      else{
        int l,r; cin>>l>>r;
        LL an = 0;
         an += max(0LL, lquery(0,l-1,1) - lquery(l-1,l,1));
        an += max(0LL, lquery(r,n,0) - lquery(r-1,r,0));
        an += lquery(r-1,r,0) - lquery(l-2,l-1,0);
      //  cout<<a<<" "<<b<<" "<<su<<endl;
        cout<<an<<endl;
      }
    }

  }
  return 0;
}

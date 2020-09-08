#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
typedef long long LL;
const int ni = -1;
#define fi first
#define se second
int n,h;
pair <int,int> t[1<<20] , lt[1<<20];
int d[1<<19];

auto combine(pair<int,int> a, pair<int,int> b) -> pair<int,int> {
  if(a.se == -1) return b;
  return a.fi > b.fi? a:b;
}

void up(int i){
  t[n+i] = {ni,i};
  int p = n+i;
  for(; p>1 ; p>>=1)
    t[p>>1] = combine(t[p], t[p^1]);
}

auto qu(int l, int r) -> pair<int,int> {
  pair<int,int> an = {ni, ni};
  for(l+=n, r+=n; l<r; l>>=1, r>>=1)
  {
    if(l&1) an = combine(an,t[l++]);
    if(r&1) an = combine(an,t[--r]);
  }
  return an;
}

// lazy seg tree
void lapply(int p, int v){
  lt[p].fi += v;
  if(p<n) d[p] += v;
}
auto lcombine(pair<int,int> &a, pair<int,int> &b) -> pair<int,int> {
    if(a.se == -1) return b;
    if(a.fi < b.fi) return a;
    if(b.fi < a.fi) return b;
    return a.se < b.se? a:b;
}

void lbuild(int p){
  while(p > 1){
          p >>= 1;
          lt[p] = lcombine(lt[p<<1], lt[p<<1|1]);
          lt[p].fi += d[p];
  }
}

void lpush(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      lapply(i<<1, d[i]);
      lapply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void linc(int l, int r, int value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      lapply(l++, value);
    }
    if (r&1) lapply(--r, value);
  }
  lbuild(l0);
  lbuild(r0 - 1);
}

void lquery(int l, int r) -> int{
  l += n, r += n;
  lpush(l);
  lpush(r - 1);
  pair<int,int> res = {-1e9,-1};
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = lcombine(res, lt[l++]);
    if (r&1) res = lcombine(lt[--r], res);
  }
  return res.se;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  h = 32 - __builtin_clz(n);
  forn(i,n) {
    cin>>t[n+i].fi;
    t[n+i].se = lt[n+i].se = i;
  }
  for(int i=n-1;i>0;i--)
    {
      t[i] = combine(t[i<<1], t[i<<1|1]);
      lt[i] = lcombine(lt[i<<1], lt[i<<1|1]);
    }

  cout<<qu(0,n).fi<<" ";
  int bo;
  for(int i=0;i<n-1;i++){
    cin>>bo;
    bo--;
    linc(bo, n, -1);
    int bp = lquery(0,n);
    auto qur = qu(0,bp+1);
    up(qur.se);
    linc(qur.se,n, 1);
    cout<<qu(0, n).fi<<" ";
  }
  cin>>bo;
  cout<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
const LL N = 200005;
const int lgn = 20;
const LL inf = 1e17;

struct node{
  LL best;
  LL mn[lgn];
  node(LL pos =inf){
    best = inf;
    forn(i,lgn)
      mn[i] = pos;
  }
};

inline node combine(const node &a, const node &b){
  node z;
  forn(i,lgn)
    z.best = min(z.best, min(min(a.best,b.best),a.mn[i]+b.mn[i]));
  forn(i,lgn)
    z.mn[i] = min(a.mn[i],b.mn[i]);
  return z;
}

node t[3*N];
int n;

void build(){
  for(int i=n-1;i>=1;i--) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void up(int p, int v){
  LL kk = v;
  p+=n;
  int i=0;
  forn(i,lgn) t[p].mn[i] = inf;
  while(v){
       int a = v%10;
       if(a) t[p].mn[i] = kk;
       i++;
       v=v/10;
     }
  for(;p>1;p>>=1){
      t[p>>1] = combine(t[p], t[p^1]);
  }
}

LL qu(LL l, LL r){
  node an;
  int f = 1;
  for(l+=n,r+=n+1;l<r;l>>=1,r>>=1)
  {
    if(l&1){
      if(f){
        an = t[l++];
        f=0;
      }
      else an = combine(an,t[l++]);
    }
    if(r&1){
      if(f){
        an = t[--r];
        f=0;
      }
      else an = combine(an,t[--r]);
  }
  }

  return f?-1:an.best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int m; cin>>n>>m;
    forn(i,n){
       LL zz; cin>>zz;
       LL kk = zz;
       int j=0;
       while(zz){
         int a = zz%10;
         if(a) t[i+n].mn[j] = kk;
         zz=zz/10;
         j++;
       }
    }
    build();
//    cout<<t[3].best<<endl;
/*    forn(i,lgn)
      cout<<t[n+2].mn[i]<<" ";
    cout<<endl;
   */ for(int i=0;i<m;i++){
      int x; cin>>x;
      if(x==2){
      int l,r; cin>>l>>r;
      l--,r--;
      LL an = qu(l,r);
      cout<<(an==inf?-1:an)<<endl;
      }
      else {
        int z,pos; cin>>pos>>z;
        pos--;
        up(pos,z);
      }
    }
    return 0;
}


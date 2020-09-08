#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define LL long long
#define fi first
#define se second
int n;
LL d[100005], s[100005], p[100005], h[100005];
struct tr{
  pair<int, int> ppr,npr,psu,nsu;
  int ini = 0;
}t[1<<18];

auto pp(int i) -> LL{
  if(i==-1) return -1e17;
  return 2*h[i] + p[i];
}

auto np(int i) -> LL{
  if(i==-1) return -1e17;
  return 2*h[i] - p[i];
}

auto ps(int i) -> LL{
  if(i==-1) return -1e17;
  return 2*h[i] + s[i];
}

auto ns(int i) -> LL{
  if(i==-1) return -1e17;
  return 2*h[i] - s[i];
}

auto combine(tr u, tr v) -> tr{
  if(u.ini) return v;
  tr an;
  vector <pair<LL,int> > vec(4);

  vec[0] = {pp( u.ppr.fi), u.ppr.fi};
  vec[1] = {pp( u.ppr.se), u.ppr.se};
  vec[2] = {pp( v.ppr.fi), v.ppr.fi};
  vec[3] = {pp( v.ppr.se), v.ppr.se};
  sort(vec.begin(), vec.end());
  an.ppr.fi = vec[3].se;
  for(int i=2;i>=0;i--)
    if(an.ppr.fi!=vec[i].se){ an.ppr.se = vec[i].se; break;}

  vec[0] = {ps( u.psu.fi), u.psu.fi};
  vec[1] = {ps( u.psu.se), u.psu.se};
  vec[2] = {ps( v.psu.fi), v.psu.fi};
  vec[3] = {ps( v.psu.se), v.psu.se};
  sort(vec.begin(), vec.end());
  an.psu.fi = vec[3].se;
  an.psu.se = vec[2].se;

  vec[0] = {np( u.npr.fi), u.npr.fi};
  vec[1] = {np( u.npr.se), u.npr.se};
  vec[2] = {np( v.npr.fi), v.npr.fi};
  vec[3] = {np( v.npr.se), v.npr.se};
  sort(vec.begin(), vec.end());
  an.npr.fi = vec[3].se;
  an.npr.se = vec[2].se;

  vec[0] = {pp( u.nsu.fi), u.nsu.fi};
  vec[1] = {pp( u.nsu.se), u.nsu.se};
  vec[2] = {pp( v.nsu.fi), v.nsu.fi};
  vec[3] = {pp( v.nsu.se), v.nsu.se};
  sort(vec.begin(), vec.end());
  an.nsu.fi = vec[3].se;
  an.nsu.se = vec[2].se;
  return an;
}

auto qu(int l, int r) -> tr{
  tr an;
  an.ppr = an.npr = an.psu = an.nsu = {-1,-1};
  an.ini = 1;
  for(l+=n-1, r+=n; l<r; l>>=1, r>>=1){
    if(l&1)   an = combine(an,t[l++]);
    if(r&1)   an = combine(an,t[--r]);
  }
  return an;
}

auto quan(int l, int r)->LL{
  if(l>r){
    tr ann = qu(r+1,l-1);
    if(ann.ppr.fi != ann.npr.fi){
      return pp(ann.ppr.fi) + np(ann.npr.fi);
    }
    else{
      return max(pp(ann.ppr.fi) + np(ann.npr.se),pp(ann.ppr.se) + np(ann.npr.fi));
    }
  }
  tr lef = qu(1,l-1);
  tr rgt = qu(r+1,n);
  vector <LL> ans;
  if(lef.ppr.fi != lef.npr.fi){
    ans.push_back(pp(lef.ppr.fi) + np(lef.npr.fi));
  }
  else{
    ans.push_back(max(pp(lef.ppr.fi) + np(lef.npr.se),pp(lef.ppr.se) + np(lef.npr.fi)));
  }

  if(rgt.psu.fi != rgt.nsu.fi){
    ans.push_back(ps(rgt.psu.fi) + ns(rgt.nsu.fi));
  }
  else{
    ans.push_back(max(ps(rgt.psu.fi) + ns(rgt.nsu.se),ps(rgt.psu.se) + ns(rgt.nsu.fi)));
  }

  ans.push_back(pp(lef.ppr.fi)+ps(rgt.psu.fi));
  return *max_element(ans.begin(),ans.end());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m; cin>>n>>m;
  forn(i,n) cin>>d[i], t[n+i].ppr = t[n+i].npr = t[n+i].psu = t[n+i].nsu = {i,-1};
  forn(i,n) cin>>h[i];
  s[n-1] = d[n-1];
  p[0] = 0;
  for(int i=n-2; i>=0; i--)
    s[i] += s[i+1] + d[i];
  for(int i=1; i<n; i++)
      p[i] += p[i-1] + d[i-1];
  for(int i=n-1;i>0;i--)
      t[i] = combine(t[i<<1],t[i<<1|1]);
  while(m--){
    int l,r; cin>>l>>r;
    cout<<quan(l,r)<<endl;
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
pair<int,int> t[1<<18];
int n;

auto combine(pair<int,int> &a, pair<int,int> &b) -> pair<int,int> {
  if(a.fi == -1) return b;
  int an = gcd(a.fi, b.fi);
  int cnt = 0;
  if(a.fi==an) cnt+=a.se;
  if(b.fi==an) cnt+=b.se;
  return {an,cnt};
}

auto qu(int l, int r) -> int{
  pair<int,int> an = {-1,0};
  int l0 =l, r0= r;
  for(l+=n-1, r+=n; l<r; l>>=1, r>>=1){
    if(l&1) an = combine(an,t[l++]);
    if(r&1) an = combine(an,t[--r]);
  }
  return r0-l0+1-an.se;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  forn(i,n) {
    cin>>t[n+i].fi;
    t[n+i].se = 1;
  }
  for(int i=n-1;i>0;i--)
    t[i] = combine(t[i<<1], t[i<<1|1]);
  int q; cin>>q;
  while(q--){
    int l,r; cin>>l>>r;
    cout<<qu(l,r)<<endl;
  }
}

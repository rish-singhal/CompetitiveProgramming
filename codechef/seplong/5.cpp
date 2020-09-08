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
LL n;
vector<LL> v;
LL cnt[1000005];
LL st[1000005][32];
vector <LL> lg;
void build(){
  for1(i,n) st[i][0] = v[i];
  for(LL i=2;i<=n;i++) lg[i] = lg[i-1] + !(i&(i-1));
  for(LL j=1; (1<<j)<=n;j++){
    for(LL i =1; (i+(1<<j)-1) <=n; i++)
      st[i][j] = __gcd(st[i][j-1], st[i + (1<<(j-1))][j-1]);
  }
}

LL qu(LL l,LL r){
  LL k = lg[r-l+1];
  return __gcd(st[l][k], st[r-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    v.resize(n+1);
    lg.resize(n+1);
    LL lgn = ceil(log2(n)) + 2;
    for1(i,n) cin>>v[i];
    build();
    for(int i=1;i<=n;i++){
      for(int j=i;j<=n;){
        LL v = qu(i,j);
        LL val = 0;
        for(LL k = lgn;k>=0;k--){
          if(j+(1<<k)-1>n) continue;
          if(qu(i,j+(1<<k)-1)==v)
          {  val+=(1<<k);  
            j+=(1<<k);
          }
        }
//      cout<<i<<" "<<j<<" :"<<val<<endl;
      if(v<1000005)
        cnt[v]+=val;
      }
    }
//    cout<<cnt[8]<<" "<<cnt[4]<<" "<<cnt[2]<<" "<<cnt[1]<<endl;
    int q; cin>>q;
    while(q--){
      LL g; cin>>g;
      LL an =0;
      for(int i=1;i*i<=g;i++){
          if(g%i==0){
            an += cnt[g/i] + cnt[i];
            if(i*i==g) an-=cnt[i];
          }
      }
      cout<<an<<endl;
    }
    return 0;
}


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
    LL a,b; cin>>a>>b;
    LL kk = min(__builtin_clzll(a), __builtin_clzll(b));
    kk = 63 - kk;
    LL an = 0;
    LL ma = a^b;
    for(int i=1;i<=kk;i++){
        b = (b>>1)|((b&1)<<kk);
        if((a^b) > ma){
          ma = a^b, an = i;
        }
//        cout<<i<<" "<<b<<endl;
    }
    cout<<an<<" "<<ma<<endl;
  }
  return 0;
}


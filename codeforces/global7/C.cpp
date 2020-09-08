#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
typedef long long LL;
#define all(v) v.begin(), v.end()


auto nxt() -> LL{
  LL x; cin>>x;
  return x;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  LL n = nxt(), k = nxt();
  vector<LL> v(n);
  generate(all(v),nxt);
  LL an = 0;
  for(int i = 0;i<k;i++)
    an += n - i;
  LL ib = -1;
  LL an2 = 1;
  for(int i=0;i<n;i++){
    if(v[i]>= n-(k-1)){
        an2 = an2*(ib==-1?1LL:(i-ib))%998244353;
        ib = i;
    }
  }
  cout<<an<<" "<<an2<<endl;
}

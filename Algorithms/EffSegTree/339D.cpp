#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,p,b,q; cin>>n>>q;
  int t[1<<(n+1)];

  for(int i=0;i<(1<<n);i++) cin>>t[(1<<n)+i];

  for(int i=(1<<n)-1;i>0;i--)
    if((n  - (32 -__builtin_clz(i)))&1)
      t[i] = t[i<<1]^t[i<<1|1];
    else t[i] = t[i<<1]|t[i<<1|1];

  while(q--){
    cin>>p>>b;
    p += (1<<n) - 1;
    for(t[p] = b; p>1; p>>=1)
      if((n  - (32 -__builtin_clz(p)))&1)
         t[p>>1] = t[p]|t[p^1];
      else  t[p>>1] = t[p]^t[p^1];
    cout<<t[1]<<endl;
  }
  return 0;
}

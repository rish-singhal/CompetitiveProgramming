#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL m = 998244353;
LL dp[3005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  LL n,s; cin>>n>>s;
  vector <LL> v(n+1);
  LL an = 0;
  for(int i=1;i<=n;i++){
    LL a; cin>>a;
    if(s>a) (an += dp[s-a]*(n-i+1) )%=m;
    if(s==a) (an+=i*(n-i+1))%=m;
    for(int su = s; su>=0; su--)
      if(su>=a) (dp[su]+=dp[su-a])%=m;
    (dp[a]+=i)%=m;
  }
  cout<<an<<endl;
  return 0;
}

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
  int n; cin>>n;
  vector<LL> v(n);
  generate(all(v),nxt);
  LL x = 0;
  for(int i=0;i<n;i++){
    cout<<(v[i]+x)<<" ";
    x = max(x,v[i]+x);
  }
  cout<<endl;
}

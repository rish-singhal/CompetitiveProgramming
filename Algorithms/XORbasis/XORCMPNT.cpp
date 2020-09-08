#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

auto sizeofset(vector <LL> &v) -> int{
    LL basis[31] = {0};
    int sz = 0;
    for(auto msk:v){
      while(msk){
        int p = __builtin_ctzll(msk);
        if(!basis[p]){
          basis[p] = msk;
          sz++;
          break;
        }
        msk^=basis[p];
      }
    }
    return sz;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
      int k,m; cin>>k>>m;
      vector <LL> v(m);
      for(auto &i:v) cin>>i;
      cout<<(1LL<<(k-sizeofset(v)))<<endl;
    }
    return 0;
}

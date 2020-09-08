#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL m = 1e9+7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,q; cin>>n>>q;
  LL po2[n+1];
  po2[0] = 1;
  for(int i=1;i<=n;i++)
    po2[i] = 2*po2[i-1] %m;
  vector <vector<LL> > basis(n+1);
  basis[0] = {};
  for(int i=0;i<n;i++){
    LL k; cin>>k;
    auto &v = basis[i+1] = basis[i];
    for(auto &e:v) k = min(k,k^e);
    if(k) v.push_back(k);
  }
  while(q--){
    int l; LL x; cin>>l>>x;
    for(auto e:basis[l]) x = min(x,x^e);
    cout<<(x?0:(po2[l-basis[l].size()]))<<endl;
  }
}

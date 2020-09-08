#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin>>n;
  LL b = 0;
  vector<LL> basis = {};
  for(int i=0;i<n;i++){
    LL k; cin>>k;
    b^=k;
    for(auto &e: basis) k = min(k,k^e);
    if(k) basis.push_back(k);
  }
  if(!b) cout<<-1<<endl;
  else cout<<basis.size()<<endl;
}

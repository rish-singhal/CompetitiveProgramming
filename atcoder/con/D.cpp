#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  LL n; cin>>n;
  vector <LL> cnt(n+1);
  vector<LL> v(n);
  LL an = 0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    cnt[v[i]]++;
  }
  for(auto i:cnt){
    an += i*(i-1)/2;
  }
  for(int i=0;i<n;i++){
    if(cnt[v[i]]>1){
      LL kk = an - (cnt[v[i]])*(cnt[v[i]] - 1)/2 + (cnt[v[i]]-1)*(cnt[v[i]]-2)/2;
      cout<<kk<<" ";
      }
    else
      cout<<an<<" ";
    }
    cout<<endl;
    return 0;
  }

#include<bits/stdc++.h>
using namespace std;

int basis[32];
int sz = 0;

auto ins(int a) -> void{
  while(a){
    int p = 31 - __builtin_clz(a);
    if(!basis[p]){
      basis[p] = a;
      sz++;
      return;
    }
    a ^= basis[p];
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin>>n;
  while(n--){
    int p,k; cin>>p>>k;
    if(p==1) ins(k);
    else{
      k--;
      int j = sz-1;
      int an = 0;
      for(int i = 29; i>=0; i--){
        if(!basis[i]) continue;
        if((an>>i&1)^(k>>j&1)) an^=basis[i];
        j--;
      }
      cout<<an<<endl;
    }
  }
  return 0;
}

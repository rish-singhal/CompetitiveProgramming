#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s; cin>>s;
  LL n = s.size();
  LL l = 0, r = ((n-1)/2) - 1;
  int b = 1;
  while(l<r){
    if(s[l]!=s[r]){
      b =0;
      break;
    }
    l++, r--;
  }
  l = ((n+3)/2) -1, r = (n) - 1;
  while(l<r){
    if(s[l]!=s[r]){
      b =0;
      break;
    }
    l++, r--;
  }
  l = 0, r = (n) - 1;
  while(l<r){
    if(s[l]!=s[r]){
      b =0;
      break;
    }
    l++, r--;
  }
  cout<<(b?"Yes":"No")<<endl;
  return 0;
}

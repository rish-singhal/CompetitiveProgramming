#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    for(int i = 0; i < n;  i++){
      int x,y; cin>>x>>y;
    }
    LL an = n;
    while(n){
      n = n/2;
      if(n >= 3) an+=n;
      else break;
    }
    cout<<an<<endl;
  }
 return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
  int x; cin>>x;
  cout<<bitset<32>(x-1)<<endl;
  cout<<bitset<32>(~(x-1))<<endl;

  cout<<bitset<32>(~(x-1) & x)<<endl;
  return 0;
}

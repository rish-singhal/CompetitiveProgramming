#include<bits/stdc++.h>
using namespace std;

int main(){
  int x, align; cin>>x>>align;
  cout<<bitset<32>(x)<<endl;
  cout<<bitset<32>(align)<<endl;
  cout<<"-------"<<endl;
  cout<<bitset<32>((x + align - 1))<<endl; 
  cout<<bitset<32>((x + align - 1) & ~(align - 1))<<endl;
  return 0;
}

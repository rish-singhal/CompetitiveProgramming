#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void quicksort(int l, int r){
  if(l >= r) return;
  int piv = v[r];
  int lp = l;
  for(int i = l; i <= r; i++){
    if(v[i] > piv){
        continue;
    }
    else{
      swap(v[lp], v[i]);
      lp++;
    }
  }
  quicksort(l, lp - 2);
  quicksort(lp, r);
}

int main(){
  int n ;cin>>n;
  v.resize(n);
  for(int i=0;i<n;i++) cin>>v[i];
  quicksort(0,n-1);
  for(auto i: v) cout<<i<<" ";
  cout<<endl;
  return 0;
}

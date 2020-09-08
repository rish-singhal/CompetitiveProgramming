#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  LL n,m; cin>>n>>m;
  LL an = (m*(m-1)/2) + (n*(n-1)/2);
  cout<<an<<endl;
  return 0;
}

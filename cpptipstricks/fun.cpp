#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

int nxt(){
  int x; cin>>x;
  return x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n = nxt();
  vector <int> v(n);
  generate(all(v), nxt);
  cout<<(*max_element(all(v)))<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
typedef long long LL;

auto nxt() -> LL{
  LL x; cin>>x;
  return x;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    if(n==1) cout<<-1<<endl;
    else{
      if((n-1)%3!=0){forn(i,n-1) cout<<2;
      cout<<3<<endl;}
      else{
        cout<<3;
        forn(i,n-2) cout<<2;
        cout<<3<<endl;
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
#define forn(i,n)  for(int i=0;i<n;i++)
typedef long long LL;
const LL m = 1e9 +7;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin>>t;
  while(t--){
    int h; cin>>h;
    cout<<1<<" "<<5<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    if(x==-1){
       return 0;
    }
    cout<<2<<" "<<5<<" "<<x<<endl;
    fflush(stdout);
    cin>>x;
    if(x==-1){
       return 0;
    }
    int an = x;
    cout<<1<<" "<<x<<" "<<endl;
    fflush(stdout);
    cin>>x;
    if(x==-1){
       return 0;
    }
    if(x == 0){
      cout<<3<<" "<<an<<endl;
      fflush(stdout);
    }
    else{
      cout<<2<<" "<<an<<" "<<2<<endl;
      fflush(stdout);
      cin>>x;
      if(x==-1){
         return 0;
      }
      cout<<3<<" "<<x<<endl;
      fflush(stdout);
    }
  }
   return 0;

  }

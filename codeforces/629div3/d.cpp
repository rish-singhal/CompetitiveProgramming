#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)

const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector <int> an(n);
    an[0] = 1;
    int k = 1;
    int bbb = 0;
    vector <int> v(n);
    forn(i,n) cin>>v[i];
    for1(i,n-1){
      if(v[i]==v[i-1]){
        an[i] = k;
      }
      else{
        k^=1;
        bbb =1;
        an[i] = k;
      }
    }
    if(an[0] == an[n-1] && v[0] != v[n-1] ){
      if(v[n-1] == v[n-2]) {
        an[n-1] = 2;
        cout<<2<<endl;
      }
      else{
        int zzz =0;
        for(int i=1;i<n;i++){
          if(zzz){
             an[i]^=1;
             continue;
          }
          if(v[i] == v[i-1] && an[i] == an[i-1]){
              an[i]^=1;
              zzz = 1;
          }
        }
        if(zzz) cout<<2<<endl;
        else {
          an[n-1]= 3;
          cout<<3<<endl;
        }
    }
    }
    else 
      cout<<(bbb?2:1)<<endl;
    for(auto i:an){
      cout<<(i==0?2:i)<<" ";
    }
    cout<<endl;
  }
  return 0;
}


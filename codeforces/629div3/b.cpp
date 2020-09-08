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
    LL n,k; cin>>n>>k;
    LL z = 1;
   // while(k>((z*(z+1))/2)){
    //  z++;
   // }
    LL l = 0, r =1e5 + 5;
    LL an = 0; 
    int cnt = 0;
    int p = -1;
    while(l<r){
      LL mid = (l+r)/2;
      if(p==mid) break;
      p = mid;
      if(k>(mid*(mid+1))/2){
        l = mid;
      }
      else{
        r = mid;
      }
      cnt ++;
    }
    z = l;
    int aa  = k - (z*(z+1)/2);
    int bb = z+2;
//    cout<<aa<<" "<<bb<<endl;
    string s="";
    for(int i=1;i<=n;i++){
      if(i==bb || i==aa) s+="b";
      else s+="a";
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
  }
  return 0;
}


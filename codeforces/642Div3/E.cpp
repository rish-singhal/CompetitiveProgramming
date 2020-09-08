#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int d = 0;
    int an =1e9;
    for(auto i:s) d+=(i=='1');
    for(int i=0;i<k;i++){
      int diff = 0;
      int mm = 0;
      for(int j=i;j<n;j+=k){
        int zz = 0;
        if(s[j]=='1'){
         diff++;
         zz = 1;}
        else {
          diff--;
          zz = -1;
        }
        diff = max(zz,diff);
        mm = max(mm,diff);
      }
      an = min(an, d - mm);
    }
    cout<<an<<endl;
  }
  return 0;
}
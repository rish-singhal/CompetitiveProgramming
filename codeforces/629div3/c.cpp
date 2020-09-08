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
    string s; cin>>s;
    string a="1",b="1"; 
    int z = 0;
    int zz = 0;
    for(auto i:s){
      if(z==0){
        z = 1; continue;
      }
      if (i=='2'){
        if(!zz){
        a+='1';
        b+='1';
        }
        else{
          a+='0';
          b+='2';
        }
      }
      else if (i=='1'){
      if(!zz){
        a+='1';
        b+='0';
        zz = 1;
      }
      else{
        a+='0';
        b+='1';
      }
      }
      else{
        a+='0';
        b+='0';
      }
    }
    cout<<a<<endl<<b<<endl;
  }

      return 0;
}


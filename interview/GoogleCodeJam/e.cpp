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
  int x = 1;
  while(x<=t){
    int n,k; cin>>n>>k;
    cout<<"Case #"<<x<<": ";
    if(k==n+1){
      cout<<"IMPOSSIBLE"<<endl;
    }
    else{
      cout<<"POSSIBLE"<<endl;
      int a = k/n;
      int b = k%n;
      if(b==0){
        vector<int> an(n);
        forn(i,n) an[i] = (a-1+n+i)%n + 1; 
        forn(i,n){
          forn(j,n) cout<<an[(i+j)%n]<<" ";
          cout<<endl;
        }
      }
      else{
        vector<int> an(n);
        forn(i,n) forn(j,n) an[i][j] = a;
         
    }
    x++;
  }
  return 0;
}


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
  int x =1;
  while(x<=t){
    cout<<"Case #"<<x<<": ";
    int n; cin>>n;
    int a[n][n];
    forn(i,n)forn(j,n) cin>>a[i][j];
    int an = 0;
    forn(i,n) an+=a[i][i];
    cout<<an<<" ";
    int c = 0;
    forn(i,n){
      vector<int> v(n+1);
      forn(j,n){
        if(v[a[i][j]]) {c++; break;
        }
        v[a[i][j]] = 1;
      }
    }
    cout<<c<<" " ;
     c = 0;
    forn(i,n){
      vector<int> v(n+1);
      forn(j,n){
        if(v[a[j][i]]) {c++; break;
        }
        v[a[j][i]] = 1;
      }
    }
    cout<<c<<endl;
  x++;
  }
    
  return 0;
}


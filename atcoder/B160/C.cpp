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
  LL k,n; cin>>k>>n;
  vector <LL> v(n);
  forn(i,n) cin>>v[i];
  LL an = 1e18;
  forn(i,n-1){
    an = min(an, k - v[i+1] + v[i]);
  }
  an = min(an, k - (v[0] + k - v[n-1]));
  cout<<an<<endl;
  return 0;
}


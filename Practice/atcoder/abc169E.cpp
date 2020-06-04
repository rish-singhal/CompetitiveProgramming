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
  int n; cin>>n;
  vector<int> a(n), b(n);
  forn(i,n) cin>>a[i]>>b[i];
  sort(all(a));
  sort(all(b));
  if(n&1){
  	cout<<(b[n/2] - a[n/2] + 1)<<endl;
  }
  else{
  	cout<<(b[n/2]+b[(n)/2 - 1] - a[(n)/2] - a[(n)/2 - 1] + 1)<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve3(int n){
  if(n&1){
      cout << (n/2) << " " << (n/2) << " " << 1 << endl;
    }
    else{
      LL k = n/2;
      if(k&1){
        cout << k - 1 << " " << k - 1 << " " << 2 << endl;
      }
      else{
        cout << k << " " << (k/2) << " " << (k/2) << endl;
      }
    }
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	int n, k; cin >> n >> k;
    if(n <= 2*k) {
      forn(i, k){
        if(i < n - k) cout << 2 << " ";
        else cout << 1 << " ";
      }
      cout << endl;
    }
    else{
      forn(i,  k - 3){
        cout << 1 << " "; 
      }
      solve3(n - k + 3);
    }
  }
  return 0;
}
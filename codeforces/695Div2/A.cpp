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
const int MAXN = 5e5 +5;
const LL mm = 1e9 + 7;
// check MAXN

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
  	if(n == 1){
  		cout << 9 << endl;
  		continue;
  	}
  	if(n == 2){
  		cout << 98 << endl;
  		continue;
  	}

  	cout << 989;

  	for(int i = 0; i < (n-3); i++)
  		cout << (i)%10;
  	cout << endl;
  }
  return 0;
}

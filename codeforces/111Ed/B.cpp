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

// a*l + b

int main(){
  fio();
  int t; cin >> t;
  while(t--) {
  	int n, a, b; cin >> n >> a >> b;
  	string s; cin >> s;
  	if (b >= 0) {
  		cout << sz(s)*(a + b) << endl;
  		continue;
  	}
  	int arr[2] = {0, 0};
  	forn(i, sz(s)) {
  		if(i == 0 || s[i - 1] != s[i]) {
  			arr[s[i] - '0']++;
  		}
  	}
  	sort(arr, arr + 2);
  	if(arr[1] == 0) {
		cout << (sz(s)*a + b) << endl;
  	}
  	else 
  		cout << (sz(s)*a + (min(arr[0], arr[1]) + 1)*b ) << endl;
  }
  return 0;
}
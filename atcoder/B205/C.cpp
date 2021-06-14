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

// a^c <= b^c

int main(){
  fio();
  LL a, b, c; cin >> a >> b >> c;
  if((c%2) == 0){
  	a = abs(a);
  	b = abs(b);
  }
  if(a == b){
  	cout << "=" << endl;
  }
  else if(a >= 0 && b >= 0) {
  	cout << (a < b? "<" : ">") << endl;
  }
  else if(a < 0 && b >= 0) {
  	cout << "<" << endl;
  }
  else if(a >= 0 && b < 0) {
	cout << ">" << endl;
  }
  else {
  	cout << (a < b? "<" : ">") << endl;
  }
  return 0;
}
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

int main(){
  fio();
  int n; cin >> n;
  set <int> s;
  forn(i,n){
  	int k; cin >> k;
  	if(k >= 1 && k <= n){
  		s.insert(k);
  	}
  	else {
  		cout << "No" << endl;
  		return 0 ;
  	}
  }
  if(s.size() == n){
  	cout << "Yes" << endl;
  }
  else{
  	cout << "No" << endl;
  }
  return 0;
}
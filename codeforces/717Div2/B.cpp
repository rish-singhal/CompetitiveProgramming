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
  int t;
  cin >> t;
  while(t--){
  	int n;
  	cin >> n;
  	vector <int> v(n);
  	int xo = 0;
  	forn(i, n){
  		cin >> v[i];
  		xo ^= v[i];	
  	}
  	if(!xo){
  		cout << "YES" << "\n";
  		continue;
  	}

  	int p1 = 0, xoo = 0;
  	while(p1 < n){
  		xoo^= v[p1];
  		if(xoo == xo){
  			break;
  		}
  		p1++;
  	}

  	int p2 = n - 1, xooo = 0;
  	while(p2 >= 0){
  		xooo^= v[p2];
  		if(xooo == xo){
  			break;
  		}
  		p2--;
  	}
  	if(p1 < p2){
  		cout << "YES" << "\n";
  	}
  	else{
  		cout << "NO\n";
  	}
  }	
  return 0;
}
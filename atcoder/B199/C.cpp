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
  int n;
  cin >> n;
  string s; cin>>s;
  int q;
  cin >> q;
  int sw = 0;
  while(q--){
  	int t; cin >> t;
  	int a, b; cin >> a >> b;
  	a--, b--;
  	if(t == 2){
  		sw^=1;
  	}
  	else{
  		if(sw){
  			if(a < n){
  				a+= n;
  			}
  			else{
  				a-=n;
  			}
  			if(b < n){
  				b+= n;
  			}
  			else{
  				b-=n;
  			}	
  		}
  		swap(s[a], s[b]);
  	}
  }
  if(sw){
  	for(int i = n; i < 2*n ; i++)
  		cout << s[i];
  	forn(i, n){
  		cout << s[i];
  	}
  	cout << "\n";
  }
  else{
  	for(auto i:s)
  		cout << i;
  	cout << "\n";
  }
  return 0;
}
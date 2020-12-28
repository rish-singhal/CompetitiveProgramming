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
  	int n ; cin>>n;
  	for(int i = 2; i <= 4*n; i ++){
		vector<int> vv;
		vv.pb(i);
		for(int x = 1; x <= 4*n; x++){
			int b = 0;
			for(auto j : vv){
				if(__gcd(j, x) == 1 || j%x ==0 || x%j == 0){
					b = 1;
					break;
				}
			}
			if(!b) vv.pb(x);
		}
		if(sz(vv) >= n){
			for(int i = 0; i < n; i++) cout<<vv[i]<<" ";
			cout<<endl;
		break;
		}
  	}
  }
  return 0;
}
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
  	string s; cin>>s;
  	int n = sz(s);
  	int ans = 0;
  	for(int i = 0; i < n - 1; i ++){
  		int j = i, bb = 0;
  		if(s[i] == s[i + 1])
  		{
  			//cout << " yes " << endl;
  			ans ++;
  			j = i + 1;
  			bb = 1;
  		}
  		if(i + 2 < n && s[i] == s[i + 2])
  		{
  			ans ++;
  			j = i + 2;
  			if( i + 3 < n && s[i + 1] == s[i + 3] && !bb)
  			{
  				ans ++;
  				j = i + 3;
  			}
  		}
  		i = j;
  	}
  	cout << ans << endl;
  }
  return 0;
}

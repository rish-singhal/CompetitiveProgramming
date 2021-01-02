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
  int n; cin>>n; 
  set <string> ss;
  set <string> s2;
  int b = 0;
  string ans;
  forn(i,n){
  	string s; cin>>s;
  	if(s[0] == '!'){
  		s2.insert(s);
  		if(ss.find(s) != ss.end())
  			{
  				b = 1;
  				ans = s;
  			}
  	}
  	else{
  		ss.insert('!' + s);
  		if(s2.find('!' + s) != s2.end())
  			{
  				b = 1;
  				ans = '!' + s;
  	}
  }
}
 	if(b) cout << ans.substr(1, ans.size() - 1) << endl;
 	else cout << "satisfiable" << endl;
  return 0;
}

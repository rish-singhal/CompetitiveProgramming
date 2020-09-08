#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<string> ss[MAXN][26];

int main(){
  fio();
  int n; cin>>n;
  forn(i,n){
  	string s; cin>>s;
  	int c = 0;
  	int z = -1;
  	for(auto j:s){
  		if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u')
  			{
  				c++;
  				z = j-'a';
  			}
  	}
  	ss[c][z].pb(s);
  }
  int cc = 0, rr = 0;
  for(int i=0;i<n;i++){
  	
  }
  return 0;
}
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
const LL m = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[2005][2005], pref[2005][2005];

int main(){
  fio();
  LL s; cin>>s;
  for1(i,s-1){
  	dp[i][0] = 1;
  	if(i>= 3) dp[i][1] = 1;
  	for(int k = 1; k <= (i-3) && k>=0; k++){
  		if(i>=3) dp[i][k+1] = pref[i-3][k];
  	}
    for(int k = 1; k <= i; k++){
  		pref[i][k] = (pref[i-1][k] + dp[i][k])%m;
  	}
  }
  LL su = 0;

  
  if(s <= 2) cout<<0<<endl;
  else{
  	for(int i = 1; i <= (s-3); i++)
  	su = (su + pref[s-3][i])%m;
  	cout<<(su + 1)%m<<endl;
  }
  return 0;
}
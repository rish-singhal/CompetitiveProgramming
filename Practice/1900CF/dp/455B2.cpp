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

int tr[MAXN][26];
int  dp[MAXN][2];

int main(){
  fio();
  int n; cin>>n;
  LL k; cin>>k;
  int sz = 0;
  forn(i,n){
  	string s; cin>>s;
  	int ro = 0;
  	for(auto c:s){
  		int x = c-'a';
  		if(!tr[ro][x])
  			tr[ro][x] = ++sz;
  		ro = tr[ro][x];
  	}
  }

  for(int i = sz; i>=0; i--){
  	int f = 0;
  	dp[i][0] = 0;
  	dp[i][1] = 0;
  	forn(j,26){
  		if(tr[i][j]!=0){
  			f = 1;
  			int k = tr[i][j];
  			dp[i][0] |= (dp[k][0]==0);
  			dp[i][1] |= (dp[k][1]==0);
  		}
  	}
  	if(f==0) dp[i][1] = 1;
  }

  if(dp[0][0] && dp[0][1]) 
  	cout<<"First"<<endl;
  else if(dp[0][0]==0) 
  	cout<<"Second"<<endl;
  else 
 	cout<<((k&1)?"First":"Second")<<endl;
  return 0;
}
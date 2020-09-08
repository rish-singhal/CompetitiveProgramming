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

int main(){
  fio();
  string s;
  while(cin>>s && s!="0"){
  	int sz = s.size();
  	vector<LL> dp(sz+1,0);
  	dp[0] = 1;
  	for1(i,sz)
  		{
  			if(s[i-1]!='0') dp[i] += dp[i-1];
  			if(i>=2)
  			{
  			int vv = (s[i-2] - '0')*10 +  (s[i-1] - '0');
  			if(vv>=10 && vv<=26)
  				dp[i] += dp[i-2];
  			}
  		}
  	cout<<dp[sz]<<endl;
  }
  return 0;
}
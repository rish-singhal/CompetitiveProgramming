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
const int MAXN = 3e6 +5;
const LL m = 1e9+7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) return (an*a)%m;
	return an;
}


LL f[MAXN], fi[MAXN];
LL dp[MAXN];


int main(){
  fio();
  LL k; cin>>k;
  string s; cin>>s;
  vector<LL> v(26);
  for(auto i:s) {
  	v[i-'a']++;
  }

  LL sz = k + s.size();
  dp[0]=1;
  forn(i,26){
  	LL num = s.size() - v[i];
  	num = (num)%m;
  	num = (num+m)%m; 	
  	vector<LL> dp2(k+1,0);
  	for(LL j = 1; j<=k;j++){
  		LL ss = (j - 1 + num)%m;
  		ss+=1;
  		ss = (ss+m)%m;
  		//dp2[j] = (dp[j-1]*(ss))%m;
  		dp2[j] = (dp2[j]%m + (dp[j-1]*(ss))%m)%m;
  	}
  }
  cout<<dp[k]<<endl;
  return 0;
}
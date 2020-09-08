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
const LL mm = 1e9 + 7;


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%mm;
	if(n&1) an = (an*a)%mm;	
	return an;
}

bool chk(LL n){
	while(n){
		int kk = n%10;
		if(kk!=4 && kk!= 7) return 0;
		n/=10;
	}
	return 1;
}

LL f[MAXN], fi[MAXN];

LL ncr(LL a, LL b){
	LL an = (f[a]*fi[a-b])%mm;
	an = (an*fi[b])%mm;
	return an;
}

int p[MAXN];
unordered_map<int,int> cn;
int cnt = 0;

LL dp[2005][2005];

int main(){
  fio();
  f[0] = fi[0] = 1;
  for1(i,MAXN-1) {
  	f[i] = (f[i-1]*i)%mm;
  	fi[i] = po(f[i],mm-2)%mm;
  }

  LL n,k; cin>>n>>k;
  LL z = 0; 
  
  forn(i,n){
  	LL x; cin>>x;
  	if(chk(x)){
  	 if(cn[x] == 0){
  	 	cn[x] = ++cnt;
  	 }
  	 p[cn[x]]++;
  	}

  	else z++;
  }

 // vector <vector<int> > dp(cnt+1, vector<int>(k+1,0));
  dp[0][0] = 1;
  for1(i,cnt){
  	//cout<<p[cnt]<<endl;
  	forn(j,cnt+1){
  		if(j>=1 && i>=1)dp[i][j] = (dp[i][j] + (dp[i-1][j-1]*1LL*p[i])%mm)%mm;
  		if(i>=1)dp[i][j] = ((LL)dp[i][j] + (LL)dp[i-1][j])%mm;
  	}
  }
  int nn = cnt;
  LL an = 0;
  forn(i,cnt+1){
  //	cout<<dp[nn][i]<<endl;
  	if(k-i>=0 && k-i<=z)
  		{
  			LL zx  = ((LL)ncr(z,k-i)*(LL)dp[nn][i])%mm;
  			an = (an + zx)%mm;
  		}
  }
  cout<<an<<endl;
  return 0;
}
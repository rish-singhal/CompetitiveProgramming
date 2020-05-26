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
const int inf = 1e7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


int main(){
  fio();
  vector <int> bit(60,-2);
  int cnt = 0;
  for(int i=2;i<60;i++){
  	if(bit[i]==-1) continue;
  		bit[i] = cnt++;
  		for(int j=2*i; j<60;j+=i)
  			bit[j] =-1;
  }
  int f[60];
  for(int i=1;i<60;i++){
  	int msk = 0;
  	int z = i;
  	for(int j=2;j*j<=60;j++){
  		if(z%j==0){
  			msk|=1<<bit[j];
  			while(z%j==0) z/=j;
  		}
  	}
  	if(z!=1) msk|=1<<bit[z];
  	f[i] = msk;
  }
  int n; cin>>n;
  vector<int> a(n);
  forn(i,n){
  	cin>>a[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(1<<cnt,inf)), val(n+1,vector<int>(1<<cnt,inf));
  forn(msk,1<<17)
  	dp[0][msk] = 0;
  for1(i,n){
  		for1(v,59){
  			int mskx = ((~f[v])&((1<<cnt)-1));
  			int msk = f[v];
  		for(int msk2=mskx;; msk2=(msk2-1)&mskx){
  			
  			if(dp[i][msk|msk2] > dp[i-1][msk2] + abs(v-a[i-1])){
  				dp[i][msk|msk2] = dp[i-1][msk2] + abs(v-a[i-1]);
  				val[i][msk|msk2] = v;
  			}
  			if(msk2==0) break;
  		}	
  	}
  }
  int an = inf;
  int msk2 = 0;
  forn(msk,1<<cnt){
  	if(an>dp[n][msk]){
  			an = dp[n][msk];
  		 	msk2 = msk;
  	}
  }
  vector<int> ans;
  for(int i=n;i>=1;i--){
  	ans.pb(val[i][msk2]);
  	msk2 = msk2^f[val[i][msk2]];
  }
  //cout<<an<<endl;
  for(auto i:vector<int>(ans.rbegin(), ans.rend())){
  	cout<<i<<" ";
  }
  cout<<endl;
  //cout<<f[1]<<endl;
  return 0;
}
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
const int MAXN = 3e4+2;
const int MAXI = 3e4+1;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*

d, d-1, d-2, d-3, d-4, .......,0 

d*d <= 30000 => d ~ [300]

9*10^7
 
*/
LL dp[MAXN][600];
int n,d;
vector<int> v(MAXN);


int dfs(int a, int pdis){
	int len = d + pdis - 300;
	//cout<<a<<" "<<len<<endl;
	LL &an = dp[a][pdis];
	if(an!=-1) return an;
	an = v[a];
	int dx[3] = {-1,0,1};
	int mm = 0;
	forn(i,3){
		if(a+len+dx[i]<=MAXI && len+dx[i]>0){
			mm = max(mm, dfs(a+len+dx[i], pdis+dx[i]));
		}
	}
	an+=mm;
	return an;
}


int main(){
  fio();
   cin>>n>>d;
   memset(dp, -1, sizeof dp);
 
  forn(i,n){
  	int x; cin>>x;
  	v[x]+=1;
  }
  cout<<dfs(d, 300)<<endl;
  return 0;
}
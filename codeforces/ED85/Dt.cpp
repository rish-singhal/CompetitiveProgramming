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

map<pair<int,int> , int> m;
int cnt = 0 ;
vector<int> v;
int n;

void dfs(int i=1){
	v.pb(i);
	if(cnt==(n*(n-1))){
		for(auto j:v) cout<<j<<" ";
			cout<<endl;
		exit(0);
	}
	for(int j=1;j<=n;j++){
		if(j==i || m[{i,j}]==1) continue;
		m[{i,j}] = 1;
		cnt++;
		dfs(j);
		m[{i,j}] = 0;
		cnt--;
	}
	v.pop_back();
}

int main(){
  fio();
 	cin>>n;
  dfs();
  return 0;
}
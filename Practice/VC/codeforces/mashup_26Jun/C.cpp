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
  int t; cin>>t;
  while(t--){
  	int n,p; cin>>n>>p;
  	int k = 2*n + p;
  	vector<vector<int>> mm(n+1, vector<int>(n+1,0));
  	for1(i,n){
  		for1(j,n){
  			if(i!=j && mm[i][j]==0){
  				mm[i][j]=mm[j][i]=1;
  				cout<<i<<" "<<j<<endl;
  				k--;
  			}
  			if(k==0) break;
  		}
  		if(k==0)break;
  	}
  }
  return 0;
}
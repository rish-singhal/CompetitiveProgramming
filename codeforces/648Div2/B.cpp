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
  	int n,m; cin>>n>>m;
  	vector<vector<int>> mat(n,vector<int>(m,0));
  	vector<int> cntr(n), cntc(m);
  	forn(i,n){
  		forn(j,m){
  			cin>>mat[i][j];
  		}
  	}
  	forn(i,n){
  		forn(j,m){
  			cntr[i]+=mat[i][j];
  			cntc[j]+=mat[i][j];
  		}
  	}
  	LL an = 0;
  	forn(i,n){
  		forn(j,m){
  			if(cntr[i]==0 && cntc[j]==0){
  			 cntr[i]=1;
  			 cntc[j]=1;
  			 an++;
  			}
  		}	
  	}
  
  	//cerr<<an<<endl;
  	if(an&1) cout<<"Ashish"<<endl;
  	else cout<<"Vivek"<<endl;
  }
  return 0;
}
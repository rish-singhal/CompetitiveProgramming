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
const int MAXN = 20 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<string> v;
int n,m;
int main(){
  fio();
  cin>>n>>m;
  v.resize(n);
  forn(i,2) cin>>v[i];
  if(v[0][0]=='>' && v[0][n-1]=='<' && v[1][0]=='^' && v[1][m-1]!='^'){
  	cout<<"YES"<<endl;
  	return 0;
  }
  if(v[0][n-1]=='>' && v[0][0]=='<' && v[1][m-1]=='^' && v[1][0]!='^'){
  	cout<<"YES"<<endl;
  	return 0;
  }
  cout<<"NO"<<endl;
  return 0;
}
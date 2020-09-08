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
  int n,m ;cin>>n>>m;
  int l1,r1,l2,r2;
  if(m&1){
  	l1 = 1, r1 = m;
  	l2 = m+1, r2 = 2*m + 1;
  }
  else{
  	l1 = 1, r1 = m+1;
  	l2 = m+2, r2 = 2*m + 1;
  }
  while(l1<r1)
  	cout<<(l1++)<<" "<<(r1--)<<endl;
  while(l2<r2)
  	cout<<(l2++)<<" "<<(r2--)<<endl;
  return 0;
}
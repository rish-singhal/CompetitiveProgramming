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
  int n,m,p; cin>>n>>m>>p;
  int cnt = 0;
  int b = 0;
  forn(i,n){
  	int x; cin>>x;
  	if(x%p==0 && b == 0){
  		cnt++;
  	}
  	else{
  		b  =1;
  	}
  }

  int cnt2 = 0;
  b = 0;
  forn(i,m){
  	int x; cin>>x;
  	if(x%p==0 && b == 0){
  		cnt2++;
  	}
  	else{
  		b  =1;
  	}
  }
  //cout<<cnt<<" "<<cnt2<<endl;
  cout<<(cnt + cnt2)<<endl;
  return 0;
}
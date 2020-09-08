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
  LL a,b,c, k; cin>>a>>b>>c>>k;
  LL an = 0;
 
  if(k<=a){
  	cout<<k<<endl;
  	return 0;
  }
  else{
  	k-=a;
  	an+=a;
  }

  if(k<=b){
  	cout<<an<<endl;
  	return 0;
  }
  else{
  	k-=b;
  }

  cout<<(k*-1 + an)<<endl;
  return 0;
}
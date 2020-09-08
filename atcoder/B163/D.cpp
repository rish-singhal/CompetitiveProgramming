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
const LL mm = 1e9+7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  LL n,k; cin>>n>>k;
  vector<LL> pr(n+5,0),su(n+5,0);
  for(LL i=1; i<n+1;i++){
  	pr[i] = (pr[i-1]+i)%mm;
  }
  for(LL i=n;i>=0;i--){
  	su[i] = (su[i+1]+i)%mm;
  }
  LL an = 0;
  for(LL i=k-1;i<=n+1;i++){
  	if(su[n-i]<pr[i]) continue;
  	an =  (an  + (su[n-(i)]- pr[i]+mm)%mm + 1)%mm;
  	an = (an+mm)%mm;
  	//cout<<pr[i]<<" "<<su[n-(i)]<<endl;
  }
  cout<<an<<endl;
  return 0;
}
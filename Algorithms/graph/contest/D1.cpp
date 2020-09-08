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
  int n; cin>>n;
  int p=n;
  while(1){
    int b = 1;  
    for(int i=2;i*i<=p;i++)
          if(p%i==0){
            b  =0; break;
          }
  if(b) break;
  }
	cout<<p<<"\n"<<n<<" "<<1<<"\n";
	for1(i,n-1) cout<<i<<" "<<i+1<<"\n";
	for1(i,p-n)	cout<<i<<" "<<i+(n>>1)<<"\n";  
  return 0;
}


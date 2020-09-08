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
const LL mm = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
  if(n==0) return 1;
  LL an = po(a,n/2);
  an = (an*an)%mm;
  if(n&1) return an*a%mm;
  return an;
}

int main(){
  fio();
  LL n,m, l, r; cin>>n>>m>>l>>r;  
  LL kk = (r-l)/2;
  if(r%2!=0 || l%2 !=0)
      kk++;
  kk%=mm;
//  LL zz = n*m%(mm-1);
  LL rr = (r - l + 1 - kk +mm)%mm;
  LL an = (po(rr,n*m) + po(kk,n*m))%mm;
 
  if(((kk+rr)&1)==0){
    LL zz = n*m;
    an = ( po(abs(rr-kk)%mm, zz))%mm;
    an = ( an + po((rr+kk)%mm,zz))%mm;
    an = an*po(2,mm-2)%
  }
  else{
     LL zz = n*m - 1;
    zz %= mm- 1;
    an = po( (rr+kk)%mm, zz)%mm;
    an = ( an*(kk+rr))%mm;
}

    cout<<an<<endl;
   return 0;
}


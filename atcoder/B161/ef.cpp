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
using u64 = LL;
using u128 = LL;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n, LL m){
  if(n==0) return 1;
  LL an = po(a,n/2,m);
  an = (an*an)%m;
  if(n&1) return an*a%m;
  return an;
}

bool isprime(LL n, int iter=100) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        LL a = 2 + rand() % (n - 3);
        if (po(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

bool chk(LL i, LL n){
  while(n%i==0) n/=i;
  if(n==1) return 1;
  if(n%i==1) return 1;
   return 0;
}
int main(){
  fio();
  LL n; cin>>n;
  if(n==2) {
    cout<<1<<endl;
    return 0;
  }
  LL k = n-1;
  set<LL> s;
  for(LL i = 2;i*i<=k;i++){
    if(k%i==0 && chk(i,n)) s.insert(i);
    if(k%i==0 && chk(k/i,n))s.insert(k/i);
  }
  s.insert(k);
  for(LL i=2;i*i<=n;i++){
    if(n%i==0 && chk(i,n)) s.insert(i);
    if(n%i ==0 && chk(n/i,i)) s.insert(n/i);
  }
 // s.insert(2);
  s.insert(n);
//  for(auto i:s) cout<<i<<" ";
  //  cout<<endl;
  cout<<s.size()<<endl;
  return 0;
}



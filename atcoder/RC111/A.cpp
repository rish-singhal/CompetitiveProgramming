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

LL po(LL a, LL b, LL m)
{
  if(b == 0) return 1;
  LL an = po(a, b/2, m);
  an = (an*an)%m;
  if(b&1)
    an = (an * a)%m;
  return an;
}

int main(){
  fio();
  LL n, m; cin>>n>>m;
  // ax + b = c
  LL mm = m * m;
  LL a = m % mm;
  LL b = po(10, n, m) % mm;
  LL c = po(10, n, mm);
  LL an = (c - b)%mm;
  an = (an + mm)%mm;
  
  for(LL x = 1; x <= mm; x++)
  {
    LL p = (a*x)%mm;
    if(p == an){
      cout << x % m << endl;
      return 0;
    }
  }

  //cout << a <<" "<< b << " "<< c << endl;
 // cout << an << endl;
  // cout << an % m << endl;
  return 0;
}